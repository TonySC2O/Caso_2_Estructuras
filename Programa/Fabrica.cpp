
//Clase que maneja algunas reglas de la simulación

#ifndef FABRICA 

#define FABRICA 1

class Fabrica{
    private:
        int ladrilloxPago;
        int pago;
        int maxTiempoFabricar;
        int minTiempoFabricar;
        int tiempoFabricar;
    public:
        Fabrica( int pMax, int pMin, int pLxP, int pPago)
        {
            this->maxTiempoFabricar = pMax;
            this->minTiempoFabricar = pMin;
            this->ladrilloxPago = pLxP;
            this->pago = pPago;
        }

        void CrearLadrillos(int pCantidad){
            tiempoFabricar = rand()%(maxTiempoFabricar+1-minTiempoFabricar) + minTiempoFabricar;
            ThreadGeneral hiloFabrica;
            hiloFabrica.Iniciar(tiempoFabricar, "CrearLadrillos");
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