//==============================================================================
// Name        : TesteKhan.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe Khan
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

#include <Isotherm/ThreeParameters/Khan.h>                 // ist::Khan


//==============================================================================
// include da googletest
//==============================================================================
#include <gtest/gtest.h>

typedef     ist::Khan TestIsotherm;

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
    EXPECT_DEATH(TestIsotherm(QMAX , K1, 0.9);, ""); 
  
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
const Real                      QEANALIT1(0.3444290755);


    EXPECT_FLOAT_EQ ( iso1.Qe(CE), QEANALIT1);

}

TEST_F(TestSuit, DeathTest) {
    
    EXPECT_DEATH(TestIsotherm(- QMAX ,  K1, K2);, ""); 
    EXPECT_DEATH(TestIsotherm(  QMAX ,  - K1, K2);, "");
    EXPECT_DEATH(TestIsotherm(  QMAX ,    K1, - K2);, "");
    EXPECT_DEATH(TestIsotherm(0.0 ,  K1, K2);, "");
    EXPECT_DEATH(TestIsotherm(QMAX ,  0.0, K2);, "");
    EXPECT_DEATH(TestIsotherm(QMAX ,  K1, 0.9);, "");
    
    EXPECT_DEATH(auto value = isotherm_2.Qe(- CE);, "");
    EXPECT_DEATH(isotherm_2.K1( - K1);, "");
    EXPECT_DEATH(isotherm_2.K1(  0.0);, "");
    EXPECT_DEATH(isotherm_2.Qmax(- QMAX);, "");
    EXPECT_DEATH(isotherm_2.Qmax(   0.0);, "");
    EXPECT_DEATH(isotherm_2.K2( - K2);, "");
    EXPECT_DEATH(isotherm_2.K2(  0.9);, "");

}

int main(int argc, char **argv)
{
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS(); 
}
