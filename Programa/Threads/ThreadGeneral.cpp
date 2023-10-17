
//Thread general

#include <string>
#include <iostream>
#include <thread>
#include "../Manager/Manager.cpp"
#include "../Casa/Casa.cpp"
#include "../Objetos/Ladrillo.cpp"
#include "../Objetos/PilaLadrillos.cpp"

#ifndef THREADGENERAL

#define THREADGENERAL

using namespace std;

class ThreadGeneral{
    private:
        thread hilo;
        Manager manager;
        Casa casa;
        int tiempo = 0;

        void Ejecutar() {
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));

                cout << "Hilo: " << tiempo << endl;
                cout << "La pila tiene " << manager.getPilaLadrillos()->getSize() << " ladrillos" << endl;
                cout << manager.getPilaLadrillos()->isEmpty() << endl;
                if(manager.getPilaLadrillos()->isEmpty()){

                    cout << "Pila vacia" << endl;
                    manager.getEncargado()->EncargarLadrillos(manager.getFabrica(), manager.getPilaLadrillos());
                    
                    continue;
                }

                //while(manager.getPilaLadrillos()->isEmpty() == false){
                    manager.getAlbanil()->RecogerLadrillos(manager.getPilaLadrillos(), casa);
                //}

                if(tiempo >= 3){
                    break;
                }

                /*
                if(casa.isCasaConstruida()){
                    break;
                }*/
            }
        }

    public:
        ThreadGeneral(Manager pManager, Casa pCasa){
            this->manager = pManager;
            this->casa = pCasa;
        }

        void Iniciar() {
            hilo = thread(&ThreadGeneral::Ejecutar, this);
            hilo.join();
        }

        Casa getCasa(){
            return casa;
        }

        Manager getManager(){
            return manager;
        }

        int getTiempo(){
            return tiempo;
        }
};

#endif