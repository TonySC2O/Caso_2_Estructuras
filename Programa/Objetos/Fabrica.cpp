
//Clase que maneja algunas reglas de la simulación

#include "Ladrillo.cpp"
#include "Camion.cpp"
#include "PilaLadrillos.cpp"
#include "Ladrillo.cpp"

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

        void CrearLadrillos(int pPagoPedido, PilaLadrillos<Ladrillo> *pPila){
            //Aquí se debe colocar un thread
            tiempoFabricar = rand()%(maxTiempoFabricar+1-minTiempoFabricar) + minTiempoFabricar;

            this->ladrillosFabricados.clear();
            int ladrillosaConstruir = calcularLadrillos(pPagoPedido);

            for (int i = 0; i < ladrillosaConstruir; i++)
            {
                this->ladrillosFabricados.push_back(new Ladrillo(i));
            }
            
            if(ladrillosFabricados.size() <= camion.getMaxLadrillosxViaje()){
                camion.Empacar(ladrillosFabricados, pPila);
            }else{
                camion.EmpacarPorPartes(ladrillosFabricados, pPila);
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