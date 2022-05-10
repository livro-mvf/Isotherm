//==============================================================================
// Name        : MacMillanTeller.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de MacMillan - Teller.
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

#include <Isotherm/ThreeParameters/MacMillanTeller.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       isothermMacMillanTeller {   PairString  ( "Qmax"
                                                    , "Capacidade máxima de adsorção.")
                                            ,   PairString  ( "K1"
                                                    , "Constante da isoterma de MacMillan - Teller.")
                                            ,   PairString  ( "K2"
                                                    , "Constante da isoterma de MacMillan - Teller.")};

template<>
VecPairString IsothermTemplate < MacMillanTeller >::infoIsotherm = isothermMacMillanTeller;


//==============================================================================
// Construtora com dois parâmetros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "MacMillanTeller :: MacMillanTeller (const Real&, const Real&, const Real&)"
MacMillanTeller :: MacMillanTeller (  const Real& _qmax,
                const Real& _k1,
                const Real& _k2) : ThreeParameters(_qmax, _k1, _k2) {

#ifdef __MAC_MILLAN_TELLER_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif


//    try {
//
//            if (_qmax < 0.0)  throw
//                    IsoException (IST_LOC, className(), BadQmaxLEZero);
//
//            if (_k1 < 0.0)  throw
//                    IsoException (IST_LOC, className(), BadK1LEZero);
//
//            if (_k2 < 0.0)  throw
//                    IsoException (IST_LOC, className(), BadK2LEZero);
//
//    } catch (const IsoException& _isoExcept) {
//
//        std::cout << _isoExcept << "\n";
//
//#ifdef __MAC_MILLAN_TELLER_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//        abort();
//
//    };

    setup = true;

#ifdef __MAC_MILLAN_TELLER_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

}

//==============================================================================
// Concentração de Equilíbrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "MacMillanTeller ::  Qe (const Real&, const Real&) const "
Real
MacMillanTeller ::  Qe (const Real& _ce, const Real&) const {

//    try {
//        if (!setup) throw
//                IsoException    (   IST_LOC
//                                ,   className()
//                                ,   BadCoefficient);
//
//        if (_ce < 0.0)  throw
//                IsoException (IST_LOC, className(), BadCeLTZero);
//
//    } catch (const IsoException& _isoExcept) {
//
//        std::cout << _isoExcept << "\n";
//
//#ifdef __MAC_MILLAN_TELLER_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//        abort();
//    }

auto    ptrValue = std::begin(coeffValue);
auto    auxi = log(*(ptrValue + 2) / _ce);
auto    auxi1 = (*(ptrValue + 1)) / auxi;
auto    auxi2 = pow(auxi1, (1 / 3));

#ifdef __MAC_MILLAN_TELLER_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

        return ( (*ptrValue) * auxi2);
}

IST_NAMESPACE_CLOSE