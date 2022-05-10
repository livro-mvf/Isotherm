//==============================================================================
// Name        : RedlichPeterson.cpp
// Authors     : Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe da isoterma de Redlich - Peterson
//
// Copyright   : Copyright (C) <2021>  Joao Flavio Vasconcellos
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
#include <Isotherm/ThreeParameters/RedlichPeterson.h>

IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       detailsRedlichPeterson
    {
        PairString  ( "K1"
                    , "Constante de Redlich-Peterson")
    ,   PairString  ( "K2"
                    , "Constante de Redlich-Peterson")
    ,   PairString  ( "K3"
                    , "Coeficiente que reflete a heterogeneidade do adsorvente")
    };

template<>
VecPairString IsothermTemplate < RedlichPeterson >::infoIsotherm = detailsRedlichPeterson;


//==============================================================================
// Construtora com dois parâmetros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "RedlichPeterson :: RedlichPeterson (const Real&, const Real&, const Real&)"
RedlichPeterson :: RedlichPeterson (
                const Real& _k1,
                const Real& _k2,
                const Real& _k3) : ThreeParameters(_k1, _k2, _k3) {

#ifdef __REDLICH_PETERSON_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif


    try {
            if (_k1 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK1LEZero);

            if (_k2 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK2LEZero);

            if (_k3 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK3LTZero);

            if (_k3 >= 1.0)  throw
                    IsoException (IST_LOC, className(), BadK3GTOne);

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";

#ifdef __REDLICH_PETERSON_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();

    };

    setup = true;

#ifdef __REDLICH_PETERSON_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

}

//==============================================================================
// Concentração de Equilíbrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real RedlichPeterson ::  Qe (const Real&, const Real&) const "
Real RedlichPeterson ::  Qe (const Real& _ce, const Real&)  const {

    try {

        if (!setup) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient);

        if (_ce <= 0.0)  throw
                IsoException (IST_LOC, className(), BadCeLEZero);
    } catch (const IsoException& _isoExcept) {

    std::cout << _isoExcept << "\n";

#ifdef __REDLICH_PETERSON_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();
    }

auto    ptrValue = std::begin(coeffValue);

auto    value = (*ptrValue * _ce) / (1 + *(ptrValue + 1) * (pow(_ce, *(ptrValue + 2))));
#ifdef __REDLICH_PETERSON_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif


        return (value >= ZERO ? value : 0.0)  ;

}

IST_NAMESPACE_CLOSE