
//Clase que maneja algunas reglas de la simulación

#include "Fabrica.cpp"
#include "PilaLadrillos.cpp"
#include "Ladrillo.cpp"

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

        void EncargarLadrillos(Fabrica *pFabrica, PilaLadrillos<Ladrillo> *pPila){
            if(presupuesto-gastoxPedido < 0){
                PedirPresupuesto(gastoxPedido);
                EncargarLadrillos(pFabrica, pPila);
            }else{
                pFabrica->CrearLadrillos(gastoxPedido, pPila);
            }
        }

        int getPresupuesto(){
            return presupuesto;
        }
};

#endif