////==============================================================================
//// Name        : Toth.cpp
//// Author      : Lara Botelho Brum
////               Joao Flavio Vieira de Vasconcellos
//// Version     : 1.0
//// Description : Classe com as equações da isoterma de Toth
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
//#include <Isotherm/ThreeParameters/Toth.h>
//
//
//IST_NAMESPACE_OPEN
//
////==============================================================================
//// Variaveis estáticas                                                              *EDITAR, CASO HAJA NECESSIDADE*
////==============================================================================
//
//VecPairString       detailsToth {   PairString  ( "K3"
//                                                , "Constante de Toth")
//                                ,   PairString  ( "K1"
//                                                , "Constante de Toth")
//                                ,   PairString  ( "K2"
//                                                , "Coeficiente de cooperatividade de Toth")};
//
//template<>
//VecPairString IsothermTemplate < Toth >::infoIsotherm = detailsToth;
//
//
//
////==============================================================================
//// Construtora com tres parâmetros
////==============================================================================
//
//#undef  __FUNCT__
//#define __FUNCT__ "Toth :: Toth (const Real&, const Real&, const Real&)"
//Toth :: Toth (  const Real& _k3,
//                const Real& _k1,
//                const Real& _k2) :
//                ThreeParameters(_k3, _k1, _k2) {
//
//#ifdef __TOTH_DEBUG_H__
//std::cout << "Entrei: " << __FUNCT__ << "\n";
//#endif
//
//
//   try {
//
//            if (_k3 <= 0.0)  throw
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
//#ifdef __TOTH_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//        abort();
//
//    }
//    setup = true;
//
//#ifdef __TOTH_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//
// }
//
////==============================================================================
//// Concentração de Equilíbrio Qe
////==============================================================================
//
//#undef  __FUNCT__
//#define __FUNCT__ "Toth ::  Qe (const Real&, const Real&) const "
//Real
//Toth ::  Qe (const Real& _ce, const Real&) const {
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
//#ifdef __TOTH_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//        abort();
//    }
//
//auto    ptrValue = std::begin(coeffValue);
//auto    auxi = pow((1 / *(ptrValue + 1)) + (pow (_ce, *(ptrValue + 2) )) , 1 / * (ptrValue + 2));
//
//#ifdef __KHAN_DEBUG_H__
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif
//
//        return *ptrValue * _ce / auxi;
//}
//
//IST_NAMESPACE_CLOSE