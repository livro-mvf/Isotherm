//=====================================================================================
// Name        : Temkin.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim barboza Storck
// Version     : 1.0
// Description : Classe com as equações da isoterma de Temkin
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
#include <Isotherm/TwoParameters/Temkin.h>

IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       detailsTemkin
    {
        PairString  ( "K1"
                    , "Constante da isoterma de Temkin")
    ,   PairString  ( "K2"
                    , "Constante de ligação de equilíbrio isotérmica")};

template<>
VecPairString IsothermTemplate < Temkin >::infoIsotherm = detailsTemkin;



//==============================================================================
// Construtora com dois parâmetros
//==============================================================================


#undef  __FUNCT__
#define __FUNCT__ "Temkin :: Temkin (const Real&, const Real&)"
Temkin :: Temkin (  const Real& _k1,
                    const Real& _k2,
                    const Real& _rgas) : TwoParameters(_k1, _k2), RGAS(_rgas) {

    try {

            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero);

            if (_k2 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK2LEZero);

            if (_rgas <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadRGasLEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";
        abort();

    }

    setup = true;

#ifdef __TEMKIN_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

    }

//==============================================================================
// Concentração de Equilíbrio Q
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Temkin ::  Qe (const Real&, const Real&) const  "
Real
Temkin ::  Qe   (   const Real&     _ce
                ,   const Real&     _temp) const
{

auto    ptrValue = std::begin(coeffValue);

        try {

            if (!setup) throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadCoefficient);

            if (_ce <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    , BadCeLEZero);

            if (_temp < 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadTempLEZero);

            if ((_ce * (*ptrValue)) <= 1.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadKCeK1LEOne);

        } catch (const IsoException& _isoExcept) {

            std::cout << _isoExcept << "\n";
            abort();
        }

auto    auxi = log(_ce * (*ptrValue));

    return (RGAS * _temp * auxi) / (*(ptrValue + 1));


}

IST_NAMESPACE_CLOSE