////==============================================================================
//// Name        : RadkePrausnitsII.cpp
//// Author      : Lara Botelho Brum
////               Joao Flavio Vieira de Vasconcellos
//// Version     : 1.0
//// Description : Classe com as equações da isoterma de Radke-Prausnits II
////
//// Copyright   : Copyright (C) <2021>  Joao Flavio Vasconcellos
////                                      (jflavio at iprj.uerj.br)
////
//// This program is free software: you can redistribute it and/or modify
//// it under the terms of the GNU General Public License as published by
//// the Free Software Foundation, either version 3 of the License.
////
//// This program is distributed in the hope that it will be useful,
//// but WITHOUT ANY WARRANTY; without even the implied warranty of
//// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//// GNU General Public License for more details.
////
//// You should have received a copy of the GNU General Public License
//// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////
////==============================================================================
//
//
//
////==============================================================================
//// includes lib c++
////==============================================================================
//
//#include <cmath>
//#include <iostream>
//
////==============================================================================
//// includes da lib IsothermLib
////==============================================================================
//
//#include <Error/IsoException.h>
//#include <Isotherm/ThreeParameters/RadkePrausnitsII.h>
//
//
//IST_NAMESPACE_OPEN
//
////==============================================================================
//// Variaveis estáticas
////==============================================================================
//
//VecPairString       detailsRadkePrausnitsII {   PairString  ( "Qmax"
//                                                           , "Capacidade máxima de adsorção")
//                                            ,   PairString  ( "K1"
//                                                           , "Constante de Radke-Prausnits II")
//                                            ,   PairString  ( "K2"
//                                                           , "Coeficiente de cooperatividade de Radke-Prausnits II")};
//
//template<>
//VecPairString IsothermTemplate < RadkePrausnitsII >::infoIsotherm = detailsRadkePrausnitsII;
//
//
////==============================================================================
//// Construtora com tres parâmetros
////==============================================================================
//
//#undef  __FUNCT__
//#define __FUNCT__ "RadkePrausnitsII :: RadkePrausnitsII (const Real&, const Real&, const Real&)"
//RadkePrausnitsII :: RadkePrausnitsII (  const Real& _qmax,
//                const Real& _k1,
//                const Real& _k2) : ThreeParameters(_qmax, _k1, _k2) {
//
//#ifdef __RADKE_PRAUSNITS_II_DEBUG_H__
//std::cout << "Entrei: " << __FUNCT__ << "\n";
//#endif
//
//
//    try {
//
//            if (_qmax <= 0.0)  throw
//                    IsoException (IST_LOC, className(), BadQmaxLEZero);
//
//            if (_k1 <= 0.0)  throw
//                    IsoException (IST_LOC, className(), BadK1LEZero);
//
//            if (_k2 <= 1)  throw
//                    IsoException (IST_LOC, className(), BadK2LEOne);
//
//    } catch (const IsoException& _isoExcept) {
//
//        std::cout << _isoExcept << "\n";
//
//#ifdef __RADKE_PRAUSNITS_II_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//        abort();
//
//    };
//
//#ifdef __RADKE_PRAUSNITS_II_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//
//}
//
////==============================================================================
//// Concentração de Equilíbrio Qe
////==============================================================================
//
//#undef  __FUNCT__
//#define __FUNCT__ "RadkePreusnitsII ::  Qe (const Real&, const Real&) const "
//Real
//RadkePrausnitsII ::  Qe (const Real& _ce, const Real&) const {
//
//    try {
//
//        if (_ce < 0.0)  throw
//                IsoException (IST_LOC, className(), BadCeLTZero);
//
//    } catch (const IsoException& _isoExcept) {
//
//        std::cout << _isoExcept << "\n";
//
//#ifdef __RADKE_PRAUSNITS_II_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//        abort();
//    }
//
//auto    ptrValue = std::begin(coeffValue);
//auto    auxi = (*(ptrValue + 1) * _ce) / (((1 + *(ptrValue + 1)) * pow ( _ce, *(ptrValue + 2))));
//
//#ifdef __RADKE_PRAUSNITS_II_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//
//        return *ptrValue * auxi;
//}
//
//IST_NAMESPACE_CLOSE