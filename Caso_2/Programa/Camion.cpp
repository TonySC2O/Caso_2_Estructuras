#include "../Soporte/stack.cpp"
#include "../Soporte/List.cpp"
#include <vector>

//Clase Pila

#ifndef CAMION 

#define CAMION 1

template <typename T>
class Camion : public Stack<T>{
    private:
        List<T> *stackList;
        int cantidadLadrillos;
        vector<int> tiemposViaje;

    public:
        Camion(vector<int> pTiemposViaje)
        {
            stackList = new List<T>();
            this.tiemposViaje = pTiemposViaje;
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