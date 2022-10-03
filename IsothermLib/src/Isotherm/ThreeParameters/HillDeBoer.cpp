//==============================================================================
// Name        : HillDeboer.cpp
// Author      : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Hill - Deboer
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

#include <cmath>                // std::exp
#include <iostream>             // std::cout


//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/ThreeParameters/HillDeboer.h>
#include <Misc/NewtonRaphson.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsHillDeboer
    {
        PairString  ( "Qmax"
                    , "Capacidade maxima de adsorcao")
    ,   PairString  ( "K1"
                    , "Constante de equilibrio de Hill Deboer")
    ,   PairString  ( "K2"
                    , "Constante de iteracao entre as moleculas adsorvidas")
    };

template<>
VecPairString IsothermTemplate < HillDeboer >::infoIsotherm = detailsHillDeboer;


//==============================================================================
// Construtora com dois parametros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "HillDeboer :: HillDeboer (const Real&, const Real&, const Real&)"
HillDeboer :: HillDeboer    (   const Real& _qmax
                            ,   const Real& _k1
                            ,   const Real& _k2
                            ,   const Real& _rgas) 
                            :   ThreeParameters(_qmax, _k1, _k2 )
                            ,   RGAS(_rgas) {



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

            if (_k2 < 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK2LTZero
                                    );

            if (_rgas <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadRGasLEZero
                                    );


    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    }

    setup = true;


    }

//==============================================================================
// Concentracao de equilibrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "HillDeboer ::  Qe (const Real&, const Real&) const"
Real
HillDeboer ::  Qe   (   const Real&     _ce
                    ,   const Real&     _temp
                    ) const {


    try {

        if (!setup) throw
            IsoException    (   IST_LOC
                            ,   className()
                            ,   BadCoefficient
                            );

        if (_ce < 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCeLTZero
                                );

        if (_temp <= 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadTempLEZero
                                );


    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
    }

    const_cast<Real&>(auxiCe) = _ce * this->K1();
    const_cast<Real&>(tempK)  = 1.0 / (_temp * Rgas());
    
    
auto fp    = std::bind(&HillDeboer::FQe, *this, _1);
auto resul = NewtonRaphson (fp, 0.95);
auto value = resul * Qmax();

    return (value >= ZERO ? value : 0.0);

}


#undef  __FUNCT__
#define __FUNCT__ "Real  HillDeboer ::  FQe (const Real&) const"
Real  
HillDeboer ::  FQe (const Real& _theta) const {


auto       auxi1  = _theta / (1.0 - _theta);
auto       auxiK2 = _theta * this->K2() * tempK;
auto       auxi2  = auxi1 * exp(auxi1 - auxiK2);

    return auxiCe - auxi2;

}

IST_NAMESPACE_CLOSE