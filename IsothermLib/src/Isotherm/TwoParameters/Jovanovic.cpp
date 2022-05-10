//==============================================================================
// Name        : Jovanovic.cpp
// Author      : Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim barboza Storck
// Version     : 1.0
// Description : Classe com as equações da isoterma de Jovanovic
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

#include <iostream>         // std::cout

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Jovanovic.h>

IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       detailsJovanovic
    {
        PairString  ( "Qmax"
                    , "Capacidade máxima de adsorção")
    ,   PairString  ( "K1"
                    , "Constante da isoterma de Jovanovic")
    };

template<>
VecPairString IsothermTemplate < Jovanovic >::infoIsotherm = detailsJovanovic;

#undef  __FUNCT__
#define __FUNCT__ "Jovanovic :: Jovanovic (const Real&, const Real&)"
Jovanovic :: Jovanovic (    const Real&     _qmax,
                            const Real&     _k1) :
                            TwoParameters(_qmax, _k1)
{

#ifdef __JOVANOVIC_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

    try {
            if (_k1 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK1LEZero);

            if (_qmax <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadQmaxLEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";

#ifdef __JOVANOVIC_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();

    }

    setup = true;

#ifdef __JOVANOVIC_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

}

//==============================================================================
// Concentração de Equilí­brio Q
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Jovanovic ::  Qe (const Real&, const Real&) "
Real
Jovanovic ::  Qe (const Real& _ce, const Real& _temp) const {
#ifdef __JOVANOVIC_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

    try {

        if (!setup) throw
            IsoException (IST_LOC, className(), BadCoefficient);

        if (_ce <= 0.0)  throw
                IsoException (IST_LOC, className(), BadCeLEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept
                    << "\n"
                    << std::flush;

#ifdef __JOVANOVIC_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();
    }

auto    ptrValue = std::begin(coeffValue);
auto    value    = *(ptrValue + 1) * exp(- (*ptrValue) * _ce) ;

#ifdef __JOVANOVIC_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

    return  (value >= ZERO ? value : 0.0) ;;

}

IST_NAMESPACE_CLOSE