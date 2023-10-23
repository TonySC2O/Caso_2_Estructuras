
#include <vector>
#include "Muro.cpp"
#include "../Objetos/Ladrillo.cpp"
#include "../Soporte/stack.cpp"

#ifndef CASA 

#define CASA 1

using std::vector;

class Casa{
    private:
        int cantidadMuros;
        int presupuestoInicial;
        int murosCompletados = 0;
        bool casaConstruida;
        vector<Muro> *muros;
        Stack<Ladrillo> *pilaLadrillos;

    public:
        Casa(){}

        Casa(vector<int> pMuros, int pPresupuesto)
        {
            this->presupuestoInicial = pPresupuesto;
            this->cantidadMuros = pMuros.size();
            this->murosCompletados = 0;
            this->casaConstruida = false;
            this->muros = new vector<Muro>();
            this->pilaLadrillos = new Stack<Ladrillo>();

            for (int i = 0; i < cantidadMuros; i++)
            {
                this->muros->push_back(pMuros.at(i));
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

        int getCantidadLadrillos(){
            int ladrillos = 0;
            
            for (int i = 0; i < muros->size(); i++)
            {
                ladrillos += muros->at(i).getLadrillosColocados();
            }

            return ladrillos;
        }

        int getCantidadLadrillosxMuro(int pIndex){
           return muros->at(pIndex).getLadrillosColocados();
        }

        vector<Muro>* getMuros()
        {
            return muros;
        }

        Stack<Ladrillo>* getPilaLadrillos(){
            return pilaLadrillos;
        }

        void VerificarMuroConstruido(){
            if (muros->at(murosCompletados).getLadrillosColocados() >= muros->at(murosCompletados).getCantidadLadrillos())
            {
                murosCompletados++;
                cout << "Se ha completado un muro, muros completados: " << murosCompletados << 
                "/" << muros->size() << endl;
            }
            if (murosCompletados == muros->size())
            {
                this->casaConstruida = true;
            }
        }

};

#endif