//==============================================================================
// Name        : MarczewskiJaroniec.cpp
// Author      : Joao Flavio Vasconcellos 
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de MarczewskiJaroniec.
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

#include <cmath>
#include <iostream>
//#include <iomanip>

//==============================================================================
// includes da lib Isotherm++
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/FourParameters/MarczewskiJaroniec.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estaticas
//==============================================================================

VecPairString       detailsMarczewskiJaroniec    {   
                                        PairString  ( "Qmax"
                                                    , "Capacidade maxima de adsorcao."
                                                    )
                                    ,   PairString  ( "K1"
                                                    , "Coeficiente da isoterma de MarczewskiJaroniec."
                                                    )
                                    ,   PairString  ( "K2"
                                                    , "Coeficiente da isoterma de MarczewskiJaroniec."
                                                    )        
                                    ,   PairString  ( "K3"
                                                    , "Coeficiente da isoterma de MarczewskiJaroniec."
                                                    )
                                                };

template<>
VecPairString IsothermTemplate < MarczewskiJaroniec >::infoIsotherm = detailsMarczewskiJaroniec;


//==============================================================================
// Construtora com quatro para¢metros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "MarczewskiJaroniec :: MarczewskiJaroniec (const Real&, const Real&, const Real&, const Real&)"
MarczewskiJaroniec :: MarczewskiJaroniec    (   const Real&     _qmax 
                                            ,   const Real&     _k1
                                            ,   const Real&     _k2
                                            ,   const Real&     _k3
                                            ) 
                                            : FourParameters(_qmax, _k1, _k2, _k3) {



    try {
        
            if (_qmax <= 0.0)  throw  
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadQmaxLEZero
                                    );             
            
            if (_k1 <= 0.0)  throw  
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero
                                    );             

            if (_k2 <= 0.0)  throw  
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK2LEZero
                                    );   

            if (_k3 <= 0.0)  throw  
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK3LEZero
                                    );  
            
            if (_k3 >= 1.0)  throw  
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK3GEOne
                                    );  
            
    } catch (const IsoException& _isoExcept) {
            
        std::cout   << _isoExcept 
                    << "\n";                      
        exit(EXIT_FAILURE);
        
    };
    
    setup = true;

}
    
//==============================================================================
// Concentracao de equilibrio Qe
//==============================================================================
   

#undef  __FUNCT__
#define __FUNCT__ "MarczewskiJaroniec ::  Qe (const Real&, const Real&) const "
Real 
MarczewskiJaroniec ::  Qe    (   const Real& _ce
                ,   const Real&
                ) const {
    
    try {
        if (!setup) throw 
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient);

        if (_ce <= 0.0)  throw 
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCeLTZero
                                ); 

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
             
        exit(EXIT_FAILURE);
        
    }
 
auto    ptrValue = std::begin(coeffValue);
auto    auxi  = pow(*(ptrValue + 1) * _ce, *(ptrValue + 2));
auto    auxi1 = auxi / (1 + auxi);
auto    value = (*ptrValue) * pow(auxi1, *(ptrValue + 3) / *(ptrValue + 2) );

    return  (value >= ZERO ? value : 0.0);
 
}

IST_NAMESPACE_CLOSE