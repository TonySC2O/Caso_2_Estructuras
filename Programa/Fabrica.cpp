
//Clase que maneja algunas reglas de la simulación

#include "../Soporte/Ladrillo.cpp"
#include "Camion.cpp"

#ifndef FABRICA 

#define FABRICA 1

class Fabrica{
    private:
        int ladrilloxPago;
        int pago;
        int maxTiempoFabricar;
        int minTiempoFabricar;
        int tiempoFabricar;
        vector<Ladrillo>* ladrillosFabricados;
        Camion<Ladrillo> camion;

    public:
        Fabrica( int pMax, int pMin, int pLxP, int pPago, Camion<Ladrillo> pCamion)
        {
            ladrillosFabricados = new vector<Ladrillo>();
            this->maxTiempoFabricar = pMax;
            this->minTiempoFabricar = pMin;
            this->ladrilloxPago = pLxP;
            this->pago = pPago;
            this->camion = pCamion;
        }

        void CrearLadrillos(int pCantidad){

            tiempoFabricar = rand()%(maxTiempoFabricar+1-minTiempoFabricar) + minTiempoFabricar;

            this->ladrillosFabricados->clear();
            for (int i = 0; i < pCantidad; i++)
            {
                Ladrillo ladrillo;
                this->ladrillosFabricados->push_back(ladrillo);
            }
            
            if(ladrillosFabricados->size() <= camion.getMaxLadrillosxViaje()){
                camion.Empacar(ladrillosFabricados);
            }else{
                camion.EmpacarPorPartes(ladrillosFabricados);
            }
        }

        int calcularLadrillos(int pPagoCliente){
           return ladrilloxPago * pPagoCliente / pago; 
        }

        int calcularAPagar(int pLadrillos){
            return pago * ladrilloxPago / ladrilloxPago; 
        }
};

#endif