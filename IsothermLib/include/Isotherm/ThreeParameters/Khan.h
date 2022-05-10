//==============================================================================
// Name        : Khan.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Khan
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


/*! \class	Khan
 *  \brief	Classe com as equações da isoterma de Khan
 *  \file	Khan.h
 *  \authors    Lara Botelho Brum
 *  \authors	Joao Flavio Vieira de Vasconcellos
 *  \version	1.0
 *  \date	2021
 *  \bug	Não há bugs conhecidos
 */

#ifndef __KHAN_H__
#define __KHAN_H__

//==============================================================================
// opção de debug
//==============================================================================

//#define __KHAN_DEBUG_H__

//==============================================================================
// include da biblioteca c++
//==============================================================================

#include <cmath>

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/ThreeParameters/ThreeParameters.h>

IST_NAMESPACE_OPEN

/// <summary>
/// Classe com as equações da isoterma de Khan
/// </summary>
///  Isoterma com três parâmetros, \f$ q_{max} \f$, \f$ K_1 \f$ e \f$ _K2 \f$,  cujas fórmulas são as seguintes:        *EDITAR, CASO HAJA NECESSIDADE*
///\begin{align}
///   \[q = q_{max}\frac{K_1C}{(1+K_1)\K_2}]
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors    Lara Botelho Brum
///  \authors    João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///
///  \copyright GNU Public License.

class Khan :  public virtual ThreeParameters,
                   public IsothermTemplate < Khan > {

//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
/// <example>

    DefineIdentity("Khan", ID::Khan);


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
///     Khan  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    Khan() = default;

/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Khan  var;
///     Khan  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo Khan original.
    Khan (const Khan& _khan) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Khan() = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de Khan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     double QMAX(1.0);
///     double K1(1.0);
///     double K2(1.0);
///     Khan  var1(Q1, K1, K2);
/// @endcode
/// </example>
///  @param _qmax Capacidade maxima de adsorção.
///  @param _k1 Constante da isortema de Khan.
///  @param _k2 Constante do expoente da isoterma de Khan.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    Khan (const Real&, const Real&, const Real&);

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
///     Khan  var1(QMAX, K1, K2);
///     Khan  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo Khan original.
///  @return Cópia de _orig.
    Khan& operator = (const Khan&) = default;

//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Função que informa o valor da capacidade maxima de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Khan  var1(QMAX, K1, K2);
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor da capacidade maxima de adsorção.
inline Real Qmax () const {return  Value(0);};


/// <summary>
/// Função que retorna o coeficiente associado a constante de Khan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Khan  var1(QMAX, K1, K2);
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente associado a constante de Khan.
inline Real K1 () const {return  Value(1);};

/// <summary>
/// Função que retorna o valor do expoente da isoterma de Khan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Khan  var1(QMAX, K1, K2);
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do expoente da isoterma de Khan.
inline Real K2 () const {return  Value(2);};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função que informa o valor da capacidade maxima de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Hill  var1(QMAX, K1, K2);
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qm Novo valor da capacidade maxima de adsorção.
///  @exception _qmax <= 0.
    void Qmax (const Real& _qmax)  {*this = Khan(_qmax, Value(1), Value(2));};

/// <summary>
/// Função que retorna o coeficiente associado a constante de Khan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Khan  var1(QMAX, K1, K2);
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante de Khan
///  @exception _k1 <= 0.
   void K1 (const Real& _k1)  {*this = Khan(Value(0), _k1,  Value(2));};



/// <summary>
/// Função para alterar o valor do expoente da isoterma de Khan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Khan  var1(QMAX, K1, K2);
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor do expoente da isoterma de Khan.
///  @exception _k2 <= 0.
    void K2 (const Real& _k2)  {*this = Khan(Value(0), Value(1),  _k2);};


//==============================================================================
// Funções virtuais
//==============================================================================

/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Khan  var1(QMAX, K1, K2);
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @return Valor da quantidade de sorção no equilíbrio.
///  @exception _c < 0.
    virtual Real Qe (const Real&, const Real&) const;

    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }



    [[nodiscard]] 
    virtual Khan* CloneImplementation() const override
    {
        return new Khan(*this);
    }
            
};

IST_NAMESPACE_CLOSE

#endif /* __KHAN_H__ */
