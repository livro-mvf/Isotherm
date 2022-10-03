//==============================================================================
// Name        : Unilan.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Unilan.
//
// Copyright   : Copyright (C) <2022>  Joao Flavio Vasconcellos
//                                      (jflavio at iprj.uerj.br)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//==============================================================================


//==============================================================================
// includes lib c++
//==============================================================================

#include <cmath>
#include <iostream>

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/ThreeParameters/Unilan.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       isothermUnilan {   PairString  ( "Qmax"
                                                    , "Capacidade maxima de adsorcao.")
                                    ,   PairString  ( "K1"
                                                    , "Constante da isoterma de Unilan.")
                                    ,   PairString  ( "K2"
                                                    , "Constante da isoterma de Unilan.")};

template<>
VecPairString IsothermTemplate < Unilan >::infoIsotherm = isothermUnilan;


//==============================================================================
// Construtora com dois parametros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Unilan :: Unilan (const Real&, const Real&, const Real&)"
Unilan :: Unilan    (   const Real&     _qmax
                    ,   const Real&     _k1
                    ,   const Real&     _k2
                    ) 
                    : ThreeParameters(_qmax, _k1, _k2) {



    try {

            if (_qmax <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadQmaxLEZero
                                    );

            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero
                                    );

            if (_k2 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK2LEZero
                                    );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    };

    setup = true;
    
auto    val = exp(_k2);
        nume = _k1 * val;
        deno = _k1 / val;
        prod = 0.5 * _qmax / _k2;


}

//==============================================================================
// Concentracao de equilibrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Unilan ::  Qe (const Real&, const Real&) const "
Real
Unilan ::  Qe   (   const Real&     _ce
                ,   const Real&
                ) const {

    try {
        if (!setup) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient);

        if (_ce < 0.0)  throw
                IsoException (IST_LOC, className(), BadCeLTZero);

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
       exit(EXIT_FAILURE);;
    }

auto    ptrValue = std::begin(coeffValue);
auto    value = prod * log ((1 + _ce * nume) / (1 + _ce * deno));

    return (value >= ZERO ? value : 0.0)  ;
    
    
}

IST_NAMESPACE_CLOSE