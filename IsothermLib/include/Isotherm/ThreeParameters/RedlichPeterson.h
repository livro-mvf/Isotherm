//==============================================================================
// Name        : RedlichPeterson.h
// Authors     : Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe da isoterma de Redlich - Peterson.
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


/*! \class	Redlich - Peterson
 *  \brief	Classe com as equações da isoterma de Redlich - Peterson.
 *  \file	RedlichPeterson.h
 *  \authors	Luan Rodrigues Soares de Souza
 *  \authors	Joao Flavio Vieira de Vasconcellos
 *  \version	1.0
 *  \date	2021
 *  \bug	Não há bugs conhecidos
 */

#ifndef __REDLICH_PETERSON_H__
#define __REDLICH_PETERSON_H__

//==============================================================================
// opção de debug
//==============================================================================

//#define __REDLICH_PETERSON_DEBUG_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/ThreeParameters/ThreeParameters.h>

IST_NAMESPACE_OPEN

/// <summary>
/// Classe com as equações da isoterma de Redlich - Peterson
/// </summary>
///  Isoterma com três parâmetros, \f$ q_{max} \f$, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas fórmulas são as seguintes:
///\begin{align}
///  \[Q_e(C_e, T) = \frac{K_1C}{1+K_2C_e^{K_3}}
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors    Luan Rodrigues Soares de Souza
///  \authors    João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///  
///  \copyright GNU Public License.

class RedlichPeterson :  public virtual ThreeParameters, 
              public IsothermTemplate < RedlichPeterson > {
    
//==============================================================================
// ID da classe
//==============================================================================

public:    
    
/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
/// <example>

    DefineIdentity("RedlichPeterson", ID::RedlichPeterson);  
    
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
///     RedlichPeterson  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    RedlichPeterson() = default;
    
/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     RedlichPeterson  var;
///     RedlichPeterson  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo RedlichPeterson original.        
    RedlichPeterson (const RedlichPeterson& _redlich_peterson) = default;
  
/// <summary>
/// Destrutora.
/// </summary>
    virtual ~RedlichPeterson() = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de Redlich - Peterson.
/// </summary>
/// <example>
/// Uso:
/// @code
///     double K1(1.0);
///     double K2(1.0);    
///     double K3(1.0);        
///     RedlichPeterson  var1(K1, K2, K3);
/// @endcode
/// </example>
///  @param _k1 Constante de Redlich-Peterson.    
///  @param  _k2 Constante de Redlich-Peterson.    
///  @param _k3 Coeficiente que reflete a heterogeneidade do adsorvente.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
///  @exception _k3 <= 0.
    RedlichPeterson (const Real&, const Real&, const Real&);
        
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
///     RedlichPeterson  var1(K1, K2, K3);              
///     RedlichPeterson  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo RedlichPeterson original.
///  @return Cópia de _orig.    
    RedlichPeterson& operator = (const RedlichPeterson&) = default;

//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Função que informa o valor da constante de Redlich-Peterson.
/// </summary>
/// <example>
/// Uso:
/// @code
///     RedlichPeterson  var1(K1, K2, K3);              
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor da constante de Redlich-Peterson.
inline Real K1 () const {return  Value(0);};


/// <summary>
/// Função que retorna o coeficiente associado a constante de Redlich - Peterson.
/// </summary>
/// <example>
/// Uso:
/// @code
///     RedlichPeterson  var1(K1, K2, K3);              
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente associado a constante de Redlich - Peterson.  
inline Real K2 () const {return  Value(1);};
    
/// <summary>
/// Função que retorna o valor do coeficiente que reflete a heterogeneidade do adsorvente.
/// </summary>
/// <example>
/// Uso:
/// @code
///     RedlichPeterson  var1(K1, K2, K3);              
///     double k3 = var1.K3();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente que reflete a heterogeneidade do adsorvente.
inline Real K3 () const {return  Value(2);};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função para alterar  a constante de Redlich-Peterson.
/// </summary>
/// <example>
/// Uso:
/// @code
///     RedlichPeterson  var1(K1, K2, K3);              
///     double k1(3.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da constante de Redlich-Peterson.
///  @exception _k1 <= 0.
     void K1 (const Real& _k1)  {*this = RedlichPeterson(_k1, Value(1), Value(2));};
     
/// <summary>
/// Função que altera o coeficiente associado a constante de Redlich - Peterson.
/// </summary>
/// <example>
/// Uso:
/// @code
///     RedlichPeterson  var1(K1, K2, K3);              
///     double k2(2.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor do coeficiente associado a constante de RedlichPeterson.
///  @exception _k2 <= 0.
    void K2 (const Real& _k2)  {*this = RedlichPeterson(Value(0), _k2, Value(2));};
    
/// <summary>
/// Função para alterar o valor do coeficiente que reflete a heterogeneidade do adsorvente.
/// </summary>
/// <example>
/// Uso:
/// @code
///     RedlichPeterson  var1(K1, K2, K3);              
///     double k3(3.0);
///     var1.K3(k3);
/// @endcode
/// </example>
///  @param _k3 Novo valor do coeficiente que reflete a heterogeneidade do adsorvente.
///  @exception _k3 <= 0.    
    void K3 (const Real& _k3)  {*this = RedlichPeterson(Value(0), Value(1), _k3);};


//==============================================================================
// Funções virtuais
//==============================================================================
    
/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     RedlichPeterson  var1(K1, K2, K3);              
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @return Valor da quantidade de sorção no equilíbrio.    
///  @exception _c < 0.    
    virtual Real Qe (const Real&, const Real& = 0) const;
    virtual RedlichPeterson* clone() const override
    {
        return new RedlichPeterson(*this);
    } 
};

IST_NAMESPACE_CLOSE

#endif /* __REDLICH_PETERSON_H__ */