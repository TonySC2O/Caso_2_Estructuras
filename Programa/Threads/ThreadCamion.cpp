#include <string>
#include <iostream>
#include <thread>
#include "ThreadSecundario.cpp"

#ifndef THREADCAMION

#define THREADCAMION

using namespace std;

class ThreadCamion: public ThreadSecundario{
    private:

        virtual void Ejecutar() override {
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                cout << "Hilo " << *tiempoActual + tiempo << endl <<
                "El camión está viajando... " << endl <<
                "---------------------------------------" << endl;
                if(tiempo == cantidadTiempo){
                    *tiempoActual = *tiempoActual + tiempo;
                    cout << "El viaje a durado " << cantidadTiempo << " horas" << endl;
                    break;
                }
            }
        }
        
    public:
        ThreadCamion(){}
        ThreadCamion(int pCantidadTiempo, int *pTiempoActual) : ThreadSecundario(pCantidadTiempo, pTiempoActual){}
};

#endif