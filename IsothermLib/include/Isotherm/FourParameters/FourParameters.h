//==============================================================================
// Name        : FourParameters.h
// Author      : Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base para as isotermas com quatro parâmetros
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

/** @defgroup FourParameters  
 *  @ingroup Base
 *  Classe base das isotermas com quatro parâmetro.
 *  @{
 */

///  <summary>
///  Classe base para todas as isotermas com quatro parâmetros.
/// </summary>
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///  
///  \copyright GNU Public License.
        

#ifndef __FOURPARAMETERS_H__
#define __FOURPARAMETERS_H__


//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm.h>

IST_NAMESPACE_OPEN

class FourParameters : public virtual Isotherm {

//==============================================================================
// ID da classe
//==============================================================================

public:

    DefineIdentity  (   "FourParameters"
                    ,   ID::FourParameters
                    );


//==============================================================================
// Construtores / Destrutora
//==============================================================================

protected:

    FourParameters() : FourParameters (0, 0, 0, 0) {};
    FourParameters(const FourParameters&) = default;
    virtual ~FourParameters() = default;


    FourParameters  (   const Real&
                    ,   const Real&
                    ,   const Real&
                    ,   const Real&
                    );


//==============================================================================
// Sobrecarga de operadores
//==============================================================================

protected:

    FourParameters& operator = ( const FourParameters& ) = default;

};

IST_NAMESPACE_CLOSE

#endif /* __FOURPARAMETERS_H__ */

/** @} */ 
        
        