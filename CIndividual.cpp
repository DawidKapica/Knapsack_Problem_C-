//
//  CIndividual.cpp
//  ZMPO4
//
//  Created by Dawid Kapica on 02/12/2018.
//  Copyright © 2018 Dawid Kapica. All rights reserved.
//

#include "CIndividual.hpp"

CIndividual::CIndividual(CKnapsackProblem *CKProblem) {
    CKnapProblem = CKProblem;
}

CIndividual::~CIndividual() {
//    genotyp.clear();
}

double CIndividual::przystosowanie() {
    return CKnapProblem->wartoscRozwiazania(genotyp);
}

void CIndividual::mutowanie(double mut_Prob) {
    for (int i = 0; i < genotyp.size(); i++) {
        int losowa = (rand() % 100);
        double wylosowana = ((double)losowa)/100.0;
        if (wylosowana < mut_Prob) {
            if (genotyp.at(i) == 1) {
                genotyp.at(i) = 0;
            }
            else {
                genotyp.at(i) = 1;
            }
        }
    }
}

void CIndividual::krzyzowanie(CIndividual *rodzic2, CIndividual *dziecko1, CIndividual *dziecko2) {
    unsigned long mozliwe_punkty_przeciecia = genotyp.size()-1;
    unsigned long miejsce_przeciecia = (rand() % mozliwe_punkty_przeciecia);
    for (unsigned long i = 0; i < miejsce_przeciecia; i++) {
        dziecko1->genotyp.push_back(genotyp.at(i));
        dziecko2->genotyp.push_back(rodzic2->genotyp.at(i));
    }
    for (unsigned long i = miejsce_przeciecia; i<rodzic2->genotyp.size(); i++) {
        dziecko1->genotyp.push_back(rodzic2->genotyp.at(i));
        dziecko2->genotyp.push_back(genotyp.at(i));
    }
}

void CIndividual::losowy_genotyp(int ilosc_elementow) {
    for (int i = 0; i < ilosc_elementow; i++) {
        int los = rand() % 100;
        if (los < 50) {
            genotyp.push_back(1);
        }
        else {
            genotyp.push_back(0);
        }
    }
}

void CIndividual::wyswietl_genotyp() {
    for (int i = 0; i < genotyp.size()-1; i++) {
        cout << genotyp.at(i);
    }
//    cout << endl ;
}
