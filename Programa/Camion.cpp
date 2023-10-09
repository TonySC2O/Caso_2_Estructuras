#include "../Soporte/stack.cpp"
#include "../Soporte/List.cpp"
#include <vector>

#include "../Threads/ThreadCamion.cpp"

//Clase Pila

#ifndef CAMION 

#define CAMION 1

template <typename T>
class Camion : public Stack<T>{
    private:
        Stack<T> *ColaLadrillos;
        int cantidadLadrillos;
        int maxLadrillosxViaje;
        int maxTiempoViaje;
        int minTiempoViaje;

    public:
        Camion(int pMax, int pMin, int pMaxLadrillosxViaje)
        {
            ColaLadrillos = new Stack<T>();
            
            this->maxTiempoViaje = pMax;
            this->minTiempoViaje = pMin;
            this->maxLadrillosxViaje = pMaxLadrillosxViaje;
        }

        void Empacar(int pCantidad){
            this->cantidadLadrillos = pCantidad;
        }

        void Viajar(){
            
        }

        void Desempacar(){

        }
};

#endif