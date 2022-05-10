//=====================================================================================
// Name        : Freundlich.cpp
// Author      : Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Classe com as equações da isoterma de Freundlich
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

#include <cfenv>                    // std::feclearexcept
#include <cmath>                    // pow
#include <iostream>                 // std::cout

#pragma STDC FENV_ACCESS on

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/Freundlich.h>

IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       detailsFreundlich
    {
        PairString  ( "K1"
                    , "Coeficiente de distribuição")
    ,   PairString  ( "K2"
                    , "Fator de correção")};

template<>
VecPairString IsothermTemplate < Freundlich >::infoIsotherm = detailsFreundlich;


//==============================================================================
// Construtora com dois parâmetros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Freundlich (const Real&, const Real&)"
Freundlich :: Freundlich    (   const Real&         _k1
                            ,   const Real&         _k2)
                            :   TwoParameters(_k1, _k2)
{

#ifdef __FREUNDLICH_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif


    try {

            if (_k1 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK1LEZero);

            if (_k2 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK2LEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";

#ifdef __FREUNDLICH_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();

    }

    invK2 = 1.0 /  _k2;
    setup = true;

#ifdef __FREUNDLICH_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

    }

//==============================================================================
// Concentração de Equilíbrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Qe (const Real&, const Real& = 0) const"
Real
Freundlich ::  Qe   (   const Real&         _ce
                    ,   const Real&             ) const
{
#ifdef __FREUNDLICH_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

Real    expValue;
auto    ptrValue = std::begin(coeffValue);

    try {

        if (!setup) throw
            IsoException (IST_LOC, className(), BadCoefficient);

        if (_ce < 0.0)  throw
                IsoException (IST_LOC, className(), BadCeLTZero);

        std::feclearexcept(FE_ALL_EXCEPT);
        expValue = pow(_ce, invK2);

        if(std::fetestexcept(FE_OVERFLOW)) throw
                IsoException (IST_LOC, className(), BadOverFlow);

    } catch (const IsoException& _isoExcept) {

    std::cout << _isoExcept << "\n";

#ifdef __FREUNDLICH_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();
    }


auto    value    = *ptrValue * expValue ;

#ifdef __FREUNDLICH_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

    return (value >= ZERO ? value : 0.0) ;

}

IST_NAMESPACE_CLOSE