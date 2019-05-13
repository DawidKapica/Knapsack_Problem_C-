//
//  main.cpp
//  ZMPO4.1
//
//  Created by Dawid Kapica on 04/12/2018.
//  Copyright © 2018 Dawid Kapica. All rights reserved.
//

#include <iostream>
#include "CKnapsackProblem.hpp"
#include "CGeneticAlgorithm.hpp"
#include "CIndividual.hpp"

int main() {
    double **piTable;
    for(int i =0; i<2; i++){
        piTable[i] = new double[10];
        for(int j =0; j<4; j++){
            piTable[i][j]=0;
        }
    }
    piTable[0][0] = 5.5;
    piTable[1][0] = 4.5;
    piTable[0][1] = 1.5;
    piTable[1][1] = 1.5;
    piTable[0][2] = 4.5;
    piTable[1][2] = 3.5;
    piTable[0][3] = 3.5;
    piTable[1][3] = 2.5;
    piTable[0][4] = 12.5;
    piTable[1][4] = 1.5;
    piTable[0][5] = 10.5;
    piTable[1][5] = 12.5;
    piTable[0][6] = 1.5;
    piTable[1][6] = 4.5;
    piTable[0][7] = 5.5;
    piTable[1][7] = 8.5;
    piTable[0][8] = 10.5;
    piTable[1][8] = 10.5;
    piTable[0][9] = 3.5;
    piTable[1][9] = 9.5;
    
    
    
    CKnapsackProblem *problem_plecakowy = new CKnapsackProblem(15, 10, piTable);
    CGeneticAlgorithm(6, 0.6, 0.1, 1000).algorytm(problem_plecakowy);
    
    
//    CGeneticAlgorithm *CGA = new CGeneticAlgorithm(6, 0.6, 0.1, 10);
//    CGA->algorytm(problem_plecakowy);
//    
//    
//    CIndividual *CIndi = CGA->getNajlepszy();
//    CIndi->wyswietl_genotyp();
//    cout << " " << CIndi->przystosowanie();
//    delete CGA;

    delete problem_plecakowy;

    return 0;
}
