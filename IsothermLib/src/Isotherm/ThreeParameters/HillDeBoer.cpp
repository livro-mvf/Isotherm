//==============================================================================
// Name        : HillDeboer.cpp
// Author      : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Hill - Deboer
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
#include <Isotherm/ThreeParameters/HillDeboer.h>
#include <Misc/NewtonRaphson.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       detailsHillDeboer
    {
        PairString  ( "Qmax"
                    , "Capacidade máxima de adsorcao")
    ,   PairString  ( "K1"
                    , "Constante de equilíbrio de Hill – Deboer")
    ,   PairString  ( "K2"
                    , "Constante de iteracao entre as moléculas adsorvidas")
    };

template<>
VecPairString IsothermTemplate < HillDeboer >::infoIsotherm = detailsHillDeboer;


//==============================================================================
// Construtora com dois parâmetros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "HillDeboer :: HillDeboer (const Real&, const Real&, const Real&)"
HillDeboer :: HillDeboer (  const Real& _qmax,
                            const Real& _k1,
                            const Real& _k2,
                            const Real& _rgas) :
                            ThreeParameters(_qmax, _k1, _k2 ),
                                             RGAS(_rgas) {

#ifdef __HILLDEBOER_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

    try {
            if (_qmax <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadQmaxLEZero);

            if (_k1 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK1LEZero);

            if (_k2 < 0.0)  throw
                    IsoException (IST_LOC, className(), BadK2LTZero);

            if (_rgas <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadRGasLEZero);


    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";

#ifdef __HILLDEBOER_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();

    }

    setup = true;


#ifdef __HILLDEBOER_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif

    }

//==============================================================================
// Concentracao de Equilíbrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "HillDeboer ::  Qe (const Real&, const Real&) const"
Real
HillDeboer ::  Qe (const Real& _ce, const Real& _temp) const {
#ifdef __HILLDEBOER_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif


    try {

        if (!setup) throw
            IsoException (IST_LOC, className(), BadCoefficient);

        if (_ce < 0.0)  throw
                IsoException (IST_LOC, className(), BadCeLTZero);

        if (_temp <= 0.0)  throw
                IsoException (IST_LOC, className(), BadTempLEZero);


    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";

#ifdef __HILLDEBOER_DEBUG_H__
std::cout << "Sai: " << __FUNCT__ << "\n";
#endif
        abort();
    }

    const_cast<Real&>(auxiCe) = _ce * this->K1();
    const_cast<Real&>(tempK)  = _temp;

auto fp    = std::bind(&HillDeboer::FQe, *this, _1);
auto resul = NewtonRaphson (fp, 0.5);
auto value = resul * Qmax();

    return (value >= ZERO ? value : 0.0);

}


#undef  __FUNCT__
#define __FUNCT__ "Real  HillDeboer ::  FQe (const Real&) const"
Real  HillDeboer ::  FQe (const Real& _theta) const {

#ifdef __HILLDEBOER_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

#ifdef __HILLDEBOER_DEBUG_H__
std::cout << "Entrei: " << __FUNCT__ << "\n";
#endif

Real       auxiK2 = _theta * this->K2() / (RGAS * tempK);
Real       auxi1  = _theta / (1 - _theta);
Real       auxi2  = auxi1 * exp(auxi1 - auxiK2);

    return auxiCe - auxi2;

}

IST_NAMESPACE_CLOSE