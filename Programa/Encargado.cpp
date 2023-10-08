
//Clase que maneja algunas reglas de la simulación

#ifndef ENCARGADO 

#define ENCARGADO 1

class Encargado{
    private:
        int presupuesto;

    public:
        Encargado(int pPresupuesto)
        {
            this->presupuesto = pPresupuesto;
        }

        void PedirPresupuesto(int pCantidad){
            this->presupuesto = presupuesto + pCantidad;
        }

        void EncargarLadrillos(){
            
        }
};

#endif