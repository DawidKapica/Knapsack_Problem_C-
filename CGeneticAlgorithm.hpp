//
//  CGeneticAlgorithm.hpp
//  ZMPO4
//
//  Created by Dawid Kapica on 02/12/2018.
//  Copyright © 2018 Dawid Kapica. All rights reserved.
//

#ifndef CGeneticAlgorithm_hpp
#define CGeneticAlgorithm_hpp

#include <stdio.h>
#include <vector>
#include "CKnapsackProblem.hpp"
#include "CIndividual.hpp"

using namespace std;

class CGeneticAlgorithm {
public:
    CGeneticAlgorithm(int rozmiar_populacji, double prawd_krzyzowania, double prawd_mutacji, int iter);
    ~CGeneticAlgorithm();
    void algorytm(CKnapsackProblem *problem_plecakowy);
    bool getCzy_dane_poprawne() {
        return czy_dane_poprawne;
    }
    CIndividual *getNajlepszy() {
        return najlepszy;
    }
    void wyswietlanie_informacji_o_najlepszym();

private:
    void losowanie_poczatkowej_populacji(CKnapsackProblem *problem_plecakowy);
    void znajdowanie_najlepszego_z_populacji();
    int wybranie_rodzica_do_krzyzowania();
    void wykonanie_krzyzowania(int rodzic1, int rodzic2, CKnapsackProblem *problem_plecakowy);
    
    double wylosowana_liczba();
    vector <CIndividual*> tab_osobniki;
    CIndividual *najlepszy = nullptr;
    int PopSize;
    double CrossProb;
    double MutProb;
    int liczba_iter_MAX;
    int liczba_el;
    int fitness_najlepszy_ind = -1;
    double fitness_najlepszy_wartosc = -1;
    bool czy_dane_poprawne = false;
    
    void informacja_o_bledzie(string blad);
    
    const string sT_blad_prawd_mut = "prawdopodobienstwo mutacji";
    const string sT_blad_prawd_krzyz = "prawdopodobienstwo krzyzowania";
    const string sT_blad_liczba_iter = "liczba iteracji";
    const string sT_blad_rozmiar_populacji = "rozmiar populacij";
    const string sT_poczatek_tekstu_z_info_o_bl = "Wystapil blad z wczytanymi danymi, podana nieprawdlowo: ";
    const string sT_wartosc = "Wartosc: ";
    const string sT_indeks = ", indeks: ";
    const string sT_genotyp = ", genotyp :";
};

#endif /* CGeneticAlgorithm_hpp */
