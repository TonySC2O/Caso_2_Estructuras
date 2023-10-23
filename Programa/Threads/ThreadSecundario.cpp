#include <string>
#include <iostream>
#include <thread>

#ifndef THREADSECUNDARIO

#define THREADSECUNDARIO

using namespace std;

class ThreadSecundario{
    protected:
        thread hilo;
        int *tiempoActual;
        int tiempo = 0;
        int cantidadTiempo = 0;

        virtual void Ejecutar() {
            
        }

    public:
        ThreadSecundario(){}
        ThreadSecundario(int pCantidadTiempo, int *pTiempoActual){
            this->tiempoActual = pTiempoActual;
            this->cantidadTiempo = pCantidadTiempo;
        }

        void Iniciar() {
            hilo = thread(&ThreadSecundario::Ejecutar, this);
            hilo.join();
        }
};

#endif