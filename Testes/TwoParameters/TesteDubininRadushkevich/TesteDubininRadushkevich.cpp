//==============================================================================
// Name        : TesteDubininRadushkevich.cpp
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Programa de teste da classe DubininRadushkevich
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
// include da isotherm++
//==============================================================================

#include <Misc/Misc.h>                                      // PrintLine
#include <Isotherm/TwoParameters/DubininRadushkevich.h>     // ist::DubininRadushkevich


int main()
{
    
//==============================================================================
// Impressão do cabeçalho
//==============================================================================
    
    PrintLine(std::cout);    
    std::cout << "Teste da classe Dubinin-Radushkevich\n";
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
const Real              RGASNovo(4.157231309);      

ist::DubininRadushkevich     f1;                    //  Construtora default 
    assert (f1.Qmax() == 0 ); 
    assert (f1.K1() == 0); 
    assert (f1.Rgas() == 8.31446261815324); 
    std::cout << "\nImprimindo a variavel f1: \n" 
              << f1 
              << std::endl;
    
ist::DubininRadushkevich     f2( QMAX, K1, RGASNovo );     // Construtora com 2 parâmetros;                     //Construtora default    
    assert (f2.Qmax() == QMAX); 
    assert (f2.K1() == K1); 
    assert (f2.Rgas() == RGASNovo); 
    std::cout << "Imprimindo a variavel f2: \n" 
              << f2 
              << std::endl;

const ist::DubininRadushkevich&     f3(f2);             // Construtoa de cópia
    assert (f2.Qmax() == f3.Qmax()); 
    assert (f2.K1() == f3.K1()); 
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
    assert (f1.Qmax() == f3.Qmax()); 
    assert (f1.K1() == f3.K1()); 
    assert (f1.Rgas() == f3.Rgas()); 
    std::cout   << "\nImprimindo a variavel f1: \n" 
                << f1 
                << std::endl;
    
const Real  QMAX1 (34.548);
const Real  K11 (98.1e-03);

ist::DubininRadushkevich     f4 = ist::DubininRadushkevich(QMAX1, K11, RGASNovo);     
    assert (f4.Qmax() == QMAX1); 
    assert (f4.K1() == K11); 
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
    
    std::cout << "RGas:\t" 
              << std::setw(12) 
              << std::fixed
              << f1.Rgas() 
              << std::endl;
    
    
    std::cout   << "\nAlterando Qmax  e K1 separadamente\n";
    std::cout   << "Imprimindo f1 antes da modificação: \n" 
                << f1 
                << std::endl;
    
    f1.Qmax(QMAX1);
    assert (f1.Qmax() == QMAX1); 
    
    f1.K1(K11);
    assert (f1.K1() == K11); 
    
    f1.Rgas(2 * RGASNovo);
    assert (f1.Rgas() == 2 * RGASNovo); 
    
    std::cout   << "Imprimindo f1 modificado: \n" 
                << f1 
                << std::endl;

//==============================================================================
// Calculo de Qe
//==============================================================================
    
const Real                      TEMP(132.0);
const Real                      CE(76.43e-3); 
const Real                      QMAX_QE(1432e-3);
const Real                      K1_QE(23.72e-8);
const ist::DubininRadushkevich  isoDR1 (QMAX_QE, K1_QE);
const ist::DubininRadushkevich  isoDR2 (QMAX_QE, K1_QE, RGASNovo);
const Real                      QeNumer1(isoDR1.Qe(CE, TEMP));
const Real                      QeNumer2(isoDR2.Qe(CE, TEMP));
const Real                      QEANALIT1(0.1940124818);
const Real                      QEANALIT2(0.8687897360);
const Real                      DiffQe1 = fabs(QeNumer1 - QEANALIT1) / QEANALIT1;
const Real                      DiffQe2 = fabs(QeNumer2 - QEANALIT2) / QEANALIT2;

 [[maybe_unused]] const Real    DQMIN(1e-6);


    std::cout   << "\n\nImprimindo isoterma para o cálculo de Qe: \n" 
                << isoDR1
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
                    << std::setprecision(3)
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
                    << std::setprecision(3)
                    << 100.0 * DiffQe2
                    << " % "
                    << std::fixed
                    << "\n";
        
        
    assert (DiffQe2 <= DQMIN);    

//==============================================================================
// Cálculo da derivada de Qe em relação a C
//==============================================================================

    [[maybe_unused]] const auto Errodqdc = isoDR1.DQDC(CE, TEMP) - 3.564277712;

    assert (fabs(Errodqdc) <= DQMIN);        

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

    for (const auto& x : f1) {
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

//const Real          QG1 (1);
//const Real          TEMPG (700);
//const Real          KG1 (1e-7);
//
//ist::DubininRadushkevich     graph(QG1 , KG1);
//
//const Real          CMIN(1e-2);
//const Real          CMAX(10);
//const UInt          NPTO(1001);
//
//auto EixoX = [&](const Real& _qe, const Real&_ce)
//{
//    Real auxi = log(1 + 1.0 / _ce);
//    return  auxi * auxi;
//};
//
//auto EixoY = [&](const Real& _qe, const Real&_ce)
//{
//    auto auxi =    1.0 / (graph.Rgas() * TEMPG);
//    return - log( _qe ) * auxi * auxi;
//
//};

//const std::string FILENAME("Figuras/CasoT700.dat");
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
//    PrintLine(std::cout);
//    std::cout << "\n";
//    PrintLine(std::cout);

    
//==============================================================================
// testes para das exceções 
//==============================================================================

    return EXIT_SUCCESS;                // Para testar as exceções do código coloque um comentário neste return   
    
//==============================================================================
// inicio dos testes para das exceções 
//==============================================================================    
    
    std::cout << "\n";
    PrintLine(std::cout);    
    std::cout << "Testes para ver o funcionamento das exceções\n";
    PrintLine(std::cout); 

const Real RGASNEG(-1);

ist::DubininRadushkevich     f6( - QMAX1 ,  K11);    
ist::DubininRadushkevich     f60( 0 ,  K11);    
ist::DubininRadushkevich     f7(  QMAX1 ,  - K11);    
ist::DubininRadushkevich     f71(  QMAX1 ,  0);    
ist::DubininRadushkevich     f8(  QMAX1 , K11, RGASNEG);    
ist::DubininRadushkevich     f81(  QMAX1 , K11, 0);    
    
    std::cout   << "Imprimindo Qe com C errada = " 
                << f1.Qe( - CE, TEMP )
                << std::endl;
    
    std::cout   << "Imprimindo Qe com temperatura errada = " 
                << f1.Qe( CE, - TEMP )
                << std::endl;
    
ist::DubininRadushkevich     f9;    
    
    std::cout   << "Imprimindo Qe sem coeficientes definidos = " 
                << f9.Qe( CE, TEMP )
                << std::endl;
   
    std::cout << "Teste para entrar com parametros errados\n";
    
    f1.K1(-K11);
    f1.K1(0);

    f1.Qmax(- QMAX1);
    f1.Qmax(0);
    
    f1.Rgas(RGASNEG);
    f1.Rgas(0);
    
    return EXIT_SUCCESS; 

}
