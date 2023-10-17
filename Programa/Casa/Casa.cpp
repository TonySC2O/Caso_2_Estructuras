
#include <vector>
#include "Muro.cpp"

#ifndef CASA 

#define CASA 1

using std::vector;

class Casa{
    private:
        int cantidadMuros;
        int presupuestoInicial;
        int murosCompletados = 0;
        vector<Muro>* Muros;
        bool casaConstruida;
    public:
        Casa(){}
        Casa(vector<int> pMuros, int pPresupuesto)
        {
            this->presupuestoInicial = pPresupuesto;
            this->cantidadMuros = pMuros.size();
            this->murosCompletados = 0;
            this->casaConstruida = false;
            this->Muros = new vector<Muro>();

            for (int i = 0; i < cantidadMuros; i++)
            {
                this->Muros->push_back(pMuros.at(i));
            }
            
        }
        
        int getCantidadMuros(){
            return cantidadMuros;
        }

        int getMurosCompletados(){
            return murosCompletados;
        }

        bool isCasaConstruida(){
            return casaConstruida;
        }

        vector<Muro>* getMuros()
        {
            return Muros;
        }

        void VerificarMuroConstruido(){
            if (Muros->at(murosCompletados).getLadrillosColocados() >= Muros->at(murosCompletados).getCantidadLadrillos())
            {
                murosCompletados++;
            }
            if (murosCompletados == Muros->size())
            {
                this->casaConstruida = true;
            }
        }
};

#endif