//==============================================================================
// includes lib c++
//==============================================================================

#include <cmath>
#include <iostream>

//==============================================================================
// includes da lib IsothermLib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/ThreeParameters/ViethSladek.h>


IST_NAMESPACE_OPEN

//==============================================================================
// Variaveis estáticas
//==============================================================================

VecPairString       isothermViethSladek     {   PairString  ( "Qmax"
                                                            , "Capacidade máxima de adsorcao")
                                            ,   PairString  ( "K1"
                                                            , "Constante de ViethSladek")
                                            ,   PairString  ( "K2"
                                                            , "Parametro da equacao de ViethSladek")};

template<>
VecPairString IsothermTemplate < ViethSladek >::infoIsotherm = isothermViethSladek;


//==============================================================================
// Construtora com dois parametros
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "ViethSladek :: ViethSladek (const Real&, const Real&, const Real&)"
ViethSladek :: ViethSladek  (   const Real&     _qmax
                            ,   const Real&     _k1
                            ,   const Real&     _k2
                            )
                            :   ThreeParameters(_qmax, _k1, _k2)
{

    try {

            if (_qmax <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadQmaxLEZero
                                    );

            if (_k1 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK1LEZero
                                    );

            if (_k2 <= 0.0)  throw
                    IsoException    (   IST_LOC
                                    ,   className()
                                    ,   BadK2LEZero
                                    );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);

    };

    setup = true;

}

//==============================================================================
// Concentracao de Equilíbrio Qe
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "ViethSladek ::  Qe (const Real&, const Real&) const "
Real
ViethSladek ::  Qe  (   const Real& _ce
                    ,   const Real&
                    ) const {

    try {
        if (!setup) throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCoefficient);

        if (_ce < 0.0)  throw
                IsoException    (   IST_LOC
                                ,   className()
                                ,   BadCeLTZero
                                );

    } catch (const IsoException& _isoExcept) {

        std::cout   << _isoExcept 
                    << "\n";
        exit(EXIT_FAILURE);
        
    }

auto    ptrValue = std::begin(coeffValue);

auto    auxiq = ((*ptrValue) * (*(ptrValue + 1)) * _ce);
auto    auxik = (1 + ((*(ptrValue + 1)) * _ce));
auto    value = ((*(ptrValue + 2)) * _ce) + auxiq / auxik;

    return (value >= ZERO ? value : 0.0)  ;
}

IST_NAMESPACE_CLOSE