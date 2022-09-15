////==============================================================================
//// Name        : TesteKiselev.cpp
//// Authors     : Iasmim Barboza Storck
////               Lara Botelho Brum
////               Luan Rodrigues Soares de Souza
////               Joao Flavio Vieira de Vasconcellos
//// Version     : 1.0
//// Description : Programa para testar a classe com as 
////               equações da isoterma de Hill-De Boer
////
//// Copyright   : Copyright (C) <2021>  Joao Flavio Vasconcellos 
////                                      (jflavio at iprj.uerj.br)
////
//// This program is free software: you can redistribute it and/or modify
//// it under the terms of the GNU General Public License as published by
//// the Free Software Foundation, either version 3 of the License.
////
//// This program is distributed in the hope that it will be useful,
//// but WITHOUT ANY WARRANTY; without even the implied warranty of
//// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//// GNU General Public License for more details.
////
//// You should have received a copy of the GNU General Public License
//// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////
////==============================================================================
//
//
////==============================================================================
//// include da lib c++ 
////==============================================================================
//
//#include <cmath>                        // std::fabs
//#include <iomanip>                      // std::setw, std::setprecision
//#include <iostream>                     // std::cout
//#include <cassert>                      // assert
//
////==============================================================================
//// include da isotherm
////==============================================================================
//#include <Misc/Misc.h>                                      // PrintLine
//#include <Isotherm/ThreeParameters/Kiselev.h>
//
//
//int main(int argc, char** argv) {
//    
////==============================================================================
//// Impressão do cabeçalho
////==============================================================================
//    
//    PrintLine(std::cout);    
//    std::cout << "Teste da classe Kiselev\n";
//    PrintLine(std::cout);    
//
////==============================================================================
//// testes com construtores e destrutora
////==============================================================================
//    
//    std::cout << "\n\n";
//    PrintLine(std::cout);    
//    std::cout << "Teste dos construtores\n";
//    PrintLine(std::cout);    
// 
//const Real          QMAX(10.0);    
//const Real          K1(1000.0); 
//const Real          K2(1.0);
//
//ist::Kiselev     f1;                 //Construtora default    
//    assert (f1.K1() == 0); 
//    assert (f1.K2() == 0); 
//    assert (f1.Qmax() == 0); 
//
//    std::cout << "\nImprimindo a variavel f1: " 
//              << f1 
//              << std::endl;
//    
//ist::Kiselev     f2( QMAX, K1, K2 );     // Construtora com 3 parâmetros; 
//    assert (f2.K1() == K1); 
//    assert (f2.K2() == K2); 
//    assert (f2.Qmax() == QMAX);
//    
//    std::cout << "\nImprimindo a variavel f2: " 
//              << f2 
//              << std::endl;
//
//ist::Kiselev     f3(f2);             // Construtoa de cópia
//    assert (f2.K1() == f3.K1()); 
//    assert (f2.K2() == f3.K2()); 
//    assert (f2.Qmax() == f3.Qmax());
//    
//    std::cout << "\nImprimindo a variavel f3: " 
//              << f3 
//              << std::endl;
//    
////==============================================================================
//// testes com sobrecarga de operadores
////==============================================================================
//
//    std::cout << "\n\n";
//    PrintLine(std::cout);    
//    std::cout << "Teste da sobrecarga de operadores\n";
//    PrintLine(std::cout);    
//    
//    f1 = f3;
//    assert (f1.K1() == f3.K1()); 
//    assert (f1.K2() == f3.K2()); 
//    assert (f1.Qmax() == f3.Qmax());
//    
//    std::cout << "\nImprimindo a variavel f1: " << f1 << std::endl;
//    
//const Real QMAX1 (778.0);
//const Real K11 (45.0);
//const Real K22 (1.5);
//
//ist::Kiselev     f4 = ist::Kiselev(QMAX1, K11, K22);
//    assert (f4.K1() == K11); 
//    assert (f4.K2() == K22); 
//    assert (f4.Qmax() == QMAX1);
//    
//
//    std::cout   << "\nImprimindo a variavel f4: "  
//                << f4 
//                << std::endl;
//    
////==============================================================================
//// testes do acesso as constantes da classe
////==============================================================================
//
//    
//    std::cout << "\n";
//    PrintLine(std::cout);    
//    std::cout << "Teste do acesso as constantes da classe\n";
//    PrintLine(std::cout);    
//    
//    
//    std::cout << f1
//              << "\n";
//    
//    std::cout   << "K1:\t" 
//                << std::setw(12)
//                << std::fixed
//                << f1.K1() 
//                << std::endl;
//    
//    std::cout   << "K2:\t" 
//                << std::setw(12)
//                << std::fixed
//                << f1.K2() 
//                << std::endl;
//    
//    std::cout << "QMAX:\t" 
//              << std::setw(12) 
//              << std::fixed
//              << f1.Qmax() 
//              << std::endl;
//        
//    std::cout   << "\nAlterando K1  e K2 separadamente\n";    
//    std::cout << "Imprimindo f1 modificado: \n" << f1 << std::endl;
//    
//    f1.K1(K11);
//    assert (f1.K1() == K11); 
//
//    f1.K2(K22);
//    assert (f1.K2() == K22); 
//    
//    f1.Qmax(QMAX1);
//    assert (f1.Qmax() == QMAX1); 
//    
//    std::cout   << "Imprimindo f1 modificado: \n" 
//                << f1 
//                << std::endl;
//   
//    
//const Real                      CE(1.6);
//const Real                      K1_QE(1432e-3);
//const Real                      K2_QE(23.72e-2);
//const Real                      QMAX_QE(4.897e-1);
//const ist::Kiselev           var_KL(QMAX_QE, K1_QE, K2_QE);
//const Real                      QEANALITICO(0.356892096);
//const Real                      QeNumerico(var_KL.Qe(CE));
//const Real                      DiffQe = fabs(QeNumerico - QEANALITICO) / QEANALITICO;
//const Real                      DQMIN(1e-06);
//
//
//       std::cout   << "\n\nImprimindo isoterma para o cálculo de Qe: \n" 
//                << var_KL
//                << std::endl; 
//       
//       
//    std::cout   << "Qe = " 
//                << std::scientific
//                << std::setprecision(6)
//                << QeNumerico
//                << " para C = "
//                << std::fixed
//                << CE
//                << "  QAnalitico = "
//                << std::scientific
//                << QEANALITICO
//                << std::fixed
//                << std::endl;
//    
//        std::cout   << "Diferença = " 
//                    << std::scientific
//                    << std::setprecision(3)
//                    << (100.0 * (QeNumerico - QEANALITICO) / QEANALITICO)
//                    << " % "
//                    << std::fixed
//                    << "\n";
//        
//        
//  assert (DiffQe <= DQMIN); 
//    
//    
//   
////==============================================================================
//// imprimindo as informações sobre as constantes
////==============================================================================
//
//    
//    std::cout << "\n";
//    PrintLine(std::cout);    
//    std::cout << "Teste do acesso as informações sobre as constantes\n";
//    PrintLine(std::cout);
//    
//    assert (f1.NumberConst() == 3);
//    std::cout   << "Numero de constantes de f1: " 
//                << f1.NumberConst() 
//                << std::endl;
//    
//    std::cout << std::setfill(' ');
//    std::cout << "Impressao de informações da isoterma\n"
//              << std::setw(20)
//              << std::left
//              << "Parâmetro"
//              << std::setw(40)
//              << " Detalhe do parâmetro"
//              << std::right
//              << std::endl;
//    
//    for (auto x : f1) {
//        std::cout   << std::setw(20)
//                    << std::left
//                    << x.first 
//                    << std::setw(40)
//                    << x.second
//                    << std::right
//                    << "\n";
//    }
//    
////==============================================================================
//// testes para dass exceções - para testar deve-se tirar os comentários abaixo
////==============================================================================
//
//     return EXIT_SUCCESS;     
//
//     
//     
////==============================================================================
//// testes para ver as exceções
////==============================================================================   
//    
//    std::cout << "\n";
//    PrintLine(std::cout);    
//    std::cout << "Testes para ver o funcionamento das exceções\n";
//    PrintLine(std::cout); 
//
//
//const Real                      CE_Errado(3.16227766); 
//const Real                      K1_Errado(0.4);
//const Real                      K2_Errado(0.5);
//const Real                      QMAX_Errado(0.7);
//ist::Kiselev     f6 ( - QMAX_Errado,    K1_Errado,    K2_Errado);            // Teste ok   
//ist::Kiselev     f61(           0,    K1_Errado,    K2_Errado);            // Teste ok  
//
//ist::Kiselev     f7 (   QMAX_Errado,  - K1_Errado,    K2_Errado);            // Teste ok   
//ist::Kiselev     f71(   QMAX_Errado,            0,    K2_Errado);            // Teste ok   
//
//ist::Kiselev     f8 (   QMAX_Errado,    K1_Errado,  - K2_Errado);            // Teste ok   
//
//    std::cout   << "Imprimindo Qe com C errada = " 
//                << f1.Qe( - CE_Errado ) 
//                << std::endl;                                // Teste ok
//    
//ist::Kiselev     f9;    
//    
//    std::cout   << "Imprimindo Qe sem coeficientes = " 
//                << f9.Qe( CE ) 
//                << std::endl;                           // Teste ok
//   
//    f1.Qmax(-QMAX1);                                    // Teste ok
//    f1.Qmax(0);                                         // Teste ok
//
//    f1.K1(-K11);                                        // Teste ok
//    f1.K1(0);                                           // Teste ok
//    
//    f1.K2(-K22);                                        // Teste ok
//
//   return EXIT_FAILURE; 
//
//}


