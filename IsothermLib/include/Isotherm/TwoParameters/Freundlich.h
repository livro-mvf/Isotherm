//==============================================================================
// Name        : Freundlich.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Freundlich
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

/** @defgroup Freundlich Freundlich
 *  @ingroup Two_Parameters
 *  Classe Freundlich contém a equação da isoterma de Freundlich.
 *  @{
 */

/// <summary>
/// Classe com a equação da isoterma de Freundlich
/// </summary>
///  Isoterma com dois parâmetros, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas fórmulas são as seguintes:
///\begin{align}
///     Q_e(C_e) = K_1C_e^{\frac{1}{K_2}}
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://tinyurl.com/yxruu6c7).
///  \authors   Iasmim Barboza Storck
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///  
///  \copyright GNU Public License.

#ifndef __FREUNDLICH_H__
#define __FREUNDLICH_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

IST_NAMESPACE_OPEN



class Freundlich :  public virtual TwoParameters, 
                    public IsothermTemplate < Freundlich > {
    
//==============================================================================
// ID da classe
//==============================================================================

public:    
    
 
/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
/// <example>
    DefineIdentity  (   "Freundlich"
                    ,   ID::Freundlich
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
///     Freundlich  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    Freundlich() = default;
    
/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Freundlich  var;
///     Freundlich  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo Freundlich original.
    Freundlich(const Freundlich& _orig) = default;
    
/// <summary>
/// Destrutora.
/// </summary>
    ~Freundlich() override = default;
    
/// <summary>
/// Construtora com os parâmetros que definem a isoterma de Freundlich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real k1(1.0);
///     Real k2(1.0);            
///     Freundlich  var1(k1, k2);              
/// @endcode
/// </example>
///  @param _k1 Coeficiente de distribuição em [M /M ].    
///  @param  _k2 Fator de correção. 
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    Freundlich  (   const Real&     _k1
                ,   const Real&     _k2
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
///     Freundlich  var1(k1, k2);              
///     Freundlich  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo Freundlich original.
///  @return Cópia de _orig. 
    Freundlich& operator = (const Freundlich& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Função que informa o valor do coeficiente de distribuição em [M /M ].
/// </summary>
/// <example>
/// Uso:
/// @code
///     Freundlich  var1(k1, k2);              
///     Real _k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente de distribuição em [M /M ].
[[nodiscard]] inline Real K1 () const
{   
    return  Value(0);
};

/// <summary>
/// Função que retorna o coeficiente associado ao fator de correção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Freundlich  var1(k1, k2);              
///     Real _k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente associado ao fator de correção.  
[[nodiscard]] inline Real K2 () const
{
    return  Value(1);
};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função para alterar o valor do coeficiente de distribuição em [M /M ].
/// </summary>
/// <example>
/// Uso:
/// @code
///     Freundlich  var1(k1, k2);              
///     Real k11(3.0);
///     var1.K1(k11);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente de distribuição em [M /M ].
///  @exception _k1 <= 0.
inline void K1 (const Real& _k1)  
{
    *this = Freundlich(_k1, Value(1));
};


/// <summary>
/// Função que altera o coeficiente associado ao fator de correção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Freundlich  var1(k1, k2);              
///     Real _k22(2.0);
///     var1.K2(_k22);
/// @endcode
/// </example>
///  @param _k2 Novo valor do coeficiente associado a energia de adsorção.
///  @exception _k2 <= 0.
inline void K2 (const Real& _k2)  
{
    *this = Freundlich(Value(0), _k2);
};

//==============================================================================
// Funções virtuais
//==============================================================================
    
/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Freundlich  var1(k1, k2);              
///     Real ce(1.0);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @return Valor da quantidade de sorção no equilíbrio.    
///  @exception _c < 0.
    [[nodiscard]] 
    Real Qe (   const Real& _c
            ,   const Real& _temp = 0) const override;

    [[nodiscard]] 
    virtual Freundlich* CloneImplementation() const override
    {
        return new Freundlich(*this);
    }
    
private:
    
Real        invK2{};

};
/// \example TesteFreundlich.cpp
 
IST_NAMESPACE_CLOSE
        
#endif /* __FREUNDLICH_H__ */

/** @} */ 