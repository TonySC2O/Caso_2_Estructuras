
#include <vector>
#include "../Soporte/stack.cpp"
#include "../Soporte/List.cpp"
#include "../Casa/Casa.cpp"
#include "Ladrillo.cpp"


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

    public:
        Camion(){}

        Camion(int pMax, int pMin, int pMaxLadrillosxViaje)
        {
            this->stackList = new List<T>();
            
            this->maxTiempoViaje = pMax;
            this->minTiempoViaje = pMin;
            this->maxLadrillosxViaje = pMaxLadrillosxViaje;
        }

        void Empacar(vector<Ladrillo*> pLadrillos, Casa *pDireccionCasa){
            
            this->stackList = new List<T>();
            this->cantidadLadrillos = pLadrillos.size();

            for (int i = 0; i < maxLadrillosxViaje; i++)
            {
                if(i < pLadrillos.size()){
                    this->push(pLadrillos.at(i));
                }
            }

            Viajar(pDireccionCasa);
        }

        void EmpacarPorPartes(vector<Ladrillo*> pLadrillos, Casa *pDireccionCasa){
            
            this->stackList = new List<T>();
            int loops = maxLadrillosxViaje / pLadrillos.size();
            
            if(maxLadrillosxViaje % pLadrillos.size() < 0){
                loops++;
            }
            
            int indexLadrillo = 0;
            
            for (int i = 0; i < loops; i++)
            {
                this->cantidadLadrillos = 0;
                for (int j = 0; j < maxLadrillosxViaje; j++)
                {
                    this->push(pLadrillos.at(indexLadrillo));
                    this->cantidadLadrillos++;
                    indexLadrillo++;

                    if(indexLadrillo == maxLadrillosxViaje){
                        break;
                    }
                }
                Viajar(pDireccionCasa);
            }
            
        }

        void Viajar(Casa *pDireccionCasa){
            //Aquí se debe colocar un thread
            int tiempoViaje = rand()%(maxTiempoViaje+1-minTiempoViaje) + minTiempoViaje;
            cout << "El viaje a durado " << tiempoViaje << " horas" << endl;
            Desempacar(pDireccionCasa);
        }

        void Desempacar(Casa *pDireccionCasa){
            int lenght = this->stackList->getSize();
            for (int i = 0; i < lenght; i++)
            {
                if (!this->isEmpty())
                {
                    pDireccionCasa->getPilaLadrillos()->push(this->pop());
                }
            }
        }

        int getMaxLadrillosxViaje(){
            return maxLadrillosxViaje;
        }
};

#endif