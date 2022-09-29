//==============================================================================
// Name        : Unilan.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Unilan.
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


/*! \class	Unilan
 *  \brief	Classe com as equacoes da isoterma de Unilan.
 *  \file	Unilan.h
 *  \author	Luan Rodrigues Soares de Souza
 *  \version	1.0
 *  \date	2021
 *  \bug	Nao ha bugs conhecidos
 */


#ifndef __UNILAN_H__
#define __UNILAN_H__


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
/// Classe com as equacoes da isoterma de Unilan.
/// </summary>
///  Isoterma com três parametros, \f$ q_{max} \f$, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas fórmulas sao as seguintes:
///\begin{align}
///  \[Q_e(C_e, T)= \frac{q_{max}}{2K_2}ln(\frac{1+K_1C_ee^{K_2}}{1+K_1C_ee^{-K_2}})\]
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors    Joao Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2020
///  \bug       Nao ha bugs conhecidos.
///  
///  \copyright GNU Public License.

class Unilan :  public virtual ThreeParameters, 
              public IsothermTemplate < Unilan > {
    
//==============================================================================
// ID da classe
//==============================================================================

public:    
    
/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
/// <example>
        
    DefineIdentity  ("Unilan", ID::Unilan);  
    
    
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
///     Unilan  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    Unilan() = default;
    
/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Unilan  var;
///     Unilan  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo Unilan original. 
    Unilan (const Unilan& _unilan) = default;
  
/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Unilan() = default;

/// <summary>
/// Construtora com os parametros que definem a isoterma de Unilan.
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
///  @param  _k1 Constante da isortema de Unilan.    
///  @param _k2 Constante da isoterma de Unilan.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    Unilan (const Real&, const Real&, const Real&);
        
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
///     Unilan  var1(QMAX, K1, K2);              
///     Unilan  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo Unilan original.
///  @return Cópia de _orig.    
    Unilan& operator = (const Unilan&) = default;
    
//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Funcao que informa o valor da capacidade maxima de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Unilan  var1(QMAX, K1, K2);              
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da  capacidade maxima de adsorcao.
    [[nodiscard]]
inline Real Qmax () const {return  Value(0);};


/// <summary>
/// Funcao que retorna o coeficiente associado a constante de Unilan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Unilan  var1(QMAX, K1, K2);              
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente associado a constante de Unilan.
[[nodiscard]]
inline Real K1 () const {return  Value(1);};
    
/// <summary>
/// Funcao que retorna o parametro da equacao de Unilan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Unilan  var1(QMAX, K1, K2);              
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do parametro da equacao de Unilan.  
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
///     Unilan  var1(QMAX, K1, K2);              
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorcao.
///  @exception _qmax <= 0.
    void Qmax (const Real& _qmax)  {*this = Unilan(_qmax, Value(1), Value(2));};

/// <summary>
/// Funcao que altera o coeficiente associado a constante da isoterma de Unilan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Unilan  var1(QMAX, K1, K2);              
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante da isoterma de Unilan. 
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)  {*this = Unilan(Value(0), _k1,  Value(2));};

/// <summary>
/// Funcao para alterar o valor associado a constante da isoterma de Unilan.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Unilan  var1(QMAX, K1, K2);              
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor associado a constante da isoterma de Unilan.
///  @exception _k2 <= 0.    
    void K2 (const Real& _k2)  {*this = Unilan(Value(0), Value(1),  _k2);};
    
    
//==============================================================================
// Funcoes virtuais
//==============================================================================
    
/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Unilan  var1(QMAX, K1, K2);              
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equilíbrio.    
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
        return std::make_unique<Unilan>(*this);
    }

    private:
        
        Real nume = 0;
        Real deno = 0;
        Real prod = 0;

};

IST_NAMESPACE_CLOSE

#endif /* __UNILAN_H__ */