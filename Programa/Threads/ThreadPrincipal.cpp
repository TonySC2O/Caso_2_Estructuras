
//Thread principal

#include <string>
#include <iostream>
#include <thread>
#include "../Manager/Manager.cpp"
#include "../Casa/Casa.cpp"
#include "../Objetos/Ladrillo.cpp"

#ifndef THREADPRINCIPAL

#define THREADPRINCIPAL

using namespace std;

class ThreadPrincipal{
    private:
        thread hilo;
        Manager *manager;
        Casa *casa;
        int *tiempo;

        void Ejecutar() {
            while(!casa->isCasaConstruida()){
                *tiempo = *tiempo + 1;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                
                VerEstado();
                
                manager->getAlbanil()->RecogerLadrillos(casa);

            }

            cout << "Se ha completado la casa." << endl;
        }

    public:
        ThreadPrincipal(Manager *pManager, Casa *pCasa, int *pTiempo){
            this->manager = pManager;
            this->casa = pCasa;
            this->tiempo = pTiempo;
        }

        void Iniciar() {
            hilo = thread(&ThreadPrincipal::Ejecutar, this);

            hilo.join();
            
        }

        void VerEstado(){

            cout << endl << "=======================================" << endl << 
            "Hilo: " << *tiempo << endl << 
            "---------------------------------------" << endl <<
            "La casa tiene " << casa->getCantidadLadrillos() << " ladrillos repartidos en:" << endl;
            for (int i = 0; i < casa->getMuros()->size(); i++)
            {
                cout << "Muro " << i+1 << ": " << casa->getCantidadLadrillosxMuro(i) << endl;
            }
            
            cout << "---------------------------------------" << endl <<
            "Al proyecto le queda un presupuesto de " << manager->getEncargado()->getPresupuesto() << " colones" << endl <<  
            "Se ha pedido un presupuesto extra de " << manager->getEncargado()->getPresupuestoExtra() << " colones" << endl <<  
            "---------------------------------------" << endl <<
            "La fabrica posee " << manager->getFabrica()->getCantidadLadrillos() << " ladrillos" << endl <<
            "El camión (pila) posee " << manager->getFabrica()->getCamion()->getSize() << " ladrillos" << endl <<
            "Los ladrillos permanecen en el camion aproximadamente " << manager->getFabrica()->getCamion()->getMediaViaje() << " horas" << endl <<
            "---------------------------------------" << endl <<
            "La pila de ladrillos tiene " << casa->getPilaLadrillos()->getSize() << " ladrillos" << endl <<
            "Los ladrillos permanecen en la pila aproximadamente " << manager->getAlbanil()->getMediaColocar() * (casa->getPilaLadrillos()->getSize() / manager->getAlbanil()->getMaxLadrillosCargados())  << " horas" << endl <<
            "---------------------------------------" << endl <<
            "El Albañil (cola) posee " << manager->getAlbanil()->getSize() << " ladrillos" << endl <<
            "Los ladrillos son colocados en la casa por el albañil en aproximadamente " << manager->getAlbanil()->getMediaColocar() << " horas" << endl <<
            "=======================================" << endl << endl;

        }

        Casa* getCasa(){
            return casa;
        }

        Manager* getManager(){
            return manager;
        }
};

#endif