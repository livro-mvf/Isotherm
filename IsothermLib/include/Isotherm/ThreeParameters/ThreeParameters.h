//==============================================================================
// Name        : ThreeParameters.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base para as isotermas com tres parametros
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


/** @defgroup ThreeParameters
 *  @ingroup Base
 *  Classe base das isotermas com tres parametro.
 *  @{
 */

///  <summary>
///  Classe base para todas as classes com tres parametros.
/// </summary>
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///
///


#ifndef __THREEPARAMETERS_H__
#define __THREEPARAMETERS_H__


#include <Isotherm.h>

IST_NAMESPACE_OPEN

class ThreeParameters : public virtual Isotherm
{

//==============================================================================
// ID da classe
//==============================================================================

public:

    DefineIdentity  (   "ThreeParameters"
                    ,   ID::ThreeParameters
                    );

//==============================================================================
// Construtores / Destrutora
//==============================================================================

protected:

    ThreeParameters() : ThreeParameters (0.0, 0.0, 0.0) {};
    ThreeParameters (const ThreeParameters&) = default;
    virtual ~ThreeParameters() = default;

    ThreeParameters     (   const Real&
                        ,   const Real&
                        ,   const Real&
                        );


//==============================================================================
// Sobrecarga de operadores
//==============================================================================

protected:

    ThreeParameters& operator = ( const ThreeParameters& ) = default;


};

IST_NAMESPACE_CLOSE

#endif /* __THREEPARAMETERS_H__ */

/** @} */