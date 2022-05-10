//==============================================================================
// Name        : TesteFreundlich.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos  
// Version     : 1.0
// Description : Programa para testar as funções da classe Freundlich
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

#include <cassert>          // assert
#include <cmath>            // fabs
#include <iomanip>          // std::setw
#include <iostream>         // std::cout


//==============================================================================
// include da isotherm++
//==============================================================================

#include <Misc/Misc.h>                                      // PrintLine
#include <Isotherm/TwoParameters/Freundlich.h>              // ist::Freundlich
    
int main(int argc, char** argv) {
    
//==============================================================================
// Impressão do cabeçalho
//==============================================================================
    
    PrintLine(std::cout);    
    std::cout << "Teste da classe Freundlich \n"; 
    PrintLine(std::cout);    

//==============================================================================
// testes com construtores e destrutora
//==============================================================================
    
    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Teste dos construtores\n";
    PrintLine(std::cout);    
 
const Real          K1(25.2);    
const Real          K2(10);    

ist::Freundlich     f1;                 //Construtora default    
    assert (f1.K1() == 0); 
    assert (f1.K2() == 0); 
    std::cout << "\nImprimindo a variavel f1: \n" 
              << f1 
              << std::endl;
    
ist::Freundlich     f2( K1, K2 );     // Construtora com 2 parâmetros; 
    assert (f2.K1() == K1); 
    assert (f2.K2() == K2); 
    std::cout << "\nImprimindo a variavel f2: \n" 
              << f2 
              << std::endl;


ist::Freundlich     f3(f2);             // Construtoa de cópia
    assert (f2.K1() == f3.K1()); 
    assert (f2.K2() == f3.K2()); 
    std::cout << "\nImprimindo a variavel f3: \n" 
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
    
const Real K11 (45.0);
const Real K22 (12.5);
ist::Freundlich     f4 = ist::Freundlich(K11, K22);     
    assert (f4.K1() == K11); 
    assert (f4.K2() == K22); 
    std::cout   << "\nImprimindo a variavel f4: \n"  
                << f4 
                << std::endl;
    
//==============================================================================
// testes do acesso as constantes da classe
//==============================================================================

    
    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Teste do acesso as constantes da classe\n";
    PrintLine(std::cout);    
    std::cout << "\n";
    
    std::cout   <<  f1 
                << "\n";

    std::cout   << "K1: \t" 
                << std::setw(12)
                << std::fixed
                << f1.K1() 
                << std::endl;
    
    std::cout << "K2: \t" 
              << std::setw(12) 
              << std::fixed
              << f1.K2() 
              << std::endl;
    
    std::cout   << "\nAlterando K1  e K2 separadamente \n";
    std::cout   << "Imprimindo f1 antes da modificação: \n" 
                << f1 
                << std::endl;
    
    f1.K2(K22);
    assert (f1.K2() == K22); 
    
    f1.K1(K11);
    assert (f1.K1() == K11); 

    std::cout   << "Imprimindo f1 modificado: \n" 
                << f1 
                << std::endl;

const Real                      CE(0.172); 
const Real                      K1_QE(2.31);
const Real                      K2_QE(0.8876);
const ist::Freundlich           isoFreundlich (K1_QE, K2_QE);
const Real                      QeNumer(isoFreundlich.Qe(CE));
const Real                      QEANALIT(0.3179308179);
const Real                      DiffQe = fabs(QeNumer - QEANALIT) / QEANALIT;
const Real                      DQMIN(1e-6);

    
    std::cout   << "\n\nImprimindo isoterma para o cálculo de Qe: \n" 
                << isoFreundlich
                << std::endl;    
    
              
    std::cout   << "Qe = " 
                << std::scientific
                << std::setprecision(6)
                << QeNumer
                << " para C = "
                << std::fixed
                << CE
                << "  QeAnalitico = "
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
    
    
//==============================================================================
// testes para das exceções 
//==============================================================================

    return EXIT_SUCCESS;                // Para testar as exceções do código coloque um comentário neste return   
    
//==============================================================================
// inicio dos testes para das exceções 
//==============================================================================    

    std::cout << "\n\n";
    PrintLine(std::cout);    
    std::cout << "Testes para ver o funcionamento das exceções\n";
    PrintLine(std::cout);     
      
ist::Freundlich     f5(- K1, K2);    
ist::Freundlich     f51(0, K2);    

ist::Freundlich     f6( K1, - K2);    
ist::Freundlich     f61( K1, 0);    

    std::cout   << "Imprimindo Qe = " 
                << f1.Qe(- CE) 
                << std::endl;

    
ist::Freundlich     f7;

    std::cout   << "Imprimindo Qe sem definir os coeficientes: \n" 
                << f7.Qe( CE ) 
                << std::endl;    

    f1.K1(-K1);            
    f1.K1(0);            
    
    
    f1.K2(-K2);            
    f1.K2(0);            
    
    return EXIT_FAILURE;
        
}

