//==============================================================================
// Name        : TesteHillDeboer.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa para testar a classe com as 
//               equações da isoterma de Hill-De Boer
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
// include da isotherm
//==============================================================================

#include <Misc/Misc.h>                                      // PrintLine
#include <Isotherm/ThreeParameters/HillDeboer.h>

//==============================================================================
// include da lib c++ 
//==============================================================================

#include <cmath>                        // std::fabs
#include <iomanip>                      // std::setw, std::setprecision
#include <iostream>                     // std::cout
#include <cassert>                      // assert


int main(int argc, char** argv) {
    
//==============================================================================
// Impressão do cabeçalho
//==============================================================================
    
    PrintLine(std::cout);    
    std::cout << "Teste da classe Hill Deboer\n";
    PrintLine(std::cout);    

//==============================================================================
// testes com construtores e destrutora
//==============================================================================
    
    std::cout << "\n\n";
    PrintLine(std::cout);    
    std::cout << "Teste dos construtores\n";
    PrintLine(std::cout);    
 
const Real          QMAX(10.0);    
const Real          K1(1000.0); 
const Real          K2(1.0);
const Real          TEMPK(200.0);
const Real          NOVRG (4.157231309);

ist::HillDeboer     f1;                 //Construtora default    
    assert (f1.K1() == 0); 
    assert (f1.K2() == 0); 
    assert (f1.Qmax() == 0);
    assert (f1.Rgas() == 8.31446261815324); 

    std::cout << "\nImprimindo a variavel f1: " 
              << f1 
              << std::endl;
    
ist::HillDeboer     f2( QMAX, K1, K2 );     // Construtora com 3 parâmetros; 
    assert (f2.K1() == K1); 
    assert (f2.K2() == K2); 
    assert (f2.Qmax() == QMAX);
    
    std::cout << "\nImprimindo a variavel f2: " 
              << f2 
              << std::endl;

ist::HillDeboer     f2a( QMAX, K1, K2, NOVRG );     // Construtora modificando o valor de RGas
    assert (f2a.K1() == K1); 
    assert (f2a.K2() == K2); 
    assert (f2a.Qmax() == QMAX);
    assert (f2a.Rgas() == NOVRG);
    
    std::cout << "\nImprimindo a variavel f2a: " 
              << f2a 
              << std::endl;

ist::HillDeboer     f3(f2);             // Construtoa de cópia
    assert (f2.K1() == f3.K1()); 
    assert (f2.K2() == f3.K2()); 
    assert (f2.Qmax() == f3.Qmax());
    assert (f2.Rgas() == f3.Rgas()); 
    
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
    assert (f1.Rgas() == f3.Rgas()); 
    
    std::cout << "\nImprimindo a variavel f1: " << f1 << std::endl;
    
const Real QMAX1 (778.0);
const Real K11 (45.0);
const Real K22 (1.5);

ist::HillDeboer     f4 = ist::HillDeboer(QMAX1, K11, K22, NOVRG);
    assert (f4.K1() == K11); 
    assert (f4.K2() == K22); 
    assert (f4.Qmax() == QMAX1);
    assert (f4.Rgas() == NOVRG); 
    

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
    
    std::cout   << "K1:\t" 
                << std::setw(12)
                << std::fixed
                << f1.K1() 
                << std::endl;
    
    std::cout   << "K2:\t" 
                << std::setw(12)
                << std::fixed
                << f1.K2() 
                << std::endl;
    
    std::cout << "QMAX:\t" 
              << std::setw(12) 
              << std::fixed
              << f1.Qmax() 
              << std::endl;
    
    std::cout << "RGas:\t" 
              << std::setw(12) 
              << std::fixed
              << f1.Rgas() 
              << std::endl;
    
        
    std::cout   << "\nAlterando K1  e K2 separadamente\n";    
    std::cout << "Imprimindo f1 modificado: \n" << f1 << std::endl;
    
    f1.K1(K11);
    assert (f1.K1() == K11); 

    f1.K2(K22);
    assert (f1.K2() == K22); 
    
    f1.Qmax(QMAX1);
    assert (f1.Qmax() == QMAX1);
    
    f1.Rgas(2 * NOVRG);
    assert (f1.Rgas() == 2 * NOVRG); 
    
    std::cout   << "Imprimindo f1 modificado: \n" 
                << f1 
                << std::endl;
   
    
const Real                      CE(0.06037902449);
const Real                      K1_QE(1432e-3);
const Real                      K2_QE(23.72e-2);
const Real                      QMAX_QE(4.897e-1);
const ist::HillDeboer           var_SP(QMAX_QE, K1_QE, K2_QE);
const ist::HillDeboer           var_SP2(QMAX_QE, K1_QE, K2_QE, NOVRG);
const Real                      QEANALITICO(389.0);
const Real                      QeNumerico(f1.Qe(CE, TEMPK));
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
                << " para Temperatura = "
                << std::scientific
                << TEMPK
                << "  QAnalitico = "
                << std::scientific
                << QEANALITICO
                << std::fixed
                << std::endl;
    
        std::cout   << "Diferença = " 
                    << std::scientific
                    << std::setprecision(3)
                    << (100.0 * (QeNumerico - QEANALITICO) / QEANALITICO)
                    << " % "
                    << std::fixed
                    << "\n";
        
        
   assert (DiffQe <= DQMIN); 
    
    
   
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
    
    
//    
////==============================================================================
//// Impressão dos resultados em um gráfico
////==============================================================================
//    
//const std::string FILENAME("Figuras/Casok200.dat");
//const Real          QG (1);
//const Real          KG1 (1e-03);
//const Real          KG2 (1e-00);
//const Real          TEMPG(300);
//
//
//const ist::HillDeboer           graph(QG, KG1, KG2);
//
//const Real          CMIN(1e-3);
//const Real          CMAX(10);
//const UInt          NPTO(1001);
//
//auto EixoX = [&](const Real& _qe, const Real&_ce) 
//{ 
//    return  log(graph.K1() * _ce);
//};
//
//auto EixoY = [&](const Real& _qe, const Real&_ce) 
//{
//auto theta = _qe / graph.Qmax();
//auto auxi1 = theta / (1 - theta);
//auto auxi2 = graph.K2() * theta / (graph.RGas() * TEMPG);
//    return log(auxi1) + 0 * ( auxi1 - auxi2);
//    
//};
//
//
//    std::cout << "\n";
//    PrintLine(std::cout);    
//    std::cout << "Impressão dos gráficos\n";
//    std::cout << "Isoterma para ser impressa: \n" << graph << "\n";
//    PrintLine(std::cout);
//    graph.PlotGraph (   FILENAME
//                    ,   EixoX
//                    ,   EixoY
//                    ,   NPTO
//                    ,   CMIN
//                    ,   CMAX
//                    ,   TEMPG);
//    
//    PrintLine(std::cout);    
//    std::cout << "\n";
//    PrintLine(std::cout);    
    
    
    
    
    
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
    
ist::HillDeboer     f5(- QMAX1, K11, K22);    
ist::HillDeboer     f6( QMAX1, - K11, K22);    
ist::HillDeboer     f7( QMAX1,  K11, - K22);   


ist::HillDeboer     f8( QMAX1,  K11,  K22, - NOVRG);    

    std::cout << "Imprimindo Qe = " << f1.Qe(- CE,  TEMPK) << std::endl;
    std::cout << "Imprimindo Qe = " << f1.Qe( CE ) << std::endl;
    std::cout << "Imprimindo Qe = " << f1.Qe( CE, - TEMPK) << std::endl;
    
    
ist::HillDeboer     f9;
    std::cout << "Imprimindo Qe = " << f9.Qe( CE,  TEMPK) << std::endl;

   return EXIT_FAILURE; 
}

