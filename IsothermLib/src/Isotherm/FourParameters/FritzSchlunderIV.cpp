////==============================================================================
//// Name        : FritzSchlunderIV.cpp
//// Author      : Lara Botelho Brum
//// Version     : 1.0
//// Description : Classe com as equações da isoterma de Fritz - Schlunder IV.
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
////==============================================================================
//// includes lib c++
////==============================================================================
//
//#include <cmath>
//#include <iostream>
//#include <iomanip>
//
////==============================================================================
//// includes da lib Isotherm++
////==============================================================================
//
//#include <Isotherm/FourParameters/FritzSchlunderIV.h>
//
//
//IST_NAMESPACE_OPEN
//
////==============================================================================
//// Variaveis estáticas
////==============================================================================
//
//VecPairString       detailsFritzSchlunderIV {   PairString  ( "Qmax"
//                                                            , "Capacidade máxima de adsorção.")
//                                            ,   PairString  ( "K1"
//                                                            , "Coeficiente da isoterma de Fritz – Schlunder IV.")
//                                            ,   PairString  ( "K2"
//                                                            , "Coeficiente da isoterma de Fritz – Schlunder IV.")        
//                                            ,   PairString  ( "K3"
//                                                            , "Expoente da isoterma de Fritz–Schlunder IV.")};
//
//template<>
//VecPairString IsothermTemplate < FritzSchlunderIV >::infoIsotherm = detailsFritzSchlunderIV;
//
//
////==============================================================================
//// Construtora com dois parâmetros
////==============================================================================
//
//#undef  __FUNCT__
//#define __FUNCT__ "FritzSchlunderIV :: FritzSchlunderV (const Real&, const Real&, const Real&, const Real&)"
//FritzSchlunderIV :: FritzSchlunderIV (  const Real& _qmax, 
//                const Real& _k1,
//                const Real& _k2,
//                const Real& _k3) : FourParameters(_qmax, _k1, _k2, _k3) {
//    
//#ifdef __FRITZ_SCHLUNDER_IV_DEBUG_H__   
//std::cout << "Entrei: " << __FUNCT__ << "\n";
//#endif    
//
//
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
//            if (_k3 > 1.0 || _k3 < 0)  throw  
//                    IsoException (IST_LOC, className(), BadK3Between);   
//            
//    } catch (const IsoException& _isoExcept) {
//            
//        std::cout << _isoExcept << "\n";
//         
//#ifdef __FRITZ_SCHLUNDER_IV_DEBUG_H__    
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif              
//        abort();
//        
//    };
//    
//    setup = true;
//            
//#ifdef __FRITZ_SCHLUNDER_IV_DEBUG_H__   
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
//#define __FUNCT__ "FritzSchlunderV ::  Qe (const Real&, const Real&) const "
//Real 
//FritzSchlunderIV ::  Qe (const Real& _ce, const Real&) const {
//    
//    try {
//        if (!setup) throw 
//                IsoException    (   IST_LOC
//                                ,   className()
//                                ,   BadCoefficient);
//
//        if (_ce <= 0.0)  throw 
//                IsoException (IST_LOC, className(), BadCeLTZero); 
//
//    } catch (const IsoException& _isoExcept) {
//
//        std::cout << _isoExcept << "\n";
//
//#ifdef __FRITZ_SCHLUNDER_IV_DEBUG_H__   
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif              
//        abort();
//    }
// 
//auto    ptrValue = std::begin(coeffValue);
//auto    auxi = (*ptrValue) * (pow(_ce, (*(ptrValue + 2))));
//auto    auxi1 = 1 + (*(ptrValue + 1)) * (pow(_ce, (*(ptrValue + 3))));
//
//
//#ifdef __FRITZ_SCHLUNDER_V_DEBUG_H__   
//std::cout << "Sai: " << __FUNCT__ << "\n";
//#endif  
//
//        return ( auxi / (auxi1) );
//}
//
//IST_NAMESPACE_CLOSE