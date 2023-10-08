
#ifndef MURO 

#define MURO 1

class Muro{
    private:
        int cantidadLadrillos;
        int ladrillosColocados;

    public:
        Muro(int pCantidadLadrillos)
        {
            this->cantidadLadrillos = pCantidadLadrillos;
            this->ladrillosColocados = 0;
        }
        
        int getCantidadLadrillos(){
            return cantidadLadrillos;
        }
        
        int getLadrillosColocados(){
            return ladrillosColocados;
        }

        void setLadrillosColocados(int pLadrillos){
            this->ladrillosColocados = pLadrillos;
        }
};

#endif