//==============================================================================
// Name        : BrouersSotolongo.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Brouers - Sotolongo.
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

#ifndef __BROUERS_SOTOLONGO_H__
#define __BROUERS_SOTOLONGO_H__

//==============================================================================
// include da biblioteca c++
//==============================================================================

#include <cmath>

//==============================================================================
// include da isotherm
//==============================================================================

#include <Isotherm/ThreeParameters/ThreeParameters.h>

IST_NAMESPACE_OPEN

/// <summary>
/// Classe com as equacoes da isoterma de Brouers - Sotolongo.
/// </summary>
///  Isoterma com tres parametros, \f$ q_{max} \f$, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas formulas sao as seguintes:
///\begin{align}
/// Q_e(C_e) = q_{max}[1-e^{-K_1C_e^{K_2}}]
///\end{align}
///  Um artigo de referencia pode ser encontrado [aqui](https://doi.org/10.1177/0263617416670909).
///  \authors    Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///
///  \copyright GNU Public License.

class BrouersSotolongo :    public virtual ThreeParameters,
                            public IsothermTemplate < BrouersSotolongo > {

//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
/// <example>

    DefineIdentity("Brouers - Sotolongo", ID::BrouersSotolongo);


//==============================================================================
// Funcoes Construtoras/Destrutora
//==============================================================================

public:

 /// <summary>
/// Construtora default.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    BrouersSotolongo() = default;

/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var;
///     BrouersSotolongo  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo Brouers - Sotolongo original.
    BrouersSotolongo (const BrouersSotolongo& _brouers_sotolongo) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~BrouersSotolongo() = default;

/// <summary>
/// Construtora com os parametros que definem a isoterma de Brouers - Sotolongo.
/// </summary>
/// <example>
/// Uso:
/// @code
///     double QMAX(1.0);
///     double K1(1.0);
///     double K2(1.0);
///     Sips  var1(Q1, K1, K2);
/// @endcode
/// </example>
///  @param _qmax Capacidade maxima de adsorcao.
///  @param  _k1 Constante da isortema de Brouers - Sotolongo.
///  @param _k2 Constante da isoterma de Brouers - Sotolongo.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    BrouersSotolongo    (   const Real&
                        ,   const Real&
                        ,   const Real&
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
///     BrouersSotolongo  var1(QMAX, K1, K2);
///     BrouersSotolongo  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo Brouers - Sotolongo original.
///  @return Copia de _orig.
    BrouersSotolongo& operator = (const BrouersSotolongo&) = default;

//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Funcao que informa o valor da capacidade maxima de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var1(QMAX, K1, K2);
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da  capacidade maxima de adsorcao.
    
[[nodiscard]]    
inline Real Qmax () const {return  Value(0);};


/// <summary>
/// Funcao que retorna o coeficiente associado a constante de Brouers - Sotolongo.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var1(QMAX, K1, K2);
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente associado a constante de Brouers - Sotolongo.

[[nodiscard]]
inline Real K1 () const {return  Value(1);};

/// <summary>
/// Funcao que retorna o parametro da equacao de Brouers - Sotolongo.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var1(QMAX, K1, K2);
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do parametro da equacao de Brouers - Sotolongo.

[[nodiscard]]
inline Real K2 () const {return  Value(2);};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar  a capacidade maxima de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var1(QMAX, K1, K2);
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorcao.
///  @exception _qmax <= 0.

void Qmax (const Real& _qmax)   {   *this = BrouersSotolongo    (  _qmax
                                                                ,   Value(1)
                                                                ,   Value(2)
                                                                );
                                };

/// <summary>
/// Funcao que altera o coeficiente associado a constante da isoterma de Brouers - Sotolongo.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var1(QMAX, K1, K2);
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante da isoterma de Brouers - Sotolongo.
///  @exception _k1 <= 0.
    
void K1 (const Real& _k1)   {   *this = BrouersSotolongo    (   Value(0)
                                                            ,   _k1
                                                            ,   Value(2)
                                                            );
                            };

/// <summary>
/// Funcao para alterar o valor associado a constante da isoterma de Brouers - Sotolongo.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var1(QMAX, K1, K2);
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor associado a constante da isoterma de Brouers - Sotolongo.
///  @exception _k2 <= 0.
    
void K2 (const Real& _k2)   {   *this = BrouersSotolongo    (   Value(0)
                                                            ,   Value(1)
                                                            ,   _k2
                                                            );
                            };

 
//==============================================================================
// Funcoes virtuais
//==============================================================================

/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilibrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     BrouersSotolongo  var1(QMAX, K1, K2);
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equilibrio.
///  @exception _c < 0.
[[nodiscard]]  
Real Qe (const Real&, const Real&) const;

[[nodiscard]] 
inline Real Qe   (   const Real& _c
) const override
{
    return Qe(_c, 0);
}

[[nodiscard]]
virtual std::unique_ptr<Isotherm> CloneImplementation() const override
{
    return std::make_unique<BrouersSotolongo>(*this);
}



};

IST_NAMESPACE_CLOSE

#endif /* __BROUERS_SOTOLONGO_H__ */