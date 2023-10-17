
#include <vector>
#include "../Soporte/stack.cpp"
#include "../Soporte/List.cpp"
#include "Ladrillo.cpp"
#include "PilaLadrillos.cpp"


//Clase Pila

#ifndef CAMION 

#define CAMION 1

template <typename T>
class Camion : public Stack<T>{
    private:
        Stack<T> ColaLadrillos;
        int cantidadLadrillos;
        int maxLadrillosxViaje;
        int maxTiempoViaje;
        int minTiempoViaje;

    public:
        Camion(){}

        Camion(int pMax, int pMin, int pMaxLadrillosxViaje)
        {
            ColaLadrillos = Stack<T>();
            
            this->maxTiempoViaje = pMax;
            this->minTiempoViaje = pMin;
            this->maxLadrillosxViaje = pMaxLadrillosxViaje;
        }

        void Empacar(vector<Ladrillo*> pLadrillos, PilaLadrillos<Ladrillo> *pPila){
            
            ColaLadrillos = Stack<T>();
            this->cantidadLadrillos = pLadrillos.size();

            for (int i = 0; i < maxLadrillosxViaje; i++)
            {
                if(i < pLadrillos.size()){
                    ColaLadrillos.push(pLadrillos.at(i));
                }
            }

            Viajar(pPila);
        }

        void EmpacarPorPartes(vector<Ladrillo*> pLadrillos, PilaLadrillos<Ladrillo> *pPila){
            
            ColaLadrillos = Stack<T>();
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
                    ColaLadrillos.push(pLadrillos.at(indexLadrillo));
                    this->cantidadLadrillos++;
                    indexLadrillo++;

                    if(indexLadrillo == maxLadrillosxViaje){
                        break;
                    }
                }
                Viajar(pPila);
            }
            
        }

        void Viajar(PilaLadrillos<Ladrillo> *pPila){
            //Aquí se debe colocar un thread
            int tiempoViaje = rand()%(maxTiempoViaje+1-minTiempoViaje) + minTiempoViaje;
            cout << "El viaje a durado " << tiempoViaje << " horas" << endl;
            Desempacar(pPila);
        }

        void Desempacar(PilaLadrillos<Ladrillo> *pPila){
            int lenght = ColaLadrillos.getSize();
            for (int i = 0; i < lenght; i++)
            {
                if (!ColaLadrillos.isEmpty())
                {
                    pPila->push(ColaLadrillos.pop());
                    
                }
                
                cout << pPila->getSize() << " y "<< ColaLadrillos.getSize()<< endl;
            }
            cout <<pPila->getSize() << endl;
        }

        int getMaxLadrillosxViaje(){
            return maxLadrillosxViaje;
        }
};

#endif