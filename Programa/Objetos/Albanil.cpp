#include "../Soporte/queue.cpp"
#include "../Soporte/List.cpp"
#include "PilaLadrillos.cpp"
#include "Ladrillo.cpp"
#include "../Casa/Casa.cpp"


//Clase Cola

#ifndef ALBA 

#define ALBA 1

template <typename T>
class Albanil : public Queue<T>{
    private:
        Queue<T> *CargaLadrillos;
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
            CargaLadrillos = new Queue<T>();
        }

        void RecogerLadrillos(PilaLadrillos<Ladrillo> *pPila, Casa pCasa){

            if (pPila->getSize() == 0)
            {
                /* code */
            }
            

            cargandoLadrillo = true;
            cout << "Entro" << endl;
            while(CargaLadrillos->getSize() < maxLadrillosCargados){
                //if (pPila.getSize() > 0){
                    CargaLadrillos->enqueue(pPila->pop());
                //}
            }

            cout << "Se han cargado " << CargaLadrillos->getSize() << " ladrillos" << endl;
            ColocarLadrillos(pCasa);
        }
        
        void ColocarLadrillos(Casa pCasa){
            //Aqui va un thread
            
            int tiempoViaje = rand()%(maxTiempoColocar+1-minTiempoColocar) + minTiempoColocar;
            
            int i = 0;
            while(CargaLadrillos->getSize() >= 0)
            {
                if(CargaLadrillos->isEmpty()){
                    break;
                }
                pCasa.getMuros()->at(pCasa.getMurosCompletados()).AgregarLadrillo(CargaLadrillos->dequeue());
                pCasa.VerificarMuroConstruido();
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