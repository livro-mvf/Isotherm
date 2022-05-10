
//==============================================================================
// Name        : TesteHenry.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
//               Iasmim Barboza Storck
// Version     : 1.0
// Description : Programa para testar as funcoes da classe Henry
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
// include da isotherm++
//==============================================================================

#include <Isotherm/OneParameter/Henry.h>            //  ist::Henry
#include <Misc/Misc.h>                              // PrintLine

//==============================================================================
// include da lib c++ 
//==============================================================================

#include <cassert>          // assert
#include <cmath>            // std::fabs
#include <iomanip>          // std::setw, std::setprecision
#include <iostream>         // std::cout

//==============================================================================
// Inicio do programa
//==============================================================================

int main(int argc, char** argv) {
    
//==============================================================================
// Impressão do cabeçalho
//==============================================================================
    
    PrintLine(std::cout);    
    std::cout << "Teste da classe Henry\n";
    PrintLine(std::cout);    

//==============================================================================
// testes com construtores e destrutora
//==============================================================================
    
    std::cout << "\n\n";
    PrintLine(std::cout);    
    std::cout << "Teste dos construtores\n";
    PrintLine(std::cout);    
 
const Real          K1(1.0);            // valor da constante do modelo

ist::Henry          f1;                 //Construtora default    
    assert (f1.K1() == 0.0); 
    std::cout << "\nImprimindo a variavel f1: \n" 
              << f1 
              << std::endl;

ist::Henry          f2(K1);            // Construtora com 1 parâmetro;                    
    assert (f2.K1() == K1); 
    std::cout << "\nImprimindo a variavel f2: \n" 
              << f2 
              << std::endl;

ist::Henry          f3(f2);             // Construtoa de cópia
    assert (f3.K1() == f2.K1()); 
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
    assert (f1.K1() == K1); 
    std::cout   << "\nImprimindo a variavel f1 = f3 modificada: \n" 
                << f1 
                << std::endl;

const Real      K11 (45.0);

ist::Henry      f4 = ist::Henry(K11);     
    assert (f4.K1() == K11); 
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
    
    
    std::cout   << "Original da " 
                << f1 
                << "\n";
    std::cout   << "Valor de K1 :    " 
                << std::setw(12)
                << std::fixed
                << f1.K1() 
                << std::endl;
    
    std::cout << "\nAlterando K1 para: " << K11 << "\n";
    f1.K1(K11);
    
    std::cout   << "Imprimindo valor modificado da " 
                << f1 
                << std::endl;
    
//==============================================================================
// Cálculo de Qe 
//==============================================================================

const Real          CE(2.00e-01); 
const Real          QEANALITICO(9.0);
const Real          K1_QE(45.0);
const ist::Henry    isoHenry(K1_QE);
const Real          QeNumerico(isoHenry.Qe(CE));
const Real          DQ = fabs(QeNumerico - QEANALITICO) / QEANALITICO;
const Real          DQMIN(1e-6);

    std::cout << "\nImprimindo isoterma para o cálculo de Qe: \n" 
              << isoHenry
              << std::endl;
    
    std::cout   << "\nResultado: Qe = " 
                << QeNumerico
                << " para C = "
                << CE
                << "  e QAnalitico = "
                << QEANALITICO
                << std::endl;
    
    std::cout   << "Diferença = " 
                << std::scientific
                << std::setprecision(3)
                << 100.0 * DQ
                << " % "
                << std::fixed
                << "\n";

    assert (DQ <= DQMIN);    
    
//==============================================================================
// Cálculo da derivada de Qe em relação a C
//==============================================================================
    
Real Errodqdc = isoHenry.DQDC((0)) -  isoHenry.K1();  

    assert (fabs(Errodqdc) <= DQMIN);    
    
    std::cout   << "Diferença entre a derivada numérica e analítica: "
                << std::scientific
                << std::setprecision(3)
                << Errodqdc
                << std::endl;
    
//==============================================================================
// imprimindo as informações sobre as constantes
//==============================================================================
    
    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Teste do acesso as informações sobre as constantes\n";
    PrintLine(std::cout);    

    std::cout   << "\nNumero de constantes de f1: " 
                << f1.NumberConst() 
                << std::endl;
    assert (f1.NumberConst() == 1);    

    
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
    std::cout << "Testes para ver o funcionamento das excessões\n";
    PrintLine(std::cout); 

ist::Henry      f6( - K11 );    // Erro pois o coeficiente deverá ser > 0
ist::Henry      f61( 0 );       // Erro pois o coeficiente deverá ser > 0

    std::cout   << "Alterando o K1 de forma errada\n"; 
    f1.K1(- K11);      
    f1.K1(0);      
    
    std::cout   << "Imprimindo Qe com C errada = " 
                << f1.Qe( - CE ) 
                << std::endl;
    
ist::Henry      f7;
    
    std::cout   << "Calculando Qe sem coeficientes definidos \n" 
                << f7.Qe(CE) 
                << std::endl;
          
    return EXIT_SUCCESS;
    
}



