//==============================================================================
// Name        : HillDeboer.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de HillDeboer
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


/*! \class	Hill - Deboer
 *  \brief	Classe com as equações da isoterma de Hill - Deboer
 *  \file	HillDeboer.h
 *  \authors	Lara Botelho Brum
 *  \authors	Joao Flavio Vieira de Vasconcellos
 *  \version	1.0
 *  \date	2021
 *  \bug	Não há bugs conhecidos
 */

#ifndef __HILLDEBOER_H__
#define __HILLDEBOER_H__
//==============================================================================
// opção de debug
//==============================================================================

//#define __HILLDEBOER_DEBUG_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/ThreeParameters/ThreeParameters.h>

IST_NAMESPACE_OPEN

/// <summary>
/// Classe com as equações da isoterma de Hill-Deboer.
/// </summary>
///  Isoterma com três parâmetros, \f$ q_{max} \f$, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas fórmulas são as seguintes:
///\begin{align}
///  \[f(\theta ) = K_1C-\frac{\theta}{1-\theta}e^{\frac{\theta}{1-\theta}-\frac{K_2\theta}{RT}}=0\]
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors    Lara Botelho Brum
///  \authors    João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///
///  \copyright GNU Public License.

class HillDeboer :  public virtual ThreeParameters,
                    public IsothermTemplate < HillDeboer > {

//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
/// <example>

    DefineIdentity("HillDeBoer", ID::HillDeBoer);

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
///     HillDeboer  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    HillDeboer() = default;

/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HillDeboer  var;
///     HillDeboer  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo HillDeboer original.
    HillDeboer (const HillDeboer& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~HillDeboer() = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de HillDeboer.
/// </summary>
/// <example>
/// Uso:
/// @code
///     double QMAX(1.0);
///     double K1(1.0);
///     double K2(1.0);
///     HillDeboer  var1(Q1, K1, K2);
/// @endcode
/// </example>
///  @param _qmax Capacidade maxima de adsorção.
///  @param  _k1 Constante de equilíbrio de Hill – Deboer.
///  @param _k2 Constante de iteração entre as moléculas adsorvidas.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    HillDeboer (    const Real& _qmax,
                    const Real& _k1,
                    const Real& _k2,
                    const Real& _rgas = Isotherm::RGASCONST) ;

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
///     HillDeboer  var1(QMAX, K1, K2);
///     HillDeboer  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo HillDeBoer original.
///  @return Cópia de _orig.
    HillDeboer& operator = (const HillDeboer& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Função que informa o valor da capacidade maxima de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HillDeBoer  var1(QMAX, K1, K2);
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor da  capacidade maxima de adsorção.
    inline Real Qmax () const {return  Value(0);};


/// <summary>
/// Função que retorna o coeficiente associado a constante de equilíbrio de Hill - Deboer.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HillDeboer  var1(QMAX, K1, K2);
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente associado a constante de equilíbrio de Hill – Deboer.
    inline Real K1 () const {return  Value(1);};
    inline Real RGas() const {return RGAS;};

/// <summary>
/// Função que retorna o valor associado a constante de iteração entre as moléculas adsorvidas.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HillDeboer  var1(QMAX, K1, K2);
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor associado a constante de iteração entre as moléculas adsorvidas.
    inline Real K2 () const {return  Value(2);};


/// <summary>
/// Função que retorna o valor da constante universal dos gases.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real rg = var1.Rgas();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor da constante universal dos gases.
    inline Real Rgas () const {return  RGAS;};


//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função para alterar  a capacidade maxima de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HillDeboer  var1(QMAX, K1, K2);
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorção.
///  @exception _qmax <= 0.
    void Qmax (const Real& _qmax)  {*this = HillDeboer(_qmax, Value(1), Value(2));};

/// <summary>
/// Função que altera o coeficiente associado a constante de equilíbrio de Hill – Deboer.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HillDeboer  var1(QMAX, K1, K2);
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante de equilíbrio de Hill – Deboer.
///  @exception _k1 <= 0.
     void K1 (const Real& _k1)  {*this = HillDeboer(Value(0), _k1, Value(2));};

/// <summary>
/// Função para alterar o valor associado a constante de iteração entre as moléculas adsorvidas.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HillDeboer  var1(QMAX, K1, K2);
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor associado a constante de iteração entre as moléculas adsorvidas.
///  @exception _k2 <= 0.
    void K2 (const Real& _k2)  {*this = HillDeboer(Value(0), Value(1), _k2);};

/// <summary>
/// Função para alterar o valor da constante universal dos gases.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real rgas(62.363598221529);
///     var1.Rgas(rgas);
/// @endcode
/// </example>
///  @param _rgas Novo valor da constante universal dos gases.
///  @exception _rgas <= 0.
    void Rgas (const Real& _rgas) {*this = HillDeboer(Value(0), Value(1), _rgas);};



//==============================================================================
// Funções virtuais
//==============================================================================

/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HillDeboer  var1(QMAX, K1, K2);
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @return Valor da quantidade de sorção no equilíbrio.
///  @exception _c < 0.
    virtual Real Qe (const Real& _c, const Real& = 0) const;

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<HillDeboer>(*this);
    }
    

//==============================================================================
// Dados da classe
//==============================================================================

    Real  FQe (const Real&) const;

    private:

    Real                auxiCe = 0;
    Real                RGAS   = Isotherm::RGASCONST;         // Constante universal dos gases
    Real                tempK  = 0;

};

IST_NAMESPACE_CLOSE

#endif /* __HILLDEBOER_H__ */

