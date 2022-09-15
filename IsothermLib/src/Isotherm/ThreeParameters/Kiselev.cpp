//=====================================================================================
// Name        : Kiselev.cpp
// Author      : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Kiselev
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
//==============================================================================//==============================================================================
// includes lib c++
//==============================================================================

#include <iostream>                     // std::cout, std::flush



//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/ThreeParameters/Kiselev.h>
#include <Misc/NewtonRaphson.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       detailsKiselev
    {
            PairString  ( "Qmax"
                        , "Capacidade máxima de adsorção")
        ,   PairString  ( "K1"
                        , "Constante de equilíbrio de Kiselev")
        ,   PairString  ( "K2"
                        , "Constante de iteração entre as moléculas adsorvidas")
    };

template<>
VecPairString IsothermTemplate < Kiselev >::infoIsotherm = detailsKiselev;


//==============================================================================
// Construtora com três parâmetros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Kiselev :: Kiselev (const Real&, const Real&, const Real&)"
Kiselev :: Kiselev (     const Real& _qmax,
                         const Real& _k1,
                         const Real& _k2) :
                         ThreeParameters(_qmax, _k1, _k2 ) {

#ifdef __KISELEV_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

    try {

        if (_qmax <= 0.0) {
            throw
                    IsoException(IST_LOC, className(), BadQmaxLEZero);
        }

            if (_k1 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK1LEZero);

            if (_k2 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK2LEZero);

    } catch (const IsoException& _isoExcept) {

    std::cout << _isoExcept << "\n" << std::flush;

#ifdef __KISELEV_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();

    };

    setup = true;


#ifdef __KISELEV_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

    }

//==============================================================================
// Concentração de Equilíbrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "Real Kiselev ::  Qe (const Real&, const Real&) const"
Real Kiselev ::  Qe (const Real& _ce, const Real&) const {

#ifdef __KISELEV_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif


    try {
        if (!setup) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient);

        if (_ce <= 0.0)  throw
                IsoException (IST_LOC, className(), BadCeLTZero);



    } catch (const IsoException& _isoExcept) {

    std::cout   << _isoExcept
                << "\n"
                << std::flush;
        std::cout << _isoExcept << "\n";

#ifdef __KISELEV_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();
    }

    const_cast<Real&>(auxiCe) = _ce * this->K1();

auto fp    = std::bind(&Kiselev::FQe, *this, _1);
auto result = NewtonRaphson (fp, 0.5);
auto value = result * this->Qmax();

return (value >= ZERO ? value : 0.0) ;

}


#undef  __FUNCT__
#define __FUNCT__ "Real  Kiselev ::  FQe (const Real&) const"
Real
Kiselev ::  FQe (const Real& _theta) const {

#ifdef __KISELEV_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif


        try {

            if (_theta >= 1.0) throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadThetaGEOne);

            if (_theta<= 0.0) throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,    BadThetaLEZero);

        } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";

#ifdef __KISELEV_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
            abort();
        }


Real       auxiK2     = 1 + (_theta * this->K2());
Real       auxiTheta  = 1 - _theta;
Real       auxi1      = _theta / (auxiK2 * auxiTheta);

    return auxiCe - auxi1;

}

IST_NAMESPACE_CLOSE
