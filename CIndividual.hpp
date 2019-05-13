//
//  CIndividual.hpp
//  ZMPO4
//
//  Created by Dawid Kapica on 02/12/2018.
//  Copyright © 2018 Dawid Kapica. All rights reserved.
//

#ifndef CIndividual_hpp
#define CIndividual_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include "CKnapsackProblem.hpp"
using namespace std;

class CIndividual {
public:
    CIndividual(CKnapsackProblem *CKProblem);
    ~CIndividual();
    double przystosowanie();
    void mutowanie(double mut_Prob);
    void krzyzowanie(CIndividual *rodzic2, CIndividual *dziecko1, CIndividual *dziecko2);
    void losowy_genotyp(int ilosc_elementow);
    void wyswietl_genotyp();
    
    vector<int> get_genotyp() {
        return genotyp;
    }
private:
    CKnapsackProblem *CKnapProblem;
    int fitness;
    vector <int> genotyp;
};

#endif /* CIndividual_hpp */
