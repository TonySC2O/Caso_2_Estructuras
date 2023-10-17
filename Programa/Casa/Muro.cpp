

#include <vector>
#include "../Objetos/Ladrillo.cpp"
#ifndef MURO 

#define MURO 1

using namespace std;

class Muro{
    private:
        int cantidadLadrillos;
        int ladrillosColocados;
        vector<Ladrillo*> ladrillos;

    public:
        Muro(int pCantidadLadrillos)
        {
            this->cantidadLadrillos = pCantidadLadrillos;
            this->ladrillosColocados = 0;
            this->ladrillos = vector<Ladrillo*>();
        }
        
        int getCantidadLadrillos(){
            return cantidadLadrillos;
        }
        
        int getLadrillosColocados(){
            return ladrillosColocados;
        }

        void AgregarLadrillo(Ladrillo *pLadrillo){
            ladrillos.push_back(pLadrillo);
            this->ladrillosColocados++;
        }
};

#endif