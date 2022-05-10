//==============================================================================
// Name        : Henry.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Henry
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

/** @defgroup Henry  Henry
 *  @ingroup One_Parameter
 *  Classe Henry é uma classe de um parâmetro
 *  @{
 */


/// <summary>
/// Classe com as equações da isoterma de Henry.
/// </summary>
///  Isoterma com um parâmetro, \f$ K_1 > 0 \f$, cuja fórmula é a seguinte:
///\begin{align}
///     Q_e(C_e) = K_1 C_e
///\end{align}
///  O artigo em que esta isoterma foi definida pode ser encontrado [aqui](https://doi.org/10.1098/rstl.1803.0004).
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///
///  \copyright GNU Public License.

#ifndef __HENRY_H__
#define	__HENRY_H__


//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/OneParameter/OneParameter.h>


IST_NAMESPACE_OPEN



class Henry :   public virtual OneParameter,
                public IsothermTemplate < Henry >
{

//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
    DefineIdentity  (   "Henry"
                    ,   ID::Henry
                    );


//==============================================================================
// Funções Construtoras/Destrutora
//==============================================================================

public:

/// <summary>
/// Construtora default.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    Henry() = default;

/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var;
///     Henry  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo Henry original.
    Henry(const Henry& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Henry() = default;

/// <summary>
/// Construtora com o parâmetros que define a isoterma de Henry.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real k1(1.0);
///     Henry  var1(k1);
/// @endcode
/// </example>
///  @param _k1 Coeficiente de distribuição.
///  @exception _k1 <= 0.
    Henry (const Real& _k1);

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

public:

/// <summary>
/// Sobrecarga do operador =.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var1(k1);
/// @endcode
/// </example>
///  @param _orig Variável do tipo Henry original.
///  @return Cópia de _orig.
    Henry& operator = (const Henry& _orig) = default;

//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Função que informa o valor do coeficiente de distribuição.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var1(k1);
///     Real   k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente de distribuição.
inline Real K1 () const
{
    return  Value(0);
};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função para alterar o valor do coeficiente de distribuição.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var1(_k1);
///     Real   k11(3.0);
///     var1.K1(k11);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente de distribuição.
///  @exception _k1 <= 0.
inline void K1 (const Real& _k1)
{
    *this = Henry(_k1);
};

//==============================================================================
// Funcoes virtuais
//==============================================================================

public:

/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var1(k);
///     Real ce(1.0);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @return Valor da quantidade de sorção no equilíbrio.
///  @exception _c < 0.
 virtual Real Qe    (   const Real&  _c
                    ,   const Real&  = 0) const ;

    [[nodiscard]] 
    virtual Henry* CloneImplementation() const override
    {
        return new Henry(*this);
    }


};

/**
 *  @example TesteHenry.cpp
 *  Exemplo de utilização da classe Henry
 */




IST_NAMESPACE_CLOSE


#endif	/* __HENRY_H__ */


/** @} */