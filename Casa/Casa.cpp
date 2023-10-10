
#include <vector>
#include "Muro.cpp"

#ifndef CASA 

#define CASA 1

using std::vector;

class Casa{
    private:
        int cantidadMuros;
        int presupuestoInicial;
        vector<Muro>* Muros;

    public:
        Casa(vector<int> pMuros, int pPresupuesto)
        {
            this->presupuestoInicial = pPresupuesto;
            this->cantidadMuros = pMuros.size();
            this->Muros = new vector<Muro>();

            for (int i = 0; i < cantidadMuros; i++)
            {
                this->Muros->push_back(pMuros.at(i));
            }
            
        }
        
        int getCantidadMuros(){
            return cantidadMuros;
        }

        vector<Muro>* getMuros()
        {
            return Muros;
        }

};

#endif