//==============================================================================
// Name        : TesteKhan.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe Khan da biblioteca isothermlib
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

//==============================================================================
// include da lib c++ 
//==============================================================================

#include <cassert>                      // assert
#include <cmath>                        // std::fabs
#include <iomanip>                      // std::setw, std::setprecision
#include <iostream>                     // std::cout


//==============================================================================
// include da IsothermLib
//==============================================================================
#include <Misc/Misc.h>                                      // PrintLine
#include <Isotherm/ThreeParameters/Khan.h>

//==============================================================================
// testes da classe Khan
//==============================================================================

int main(int argc, char** argv) {
    
    PrintLine(std::cout);    
    std::cout << "Teste da classe Khan\n";
    PrintLine(std::cout);    

//==============================================================================
// testes com construtores e destrutora
//==============================================================================
    
    std::cout << "\n\n";
    PrintLine(std::cout);    
    std::cout << "Teste dos construtores\n";
    PrintLine(std::cout);    
  
const Real  QMAX(100.0);        // Constantes do modelo
const Real  K1(1.0);            // Constantes do modelo
const Real  K2(2.0);            // Constantes do modelo

ist::Khan     f1;                 //Construtora default    
    assert (f1.K1() == 0); 
    assert (f1.K2() == 0); 
    assert (f1.Qmax() == 0);

    std::cout << "\nImprimindo a variavel f1: " 
              << f1 
              << std::endl;
    
    
ist::Khan   f2(QMAX, K1, K2);       // Construtora com 3 parametros
    assert (f2.K1() == K1); 
    assert (f2.K2() == K2); 
    assert (f2.Qmax() == QMAX);
    
    std::cout << "\nImprimindo a variavel f2: " 
              << f2 
              << std::endl;
    
ist::Khan    f3(f2);             // Construtora de cópia
    assert (f2.K1() == f3.K1()); 
    assert (f2.K2() == f3.K2()); 
    assert (f2.Qmax() == f3.Qmax());
    
    std::cout << "\nImprimindo a variavel f3: " 
              << f3 
              << std::endl;
   
//==============================================================================
// testes com sobrecarga de operadores
//==============================================================================

    std::cout << "\n\n";
    PrintLine(std::cout);    
    std::cout << "Teste da sobrecarga de operadores\n";
    PrintLine(std::cout);    
    
    f1 = f3;
    assert (f1.K1() == f3.K1()); 
    assert (f1.K2() == f3.K2()); 
    assert (f1.Qmax() == f3.Qmax());
    
    
    std::cout << "\nImprimindo a variavel f1: " << f1 << std::endl;
    
const Real QMAX1 (778.0);
const Real K11 (45.);
const Real K22 (1.5);

ist::Khan  f4 = ist::Khan(QMAX1, K11, K22);
    assert (f4.K1() == K11); 
    assert (f4.K2() == K22); 
    assert (f4.Qmax() == QMAX1);
    

    std::cout   << "\nImprimindo a variavel f4: "  
                << f4 
                << std::endl;
    
    
//==============================================================================
// testes do acesso as constantes da classe
//==============================================================================

    
    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Teste do acesso as constantes da classe\n";
    PrintLine(std::cout);    
    
    
    std::cout << f1
              << "\n";
    
        
    std::cout << "K1:\t" 
              << std::setw(12) 
              << std::fixed
              << f1.K1() 
              << std::endl;

    std::cout   << "K2:\t" 
                << std::setw(12)
                << std::fixed
                << f1.K2() 
                << std::endl;

    std::cout   << "QMAX:\t" 
                << std::setw(12)
                << std::fixed
                << f1.Qmax() 
                << std::endl;
        
    std::cout   << "\nAlterando K1  e K2 separadamente\n";
    std::cout   << "Imprimindo f1 antes da modificação: \n" 
                << f1 
                << std::endl;
    
    f1.K1(K11);
    assert (f1.K1() == K11); 
    
    f1.K2(K22);
    assert (f1.K2() == K22); 
    
    f1.Qmax(QMAX1);
    assert (f1.Qmax() == QMAX1); 
        
    std::cout   << "Imprimindo f1 modificado: \n" 
                << f1 
                << std::endl;
    
    
    
const Real                      CE(2.00e-01); 
const Real                      K1_QE(1432e-3);
const Real                      K2_QE(23.72);
const Real                      QMAX_QE(4.897e-1);
const ist::Khan                 var_SP(QMAX_QE, K1_QE, K2_QE);
const Real                      QEANALITICO(1.543297749);
const Real                      QeNumerico(f1.Qe(CE));
const Real                      DiffQe = fabs(QeNumerico - QEANALITICO) / QEANALITICO;
const Real                      DQMIN(1e-06);


   std::cout   << "\n\nImprimindo isoterma para o cálculo de Qe: \n" 
                << var_SP
                << std::endl;    
   
   
    std::cout   << "Qe = " 
                << std::scientific
                << std::setprecision(6) 
                << QeNumerico
                << " para C = "
                << std::fixed
                << CE
                << "  QAnalitico = "
                << std::scientific
                << QEANALITICO
                << std::endl;
    
    std::cout   << "Diferença = " 
                << std::scientific
                << std::setprecision(3)
                << 100.0 * DiffQe
                << " % "
                << std::fixed
                << "\n";
        
    //assert (DiffQe <= DQMIN);   
    
    

//==============================================================================
// imprimindo as informações sobre as constantes
//==============================================================================

    
    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Teste do acesso as informações sobre as constantes\n";
    PrintLine(std::cout);    

    assert (f1.NumberConst() == 3);  
    std::cout   << "Numero de constantes de f1: " 
                << f1.NumberConst() 
                << std::endl;

    std::cout << std::setfill(' ');
    std::cout << "Impressao de informações da isoterma\n"
              << std::setw(20)
              << std::left
              << "Parâmetro"
              << std::setw(40)
              << " Detalhe do parâmetro"
              << std::right
              << std::endl;
    
    for (auto x : f1) {
        std::cout   << std::setw(20)
                    << std::left
                    << x.first 
                    << std::setw(40)
                    << x.second
                    << std::right
                    << "\n";
    }
    
    
    
    
/*    
//==============================================================================
// Impressão dos resultados em um gráfico
//==============================================================================
    
const std::string FILENAME("Figuras/CasoK101.dat");
const Real          QG (1);
const Real          KG1 (0.1);
const Real          KG2 (2);

ist::Khan           graph(QG , KG1, KG2);  

const Real          CMIN(1e-3);
const Real          CMAX(10);
const UInt          NPTO(1001);

auto EixoX = [&](const Real& _qe, const Real&_ce) 
{ 
    return  log10(_ce);
};

auto EixoY = [&](const Real& _qe, const Real&_ce) 
{
auto auxi = _qe / (graph.Qmax() - _qe);    
    return log10(auxi);
    
};


    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Impressão dos gráficos\n";
    std::cout << "Isoterma para ser impressa: \n" << graph << "\n";
    PrintLine(std::cout);
    graph.PlotGraph (   FILENAME
                    ,   EixoX
                    ,   EixoY
                    ,   NPTO
                    ,   CMIN
                    ,   CMAX);
    
    PrintLine(std::cout);    
    std::cout << "\n";
    PrintLine(std::cout);    
 */   
    
//==============================================================================
// testes para dass exceções - para testar deve-se tirar os comentários abaixo
//==============================================================================

     return EXIT_SUCCESS; 

      
//==============================================================================
// testes para ver as exceções
//==============================================================================
 
    
    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Testes para ver o funcionamento das exceções\n";
    PrintLine(std::cout); 


const Real                      CE_Errado(3.16227766); 
const Real                      K1_Errado(0.4);
const Real                      K2_Errado(0.5);
const Real                      QMAX_Errado(0.7);

ist::Khan     f6 ( - QMAX_Errado,    K1_Errado,    K2_Errado);             
ist::Khan     f61(           0,    K1_Errado,    K2_Errado);              

ist::Khan     f7 (   QMAX_Errado,  - K1_Errado,    K2_Errado);             
ist::Khan     f71(   QMAX_Errado,            0,    K2_Errado);            

ist::Khan     f8 (   QMAX_Errado,    K1_Errado,  - K2_Errado);             
ist::Khan     f81(   QMAX_Errado,            K1_Errado,    1);              

    std::cout   << "Imprimindo Qe com C errada = " 
                << f1.Qe( - CE_Errado ) 
                << std::endl;                          
    
ist::Khan     f9;    
    
    std::cout   << "Imprimindo Qe sem coeficientes = " 
                << f9.Qe( CE ) 
                << std::endl;                           
   
    f1.Qmax(-QMAX1);                                    
    f1.Qmax(0);                                        

    f1.K1(-K11);                                        
    f1.K1(0);                                          
    
    f1.K2(-K22);                                       
    f1.K2(1);                                          

   return EXIT_FAILURE; 

}