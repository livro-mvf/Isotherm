//==============================================================================
// Name        : DubininRadushkevich.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Dubinin-Radushkevich
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

/** @defgroup DubininRadushkevich Dubinin-Radushkevich
 *  @ingroup Two_Parameters
 *  Classe DubininRadushkevich contém as equações da isoterma de Dubinin Radushkevich.
 *  @{
 */

/// <summary>
/// Classe com as equações da isoterma de Dubinin-Radushkevich
/// </summary>
///  Isoterma com dois parâmetros, \f$ q_{max} \f$ e \f$ K_1 \f$,  cujas fórmulas são as seguintes:
///\begin{align}
///     Q_e (C_e, T) &= q_{max} \exp( -K_1 \epsilon^2 ) \hfil  \\\ \\\
///     \epsilon &= R T \ln \left(1 + \frac{1}{C_e} \right)
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1021/cr60204a006).
///  \authors   Iasmim Barboza Storck
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///
///  \copyright GNU Public License.

#ifndef __DUBININ_RADUSHKEVICH_H__
#define	__DUBININ_RADUSHKEVICH_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

IST_NAMESPACE_OPEN


class DubininRadushkevich : public virtual TwoParameters,
                            public IsothermTemplate < DubininRadushkevich > {


//==============================================================================
// ID da classe
//==============================================================================

public:


/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
    DefineIdentity  (   "DubininRadushkevich"
                    ,   ID::DubininRadushkevich
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
///     DubininRadushkevich  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    DubininRadushkevich() = default;

/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var;
///     DubininRadushkevich  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo DubininRadushkevich original.
    DubininRadushkevich ( const DubininRadushkevich& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~DubininRadushkevich()  = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de DubininRadushkevich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real q1(1.0);
///     Real k1(1.0);
///     Real RGAS(62.363598221529);
///     DubininRadushkevich  var1(q1, k1);              // Constante dos gases default
///     DubininRadushkevich  var2(q1, k1, RGAS);        // Constante dos gases modificada
/// @endcode
/// </example>
///  @param _qmax Constante de equilíbrio de Dubinin-Radushkevich.
///  @param  _k1 Coeficiente associado a energia de adsorção.
///  @param _rgas Valor da constante universal dos gases diferente do padrão.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _rgas <= 0.
    DubininRadushkevich (   const Real&     _qmax
                        ,   const Real&     _k1
                        ,   const Real&     _rgas = Isotherm::RGASCONST
                        );

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
///     DubininRadushkevich  var1(q1, k1);
///     DubininRadushkevich  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo DubininRadushkevich original.
///  @return Cópia de _orig.
    DubininRadushkevich& operator = (const DubininRadushkevich& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Função que informa o valor da constante de equilíbrio de Dubinin-Radushkevich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor da  constante de equilíbrio de Dubinin-Radushkevich.
[[nodiscard]] inline Real Qmax () const
{
    return  Value(0);
};

/// <summary>
/// Função que retorna o coeficiente associado a energia de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real vk1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente associado a energia de adsorção.
[[nodiscard]] inline Real K1 () const
{
    return  Value(1);
};


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
[[maybe_unused]] [[nodiscard]] inline Real Rgas () const
{
    return  RGAS;
};


//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função para alterar  a constante de equilíbrio de Dubinin-Radushkevich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real vq1(3.0);
///     var1.Qmax(vq1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da constante de equilíbrio de Dubinin-Radushkevich.
///  @exception _qmax <= 0.
inline void Qmax (const Real& _qmax)
{
    *this = DubininRadushkevich     (   _qmax
                                    ,   Value(1)
                                    );
};


/// <summary>
/// Função que altera o coeficiente associado a energia de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real vk1(2.0);
///     var1.K1(vk1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a energia de adsorção.
///  @exception _k1 <= 0.
inline  void K1 (const Real& _k1)
{
    *this = DubininRadushkevich (   Value(0)
                                ,   _k1
                                );
};

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
[[maybe_unused]] inline  void Rgas (const Real& _rgas)
{
    *this = DubininRadushkevich     (   Value(0)
                                    ,   Value(1)
                                    ,   _rgas
                                    );

};

//==============================================================================
// Funcoes virtuais
//==============================================================================
//
/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real ce(1);
///     Real tempK(300);
///     Real qe = var1.Qe(ce, tempK);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @param _temp Temperatura em K.
///  @return Valor da quantidade de sorção no equilíbrio.
///  @exception _c <= 0.
///  @exception _temp <= 0.
    virtual Real Qe         (   const Real& _c
                            ,   const Real& _temp
                            ) const;

/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real ce(1);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @return Valor da quantidade de sorção no equilíbrio.
///  @exception _c <= 0.
    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }



    [[nodiscard]] 
    virtual DubininRadushkevich* CloneImplementation() const override
    {
        return new DubininRadushkevich(*this);
    }


private:

Real                    RGAS = Isotherm::RGASCONST;      /// Valor default da constante universal dos gases.

};


/// \example TesteDubininRadushkevich.cpp


IST_NAMESPACE_CLOSE

#endif
