//==============================================================================
// Name        : FritzSchlunderV.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Frenkel-Halsey-Hill.
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
#include <iomanip>

//==============================================================================
// includes da lib Isotherm++
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/FiveParameters/FrenkelHalseyHill.h>

IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       isothermFrenkelHalseyHill {   PairString  ( "Qmax"
                                                    , "Capacidade máxima de adsorção.")
                                    ,   PairString  ( "K1"
                                                    , "Coeficiente da isoterma de Fritz – Schlunder - V.")
                                    ,   PairString  ( "K2"
                                                    , "Coeficiente da isoterma de Fritz – Schlunder - V.")
                                    ,   PairString  ( "K3"
                                                    , "Expoente da isoterma de Fritz – Schlunder - V.")
                                    ,   PairString  ( "K4"
                                                    , "Expoente da isoterma de Fritz–Schlunder - V.")};

template<>
VecPairString IsothermTemplate <FrenkelHalseyHill >::infoIsotherm = isothermFrenkelHalseyHill;


//==============================================================================
// Construtora com dois parâmetros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "FrenkelHalseyHill:: FrenkelHalseyHill(const Real&, const Real&, const Real&, const Real&, const Real&)"
FrenkelHalseyHill:: FrenkelHalseyHill(  const Real& _qmax,
                const Real& _k1,
                const Real& _k2,
                const Real& _k3,
                const Real& _k4) : FiveParameters(_qmax, _k1, _k2, _k3, _k4) {



    try {

            if (_qmax < 0.0)  throw
                    IsoException (IST_LOC, className(), BadQmaxLEZero);

            if (_k1 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK1LEZero);

            if (_k2 <= 0.0)  throw
                    IsoException (IST_LOC, className(), BadK2LEZero);

            if (_k3  <= 0)  throw
                    IsoException (IST_LOC, className(), BadK3LEZero);

            if (_k4 <=
                    0.0)  throw
                    IsoException (IST_LOC, className(), BadK4LEZero);

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";
        exit(EXIT_FAILURE);

    };

    setup = true;


}

//==============================================================================
// Concentração de Equilíbrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "FrenkelHalseyHill::  Qe (const Real&, const Real&) const "
Real
FrenkelHalseyHill::  Qe (const Real& _ce, const Real&) const {

    try {
        if (!setup) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient);

        if (_ce <= 0.0)  throw
                IsoException (IST_LOC, className(), BadCeLTZero);

    } catch (const IsoException& _isoExcept) {

        std::cout << _isoExcept << "\n";
        exit(EXIT_FAILURE);
    }

auto    ptrValue = std::begin(coeffValue);
auto    auxi = (*ptrValue) * (pow(_ce, (*(ptrValue + 3))));
auto    auxi1 = (*(ptrValue + 2)) * (pow(_ce, (*(ptrValue + 4))));


        return ( auxi / ((*(ptrValue + 1)) + auxi1) );
}

IST_NAMESPACE_CLOSE