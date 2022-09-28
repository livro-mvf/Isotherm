//==============================================================================
// Name        : FourParameters.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base para as isotermas com quatro parâmetros
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
// includes da lib Isotherm++
//==============================================================================

#include <Isotherm/FourParameters/FourParameters.h>

IST_NAMESPACE_OPEN
        
//==============================================================================
// Variaveis estáticas
//==============================================================================

template<>
VecPairString IsothermTemplate < FourParameters >::infoIsotherm  = VecPairString();


#undef  __FUNCT__
#define __FUNCT__ "FourParameters :: FourParameters (const Real&, const Real&, const Real&, const Real&)"
FourParameters :: FourParameters    (   const Real&     _par_0      // Primeiro parâmetro
                                    ,   const Real&     _par_1      // Segundo parâmetro
                                    ,   const Real&     _par_2      // Terceiro parâmetro
                                    ,   const Real&     _par_3      // Terceiro parâmetro
                                    )
{
    coeffValue    = VecReal(( _par_0, _par_1, _par_2, _par_3));
}

IST_NAMESPACE_CLOSE