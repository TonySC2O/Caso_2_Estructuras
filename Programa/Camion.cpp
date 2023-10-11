#include "../Soporte/stack.cpp"
#include "../Soporte/List.cpp"
#include "../Soporte/Ladrillo.cpp"
#include <vector>

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

        void Empacar(vector<Ladrillo*> pLadrillos){
            this->cantidadLadrillos = pLadrillos.size();
            
            for (int i = 0; i < cantidadLadrillos; i++)
            {
                ColaLadrillos.push(pLadrillos.at(i));
            }

            Viajar();
        }

        void EmpacarPorPartes(vector<Ladrillo*> pLadrillos){
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

                    if(indexLadrillo > maxLadrillosxViaje){
                        break;
                    }
                }
                Viajar();
            }
            
        }

        void Viajar(){
            cout << "Viaje" << endl;
        }

        void Desempacar(){

        }

        int getMaxLadrillosxViaje(){
            return maxLadrillosxViaje;
        }
};

#endif