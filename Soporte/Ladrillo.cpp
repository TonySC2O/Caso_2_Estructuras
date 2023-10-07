#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#ifndef LADRILLO

#define LADRILLO 1

class Ladrillo {
    private: 
        int num;

    public:
        Ladrillo(int pNum) {
            this->num = pNum;
        }

        int getNum() {
            return num;
        }
};

#endif