
//Clase que maneja algunas reglas de la simulación

#include "Fabrica.cpp"
#include "Ladrillo.cpp"
#include "../Casa/Casa.cpp"

#ifndef ENCARGADO 

#define ENCARGADO 1

class Encargado{
    private:
        int presupuesto;
        int gastoxPedido;
        int presupuestoExtra;
        int *tiempo;
        Fabrica *fabrica;
    public:
        Encargado(int pPresupuesto, int pGastoxPedido, int *pTiempo, Fabrica *pFabrica)
        {
            this->presupuesto = pPresupuesto;
            this->gastoxPedido = pGastoxPedido;
            this->presupuestoExtra = 0;
            this->tiempo = pTiempo;
            this->fabrica = pFabrica;
        }

        void PedirPresupuesto(int pCantidad){
            this->presupuesto = presupuesto + pCantidad;
            this->presupuestoExtra = presupuestoExtra + pCantidad;
            cout << "Se ha pedido un presupuesto de $" << pCantidad << endl
            << "Total de presupuesto extra pedido: $" << presupuestoExtra << endl;
        }

        void EncargarLadrillos(){
            if(presupuesto-gastoxPedido < 0){
                PedirPresupuesto(gastoxPedido);
            }
            presupuesto -= gastoxPedido;
            fabrica->CrearLadrillos(gastoxPedido);
        }

        int getPresupuesto(){
            return presupuesto;
        }

        int getPresupuestoExtra(){
            return presupuestoExtra;
        }
};

#endif