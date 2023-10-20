#include "../Soporte/queue.cpp"
#include "../Soporte/List.cpp"
#include "../Soporte/stack.cpp"
#include "Ladrillo.cpp"
#include "../Casa/Casa.cpp"


//Clase Cola

#ifndef ALBA 

#define ALBA 1

template <typename T>
class Albanil : public Queue<T>{
    private:
        int maxLadrillosCargados;
        int maxTiempoColocar;
        int minTiempoColocar;
        bool cargandoLadrillo;

    public:
        Albanil(int pMax, int pMaxTiempo, int pMinTiempo){
            this->maxLadrillosCargados = pMax;
            this->maxTiempoColocar = pMaxTiempo;
            this->minTiempoColocar = pMinTiempo;
            this->cargandoLadrillo = false;
            this->queueList = new List<T>();
        }

        void RecogerLadrillos(Casa *pCasa){

            if (pCasa->getPilaLadrillos()->getSize() == 0)
            {
                /* code */
            }
            

            cargandoLadrillo = true;
            while(this->queueList->getSize() < maxLadrillosCargados){
                if (pCasa->getPilaLadrillos()->getSize() > 0){
                    this->enqueue(pCasa->getPilaLadrillos()->pop());
                }
            }

            cout << "Se han cargado " << this->queueList->getSize() << " ladrillos" << endl;
            ColocarLadrillos(pCasa);
        }
        
        void ColocarLadrillos(Casa *pCasa){
            //Aqui va un thread
            
            int tiempoViaje = rand()%(maxTiempoColocar+1-minTiempoColocar) + minTiempoColocar;
            
            int i = 0;
            while(this->queueList->getSize() >= 0)
            {
                if(this->queueList->isEmpty()){
                    break;
                }
                pCasa->getMuros()->at(pCasa->getMurosCompletados()).AgregarLadrillo(this->dequeue());
                pCasa->VerificarMuroConstruido();
                i++;
            }
            cargandoLadrillo = false;
            cout << "Se han colocado " << i << " ladrillos" << endl;
        }

        bool isCargandoLadrillo(){
            return cargandoLadrillo;
        }

        void informar(){
            
        }

};

#endif