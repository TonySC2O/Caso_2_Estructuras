#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#ifndef LADRILLO

#define LADRILLO 1

class Ladrillo {
    private: 
        int tiempoCreacion;
        int tiempoPilaCamion;
        int tiempoColocacion;
        int id;
    public:
        Ladrillo(int pId) {
            this->tiempoCreacion = 0;
            this->tiempoPilaCamion = 0;
            this->tiempoColocacion = 0;
            this->id = pId;
        }

        int getTiempoCreacion(){
            return tiempoCreacion;
        }

        void setTiempoCreacion(int pTiempo){
            this->tiempoCreacion = pTiempo;
        }

        int getTiempoColocacion(){
            return tiempoColocacion;
        }

        void setTiempoColocacion(int pTiempo){
            this->tiempoColocacion = pTiempo;
        }

        int getTiempoPilaCamion(){
            return tiempoPilaCamion;
        }

        void setTiempoPilaCamion(int pTiempo){
            this->tiempoPilaCamion = pTiempo;
        }

        int getId(){
            return id;
        }
};

#endif