//==============================================================================
// Name        : TesteKiselev.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe Kiselev
//
// Copyright   : Copyright (C) <2022>  Joao Flavio Vasconcellos 
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

#include <Isotherm/ThreeParameters/Kiselev.h>                 // ist::Kiselev


//==============================================================================
// include da googletest
//==============================================================================
#include <gtest/gtest.h>

typedef     ist::Kiselev TestIsotherm;

class TestSuit : public ::testing::Test {  
    
protected: 
    
const Real              QMAX        = 2.50;    
const Real              K1          = 0.77;   
const Real              K2          = 1.9;    
const Real              QMAXNovo    = 34.548;    
const Real              K1Novo      = 98.1e-03;    
const Real              K2Novo      = 3.3;    
const Real              CE          = 0.25;

public:
        
    TestIsotherm     isotherm_1;    
    TestIsotherm     isotherm_2 = TestIsotherm(QMAX, K1, K2);    
    TestIsotherm     isotherm_3 = TestIsotherm(isotherm_2);    

};  

TEST_F(TestSuit, ConstrutorDefault) {
 
    EXPECT_EQ(isotherm_1.Qmax(), 0);
    EXPECT_EQ(isotherm_1.K1(), 0);
    EXPECT_EQ(isotherm_1.K2(), 0);
    EXPECT_EQ(isotherm_1.NumberConst(), 3);
  
}

