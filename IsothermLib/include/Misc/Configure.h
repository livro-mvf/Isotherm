


//==============================================================================
// Name        : Config.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Arquivo onde são definidas algumas variáveis de
//               configuração do programa
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


/** @defgroup Configure  Configurações da Biblioteca
 *  @ingroup Miscelânea
 *  Algumas configurações que serão utilizadas por diversas 
 * classes e funções da biblioteca Isotherm++.
 *  @{
 */


#ifndef __CONFIGURE_ISOTHERM_H__
#define __CONFIGURE_ISOTHERM_H__

//==============================================================================
//  Includes c++
//==============================================================================

#include <iosfwd>
#include <functional>
#include <limits>

//==============================================================================
//  Includes da biblioteca
//==============================================================================

#include <Misc/Type.h>


//==============================================================================
//  Definição do namespace
//==============================================================================

/// <summary>
/// Definoção do início namespace da biblioteca Isotherm++
#define IST_NAMESPACE_OPEN namespace ist {
/// <summary>
/// Definoção do fim namespace da biblioteca Isotherm++
#define IST_NAMESPACE_CLOSE }


IST_NAMESPACE_OPEN

const Real      ZERO(1e250 * std::numeric_limits<Real>::min()); /*!< Valor para zero nos processos iterativos */
const UInt      LSIZE(0x50);                                    /*!< Tamanho default da linha que será utilizada pela função PrintLine */                                   //! ;

IST_NAMESPACE_CLOSE
#endif /* __CONFIGURE_ISOTHERM_H__ */


/** @} */  