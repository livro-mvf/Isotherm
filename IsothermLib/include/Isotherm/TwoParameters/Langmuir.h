//==============================================================================
// Name        : Langmuir.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Langmuir
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


/** @defgroup Langmuir Langmuir
 *  @ingroup Two_Parameters
 *  Classe Langmuir é uma classe de dois parâmetros.
 */

/// <summary>
/// Classe com a equação da isoterma de Langmuir
/// </summary>
///  Isoterma com dois parâmetros, \f$ q_{max} \f$ e \f$ K_1 \f$,  cujas fórmulas são as seguintes:
///\begin{align}
///     \[Q_e(C_e, T) = q_{max}\frac{K_1C_e}{1+K_1C_e}\]
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors   Iasmim Barboza Storck
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///
///  \copyright GNU Public License.


#ifndef __LANGMUIR_H__
#define	__LANGMUIR_H__

//==============================================================================
// opção de debug
//==============================================================================

//#define __LANGMUIR_DEBUG_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

IST_NAMESPACE_OPEN


class Langmuir :    public virtual TwoParameters,
                    public IsothermTemplate < Langmuir >
{

//==============================================================================
// ID da classe
//==============================================================================

public:


/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
/// <example>
    DefineIdentity  (   "Langmuir"
                    ,   ID::Langmuir
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
///     Langmuir  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    Langmuir() = default;

/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var;
///     Langmuir  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo Langmuir original.
    Langmuir(const Langmuir& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Langmuir() = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de Langmuir.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real q1(1.0);
///     Real k1(1.0);

/// @endcode
/// </example>
///  @param _qmax Capacidade máxima de adsorção em [M /M ].
///  @param  _k1 Constante de equilíbrio de Langmuir.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
    Langmuir (const Real& _qmax, const Real& _k1);

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
///     Langmuir  var1(q1, k1);
///     Langmuir  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo Langmuir original.
///  @return Cópia de _orig.
    Langmuir& operator = (const Langmuir& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Função que informa o valor da capacidade máxima de adsorção em [M /M ].   .
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor da capacidade máxima de adsorção em [M /M ].
    inline Real Qmax () const {return  Value(0);};

/// <summary>
/// Função que retorna o coeficiente associado a constante de equilíbrio de Langmuir.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real k2 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente associado a constante de equilíbrio de Langmuir.
    inline Real K1 () const {return  Value(1);};


//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função para alterar a capacidade máxima de adsorção em [M /M ].   .
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real q2(3.0);
///     var1.Qmax(q2);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade máxima de adsorção em [M /M ].   .
///  @exception _qmax <= 0.
    void Qmax (const Real& _qmax)  {*this = Langmuir(_qmax, Value(1));};


/// <summary>
/// Função que altera o coeficiente associado a constante de equilíbrio de Langmuir.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real k2(2.0);
///     var1.K1(k2);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante de equilíbrio de Langmuir.
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)  {*this = Langmuir(Value(0), _k1);};


//==============================================================================
// Funções virtuais
//==============================================================================

/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real ce(1);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @return Valor da quantidade de sorção no equilíbrio.
///  @exception _c < 0.
    virtual Real Qe (const Real& _c, const Real&) const;
    
    [[nodiscard]] 
    inline Real Qe   (const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }
    
    [[nodiscard]] 
    virtual Langmuir* CloneImplementation() const override
    {
        return new Langmuir(*this);
    }   

};


/// \example TesteLangmuir.cpp
///Este é um arquivo com exemplos de aplicação da classe Langmuir.


IST_NAMESPACE_CLOSE

#endif	/* LANGMUIR_H */

/** @} */

