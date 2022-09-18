//==============================================================================
// Name        : ViethSladek.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Vieth-Sladek
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

/** @defgroup ViethSladek Vieth-Sladek
 *  @ingroup Three_Parameters
 *  Classe ViethSladek contém a equação da isoterma de Vieth-Sladek.
 *  @{
 */

/// <summary>
/// Classe com as equações da isoterma de ViethSladek
/// </summary>
///  Isoterma com três parâmetros, \f$ q_{max} \f$, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas fórmulas são as seguintes:
///  \f{Q_e(C_e) = K_2 C_e + \frac{q_{max} K_1C_e} {1+K_1C_e} \f}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/0095-8522(65)90071-1).
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///  
///  \copyright GNU Public License.

#ifndef __VIETH_SLADEK_H__
#define __VIETH_SLADEK_H__

//==============================================================================
// include da biblioteca c++
//==============================================================================

#include <cmath>

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/ThreeParameters/ThreeParameters.h>

IST_NAMESPACE_OPEN


class ViethSladek :  public virtual ThreeParameters, 
              public IsothermTemplate < ViethSladek > {
    
//==============================================================================
// ID da classe
//==============================================================================

public:    
    
/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
/// <example>
        
    DefineIdentity  (   "Vieth-Sladek"
                    ,   ID::ViethSladek
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
///     ViethSladek  var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    ViethSladek() = default;
    
/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     ViethSladek  var;
///     ViethSladek  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo Vieth-Sladek original. 
    ViethSladek (const ViethSladek& _vieth_sladek) = default;
  
/// <summary>
/// Destrutora.
/// </summary>
    virtual ~ViethSladek() = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de ViethSladek.
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
///  @param _qmax Capacidade maxima de adsorção.    
///  @param  _k1 Constante da isortema de Vieth-Sladek.    
///  @param _k2 Constante do expoente da isoterma de Vieth-Sladek.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    ViethSladek (   const Real&
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
///     ViethSladek  var1(QMAX, K1, K2);              
///     ViethSladek  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variável do tipo ViethSladek original.
///  @return Cópia de _orig.    
    ViethSladek& operator = (const ViethSladek& _orig) = default;
    
//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Função que informa o valor da capacidade maxima de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     ViethSladek  var1(QMAX, K1, K2);              
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor da  capacidade maxima de adsorção.
inline Real Qmax () const 
{
    return  Value(0);
};


/// <summary>
/// Função que retorna o coeficiente associado a constante de Vieth-Sladek.
/// </summary>
/// <example>
/// Uso:
/// @code
///     ViethSladek  var1(QMAX, K1, K2);              
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do coeficiente associado a constante de Vieth-Sladek.
inline Real K1 () const 
{
    return  Value(1);
};
    
/// <summary>
/// Função que retorna o parâmetro da equação de Vieth–Sladek.
/// </summary>
/// <example>
/// Uso:
/// @code
///     ViethSladek  var1(QMAX, K1, K2);              
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Não há parâmetros.
///  @return Valor do parâmetro da equação de Vieth–Sladek.    
inline Real K2 () const 
{
    return  Value(2);
};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função para alterar  a capacidade maxima de adsorção.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Kilselev  var1(QMAX, K1, K2);              
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorção.
///  @exception _qmax <= 0.
inline void Qmax (const Real& _qmax)  
{
    *this = ViethSladek (_qmax, Value(1), Value(2));
};

/// <summary>
/// Função que altera o coeficiente associado a constante de equilíbrio de ViethSladek. 
/// </summary>
/// <example>
/// Uso:
/// @code
///     ViethSladek  var1(QMAX, K1, K2);              
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante de equilíbrio de ViethSladek. 
///  @exception _k1 <= 0.
inline void K1 (const Real& _k1)  
{
    *this = ViethSladek (Value(0), _k1, Value(2));
};

/// <summary>
/// Função para alterar o valor associado ao parâmetro da equação de Vieth–Sladek.
/// </summary>
/// <example>
/// Uso:
/// @code
///     ViethSladek  var1(QMAX, K1, K2);              
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor associado ao parâmetro da equação de Vieth–Sladek.
///  @exception _k2 <= 0.    
inline void K2 (const Real& _k2)  
{
    *this = ViethSladek(Value(0), Value(1), _k2);
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
///     ViethSladek  var1(QMAX, K1, K2);              
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentração do soluto.
///  @return Valor da quantidade de sorção no equilíbrio.    
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
        return std::make_unique<ViethSladek>(*this);
    }

    
};

IST_NAMESPACE_CLOSE

#endif /* __VIETH_SLADEK_H__ */
        
/** @} */ 
        
        