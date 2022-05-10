//==============================================================================
// Name        : Langmuir.cpp
// Author      : Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Classe com as equações da isoterma de Langmuir
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

#include <iostream>

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Langmuir.h>

IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       detailsLangmuir
    {
        PairString  ( "Qmax"
                    , "Capacidade máxima de adsorção")
    ,   PairString  ( "K1"
                    , "Constante de equilibrio de Langmuir")
    };

template<>
VecPairString IsothermTemplate < Langmuir >::infoIsotherm = detailsLangmuir;


#undef  __FUNCT__
#define __FUNCT__ "Langmuir :: Langmuir (const Real&, const Real&)"
Langmuir :: Langmuir    (   const Real&     _qmax
                        ,   const Real&     _k1)
                        :   TwoParameters(_qmax, _k1)
{

#ifdef __LANGMUIR_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

    try {

            if (_qmax <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadQmaxLEZero);

            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";

#ifdef __LANGMUIR_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();

    }

    setup = true;

#ifdef __LANGMUIR_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

    }

//==============================================================================
// Construtores
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Langmuir ::  Qe (const Real&, const Real&) const "
Real Langmuir ::  Qe (const Real& _ce, const Real&) const {
#ifdef __LANGMUIR_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

    try {

        if (!setup) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient);

        if (_ce <= 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                , BadCeLTZero);

    } catch (const IsoException& _isoExcept) {

    std::cout << _isoExcept << "\n";

#ifdef __LANGMUIR_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();
    }

auto    ptrValue    = std::begin(coeffValue);
auto    auxi        = *(ptrValue + 1) * _ce;
auto    value       = *ptrValue * auxi / (1.0 + auxi);

#ifdef __LANGMUIR_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

//    return  (value >= ZERO ? value : 0.0);

    return value;

}

IST_NAMESPACE_CLOSE