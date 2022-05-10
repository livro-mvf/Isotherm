//==============================================================================
// Name        : TesteHarkinJura.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe HarkinJura
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
// include da isotherm
//==============================================================================

#include <Misc/Misc.h>                                     // PrintLine
#include <Isotherm/TwoParameters/HarkinJura.h>             // ist::HarkinJura            

int main(int _argc, char** _argv) {
    
//==============================================================================
// Impressão do cabeçalho
//==============================================================================
    
    PrintLine(std::cout);    
    std::cout << "Teste da classe Harkin-Jura\n";
    PrintLine(std::cout);    

//==============================================================================
// Testes com construtores e destrutora
//==============================================================================
    
    std::cout << "\n\n";
    PrintLine(std::cout);    
    std::cout << "Teste dos construtores\n";
    PrintLine(std::cout);    
 
const Real              K1(25.2);    
const Real              K2(0.7);          

ist::HarkinJura     f1;                    //  Construtora default 
    assert (f1.K1() == 0); 
    assert (f1.K2() == 0); 
    
    std::cout << "\nImprimindo a variavel f1: \n" 
              << f1 
              << std::endl;
    
ist::HarkinJura     f2(K1, K2);     // Construtora com 2 parâmetros;                     //Construtora default    
    assert (f2.K1() == K1); 
    assert (f2.K2() == K2); 

    std::cout << "Imprimindo a variavel f2: \n" 
              << f2 
              << std::endl;

ist::HarkinJura     f3(f2);             // Construtoa de cópia
    assert (f2.K1() == f3.K1()); 
    assert (f2.K2() == f3.K2()); 
 
    std::cout << "Imprimindo a variavel f3: \n" 
              << f3 
              << std::endl;
    
//==============================================================================
// testes com sobrecarga de operadores
//==============================================================================

    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Teste da sobrecarga de operadores\n";
    PrintLine(std::cout);    
    
    f1 = f3;
    assert (f1.K1() == f3.K1()); 
    assert (f1.K2() == f3.K2()); 
 
    std::cout   << "\nImprimindo a variavel f1: \n" 
                << f1 
                << std::endl;
    
const Real  K11 (34.548);
const Real  K22 (98.1e-03);

ist::HarkinJura     f4 = ist::HarkinJura(K11, K22);     
    assert (f4.K1() == K11); 
    assert (f4.K2() == K22);  
    
    std::cout   << "Imprimindo a variavel f4: \n"  
                << f4 
                << std::endl;
    
//==============================================================================
// testes do acesso as constantes da classe
//==============================================================================

    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Teste do acesso as constantes da classe\n";
    PrintLine(std::cout);    
    
    std::cout   <<  f1 
                << "\n";
    
    std::cout << "K1:\t" 
              << std::setw(12) 
              << std::fixed
              << f1.K2() 
              << std::endl;

    std::cout   << "K2:\t" 
                << std::setw(12)
                << std::fixed
                << f1.K2() 
                << std::endl;
    
    std::cout   << "\nAlterando K1  e K2 separadamente\n";
    std::cout   << "Imprimindo f1 antes da modificação: \n" 
                << f1 
                << std::endl;
    
    f1.K1(K11);
    assert (f1.K1() == K11); 
    
    f1.K2(K22);
    assert (f1.K2() == K22); 
    
    std::cout   << "Imprimindo f1 modificado: \n" 
                << f1 
                << std::endl;

    
const Real                      CE(1.60); 
const Real                      K1_QE(1432e-3);
const Real                      K2_QE(23.72e-2);
const ist::HarkinJura           var_HJ (K1_QE, K2_QE);
const Real                      QeNumer(var_HJ.Qe(CE));
const Real                      QEANALIT(6.57943567);
const Real                      DiffQe = fabs(QeNumer - QEANALIT) / QEANALIT;
const Real                      DQMIN(1e-06);


    std::cout   << "\n\nImprimindo isoterma para o cálculo de Qe: \n" 
                << var_HJ
                << std::endl;    
    
              
    std::cout   << "Qe = " 
                << std::scientific
                << std::setprecision(6)
                << QeNumer
                << " para C = "
                << std::fixed
                << CE
                << "  QAnalitico = "
                << std::scientific
                << QEANALIT
                << std::endl;
    

        std::cout   << "Diferença = " 
                    << std::setprecision(3)
                    << std::scientific
                    << 100.0 * DiffQe
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

    assert (f1.NumberConst() == 2);    
    std::cout   << "\nNumero de constantes de f1: " 
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

////==============================================================================
//// Impressão dos resultados em um gráfico
////==============================================================================
//    
//const std::string FILENAME("Figuras/CasoK1m4.dat");
//const Real          KG2 (1);
//const Real          KG1 (1e-4);
//
//ist::HarkinJura     graph(KG1 , KG2);  
//
//const Real          CMIN(1e-3);
//const Real          CMAX(1);
//const UInt          NPTO(1001);
//
//auto EixoX = [&](const Real& _qe, const Real&_ce) 
//{ 
//    return  log10(_ce);
//};
//
//auto EixoY = [&](const Real& _qe, const Real&_ce) 
//{
//    return 1. / (_qe * _qe);
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
//                    ,   CMAX);
//    
//    PrintLine(std::cout);    
//    std::cout << "\n";
//    PrintLine(std::cout);    
//

    
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


ist::HarkinJura     f6( - K1_Errado,    K2_Errado);            // Teste ok   
ist::HarkinJura     f61( 0,    K2_Errado);                     // Teste ok   
ist::HarkinJura     f7(   K1_Errado,  - K2_Errado);            // Teste ok   
    
    std::cout   << "Imprimindo Qe com C errada = " 
                << f1.Qe( - CE_Errado ) 
                << std::endl;                                // Teste ok
    
ist::HarkinJura     f9;    
    
    std::cout   << "Imprimindo Qe sem coeficientes = " 
                << f9.Qe( CE ) 
                << std::endl;                           // Teste ok
   
    f1.K1(-K11);                                        // Teste ok
    
    f1.K2(-K22);                                        // Teste ok

Real qe  = f1.Qe(CE_Errado);                             // Teste ok
Real qe1 = f1.Qe(-CE_Errado);                             // Teste ok
    
    return EXIT_FAILURE; 

}
