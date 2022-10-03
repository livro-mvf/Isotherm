/** @defgroup NewtonRaphson Metodo de Newton-Rapshon
 *  @ingroup Misceli¢nea
 *  Programacao do metodo Newton-Raphson para o calculo de raizes de funcoes.
 *  @{
 */


#ifndef __NEWTONRAPHSON_H__
#define __NEWTONRAPHSON_H__


#include <functional>
using namespace std::placeholders;


#include <Misc/Misc.h>

typedef         std::function<Real(Real)>                           NRFunction;
Real  NewtonRaphson (NRFunction, const Real&);

#endif /* __NEWTONRAPHSON_H__ */

        
/** @} */    
        
        
   

