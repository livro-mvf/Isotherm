//==============================================================================
// Name        : TesteTemkin.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe Temkin
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

#include <Misc/Misc.h>                             // PrintLine
#include <Isotherm/TwoParameters/Temkin.h>         //ist::Temkin


int main(int _argc, char** _argv) {
    
//==============================================================================
// Impressão do cabeçalho
//==============================================================================
    
    PrintLine(std::cout);    
    std::cout << "Teste da classe Temkin\n";
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

ist::Temkin     f1;                    //  Construtora default 
    assert (f1.K1() == 0 ); 
    assert (f1.K2() == 0); 
    assert (f1.Rgas() == 8.31446261815324); 
    std::cout << "\nImprimindo a variavel f1: \n" 
              << f1 
              << std::endl;
    
const Real  RGASNovo(0.5 * f1.Rgas());
ist::Temkin     f2( K1, K2, RGASNovo );     // Construtora com 2 parâmetros;                     //Construtora default    
    assert (f2.K1() == K1); 
    assert (f2.K2() == K2); 
    assert (f2.Rgas() == RGASNovo); 
    std::cout << "Imprimindo a variavel f2: \n" 
              << f2 
              << std::endl;

ist::Temkin     f3(f2);             // Construtoa de cópia
    assert (f2.K1() == f3.K1()); 
    assert (f2.K2() == f3.K2()); 
    assert (f2.Rgas() == f3.Rgas()); 
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
    assert (f1.Rgas() == f3.Rgas()); 
    std::cout   << "\nImprimindo a variavel f1: \n" 
                << f1 
                << std::endl;
    
const Real  K11 (34.548);
const Real  K22 (98.1e-03);

ist::Temkin     f4 = ist::Temkin(K11, K22, RGASNovo);     
    assert (f4.K1() == K11); 
    assert (f4.K2() == K22); 
    assert (f4.Rgas() == RGASNovo); 
    
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
              << f1.K1() 
              << std::endl;

    std::cout   << "K2:\t" 
                << std::setw(12)
                << std::fixed
                << f1.K2() 
                << std::endl;
    
    std::cout << "RGas:\t" 
              << std::setw(12) 
              << std::fixed
              << f1.Rgas() 
              << std::endl;
    
    
    std::cout   << "\nAlterando K1 e K2 separadamente\n";
    std::cout   << "Imprimindo f1 antes da modificação: \n" 
                << f1 
                << std::endl;
    
    f1.K1(K11);
    assert (f1.K1() == K11); 
    
    f1.K2(K22);
    assert (f1.K2() == K22); 
    
    f1.Rgas(2 * RGASNovo);
    assert (f1.Rgas() == 2 * RGASNovo); 
    
    std::cout   << "Imprimindo f1 modificado: \n" 
                << f1 
                << std::endl;

//==============================================================================
// Calculo de Qe
//==============================================================================
    
const Real                      TEMP(132.0);
const Real                      CE(76.43e-2); 
const Real                      K1_QE(1432e-3);
const Real                      K2_QE(23.72e-2);
const ist::Temkin               isoTemk01 (K1_QE, K2_QE);
const ist::Temkin               isoTemk02 (2 * K1_QE, 2 * K2_QE, RGASNovo);
const Real                      QeNumer1(isoTemk01.Qe(CE, TEMP));
const Real                      QeNumer2(isoTemk02.Qe(CE, TEMP));
const Real                      QEANALIT1(417.7066379);
const Real                      QEANALIT2(906.2134579);
const Real                      DiffQe1 = fabs(QeNumer1 - QEANALIT1) / QEANALIT1;
const Real                      DiffQe2 = fabs(QeNumer2 - QEANALIT2) / QEANALIT2;
const Real                      DQMIN(1e-6);


    std::cout   << "\n\nImprimindo isoterma para o cálculo de Qe: \n" 
                << isoTemk01
                << std::endl;    
    
              
    std::cout   << "Qe1 = " 
                << std::scientific
                << std::setprecision(6)
                << QeNumer1
                << " para C = "
                << std::fixed
                << CE
                << "  QAnalitico1 = "
                << std::scientific
                << QEANALIT1
                << std::endl;
    

        std::cout   << "Diferença = " 
                    << std::setprecision(6)
                    << std::scientific
                    << 100.0 * DiffQe1
                    << " % "
                    << std::fixed
                    << "\n";
        
        
     assert (DiffQe1 <= DQMIN);    
    
    std::cout   << "Qe2 = " 
                << std::setprecision(3)
                << std::scientific
                << QeNumer2
                << " para C = "
                << std::fixed
                << CE
                << "  QAnalitico2 = "
                << std::scientific
                << QEANALIT2
                << std::endl;
    

        std::cout   << "Imprimindo Diferença = " 
                    << std::scientific
                    << std::setprecision(6)
                    << 100.0 * DiffQe2
                    << " % "
                    << std::fixed
                    << "\n";
        
        assert (DiffQe2 <= DQMIN);    


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
    
    
//
////==============================================================================
//// Impressão dos resultados em um gráfico
////==============================================================================
//    
//const Real          TEMPG(1);  
//const Real          KG1 (1e+00);
//const Real          KG2 (1);
//ist::Temkin         graph(KG1 , KG2, 1);  
//
//const Real          CMIN(1e-10);
//const Real          CMAX(100);
//const UInt          NPTO(3001);
//
////const std::string FILENAME("Figuras/CasoK100.dat");
//
////    graph.PlotGraph(NPTO, CMIN, CMAX, FILENAME, TEMPG);
//    

    
//==============================================================================
// testes para das exceções - para testar deve-se tirar os comentários abaixo
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


ist::Temkin     f6( - K1_Errado,    K2_Errado);            // Teste ok   
ist::Temkin     f61(          0,    K2_Errado);            // Teste ok   
ist::Temkin     f7(   K1_Errado,  - K2_Errado);            // Teste ok   
ist::Temkin     f71(   K1_Errado,  0);            // Teste ok   
    
    std::cout   << "Imprimindo Qe com C errada = " 
                << f1.Qe( - CE_Errado, TEMP) 
                << std::endl;                                // Teste ok
    
ist::Temkin     f9;    
    
    std::cout   << "Imprimindo Qe sem coeficientes = " 
                << f9.Qe( CE, TEMP ) 
                << std::endl;                           // Teste ok
   
    f1.K1(-K11);                                        // Teste ok
    
    f1.K2(-K22);                                        // Teste ok

Real qe = f1.Qe(CE_Errado, TEMP);                       // Teste ok
  
Real K1_errado(0.1);
Real K2_errado(0.2);
Real CE_errado(0.1);

ist::Temkin f10(K1_errado, K1_errado);
Real q_e = f10.Qe(CE_errado,TEMP);

std::cout<<"Q_e = "<<q_e<<std::endl; //Teste Ok
    return EXIT_SUCCESS; 

}
