#include <string>
#include <iostream>
#include <thread>

#ifndef THREADCAMION

#define THREADCAMION

using namespace std;

class ThreadCamion{
    private:
        thread hilo;
        int tiempo = 0;
        int cantidadTiempo = 0;

        void Ejecutar() {
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                cout << "Viajando " << tiempo << endl;
                if(tiempo == cantidadTiempo){
                    break;
                }
            }
        }

    public:
        ThreadCamion(int pCantidadTiempo){
            this->cantidadTiempo = pCantidadTiempo;
        }
        void Iniciar() {
            hilo = thread(&ThreadCamion::Ejecutar, this);
            hilo.join();
        }
};

#endif