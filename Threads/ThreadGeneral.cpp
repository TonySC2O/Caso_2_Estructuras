
//Thread general

#include <string>
#include <iostream>
#include <thread>
#include "../Manager/Manager.cpp"
#include "../Casa/Casa.cpp"

using namespace std;

class ThreadGeneral{
    private:
        thread hilo;
        Manager manager;
        Casa casa;
        int tiempo = 0;
        bool *pilaLlena;

        void Ejecutar() {
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(3));
                std::cout << "Hilo: " << tiempo << std::endl;

                if(manager.getPilaLadrillos()->isEmpty() && !pilaLlena){
                    manager.getEncargado()->EncargarLadrillos(manager.getFabrica(), pilaLlena);
                }

                if(tiempo == 5){
                    break;
                }
            }
        }

    public:
        ThreadGeneral(Manager pManager, Casa pCasa){
            this->manager = pManager;
            this->casa = pCasa;
            this->pilaLlena = new bool(false);
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
