
//Thread general

#include <string>
#include <iostream>
#include <thread>
#include "../Manager/Manager.cpp"
#include "../Casa/Casa.cpp"
#include "../Objetos/Ladrillo.cpp"

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
                
                cout << "=======================================" << endl;
                cout << "Hilo: " << tiempo << endl;
                cout << "La pila tiene " << casa.getPilaLadrillos()->getSize() << " ladrillos" << endl;
                
                if(casa.getPilaLadrillos()->isEmpty()){

                    cout << "Pila vacia" << endl;
                    manager.getEncargado()->EncargarLadrillos(manager.getFabrica(), &casa);
                    continue;
                }

                if(casa.getPilaLadrillos()->isEmpty() == false){
                    manager.getAlbanil()->RecogerLadrillos(&casa);
                }

                if(casa.isCasaConstruida()){
                    break;
                }
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