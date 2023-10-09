#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#ifndef LADRILLO

#define LADRILLO 1

class Ladrillo {
    private: 
        int tiempoPilaCamion;
    public:
        Ladrillo() {
            this->tiempoPilaCamion = 0;
        }
};

#endif