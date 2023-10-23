#include <string>
#include <iostream>
#include <thread>
#include "ThreadSecundario.cpp"

#ifndef THREADALBANIL

#define THREADALBANIL

using namespace std;

class ThreadAlbanil: public ThreadSecundario{
    private:

        virtual void Ejecutar() override {
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));

                cout << "Hilo: " << *tiempoActual + tiempo << endl << 
                "El albañil está colocando los ladrillos... " << endl <<
                "---------------------------------------" << endl;
                if(tiempo == cantidadTiempo){
                    *tiempoActual = *tiempoActual + tiempo;
                    cout << "El albañil ha terminado de colocar los ladrillos en " << cantidadTiempo << " horas" << endl
                    << "=======================================" << endl;
                    break;
                }
            }
        }
        
    public:
        ThreadAlbanil(){}
        ThreadAlbanil(int pCantidadTiempo, int *pTiempoActual) : ThreadSecundario(pCantidadTiempo, pTiempoActual){}
};

#endif