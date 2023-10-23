#include "../Soporte/queue.cpp"
#include "../Soporte/List.cpp"
#include "../Threads/ThreadAlbanil.cpp"
#include "Ladrillo.cpp"
#include "../Casa/Casa.cpp"
#include "Encargado.cpp"


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
        int *tiempo;
        Encargado *encargado;
        ThreadAlbanil hiloAlbanil;

    public:
        Albanil(int pMax, int pMaxTiempo, int pMinTiempo, int *pTiempo, Encargado *pEncargado){
            this->maxLadrillosCargados = pMax;
            this->maxTiempoColocar = pMaxTiempo;
            this->minTiempoColocar = pMinTiempo;
            this->cargandoLadrillo = false;
            this->tiempo = pTiempo;
            this->encargado = pEncargado;
            this->queueList = new List<T>();
        }

        void RecogerLadrillos(Casa *pCasa){

            if (pCasa->getPilaLadrillos()->getSize() == 0){
                encargado->EncargarLadrillos();
            }
            
            cout << "=======================================" << endl;

            cargandoLadrillo = true;
            
            while(this->queueList->getSize() < maxLadrillosCargados){
                if (pCasa->getPilaLadrillos()->getSize() > 0){
                    this->enqueue(pCasa->getPilaLadrillos()->pop());
                }
            }

            cout << "El albañil ha recogido " << this->queueList->getSize() << " ladrillos" << endl;
            ColocarLadrillos(pCasa);
        }
        
        void ColocarLadrillos(Casa *pCasa){
            
            int tiempoViaje = rand()%(maxTiempoColocar+1-minTiempoColocar) + minTiempoColocar;
            hiloAlbanil = ThreadAlbanil(tiempoViaje, tiempo);
            hiloAlbanil.Iniciar();

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
        }
        
        int getMediaColocar(){
            return (int) (minTiempoColocar+maxTiempoColocar)/2;
        }

        int getMaxLadrillosCargados(){
            return maxLadrillosCargados;
        }

        bool isCargandoLadrillo(){
            return cargandoLadrillo;
        }

};

#endif