//
//  CKnapsackProblem.cpp
//  ZMPO4
//
//  Created by Dawid Kapica on 02/12/2018.
//  Copyright © 2018 Dawid Kapica. All rights reserved.
//

#include "CKnapsackProblem.hpp"

CKnapsackProblem::CKnapsackProblem(double pojemnoscPlecaka, int liczba_elementow, double **pi_tabl) {
    pi_table = pi_tabl;
    if (pojemnoscPlecaka < 1) {
        czy_dane_poprawne = false;
        informacja_o_bledzie(sT_blad_poj_ple);
    }
    else {
        pojemnosc = pojemnoscPlecaka;
        czy_dane_poprawne = true;
    }
    
    if (liczba_elementow < 1) {
        czy_dane_poprawne = false;
        informacja_o_bledzie(sT_blad_l_el);
    }
    else {
        liczba_el = liczba_elementow + 1;
        if (czy_dane_poprawne == true) {
            czy_dane_poprawne = true;
        }
    }
}

CKnapsackProblem::~CKnapsackProblem() {
    delete pi_table[iN_wartosc];
    delete pi_table[iN_waga];
}

double CKnapsackProblem::wartoscRozwiazania(vector < int > &tab_rozwiazanie) {
    double wynik = 0.0;
    double rozmiar = 0.0;
    for (int i = 0; i < tab_rozwiazanie.size()-1; i++) {
        if (tab_rozwiazanie.at(i) == 1) {
            wynik = wynik + pi_table[iN_wartosc][i];
            rozmiar = rozmiar + pi_table [iN_waga][i];
        }
    }
    if (rozmiar > pojemnosc) {
        wynik = 0;
    }
    return wynik;
}

void CKnapsackProblem::informacja_o_bledzie(string blad) {
    cout << sT_poczatek_tekstu_z_info_o_bl << blad << endl;
}
