
//Clase que maneja algunas reglas de la simulación

#include "Fabrica.cpp"

#ifndef ENCARGADO 

#define ENCARGADO 1

class Encargado{
    private:
        int presupuesto;
        int gastoxPedido;
        int presupuestoExtra;

    public:
        Encargado(int pPresupuesto, int pGastoxPedido)
        {
            this->presupuesto = pPresupuesto;
            this->gastoxPedido = pGastoxPedido;
            this->presupuestoExtra = 0;
        }

        void PedirPresupuesto(int pCantidad){
            this->presupuesto = presupuesto + pCantidad;
            this->presupuestoExtra = presupuestoExtra + pCantidad;
            cout << "Se ha pedido un presupuesto de $" << pCantidad << endl
            << "Total de presupuesto extra pedido: $" << presupuestoExtra << endl;
        }

        void EncargarLadrillos(Fabrica *pFabrica){
            if(presupuesto-gastoxPedido < 0){
                PedirPresupuesto(gastoxPedido);
                EncargarLadrillos(pFabrica);
            }else{
                pFabrica->CrearLadrillos(gastoxPedido);
            }
        }

        int getPresupuesto(){
            return presupuesto;
        }
};

#endif