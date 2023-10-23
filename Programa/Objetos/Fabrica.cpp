
//Clase que maneja algunas reglas de la simulación

#include "Ladrillo.cpp"
#include "Camion.cpp"
#include "../Soporte/stack.cpp"
#include "../Casa/Casa.cpp"
#include "../Threads/ThreadFabrica.cpp"

#ifndef FABRICA 

#define FABRICA 1

class Fabrica{
    private:
        int ladrilloxPago;
        int pago;
        int maxTiempoFabricar;
        int minTiempoFabricar;
        int tiempoFabricar;
        int *tiempo;
        Stack<Ladrillo> *ladrillosFabricados;
        Camion<Ladrillo> camion;
        ThreadFabrica hiloFabrica;

    public:
        Fabrica( int pMax, int pMin, int pLxP, int pPago, Camion<Ladrillo> pCamion, int *pTiempo)
        {
            ladrillosFabricados = new Stack<Ladrillo>();
            this->maxTiempoFabricar = pMax;
            this->minTiempoFabricar = pMin;
            this->ladrilloxPago = pLxP;
            this->pago = pPago;
            this->camion = pCamion;
            this->tiempo = pTiempo;
        }

        void CrearLadrillos(int pPagoPedido){
            
            tiempoFabricar = rand()%(maxTiempoFabricar+1-minTiempoFabricar) + minTiempoFabricar;
            
            int ladrillosaConstruir = calcularLadrillos(pPagoPedido);
            cout << "Se van a construir " << ladrillosaConstruir << " ladrillos" << endl;
            
            cout << "=======================================" << endl;

            hiloFabrica = ThreadFabrica(tiempoFabricar, tiempo);
            hiloFabrica.Iniciar();
            
            for (int i = 0; i < ladrillosaConstruir; i++)
            {
                this->ladrillosFabricados->push(new Ladrillo(i));
            }
            
            if(ladrillosFabricados->getSize() <= camion.getMaxLadrillosxViaje()){
                camion.Empacar(ladrillosFabricados);
            }else{
                camion.EmpacarPorPartes(ladrillosFabricados);
            }
        }

        int getCantidadLadrillos(){
            return ladrillosFabricados->getSize();
        }

        Camion<Ladrillo>* getCamion(){
            return &camion;
        }

        int getMediaFabricar(){
            return (int) (minTiempoFabricar+maxTiempoFabricar)/2;
        }

        int calcularLadrillos(int pPagoCliente){
           return ladrilloxPago * pPagoCliente / pago; 
        }

        int calcularAPagar(int pLadrillos){
            return pago * ladrilloxPago / ladrilloxPago; 
        }
};

#endif