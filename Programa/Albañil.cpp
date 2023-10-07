#include "../Soporte/queue.cpp"
#include "../Soporte/List.cpp"

//Clase Cola

#ifndef COLA 

#define COLA 1

template <typename T>
class Albañil : public Queue<T>{
    private:
        List<T> *stackList;
        bool cargandoLadrillo = false;

    public:
        void RecogerLadrillo(){
            //pop a PilaLadrillos y enqueue a esta clase.
        }
        
        void RecogerLadrillo(){
            //dequeue.
        }

        bool isCargandoLadrillo(){
            return cargandoLadrillo;
        }

        void informar(){
            
        }

};