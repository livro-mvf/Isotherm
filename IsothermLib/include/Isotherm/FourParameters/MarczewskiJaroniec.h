//==============================================================================
// Name        : MarczewskiJaroniec.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de MarczewskiJaroniec.
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

/** @defgroup MarczewskiJaroniec  MarczewskiJaroniec
 *  @ingroup Four_Parameters
 *  Classe MarczewskiJaroniec contem a equacao da isoterma de MarczewskiJaroniec.
 *  @{
 */        

/// <summary>
/// Classe com as equacoes da isoterma de MarczewskiJaroniec.
/// </summary>
///  Isoterma com quatro parametros, \f$ q_{max} \f$, \f$ K_1 \f$, \f$ K_2 \f$ e \f$ K_3 \f$ cuja formula e a seguinte:
///\begin{align}
///  \frac{Q_e(C_e)}{q_{max}} = \left[ \frac{(K_1 C_e)^{K_2}}{1 + (K_1 C_e)^{K_2}}\right]^\frac{K_2}{K_3}
///\end{align}
///  Um artigo de referencia pode ser encontrado [aqui]( https://doi.org/https://doi.org/10.1007/BF01134184 ).

///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///  
///  \copyright GNU Public License.



#ifndef __MARCZEWSKIJARONIEC_H__
#define __MARCZEWSKIJARONIEC_H__


//==============================================================================
// include da biblioteca c++
//==============================================================================

#include <cmath>

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/FourParameters/FourParameters.h>

IST_NAMESPACE_OPEN

class MarczewskiJaroniec :  public virtual FourParameters,
                            public IsothermTemplate < MarczewskiJaroniec > {
    
    
//==============================================================================
// ID da classe
//==============================================================================

private:    
    
/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
    
    DefineIdentity  (   "MarczewskiJaroniec"
                    ,   ID::MarczewskiJaroniec
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
///     MarczewskiJaroniec  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    MarczewskiJaroniec() = default;
    
/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var;
///     MarczewskiJaroniec  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo MarczewskiJaroniec original. 
    MarczewskiJaroniec (const MarczewskiJaroniec& _orig) = default;
  
/// <summary>
/// Destrutora.
/// </summary>
    virtual ~MarczewskiJaroniec() = default;

/// <summary>
/// Construtora com os parametros que definem a isoterma de MarczewskiJaroniec.
/// </summary>
/// <example>
/// Uso:
/// @code
///     double QMAX(1.0);
///     double K1(1.0);    
///     double K2(1.0);
///     double K3(1.0);
///     MarczewskiJaroniec  var1(Q1, K1, K2, K3);
/// @endcode
/// </example>
///  @param _qmax Capacidade maxima de adsorcao.    
///  @param _k1 Coeficiente da isortema de MarczewskiJaroniec.    
///  @param _k2 Coeficiente da isoterma de MarczewskiJaroniec.
///  @param _k3 Coeficiente da  isoterma de MarczewskiJaroniec.    
///  @exception _qmax < 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
///  @exception _k3 <= 0.
///  @exception _k3 >= 1.
    MarczewskiJaroniec  (   const Real& _qmax
                        ,   const Real&     _k1 
                        ,   const Real&     _k2
                        ,   const Real&     _k3
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
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     MarczewskiJaroniec  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo MarczewskiJaroniec.
///  @return Copia de _orig.    
    MarczewskiJaroniec& operator = (const MarczewskiJaroniec& _orig) = default;
    
//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Funcao que informa o valor da capacidade maxima de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da  capacidade maxima de adsorcao.
    
[[nodiscard]] 
inline Real Qmax () const {return  Value(0);};


/// <summary>
/// Funcao que retorna o coeficiente associado a constante de MarczewskiJaroniec.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente associado a constante de MarczewskiJaroniec.


[[nodiscard]] 
inline Real K1 () const {return  Value(1);};
    
/// <summary>
/// Funcao que retorna o parametro da equacao de MarczewskiJaroniec.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do parametro da equacao de MarczewskiJaroniec.    
[[nodiscard]] 
inline Real K2 () const {return  Value(2);};

/// <summary>
/// Funcao que retorna o parametro da equacao de MarczewskiJaroniec.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double k3 = var1.K3();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do parametro da equacao de MarczewskiJaroniec.  
[[nodiscard]] 
inline Real K3 () const {return  Value(3);};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar a capacidade maxima de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorcao.
///  @exception _qmax < 0.
    void Qmax (const Real& _qmax)   {   *this = MarczewskiJaroniec  (       _qmax 
                                                                    ,       Value(1) 
                                                                    ,       Value(2)
                                                                    ,       Value(3)
                                                                    );
                                    };

/// <summary>
/// Funcao que altera o coeficiente associado a constante da isoterma de MarczewskiJaroniec.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante da isoterma de MarczewskiJaroniec. 
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)   {   *this = MarczewskiJaroniec    (   Value(0) 
                                                                ,   _k1 
                                                                ,   Value(2) 
                                                                ,   Value(3)
                                                                );
                                };

/// <summary>
/// Funcao para alterar o valor associado a constante da isoterma de MarczewskiJaroniec.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor associado a constante da isoterma de MarczewskiJaroniec.
///  @exception _k2 <= 0.    
    void K2 (const Real& _k2)   {   *this = MarczewskiJaroniec    (   Value(0) 
                                                                ,   Value(1) 
                                                                ,   _k2     
                                                                ,   Value(3)
                                                                );
                                };

/// <summary>
/// Funcao para alterar o valor associado ao expoente da isoterma de MarczewskiJaroniec.
/// </summary>
/// <example>
/// Uso:
/// @code
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double k3(3.0);
///     var1.K3(k3);
/// @endcode
/// </example>
///  @param _k3 Novo valor associado ao expoente da isoterma de MarczewskiJaroniec.
///  @exception _k3 <= 0    
///  @exception _k3 >= 1    
    void K3 (const Real& _k3)  {    *this = MarczewskiJaroniec  (   Value(0) 
                                                                ,   Value(1) 
                                                                ,   Value(2) 
                                                                ,   _k3
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
///     MarczewskiJaroniec  var1(QMAX, K1, K2, K3);              
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equilibrio.    
///  @exception _c <= 0. 
    
public:
    
    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }
                              
                                
private:                                  
    [[nodiscard]]  
    Real Qe (const Real&, const Real&) const;

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<MarczewskiJaroniec>(*this);
    }
    

    
};

IST_NAMESPACE_CLOSE

#endif /* __MARCZEWSKIJARONIEC_H__ */
        
        
/** @} */ 