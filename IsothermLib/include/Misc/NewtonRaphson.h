/** @defgroup NewtonRaphson Método de Newton-Rapshon
 *  @ingroup Miscelânea
 *  Programação do método Newton-Raphson para o cálculo de raízes de funções.
 *  @{
 */


#ifndef __NEWTONRAPHSON_H__
#define __NEWTONRAPHSON_H__

//==============================================================================
// debug
//==============================================================================
//#define __NEWTONRAPHSON_DEBUG_H__

#include <functional>
using namespace std::placeholders;


#include <Misc/Misc.h>

typedef         std::function<Real(Real)>                           NRFunction;
Real  NewtonRaphson (NRFunction, const Real&);

#endif /* __NEWTONRAPHSON_H__ */

        
/** @} */    
        
        
   

