//==============================================================================
// Name        : TesteLangmuir.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe Langmuir
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
#include <Isotherm/TwoParameters/Langmuir.h>               // ist::Langmuir


int main(int _argc, char** _argv) {
    
    
//==============================================================================
// Impressão do cabeçalho
//==============================================================================
    
    PrintLine(std::cout);    
    std::cout << "Teste da classe Langmuir\n";
    PrintLine(std::cout);    

//==============================================================================
// Testes com construtores e destrutora
//==============================================================================
    
    std::cout << "\n\n";
    PrintLine(std::cout);    
    std::cout << "Teste dos construtores\n";
    PrintLine(std::cout);    
 
const Real              QMAX(25.2);    
const Real              K1(0.7);    


ist::Langmuir     f1;                    //  Construtora default 
    assert (f1.Qmax() == 0 ); 
    assert (f1.K1() == 0); 
    std::cout << "\nImprimindo a variavel f1: \n" 
              << f1 
              << std::endl;
    
ist::Langmuir     f2( QMAX, K1 );     // Construtora com 2 parâmetros;                     //Construtora default    
    assert (f2.Qmax() == QMAX); 
    assert (f2.K1() == K1); 
 
    std::cout << "Imprimindo a variavel f2: \n" 
              << f2 
              << std::endl;

ist::Langmuir     f3(f2);             // Construtoa de cópia
    assert (f2.Qmax() == f3.Qmax()); 
    assert (f2.K1() == f3.K1()); 

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
    assert (f1.Qmax() == f3.Qmax()); 
    assert (f1.K1() == f3.K1()); 
   
    std::cout   << "\nImprimindo a variavel f1: \n" 
                << f1 
                << std::endl;
    
const Real  QMAX1 (34.548);
const Real  K11 (98.1e-03);

ist::Langmuir     f4 = ist::Langmuir(QMAX1, K11);     
    assert (f4.Qmax() == QMAX1); 
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
    
    std::cout   <<  f1 
                << "\n";
    
    std::cout << "Qmax:\t" 
              << std::setw(12) 
              << std::fixed
              << f1.Qmax() 
              << std::endl;

    std::cout   << "K1:\t" 
                << std::setw(12)
                << std::fixed
                << f1.K1() 
                << std::endl;
    
    
    std::cout   << "\nAlterando Qmax  e K1 separadamente\n";
    std::cout   << "Imprimindo f1 antes da modificação: \n" 
                << f1 
                << std::endl;
    
    f1.Qmax(QMAX1);
    assert (f1.Qmax() == QMAX1); 
    
    f1.K1(K11);
    assert (f1.K1() == K11); 
    
    
    std::cout   << "Imprimindo f1 modificado: \n" 
                << f1 
                << std::endl;

    
const Real                      CE(76.43e-3); 
const Real                      QMAX_QE(1432e-3);
const Real                      K1_QE(23.72e-4);
const ist::Langmuir             varLang (QMAX_QE, K1_QE);
const Real                      QeNumer(varLang.Qe(CE));
const Real                      QEANALIT(0.00025956303);
const Real                      DiffQe1 = fabs(QeNumer - QEANALIT) / QEANALIT;
const Real                      DQMIN(1e-6);

    std::cout   << "\n\nImprimindo isoterma para o cálculo de Qe: \n" 
                << varLang
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
                    << 100.0 * DiffQe1
                    << " % "
                    << std::fixed
                    << "\n";
        
        
    assert (DiffQe1 <= DQMIN);    

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
// Impressão dos resultados em um gráfico
//==============================================================================
    
//const std::string FILENAME("Figuras/CasoQm0001.dat");
//const Real          QG (0.01);
//const Real          KG1 (1);
//
//ist::Langmuir       graph(QG , KG1);  
//
//const Real          CMIN(1e-3);
//const Real          CMAX(10);
//const UInt          NPTO(1001);
//
//auto EixoX = [&](const Real& _qe, const Real&_ce) 
//{ 
//    return  log10(_ce);
//};
//
//auto EixoY = [&](const Real& _qe, const Real&_ce) 
//{
//    return log10(_ce / _qe);
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



ist::Langmuir     f6( - QMAX1 ,  K11);    //Teste OK!
ist::Langmuir     f60( 0 ,  K11);    //Teste OK!  

ist::Langmuir     f7(  QMAX1 ,  - K11);    //Teste OK!
ist::Langmuir     f70(  QMAX1 ,  0);    
  
    
    std::cout   << "Imprimindo Qe com C errada = " 
                << f1.Qe( - CE ) 
                << std::endl;    //Teste OK!
    
 
ist::Langmuir     f9;    
    
    std::cout   << "Imprimindo Qe sem coeficientes = " 
                << f9.Qe( CE ) 
                << std::endl;    //Teste OK!
   
    std::cout   << "Teste para entrar com parametros errados\n";
    
    f1.K1(-K11);    //Teste OK!
    f1.K1(0);    //Teste OK!
    
    f1.Qmax(-QMAX1);    //Teste OK!
    f1.Qmax(0);    //Teste OK!
    
    
    return EXIT_FAILURE; 

}
