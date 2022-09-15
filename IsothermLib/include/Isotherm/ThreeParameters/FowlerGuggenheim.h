//==============================================================================
// Name        : FowlerGuggenheim.h
// Author      : Iasmim Barboza Storck
//               Lara Botelho Brum
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Fowler - Guggenheim
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


/*! \class	Fowler - Guggenheim
 *  \brief	Classe com as equacoes da isoterma de Fowler - Guggenheim
 *  \file	FowlerGuggenheim.h
 *  \authors	Lara Botelho Brum
 *  \authors	Joao Flavio Vieira de Vasconcellos
 *  \version	1.0
 *  \date	2021
 *  \bug	Nao ha bugs conhecidos
 */

#ifndef __FOWLERGUGGENHEIM_H__
#define	__FOWLERGUGGENHEIM_H__


//==============================================================================
// opçao de debug
//==============================================================================

//#define __FOWLERGUGGENHEIM_DEBUG_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/ThreeParameters/ThreeParameters.h>

IST_NAMESPACE_OPEN

/// <summary>
/// Classe com as equacoes da isoterma de Fowler - Guggenheim
/// </summary>
///  Isoterma com tras parâmetros, \f$ q_{max} \f$, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas fórmulas sao as seguintes:
///\begin{align}
///  \[\[f(\theta = K_1C-\frac{\theta}{1-\theta}e^{\frac{K_2\theta}{RT}}=0\]
///\end{align}
///  Um artigo de referancia pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors    Lara Botelho Brum
///  \authors    Joao Flavio Vieira de Vasconcellos
///  \authors    Iasmim Barboza Storck
///  \version   1.0
///  \date      2021
///  \bug       Nao ha bugs conhecidos.
///  
///  \copyright GNU Public License.

class FowlerGuggenheim :  public virtual ThreeParameters, 
                    public IsothermTemplate < FowlerGuggenheim > {


//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definiçao de ID para esta classe para fins de identificaçao de erros.
/// </summary>
/// <example>

    DefineIdentity("Fowler - Guggenheim", ID::FowlerGuggenheim);

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
///     FowlerGuggenheim  var;
/// @endcode
/// </example>
/// @param " " Nao ha parâmetros para esta funçao
    FowlerGuggenheim () = default;

/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var;
///     FowlerGuggenheim  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo FowlerGuggenheim original.
    FowlerGuggenheim (const FowlerGuggenheim& _fowlerguggenheim) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~FowlerGuggenheim () = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de Fowler - Guggenheim.
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
///  @param _qmax Capacidade maxima de adsorçao.
///  @param  _k1 Constante da isortema de Fowler - Guggenheim.
///  @param _k2 Constante do expoente da isoterma de Fowler - Guggenheim.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    FowlerGuggenheim    (   const Real&     _qmax
                        ,   const Real&     _k1
                        ,   const Real&     _k2
                        ,   const Real&     _rgas = Isotherm::RGASCONST
                        ) ;

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
///     FowlerGuggenheim  var1(QMAX, K1, K2);
///     FowlerGuggenheim  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo Fowler - Guggenheim original.
///  @return Cópia de _orig.
    FowlerGuggenheim& operator = (const FowlerGuggenheim& _orig) = default;

//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Funçao que informa o valor da capacidade maxima de adsorçao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var1(QMAX, K1, K2);
///     double q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Nao ha parâmetros.
///  @return Valor da  capacidade maxima de adsorçao.
    inline Real Qmax () const {return  Value(0);};


/// <summary>
/// Funçao que retorna o coeficiente associado a constante de Fowler - Guggenheim.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim var1(QMAX, K1, K2);
///     double k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parâmetros.
///  @return Valor do coeficiente associado a constante de Fowler - Guggenheim.
    inline Real K1 () const {return  Value(1);};

/// <summary>
/// Funçao que retorna o valor do expoente da isoterma de Fowler - Guggenheim.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var1(QMAX, K1, K2);
///     double k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Nao ha parâmetros.
///  @return Valor do expoente da isoterma de Fowler - Guggenheim.
    inline Real K2 () const {return  Value(2);};

/// <summary>
/// Funçao que retorna o valor da constante universal dos gases.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var1(q1, k1);
///     Real rg = var1.Rgas();
/// @endcode
/// </example>
///  @param " " Nao ha parâmetros.
///  @return Valor da constante universal dos gases.
    inline Real Rgas () const {return  RGAS;};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funçao para alterar  a capacidade maxima de adsorçao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var1(QMAX, K1, K2);
///     double q1(3.0);
///     var1.Qmax(q1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorçao.
///  @exception _qmax <= 0.
    void Qmax (const Real& _qmax) {*this = FowlerGuggenheim(_qmax, Value(1), Value(2), this->Rgas());};

/// <summary>
/// Funçao que altera o coeficiente associado a constante de equilíbrio de Fowler-Guggenheim.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var1(QMAX, K1, K2);
///     double k1(2.0);
///     var1.K1(k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante de equilíbrio de Fowler-Guggenheim.
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)  {*this = FowlerGuggenheim(Value(0), _k1, Value(2), this->Rgas());};

/// <summary>
/// Funçao para alterar o valor da constante de iteraçao entre as moléculas adsorvidas.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var1(QMAX, K1, K2);
///     double k2(3.0);
///     var1.K2(k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor da constante de iteraçao entre as moléculas adsorvidas.
///  @exception _k2 <= 0.
    void K2 (const Real& _k2)  {*this = FowlerGuggenheim(Value(0), Value(1), _k2, this->Rgas());};

/// <summary>
/// Funçao para alterar o valor da constante universal dos gases.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var1(q1, k1, k2);
///     Real rgas(62.363598221529);
///     var1.Rgas(rgas);
/// @endcode
/// </example>
///  @param _rgas Novo valor da constante universal dos gases.
///  @exception _rgas <= 0.
    void Rgas (const Real& _rgas) {*this = FowlerGuggenheim(Value(0), Value(1), Value(2), _rgas);};



//==============================================================================
// Funcoes virtuais
//==============================================================================

/// <summary>
/// Funçao que calcula a quantidade de sorçao no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     FowlerGuggenheim  var1(QMAX, K1, K2);
///     double ce(1.0);
///     double qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentraçao do soluto.
///  @return Valor da quantidade de sorçao no equilíbrio.
///  @exception _c < 0.
    virtual Real Qe (const Real& _c, const Real& _temp) const;

    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }


    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<FowlerGuggenheim>(*this);
    }

    

//==============================================================================
// Dados da classe
//==============================================================================

Real  FQe (const Real&) const;

private:

Real                 auxiCe = 0;
Real                 RGAS = Isotherm::RGASCONST;                // Constante universal dos gases
Real                 tempK = 0;

};

IST_NAMESPACE_CLOSE

        
#endif	/* FOWLERGUGGENHEIM_H */


