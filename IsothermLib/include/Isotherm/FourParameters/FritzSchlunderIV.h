//==============================================================================
// Name        : FritzSchlunderIV.h
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Fritz-SchlundeIV.
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

/** @defgroup FritzSchlunderIV  FritzSchlunderIV
 *  @ingroup Four_Parameters
 *  Classe FritzSchlunderIV contém a equação da isoterma de FritzSchlunder IV.
 *  @{
 */        

/// <summary>
/// Classe com as equações da isoterma de Fritz-Schlunder IV.
/// </summary>
///  Isoterma com quatro parâmetros, \f$ q_{max} \f$, \f$ K_1 \f$, \f$ K_2 \f$ e \f$ K_3 \f$ cujas fórmulas são as seguintes:
///\begin{align}
///  Q_e(C_e, T) = \frac{q_{max}C_e^{K_3}}{1 + K_1C_e^{K_3}}
///\end{align}
///  Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   João Flávio Vieira de Vasconcellos
///  \version   1.0
///  \date      2021
///  \bug       Não há bugs conhecidos.
///  
///  \copyright GNU Public License.



#ifndef __FRITZ_SCHLUNDER_IV_H__
#define __FRITZ_SCHLUNDER_IV_H__

//
////==============================================================================
//// include da biblioteca c++
////==============================================================================
//
//#include <cmath>
//
//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/FourParameters/FourParameters.h>

IST_NAMESPACE_OPEN

