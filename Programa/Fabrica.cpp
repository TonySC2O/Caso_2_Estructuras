
//Clase que maneja algunas reglas de la simulación

#include "../Soporte/Ladrillo.cpp"

#ifndef FABRICA 

#define FABRICA 1

class Fabrica{
    private:
        vector<Ladrillo>* ladrillosFabricados;
        int ladrilloxPago;
        int pago;
        int maxTiempoFabricar;
        int minTiempoFabricar;
        int tiempoFabricar;
    public:
        Fabrica( int pMax, int pMin, int pLxP, int pPago)
        {
            ladrillosFabricados = new vector<Ladrillo>();
            this->maxTiempoFabricar = pMax;
            this->minTiempoFabricar = pMin;
            this->ladrilloxPago = pLxP;
            this->pago = pPago;
        }

        void CrearLadrillos(int pCantidad){
            tiempoFabricar = rand()%(maxTiempoFabricar+1-minTiempoFabricar) + minTiempoFabricar;

            this->ladrillosFabricados->clear();
            for (int i = 0; i < pCantidad; i++)
            {
                Ladrillo ladrillo;
                this->ladrillosFabricados->push_back(ladrillo);
            }
            
            EnviarLadrillos();
        }

        void EnviarLadrillos(){
            
        }

        int calcularLadrillos(int pPagoCliente){
           return ladrilloxPago * pPagoCliente / pago; 
        }

        int calcularAPagar(int pLadrillos){
            return pago * ladrilloxPago / ladrilloxPago; 
        }
};

#endif