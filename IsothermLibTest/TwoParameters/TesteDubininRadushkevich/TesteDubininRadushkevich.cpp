//==============================================================================
// Name        : TesteDubininRadushkevich.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe DubininRadushkevich
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

#include <Isotherm/TwoParameters/DubininRadushkevich.h>     // ist::DubininRadushkevich

//==============================================================================
// include da googletest
//==============================================================================
#include <gtest/gtest.h>

typedef     ist::DubininRadushkevich TestIsotherm;

class TestSuit : public ::testing::Test {  
    
protected: 
    
const Real              QMAX        = 25.2;    
const Real              K1          = 0.7;    
const Real              RGASNovo    = 4.157231309;      
const Real              QMAXNovo    = 34.548;    
const Real              K1Novo      = 98.1e-03;    
const Real              TEMP        = 132.0;
const Real              CE          = 76.43e-3; 


public:
        
    TestIsotherm     isotherm_1;    
    TestIsotherm     isotherm_2 = TestIsotherm(QMAX, K1, RGASNovo);    
    TestIsotherm     isotherm_3 = TestIsotherm(isotherm_2);    

};  

TEST_F(TestSuit, ConstrutorDefault) {
 
    EXPECT_EQ(isotherm_1.Qmax(), 0);
    EXPECT_EQ(isotherm_1.K1(), 0);
    EXPECT_EQ(isotherm_1.Rgas(), 8.31446261815324);
    EXPECT_EQ(isotherm_1.NumberConst(), 2);
    EXPECT_DEATH(auto value = isotherm_1.Qe(CE, TEMP);, "");
  
}

TEST_F(TestSuit, ConstrutorPadrao) {
    
  EXPECT_EQ(isotherm_2.Rgas(), RGASNovo);
  EXPECT_EQ(isotherm_2.Qmax(), QMAX);
  EXPECT_EQ(isotherm_2.K1(), K1);  
  EXPECT_EQ(isotherm_2.NumberConst(), 2);

  isotherm_2.Rgas(2 * RGASNovo);
  isotherm_2.Qmax(QMAXNovo);
  isotherm_2.K1(K1Novo);

  EXPECT_EQ(isotherm_2.Qmax(), QMAXNovo);
  EXPECT_EQ(isotherm_2.K1(), K1Novo);
  EXPECT_EQ(isotherm_2.Rgas(), 2 * RGASNovo);
}

TEST_F(TestSuit, ConstrutoraDeCopia) {

  EXPECT_EQ(isotherm_3.Rgas(), RGASNovo);
  EXPECT_EQ(isotherm_3.Qmax(), QMAX);
  EXPECT_EQ(isotherm_3.K1(), K1);
  EXPECT_EQ(isotherm_3.NumberConst(), 2);

  isotherm_3.Qmax(QMAXNovo);
  isotherm_3.K1(K1Novo);

  EXPECT_EQ(isotherm_3.Qmax(), QMAXNovo);
  EXPECT_EQ(isotherm_3.K1(), K1Novo);
  EXPECT_EQ(isotherm_3.Rgas(), RGASNovo);
  
}


TEST_F(TestSuit, CalculoQe) {

    

const Real                      QMAX_QE(1432e-3);
const Real                      K1_QE(23.72e-8);

const TestIsotherm              iso1 (QMAX_QE, K1_QE);
const TestIsotherm              iso2 (QMAX_QE, K1_QE, RGASNovo);


const Real                      QEANALIT1(0.1940124818);
const Real                      QEANALIT2(0.8687897360);


    EXPECT_FLOAT_EQ ( iso1.Qe(CE, TEMP), QEANALIT1);
    EXPECT_FLOAT_EQ ( iso2.Qe(CE, TEMP), QEANALIT2);

}

TEST_F(TestSuit, DeathTest) {
    
    EXPECT_DEATH(TestIsotherm(- QMAX ,  K1);, ""); 
    EXPECT_DEATH(TestIsotherm(- QMAX ,  K1);, "");
    EXPECT_DEATH(TestIsotherm(  QMAX ,  - K1);, "");
    EXPECT_DEATH(TestIsotherm(0.0 ,  K1);, "");
    EXPECT_DEATH(TestIsotherm(QMAX ,  0.0);, "");
    EXPECT_DEATH(TestIsotherm(  QMAX ,  K1, - RGASNovo);, "");
    EXPECT_DEATH(TestIsotherm(  QMAX ,   K1, 0.0);, "");
    
    EXPECT_DEATH(auto value = isotherm_2.Qe(- CE,   TEMP);, "");
    EXPECT_DEATH(auto value = isotherm_2.Qe(  CE, - TEMP);, "");
    EXPECT_DEATH(auto value = isotherm_2.Qe( 0.0,   TEMP);, "");
    EXPECT_DEATH(auto value = isotherm_2.Qe(  CE,    0.0);, "");
    EXPECT_DEATH(isotherm_2.K1( - K1);, "");
    EXPECT_DEATH(isotherm_2.K1(  0.0);, "");
    EXPECT_DEATH(isotherm_2.Qmax(- QMAX);, "");
    EXPECT_DEATH(isotherm_2.Qmax(   0.0);, "");
    EXPECT_DEATH(isotherm_2.Rgas(- RGASNovo);, "");
    EXPECT_DEATH(isotherm_2.Rgas(       0.0);, "");

}

int main(int argc, char **argv)
{
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS(); 
}
