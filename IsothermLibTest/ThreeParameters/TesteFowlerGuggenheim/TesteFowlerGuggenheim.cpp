//==============================================================================
// Name        : TesteFowlerGuggenheim.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe FowlerGuggenheim
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

#include <Isotherm/ThreeParameters/FowlerGuggenheim.h>                 // ist::FowlerGuggenheim

//==============================================================================
// include da googletest
//==============================================================================
#include <gtest/gtest.h>


typedef     ist::FowlerGuggenheim TestIsotherm;


class TestSuit : public ::testing::Test {  
    
protected: 
    
const Real              QMAX        = 4.897e-1;    
const Real              K1          = 1432e-3;    
const Real              K2          = 23.72e-2;    
const Real              QMAXNovo    = 2 * QMAX;    
const Real              K1Novo      = 3 * K1;    
const Real              K2Novo      = 4 * K2;    
const Real              CE          = 1.6000; 
const Real              TEMP        = 200.0;


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
    EXPECT_EQ (isotherm_1.Rgas(), 8.31446261815324);
    EXPECT_DEATH(auto value = isotherm_1.Qe(CE);, "");
    
}

TEST_F(TestSuit, ConstrutorPadrao) {
    
    EXPECT_EQ(isotherm_2.Qmax(), QMAX);
    EXPECT_EQ(isotherm_2.K1(), K1);  
    EXPECT_EQ(isotherm_2.K2(), K2);  
    EXPECT_EQ (isotherm_2.Rgas(), 8.31446261815324);
    EXPECT_EQ(isotherm_2.NumberConst(), 3);
  

    isotherm_2.Rgas(0.5 * isotherm_1.Rgas());
    isotherm_2.Qmax(QMAXNovo);
    isotherm_2.K1(K1Novo);
    isotherm_2.K2(K2Novo);

    EXPECT_EQ(isotherm_2.Qmax(), QMAXNovo);
    EXPECT_EQ(isotherm_2.K1(), K1Novo);
    EXPECT_EQ(isotherm_2.K2(), K2Novo);
    EXPECT_EQ (isotherm_2.Rgas(), 0.5 * isotherm_1.Rgas());
  
  
}

TEST_F(TestSuit, ConstrutoraDeCopia) {

    isotherm_3.Rgas(0.5 * isotherm_2.Rgas());
    
    EXPECT_EQ(isotherm_3.Qmax(), QMAX);
    EXPECT_EQ(isotherm_3.Rgas(), 0.5 * isotherm_2.Rgas());
        
    EXPECT_EQ(isotherm_3.K1(), K1);  
    EXPECT_EQ(isotherm_3.K2(), K2);  
    EXPECT_EQ(isotherm_3.NumberConst(), 3);
    EXPECT_EQ(isotherm_3.Rgas(),  0.5 * isotherm_2.Rgas());  

    isotherm_3.Qmax(QMAXNovo);
    isotherm_3.K1(K1Novo);
    isotherm_3.K2(K2Novo);
    isotherm_3.Rgas(2 * isotherm_2.Rgas( ));

    EXPECT_EQ(isotherm_3.Qmax(), QMAXNovo);
    EXPECT_EQ(isotherm_3.K1(), K1Novo);
    EXPECT_EQ(isotherm_3.K2(), K2Novo);
    EXPECT_EQ(isotherm_3.Rgas(), 2 * isotherm_2.Rgas());
  
}


TEST_F(TestSuit, CalculoQe) {

    

const TestIsotherm              iso1 (QMAX, K1, K2);


const Real                      QEANALIT1(0.340898999);

    EXPECT_FLOAT_EQ (iso1.Qe(CE, TEMP), QEANALIT1);

}

TEST_F(TestSuit, DeathTest) {
    
    EXPECT_DEATH(TestIsotherm(- QMAX ,    K1,   K2);, ""); 
    EXPECT_DEATH(TestIsotherm(  QMAX ,  - K1,   K2);, "");
    EXPECT_DEATH(TestIsotherm(  QMAX ,    K1, - K2);, "");
//    EXPECT_DEATH(TestIsotherm(   0.0 ,    K1,   K2);, "");
//    EXPECT_DEATH(TestIsotherm(  QMAX ,   0.0,   K2);, "");
//    EXPECT_DEATH(TestIsotherm(  QMAX ,    K1,  0.0);, "");
    
    EXPECT_DEATH(auto value = isotherm_2.Qe(- CE, TEMP);, "");
    EXPECT_DEATH(auto value = isotherm_2.Qe(  CE, - TEMP);, "");
    EXPECT_DEATH(isotherm_2.K1( - K1);, "");
//    EXPECT_DEATH(isotherm_2.K1(  0.0);, "");
    EXPECT_DEATH(isotherm_2.Qmax(- QMAX);, "");
//    EXPECT_DEATH(isotherm_2.Qmax(   0.0);, "");
    EXPECT_DEATH(isotherm_2.K2( - K2);, "");
//    EXPECT_DEATH(isotherm_2.K2(  0.0);, "");
    EXPECT_DEATH(isotherm_2.Rgas( - K2);, "");
//    EXPECT_DEATH(isotherm_2.Rgas(  0.0);, "");

}

int main(int argc, char **argv)
{
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS(); 
}
