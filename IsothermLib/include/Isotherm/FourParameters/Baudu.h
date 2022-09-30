//==============================================================================
// Name        : Baudu.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equaco�es da isoterma de Baudu.
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

/** @defgroup Baudu  Baudu
 *  @ingroup Four_Parameters
 *  Classe Baudu contém a equacao da isoterma de Baudu.
 *  @{
 */        

/// <summary>
/// Classe com as equaco�es da isoterma de Baudu.
/// </summary>
///  Isoterma com quatro parametros, \f$ q_{max} \f$, \f$ K_1 \f$, \f$ K_2 \f$ e \f$ K_3 \f$ cujas formulas sao as seguintes:
///\begin{align}
///  Q_e(C_e, T) = \frac{q_{max}C_e^{K_3}}{1 + K_1C_e^{K_3}}
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Fli�vio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Nao ha bugs conhecidos.
///  
///  \copyright GNU Public License.



#ifndef __BAUDU_H__
#define __BAUDU_H__


//==============================================================================
// include da biblioteca c++
//==============================================================================

#include <cmath>

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/FourParameters/FourParameters.h>

IST_NAMESPACE_OPEN

class Baudu :    public virtual FourParameters,
                            public IsothermTemplate < Baudu > {
    
    
//==============================================================================
// ID da classe
//==============================================================================

public:    
    
/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
    
    DefineIdentity  (   "Baudu"
                    ,   ID::Baudu
                    );  
    
    
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
///     Baudu  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    Baudu() = default;
    
/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var;
///     Baudu  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo Baudu original. 
    Baudu (const Baudu& _orig) = default;
  
/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Baudu() = default;

/// <summary>
/// Construtora com os parametros que definem a isoterma de Baudu.
/// </summary>
/// <example>
/// Uso:
/// @code
///     double QMAX(1.0);
///     double K1(1.0);    
///     double K2(1.0);
///     double K3(1.0);
///     Baudu  var1(Q1, K1, K2, K3);
/// @endcode
/// </example>
///  @param _qmax Capacidade maxima de adsorcao.    
///  @param _k1 Coeficiente da isortema de Baudu.    
///  @param _k2 Coeficiente da isoterma de Baudu.
///  @param _k3 Expoente da isoterma de Baudu.    
///  @exception _qmax < 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
///  @exception 0 < _k3 < 1.
    Baudu   (   const Real& 
            ,   const Real& 
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
///     Baudu  var1(QMAX, K1, K2, K3);              
///     Baudu  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo Baudu.
///  @return Copia de _orig.    
    Baudu& operator = (const Baudu&) = default;
    
//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Funcao que informa o valor da capacidade maxima de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da  capacidade maxima de adsorcao.
    
[[nodiscard]] 
inline Real Qmax () const {return  Value(0);};


/// <summary>
/// Funcao que retorna o coeficiente associado a constante de Baudu.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente associado a constante de Baudu.


[[nodiscard]] 
inline Real K1 () const {return  Value(1);};
    
/// <summary>
/// Funcao que retorna o parametro da equacao de Baudu.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do parametro da equacao de Baudu.    
[[nodiscard]] 
inline Real K2 () const {return  Value(2);};

/// <summary>
/// Funcao que retorna o parametro da equacao de Baudu.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double k3 = var1.K3();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do parametro da equacao de Baudu.  
[[nodiscard]] 
inline Real K3 () const {return  Value(3);};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar  a capacidade maxima de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorcao.
///  @exception _qmax < 0.
    void Qmax (const Real& _qmax)   {   *this = Baudu    (       _qmax 
                                                                    ,       Value(1) 
                                                                    ,       Value(2)
                                                                    ,       Value(3)
                                                                    );
                                    };

/// <summary>
/// Funcao que altera o coeficiente associado a constante da isoterma de Baudu.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante da isoterma de Baudu. 
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)   {   *this = Baudu    (   Value(0) 
                                                                ,   _k1 
                                                                ,   Value(2) 
                                                                ,   Value(3)
                                                                );
                                };

/// <summary>
/// Funcao para alterar o valor associado a constante da isoterma de Baudu.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor associado a constante da isoterma de Baudu.
///  @exception _k2 <= 0.    
    void K2 (const Real& _k2)   {   *this = Baudu    (   Value(0) 
                                                                ,   Value(1) 
                                                                ,   _k2     
                                                                ,   Value(3)
                                                                );
                                };

/// <summary>
/// Funcao para alterar o valor associado ao expoente da isoterma de Baudu.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double k3(3.0);
///     var1.K3(k3);
/// @endcode
/// </example>
///  @param _k3 Novo valor associado ao expoente da isoterma de Baudu.
///  @exception 0 < _k3 < 1.    
    void K3 (const Real& _k3)  {    *this = Baudu    (   Value(0) 
                                                                ,   Value(1) 
                                                                ,   Value(2) 
                                                                ,   _k3
                                                                );
                                };

    
//==============================================================================
// Funco�es virtuais
//==============================================================================
    
/// <summary>
/// Funcao que calcula a quantidade de sorcao no equili�brio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Baudu  var1(QMAX, K1, K2, K3);              
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equili�brio.    
///  @exception _c < 0.    
    [[nodiscard]]  Real Qe (const Real&, const Real&) const;

    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }



    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<Baudu>(*this);
    }
    

    
};

IST_NAMESPACE_CLOSE

#endif /* __BAUDU_H__ */
        
        
/** @} */ 