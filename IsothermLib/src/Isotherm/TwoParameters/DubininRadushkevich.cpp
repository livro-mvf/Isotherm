//==============================================================================
// Name        : DubininRadushkevich.cpp
// Authors     : Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Classe com as equações da isoterma de Dubinin-Radushkevich
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

//#include <cmath>
//#include <iostream>

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/DubininRadushkevich.h>

//==============================================================================
// Variaveis estáticas
//==============================================================================

IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       detailsDubininRadushkevich                      /* NOLINT */
    {
        PairString  ( "Qmax"
                    , "Constante de equilíbrio de Dubinin-Radushkevich")
    ,   PairString  ( "K1"
                    , "Coeficiente associado a energia de adsorção")};

template<>
VecPairString IsothermTemplate < DubininRadushkevich >::infoIsotherm = detailsDubininRadushkevich; /* NOLINT */


//==============================================================================
// Construtora com dois parâmetros
//==============================================================================



DubininRadushkevich :: DubininRadushkevich  (   const Real&         _qmax
                                            ,   const Real&         _k1
                                            ,   const Real&         _rgas)
                                            :   TwoParameters ( _qmax,  _k1 )
                                            ,   RGAS (_rgas )
{
//
//    try {
//
//        if (_qmax <= 0.0) {
//            throw IsoException(IST_LOC, className(), BadQmaxLEZero);
//        }
//
//        if (_k1 <= 0.0) {
//            throw IsoException(IST_LOC, className(), BadK1LEZero);
//        }
//
//        if (_rgas <= 0.0) {
//            throw IsoException(IST_LOC, className(), BadRGasLEZero);
//        }
//
//    } catch (const IsoException& _isoExcept) {
//
//        std::cout   << _isoExcept;
//        abort();
//
//    }
//
//    setup = true;
//
}

//==============================================================================
// Concentração de equilibro Qe
//==============================================================================

Real
DubininRadushkevich ::  Qe  (   const Real&     _ce
                            ,   const Real&     _temp) const
{

//    try {
//
//        if (!setup) {
//            throw IsoException(IST_LOC, className(), BadCoefficient);
//        }
//
//        if (_ce <= 0.0) {
//            throw IsoException(IST_LOC, className(), BadCeLEZero);
//        }
//
//        if (_temp <= 0.0) {
//            throw IsoException(IST_LOC, className(), BadTempLEZero);
//        }
//
//    } catch (const IsoException& _isoExcept) {
//
//        std::cout << _isoExcept << "\n";
//        abort();
//
//    }
//
//auto    ptrValue    = std::begin(coeffValue);
//auto    eps         = RGAS * _temp * log(1.0 + (1.0 / _ce));
//
//    return  *ptrValue * exp( - (*(ptrValue + 1) * eps * eps));
    return 0;
}

IST_NAMESPACE_CLOSE