class FritzSchlunderIV :    public virtual FourParameters, 
                            public IsothermTemplate < FritzSchlunderIV > {
    
//==============================================================================
// ID da classe
//==============================================================================

public:    
    
/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
    
    DefineIdentity  (   "FritzSchlunderIV"
                    ,   ID::FritzSchlunderIV
                    );  
    
    
////==============================================================================
//// Funções Construtoras/Destrutora
////==============================================================================
//    
//public:
//
// /// <summary>
///// Construtora default.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var;
///// @endcode
///// </example>
///// @param " " Não há parâmetros para esta função
//    FritzSchlunderIV() = default;
//    
///// <summary>
///// Construtora de cópia.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var;
/////     FritzSchlunderIV  var1(var);
///// @endcode
///// </example>
///// @param  _orig Variável do tipo Fritz-Schlunder IV original. 
//    FritzSchlunderIV (const FritzSchlunderIV& _fritz_schlunder_iv) = default;
//  
///// <summary>
///// Destrutora.
///// </summary>
//    virtual ~FritzSchlunderIV() = default;
//
///// <summary>
///// Construtora com os parâmetros que definem a isoterma de FritzSchlunderV.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     double QMAX(1.0);
/////     double K1(1.0);    
/////     double K2(1.0);
/////     double K3(1.0);
/////     Sips  var1(Q1, K1, K2, K3);
///// @endcode
///// </example>
/////  @param _qmax Capacidade maxima de adsorção.    
/////  @param _k1 Coeficiente da isortema de Fritz - Schlunder IV.    
/////  @param _k2 Coeficiente da isoterma de Fritz - Schlunder IV.
/////  @param _k3 Expoente da isoterma de Fritz - Schlunder IV.    
/////  @exception _qmax < 0.
/////  @exception _k1 <= 0.
/////  @exception _k2 <= 0.
/////  @exception 0 < _k3 < 1.
//    FritzSchlunderIV (  const Real&, 
//                        const Real&, 
//                        const Real&, 
//                        const Real&);
//        
////==============================================================================
//// Sobrecarga de operadores
////==============================================================================
//
//public:
//    
//
///// <summary>
///// Sobrecarga do operador =. 
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var1(QMAX, K1, K2, K3);              
/////     FritzSchlunderIV  var2 = var1;
///// @endcode
///// </example>
/////  @param _orig Variável do tipo FritzSchlunderV original.
/////  @return Cópia de _orig.    
//    FritzSchlunderIV& operator = (const FritzSchlunderIV&) = default;
//    
////==============================================================================
//// Acesso as constantes da classe
////==============================================================================
//
///// <summary>
///// Função que informa o valor da capacidade maxima de adsorção.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var1(QMAX, K1, K2, K3);              
/////     double q1 = var1.Qmax();
///// @endcode
///// </example>
/////  @param " " Não há parâmetros.
/////  @return Valor da  capacidade maxima de adsorção.
//inline Real Qmax () const {return  Value(0);};
//
//
///// <summary>
///// Função que retorna o coeficiente associado a constante de Fritz - Schlunder IV.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderV  var1(QMAX, K1, K2, K3);              
/////     double k1 = var1.K1();
///// @endcode
///// </example>
/////  @param " " Não há parâmetros.
/////  @return Valor do coeficiente associado a constante de Fritz - Schlunder IV.
//inline Real K1 () const {return  Value(1);};
//    
///// <summary>
///// Função que retorna o parâmetro da equação de Fritz - Schlunder IV.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var1(QMAX, K1, K2, K3);              
/////     double k2 = var1.K2();
///// @endcode
///// </example>
/////  @param " " Não há parâmetros.
/////  @return Valor do parâmetro da equação de Fritz - Schlunder IV.    
//inline Real K2 () const {return  Value(2);};
//
///// <summary>
///// Função que retorna o parâmetro da equação de Fritz - Schlunder IV.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var1(QMAX, K1, K2, K3);              
/////     double k3 = var1.K3();
///// @endcode
///// </example>
/////  @param " " Não há parâmetros.
/////  @return Valor do parâmetro da equação de Fritz - Schlunder IV.    
//inline Real K3 () const {return  Value(3);};
//
////==============================================================================
//// Alterando as constantes da classe
////==============================================================================
//
///// <summary>
///// Função para alterar  a capacidade maxima de adsorção.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var1(QMAX, K1, K2, K3);              
/////     double q1(3.0);
/////     var1.Qmax(q1);
///// @endcode
///// </example>
/////  @param _qmax Novo valor da capacidade maxima de adsorção.
/////  @exception _qmax < 0.
//    void Qmax (const Real& _qmax)  {*this = FritzSchlunderIV (   _qmax, 
//                                                                Value(1), 
//                                                                Value(2),
//                                                                Value(3));};
//
///// <summary>
///// Função que altera o coeficiente associado a constante da isoterma de Fritz – Schlunder IV.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var1(QMAX, K1, K2, K3);              
/////     double k1(2.0);
/////     var1.K1(k1);
///// @endcode
///// </example>
/////  @param _k1 Novo valor do coeficiente associado a constante da isoterma de Fritz – Schlunder IV. 
/////  @exception _k1 <= 0.
//    void K1 (const Real& _k1)  {*this = FritzSchlunderIV (   Value(0), 
//                                                            _k1, 
//                                                            Value(2), 
//                                                            Value(3));};
//
///// <summary>
///// Função para alterar o valor associado a constante da isoterma de Fritz – Schlunder IV.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var1(QMAX, K1, K2, K3);              
/////     double k2(3.0);
/////     var1.K2(k2);
///// @endcode
///// </example>
/////  @param _k2 Novo valor associado a constante da isoterma de Fritz – Schlunder IV.
/////  @exception _k2 <= 0.    
//    void K2 (const Real& _k2)  {*this = FritzSchlunderIV(    Value(0), 
//                                                            Value(1), 
//                                                            _k2     ,
//                                                            Value(3));};
//
///// <summary>
///// Função para alterar o valor associado ao expoente da isoterma de Fritz – Schlunder IV.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderIV  var1(QMAX, K1, K2, K3);              
/////     double k3(3.0);
/////     var1.K3(k3);
///// @endcode
///// </example>
/////  @param _k3 Novo valor associado ao expoente da isoterma de Fritz – Schlunder IV.
/////  @exception 0 < _k3 < 1.    
//    void K3 (const Real& _k3)  {*this = FritzSchlunderIV(   Value(0), 
//                                                            Value(1), 
//                                                            Value(2), 
//                                                            _k3);};
//
//    
////==============================================================================
//// Funções virtuais
////==============================================================================
//    
///// <summary>
///// Função que calcula a quantidade de sorção no equilíbrio.
///// </summary>
///// <example>
///// Uso:
///// @code
/////     FritzSchlunderV  var1(QMAX, K1, K2, K3);              
/////     double ce(1.0);
/////     double qe = var1.Qe(ce);
///// @endcode
///// </example>
/////  @param _c Concentração do soluto.
/////  @return Valor da quantidade de sorção no equilíbrio.    
/////  @exception _c < 0.    
//    virtual Real Qe (const Real&, const Real& = 0) const;
//
//
    
//    virtual FritzSchlunderV* clone() const override
//    {
//        return new FritzSchlunderV(*this);
//    }      
};

IST_NAMESPACE_CLOSE

#endif /* __FRITZ_SCHLUNDER_V_H__ */
        
        
/** @} */ 