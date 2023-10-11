#include "../Soporte/stack.cpp"
#include "../Soporte/List.cpp"

//Clase Pila

#ifndef PILA 

#define PILA 1

template <typename T>
class PilaLadrillos : public Stack<T>{
    private:
        List<T> *listaLadrillos;
    
    public:
        PilaLadrillos(){
            this->listaLadrillos = new List<T>();
        }

};

#endif