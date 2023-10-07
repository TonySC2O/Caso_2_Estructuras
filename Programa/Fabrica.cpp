
//Clase que maneja algunas reglas de la simulación

#ifndef FABRICA 

#define FABRICA 1

class Fabrica{
    private:
        int cantidadLadrillos;
        int costeLadrillos;

    public:
        Fabrica(int pCosteLadrillos)
        {
            this->costeLadrillos = pCosteLadrillos;
            this->cantidadLadrillos = 0;
        }

        void CrearLadrillos(int pCantidad){
            
        }

        void EnviarLadrillos(){
            
        }
};

#endif