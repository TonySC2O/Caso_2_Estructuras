
#include <vector>
#include "../Soporte/stack.cpp"
#include "../Soporte/List.cpp"
#include "../Casa/Casa.cpp"
#include "Ladrillo.cpp"
#include "../Threads/ThreadCamion.cpp"

//Clase Pila

#ifndef CAMION 

#define CAMION 1

template <typename T>
class Camion : public Stack<T>{
    private:
        int cantidadLadrillos;
        int maxLadrillosxViaje;
        int maxTiempoViaje;
        int minTiempoViaje;
        Casa *direccionCasa;
        int *tiempo;
    public:
        Camion(){}

        Camion(int pMax, int pMin, int pMaxLadrillosxViaje, Casa *pCasa, int *pTiempo)
        {
            this->stackList = new List<T>();
            
            this->maxTiempoViaje = pMax;
            this->minTiempoViaje = pMin;
            this->maxLadrillosxViaje = pMaxLadrillosxViaje;
            this->direccionCasa = pCasa;
            this->tiempo = pTiempo;
        }

        void Empacar(Stack<Ladrillo> *pLadrillos){
            
            this->stackList = new List<T>();
            this->cantidadLadrillos = pLadrillos->getSize();
            
            for (int i = 0; i < maxLadrillosxViaje; i++)
            {
                this->push(pLadrillos->pop());

                if (pLadrillos->getSize() == 0){
                    break;
                }
                
            }

            Viajar();
        }

        void EmpacarPorPartes(Stack<Ladrillo> *pLadrillos){
            
            this->stackList = new List<T>();
            int loops = pLadrillos->getSize() / maxLadrillosxViaje;

            if(maxLadrillosxViaje % pLadrillos->getSize() > 0){
                loops++;
            }
            
            int indexLadrillo = 0;

            cout << "El envio se necesitará repartir en " << loops << " viajes." << endl;
            
            for (int i = 0; i < loops; i++)
            {
                this->cantidadLadrillos = 0;
                for (int j = 0; j < maxLadrillosxViaje; j++)
                {
                    this->push(pLadrillos->pop());
                    this->cantidadLadrillos++;
                    indexLadrillo++;

                    if(indexLadrillo == maxLadrillosxViaje){
                        break;
                    }

                    if(pLadrillos->getSize() == 0){
                        break;
                    }
                }
                cout << "=======================================" << endl
                << "Se van a enviar " << this->getSize() << " ladrillos" << endl; 
                Viajar();
                if (pLadrillos->getSize() != 0){
                    cout << "Se enviaron los ladrillos, faltan " << pLadrillos->getSize() << endl; 
                }
                
            }
            
        }

        void Viajar(){
            int tiempoViaje = rand()%(maxTiempoViaje+1-minTiempoViaje) + minTiempoViaje;
            ThreadCamion hiloCamion(tiempoViaje, tiempo);
            hiloCamion.Iniciar();
            Desempacar();
        }

        void Desempacar(){
            int lenght = this->stackList->getSize();
            for (int i = 0; i < lenght; i++)
            {
                if (!this->isEmpty())
                {
                    direccionCasa->getPilaLadrillos()->push(this->pop());
                }
            }
        }
        
        int getMediaViaje(){
            return (int) (minTiempoViaje+maxTiempoViaje)/2;
        }

        int getMaxLadrillosxViaje(){
            return maxLadrillosxViaje;
        }
};

#endif