TEST_F(TestSuit, ConstrutorPadrao) {
    
  EXPECT_EQ(isotherm_2.Qmax(), QMAX);
  EXPECT_EQ(isotherm_2.K1(), K1);  
  EXPECT_EQ(isotherm_2.K2(), K2);  
  EXPECT_EQ(isotherm_2.NumberConst(), 3);

  isotherm_2.Qmax(QMAXNovo);
  isotherm_2.K1(K1Novo);
  isotherm_2.K2(K2Novo);

  EXPECT_EQ(isotherm_2.Qmax(), QMAXNovo);
  EXPECT_EQ(isotherm_2.K1(), K1Novo);
  EXPECT_EQ(isotherm_2.K2(), K2Novo);
  
  
}

TEST_F(TestSuit, ConstrutoraDeCopia) {

  EXPECT_EQ(isotherm_3.Qmax(), QMAX);
  EXPECT_EQ(isotherm_3.K1(), K1);  
  EXPECT_EQ(isotherm_3.K2(), K2);  
  EXPECT_EQ(isotherm_3.NumberConst(), 3);

  isotherm_3.Qmax(QMAXNovo);
  isotherm_3.K1(K1Novo);
  isotherm_3.K2(K2Novo);

  EXPECT_EQ(isotherm_3.Qmax(), QMAXNovo);
  EXPECT_EQ(isotherm_3.K1(), K1Novo);
  EXPECT_EQ(isotherm_3.K2(), K2Novo);
  
}


TEST_F(TestSuit, CalculoQe) {

    

const TestIsotherm              iso1 (QMAX, K1, K2);
const Real                      QEANALIT1(0.5320128142);


    EXPECT_FLOAT_EQ ( iso1.Qe(CE), QEANALIT1);

}

TEST_F(TestSuit, DeathTest) {
    
    EXPECT_DEATH(TestIsotherm(- QMAX ,  K1, K2);, ""); 
    EXPECT_DEATH(TestIsotherm(  QMAX ,  - K1, K2);, "");
    EXPECT_DEATH(TestIsotherm(  QMAX ,    K1, - K2);, "");
    EXPECT_DEATH(TestIsotherm(0.0 ,  K1, K2);, "");
    EXPECT_DEATH(TestIsotherm(QMAX ,  0.0, K2);, "");
    EXPECT_DEATH(TestIsotherm(QMAX ,  K1, 0.0);, "");
    
    EXPECT_DEATH(auto value = isotherm_2.Qe(- CE);, "");
    EXPECT_DEATH(isotherm_2.K1( - K1);, "");
    EXPECT_DEATH(isotherm_2.K1(  0.0);, "");
    EXPECT_DEATH(isotherm_2.Qmax(- QMAX);, "");
    EXPECT_DEATH(isotherm_2.Qmax(   0.0);, "");
    EXPECT_DEATH(isotherm_2.K2( - K2);, "");
    EXPECT_DEATH(isotherm_2.K2(  0.0);, "");

}

int main(int argc, char **argv)
{
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS(); 
}
