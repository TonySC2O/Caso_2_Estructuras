#include "../Soporte/stack.cpp"
#include "../Soporte/List.cpp"

//Clase Pila

#ifndef PILA 

#define PILA 1

template <typename T>
class PilaLadrillos : public Stack<T>{
    private:
        Stack<T> *listaLadrillos;
    
    public:
        PilaLadrillos(){
            this->listaLadrillos = new Stack<T>();
        }

        int getSize(){
            return listaLadrillos->getSize();
        }

};

#endif