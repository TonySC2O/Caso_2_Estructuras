#include <string>
#include <iostream>
#include <thread>
#include "ThreadSecundario.cpp"

#ifndef THREADFABRICA

#define THREADFABRICA

using namespace std;

class ThreadFabrica: public ThreadSecundario{
    private:

        virtual void Ejecutar() override {
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                
                cout << "Hilo: " << *tiempoActual + tiempo << endl << 
                "Se estan fabricando los ladrillos... " << endl <<
                "---------------------------------------" << endl;
                if(tiempo == cantidadTiempo){
                    *tiempoActual = *tiempoActual + tiempo;
                    cout << "Se ha fabricado el pedido de ladrillos en " << cantidadTiempo << " horas" << endl
                    << "=======================================" << endl;
                    break;
                }
            }
        }
        
    public:
        ThreadFabrica(){}
        ThreadFabrica(int pCantidadTiempo, int *pTiempoActual) : ThreadSecundario(pCantidadTiempo, pTiempoActual){}

};

#endif