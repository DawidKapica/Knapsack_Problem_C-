//
//  CKnapsackProblem.hpp
//  ZMPO4
//
//  Created by Dawid Kapica on 02/12/2018.
//  Copyright © 2018 Dawid Kapica. All rights reserved.
//

#ifndef CKnapsackProblem_hpp
#define CKnapsackProblem_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include "CObiekt.hpp"
using namespace std;

class CKnapsackProblem {
public:
    CKnapsackProblem(double pojemnoscPlecaka, int liczba_elementow, double **pi_tabl);
    CKnapsackProblem();
    ~CKnapsackProblem();
//    int wartoscRozwiazania(vector < int > &tab_rozwiazanie);
    double wartoscRozwiazania(vector < int > &tab_rozwiazanie);
    int getLiczba_el() {
        return liczba_el;
    }
    bool getCzy_dane_poprawne() {
        return czy_dane_poprawne;
    }
    
    double **getPi_table(){
        return pi_table;
    }
private:
    double pojemnosc;
    double **pi_table;
    int liczba_el;
//    vector<CObiekt*> tab_obiektow;
    
    
    bool czy_dane_poprawne;
    void informacja_o_bledzie(string blad);
    
    const string sT_blad_poj_ple = "pojemnosc plecaka";
    const string sT_blad_l_el = "liczba elementow";
    const string sT_poczatek_tekstu_z_info_o_bl = "Wystapil blad z wczytanymi danymi, podana nieprawdlowo: ";

    const int iN_wartosc = 0;
    const int iN_waga = 1;
};

#endif /* CKnapsackProblem_hpp */
