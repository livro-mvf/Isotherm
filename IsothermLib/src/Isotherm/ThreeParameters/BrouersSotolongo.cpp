//==============================================================================
// Name        : BrouersSotolongo.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de BrouersSotolongo
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
#include <Isotherm/ThreeParameters/BrouersSotolongo.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       isothermBrouersSotolongo    {   PairString  ( "Qmax"
                                                                , "Capacidade maxima de adsorcao.")
                                                ,   PairString  ( "K1"
                                                                , "Constante da isoterma de Brouers - Sotolongo.")
                                                ,   PairString  ( "K2"
                                                                , "Constante da isoterma de Brouers - Sotolongo.")};

template<>
VecPairString IsothermTemplate < BrouersSotolongo >::infoIsotherm = isothermBrouersSotolongo;


//==============================================================================
// Construtora com dois parametros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "BrouersSotolongo :: BrouersSotolongo (const Real&, const Real&, const Real&)"
BrouersSotolongo :: BrouersSotolongo    (   const Real&     _qmax
                                        ,   const Real&     _k1
                                        ,   const Real&     _k2
                                        )
                                        :   ThreeParameters(_qmax, _k1, _k2)
{

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

}

//==============================================================================
// Concentracao de equilibrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "BrouersSotolongo ::  Qe (const Real&, const Real&) const "
Real
BrouersSotolongo ::  Qe     (   const Real&     _ce
                            ,   const Real&
                            ) const
{


    try {
        if (!setup) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient
                                );

        if (_ce <= 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCeLEZero
                                );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
    }

auto    ptrValue = std::begin(coeffValue);
auto    auxiK2 = pow(_ce, *(ptrValue + 2));
auto    auxi = exp(-((*(ptrValue + 1)) * auxiK2));
auto    value = *ptrValue *   (1 - auxi);

    return  (value >= ZERO ? value : 0.0);

}

IST_NAMESPACE_CLOSE