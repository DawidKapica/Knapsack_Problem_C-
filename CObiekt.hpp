//
//  CObiekt.hpp
//  ZMPO4.1
//
//  Created by Dawid Kapica on 06/12/2018.
//  Copyright © 2018 Dawid Kapica. All rights reserved.
//

#ifndef CObiekt_hpp
#define CObiekt_hpp

#include <stdio.h>
class CObiekt {
public:
    void setWaga(int pod_waga) {
        waga = pod_waga;
    }
    void setWartosc(int pod_wartosc) {
        wartosc = pod_wartosc;
    }
    int getWaga() {
        return waga;
    }
    int getWartosc() {
        return wartosc;
    }
private:
    int waga;
    int wartosc;
};
#endif /* CObiekt_hpp */
