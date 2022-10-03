//==============================================================================
// Name        : RadkePrausnitsIII.cpp
// Author      : Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Radke-Prausnits III
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
#include <Isotherm/ThreeParameters/RadkePrausnitsIII.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsRadkePrausnitsIII {   PairString  ( "Qmax"
                                                           , "Capacidade maxima de adsorcao")
                                            ,   PairString  ( "K1"
                                                           , "Constante de Radke-Prausnits III")
                                            ,   PairString  ( "K2"
                                                           , "Coeficiente de cooperatividade de Radke-Prausnits III")};

template<>
VecPairString IsothermTemplate < RadkePrausnitsIII >::infoIsotherm = detailsRadkePrausnitsIII;


//==============================================================================
// Construtora com tres parametros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "RadkePrausnitsIII :: RadkePrausnitsIII (const Real&, const Real&, const Real&)"
RadkePrausnitsIII :: RadkePrausnitsIII  (   const Real&     _qmax
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

            if (_k2 <= 1)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK2LEOne
                                    );

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";
        exit(EXIT_FAILURE);
    };

}

//==============================================================================
// Concentracao de equilibrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "RadkePreusnitsIII ::  Qe (const Real&, const Real&) const "
Real
RadkePrausnitsIII ::  Qe (const Real& _ce, const Real&) const {

    try {

        if (_ce < 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCeLTZero
                                );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
    }

auto    ptrValue = std::begin(coeffValue);
auto    auxi =  *(ptrValue + 1) *  pow(_ce, *(ptrValue+2));
auto    value = *ptrValue * auxi / (1 + auxi / _ce);
return (value >= ZERO ? value : 0.0) ;
        
}

IST_NAMESPACE_CLOSE