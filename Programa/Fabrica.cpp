
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
        vector<Ladrillo*> ladrillosFabricados;
        Camion<Ladrillo> camion;

    public:
        Fabrica( int pMax, int pMin, int pLxP, int pPago, Camion<Ladrillo> pCamion)
        {
            ladrillosFabricados = vector<Ladrillo*>();
            this->maxTiempoFabricar = pMax;
            this->minTiempoFabricar = pMin;
            this->ladrilloxPago = pLxP;
            this->pago = pPago;
            this->camion = pCamion;
        }

        void CrearLadrillos(int pPagoPedido){

            tiempoFabricar = rand()%(maxTiempoFabricar+1-minTiempoFabricar) + minTiempoFabricar;

            this->ladrillosFabricados.clear();
            int ladrillosaConstruir = calcularLadrillos(pPagoPedido);
            cout << ladrillosaConstruir << endl;
            for (int i = 0; i < ladrillosaConstruir; i++)
            {
                Ladrillo *ladrillo;
                this->ladrillosFabricados.push_back(ladrillo);
            }
            
            if(ladrillosFabricados.size() <= camion.getMaxLadrillosxViaje()){
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