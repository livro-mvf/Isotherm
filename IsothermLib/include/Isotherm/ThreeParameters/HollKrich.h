//==============================================================================
// Name        : HollKrich.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de HollKrich
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


/*! \class	HollKrich
 *  \brief	Classe com as equações da isoterma de Holl - Krich
 *  \file	HollKrich.h
 *  \authors	Lara Botelho Brum
 *  \authors	Joao Flavio Vieira de Vasconcellos
 *  \version	1.0
 *  \date	2021
 *  \bug	Não há bugs conhecidos
 */

//#ifndef __HOLL_KRICH_H__
#define __HOLL_KRICH_H__

//==============================================================================
// opção de debug
//==============================================================================

//#define __HOLL_KRICH_DEBUG_H__

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
/// Classe com as equações da isoterma de Holl-Krich
/// </summary>
///  Isoterma com três parâmetros, \f$ q_{max} \f$, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas fórmulas são as seguintes:
///\begin{align}
///  \[Q_e(C_e, T) = q_{max}\frac{{K_1}(C^{K_2})}{1+K_1(C^{K_2})}]
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors	 Lara Botelho Brum
///  \authors    João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///
///  \copyright GNU Public License.

class HollKrich :  public virtual ThreeParameters,
                   public IsothermTemplate < HollKrich > {

//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
/// <example>

    DefineIdentity("HollKrich", ID::HollKrich);


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
///     HollKrich  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    HollKrich() = default;

/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HollKrich  var;
///     HollKrich  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo Holl-Krich original.
    HollKrich (const HollKrich& _hollkrich) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~HollKrich() = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de HollKrich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     double QMAX(1.0);                                                           *EDITAR, CASO HAJA NECESSIDADE*
///     double K1(1.0);                                                             *EDITAR, CASO HAJA NECESSIDADE*
///     double K2(1.0);                                                             *EDITAR, CASO HAJA NECESSIDADE*
///     HollKrich  var1(Q1, K1, K2);
/// @endcode
/// </example>
///  @param _qmax Capacidade maxima de adsorção.                                    *EDITAR, CASO HAJA NECESSIDADE*
///  @param  _k1 Constante da isortema de HollKrich.                                *EDITAR, CASO HAJA NECESSIDADE*
///  @param _k2 Constante do expoente da isoterma de HollKrich.                     *EDITAR, CASO HAJA NECESSIDADE*
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    HollKrich (const Real&, const Real&, const Real&);

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
///     HollKrich  var1(QMAX, K1, K2);                                              *EDITAR, CASO HAJA NECESSIDADE*
///     HillKrich  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo Holl-Krich original.
///  @return Cópia de _orig.
    HollKrich& operator = (const HollKrich&) = default;

//==============================================================================
// Acesso as constantes da classe                                                   *EDITAR SEÇÃO CASO HAJA NECESSIDADE*
//==============================================================================

/// <summary>
/// Função que informa o valor da capacidade maxima de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HollKrich  var1(QMAX, K1, K2);
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor da  capacidade maxima de adsorção.
inline Real Qmax () const {return  Value(0);};


/// <summary>
/// Função que retorna o coeficiente associado a constante de HollKrich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HollKrich  var1(QMAX, K1, K2);
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente associado a constante de HollKrich.
inline Real K1 () const {return  Value(1);};

/// <summary>
/// Função que retorna o valor do expoente da isoterma de HollKrich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HollKrich  var1(QMAX, K1, K2);
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do expoente da isoterma de HollKrich.
inline Real K2 () const {return  Value(2);};

//==============================================================================
// Alterando as constantes da classe                                                *EDITAR SEÇÃO CASO HAJA NECESSIDADE*
//==============================================================================

/// <summary>
/// Função para alterar  a capacidade maxima de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HollKrich  var1(QMAX, K1, K2);
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorção.
///  @exception _qmax <= 0.
    void Qmax (const Real& _qmax)   {*this = HollKrich(_qmax, Value(1), Value(2));};

/// <summary>
/// Função que altera o coeficiente associado a constante de HollKrich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HollKrich  var1(QMAX, K1, K2);
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante de HollKrich.
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)  {*this = HollKrich(Value(0), _k1,  Value(2));};

/// <summary>
/// Função para alterar o valor do expoente da isoterma de HollKrich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HollKrich  var1(QMAX, K1, K2);
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor do expoente da isoterma de HollKrich.
///  @exception _k2 <= 0.
    void K2 (const Real& _k2)  {*this = HollKrich(Value(0), Value(1),  _k2);};


//==============================================================================
// Funções virtuais
//==============================================================================

/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HollKrich  var1(QMAX, K1, K2);
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
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<HollKrich>(*this);
    }

};

IST_NAMESPACE_CLOSE

