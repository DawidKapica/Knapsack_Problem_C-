//
//  CGeneticAlgorithm.cpp
//  ZMPO4
//
//  Created by Dawid Kapica on 02/12/2018.
//  Copyright © 2018 Dawid Kapica. All rights reserved.
//

#include "CGeneticAlgorithm.hpp"
CGeneticAlgorithm::CGeneticAlgorithm(int rozmiar_populacji, double prawd_krzyzowania, double prawd_mutacji, int iter) {
    if (prawd_mutacji < 0 || prawd_mutacji >1) {
        czy_dane_poprawne = false;
        informacja_o_bledzie(sT_blad_prawd_mut);
    }
    else {
        MutProb = prawd_mutacji;
        czy_dane_poprawne = true;

    }
    if (prawd_krzyzowania < 0 || prawd_krzyzowania > 1) {
        czy_dane_poprawne = false;
        informacja_o_bledzie(sT_blad_prawd_krzyz);

    }
    else {
        CrossProb = prawd_krzyzowania;
        if (czy_dane_poprawne == true) {
            czy_dane_poprawne = true;
        }

    }
    if (iter < 1) {
        czy_dane_poprawne = false;
        informacja_o_bledzie(sT_blad_liczba_iter);
    }
    else {
        liczba_iter_MAX = iter;
        if (czy_dane_poprawne == true) {
            czy_dane_poprawne = true;
        }
    }
    if (rozmiar_populacji < 1){
        czy_dane_poprawne = false;
        informacja_o_bledzie(sT_blad_rozmiar_populacji);

    }
    else {
       PopSize = rozmiar_populacji;
        if (czy_dane_poprawne == true) {
            czy_dane_poprawne = true;
        }

    }
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    for (int i = 0; i <tab_osobniki.size(); i++) {
        delete tab_osobniki.at(i);
    }
    tab_osobniki.clear();
}


void CGeneticAlgorithm::algorytm(CKnapsackProblem *problem_plecakowy) {
    srand( time( NULL ));
    if (problem_plecakowy->getCzy_dane_poprawne() == true && czy_dane_poprawne == true) {
        int numer_iter = 0;
        int liczba_krzyzowan = PopSize/2;
        liczba_el = problem_plecakowy->getLiczba_el();

        losowanie_poczatkowej_populacji(problem_plecakowy);
        
        while (numer_iter < liczba_iter_MAX) {
            
            znajdowanie_najlepszego_z_populacji();
            
            for (int i = 0; i < liczba_krzyzowan; i++) {

                int rodzic1_do_krzyz = wybranie_rodzica_do_krzyzowania();
                int rodzic2_do_krzyz = wybranie_rodzica_do_krzyzowania();
                
                wykonanie_krzyzowania(rodzic1_do_krzyz, rodzic2_do_krzyz, problem_plecakowy);
            }
            
            
            numer_iter = numer_iter + 1;
            
            wyswietlanie_informacji_o_najlepszym();
            
        }
    }
}

double CGeneticAlgorithm::wylosowana_liczba() {
    
    int losowa = ((rand() % 100) + 0);
    double wylosowana = ((double)losowa)/100.0;
    return wylosowana;
}

void CGeneticAlgorithm::informacja_o_bledzie(string blad) {
    cout << sT_poczatek_tekstu_z_info_o_bl << blad << endl;
}


void CGeneticAlgorithm::losowanie_poczatkowej_populacji(CKnapsackProblem *problem_plecakowy) {
    for (int i = 0; i < PopSize; i++) {
        CIndividual *c = new CIndividual(problem_plecakowy);
        c->losowy_genotyp(liczba_el);
        tab_osobniki.push_back(c);
    }
}

void CGeneticAlgorithm::znajdowanie_najlepszego_z_populacji() {
    for (int i = 0 - PopSize; i < 0; i++) {
        double fitness = tab_osobniki.at(tab_osobniki.size()+i)->przystosowanie();
        if (fitness_najlepszy_wartosc < fitness) {
            fitness_najlepszy_wartosc = fitness;
            fitness_najlepszy_ind = tab_osobniki.size() + i;
            najlepszy = tab_osobniki.at(tab_osobniki.size()+i);
        }
    }
}

int CGeneticAlgorithm::wybranie_rodzica_do_krzyzowania() {
    int rodzic1 = rand() % PopSize;
    int rodzic2 = rand() % PopSize;
    
    if (tab_osobniki.at(rodzic1)->przystosowanie() >= tab_osobniki.at(rodzic2)->przystosowanie()) {
        return rodzic1;
    }
    else {
        return rodzic2;
    }
}

void CGeneticAlgorithm::wykonanie_krzyzowania(int rodzic1, int rodzic2, CKnapsackProblem *problem_plecakowy) {
    CIndividual *dziecko1 = new CIndividual(problem_plecakowy);
    CIndividual *dziecko2 = new CIndividual(problem_plecakowy);
    
    int czy_krzyzowac = (rand() % 100)/100;
    if (czy_krzyzowac < CrossProb) {
        tab_osobniki.at(rodzic1)->krzyzowanie(tab_osobniki.at(rodzic2), dziecko1, dziecko2);
        dziecko1->mutowanie(MutProb);
        dziecko2->mutowanie(MutProb);
        tab_osobniki.push_back(dziecko1);
        tab_osobniki.push_back(dziecko2);
    }
    else {
        
        dziecko1 = new CIndividual(*tab_osobniki.at(rodzic1));
        dziecko2 = new CIndividual(*tab_osobniki.at(rodzic2));
        
        dziecko1->mutowanie(MutProb);
        dziecko2->mutowanie(MutProb);
        tab_osobniki.push_back(dziecko1);
        tab_osobniki.push_back(dziecko2);
    }
}

void CGeneticAlgorithm::wyswietlanie_informacji_o_najlepszym() {
    cout << sT_wartosc << najlepszy->przystosowanie() << sT_indeks << fitness_najlepszy_ind << sT_genotyp;
    najlepszy->wyswietl_genotyp();
    cout << endl;
    
    //            for (int i = 0; i < tab_osobniki.size(); i++) {
    //                tab_osobniki.at(i)->wyswietl_genotyp();
    //                cout << ", ";
    //            }
    //           cout << endl;
}

