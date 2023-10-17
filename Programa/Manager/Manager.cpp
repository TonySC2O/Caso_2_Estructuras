
#include "../Objetos/Camion.cpp"
#include "../Objetos/Encargado.cpp"
#include "../Objetos/Fabrica.cpp"
#include "../Objetos/PilaLadrillos.cpp"
#include "../Objetos/Ladrillo.cpp"
#include "../Objetos/Albanil.cpp"
#include "../Json/json.hpp"

#ifndef MANAGER 

#define MANAGER 1

class Manager{
    private:
        Encargado *encargado;
        Fabrica *fabrica;
        PilaLadrillos<Ladrillo> *pilaLadrillos;
        Albanil<Ladrillo> *albanil;

    public:
        Manager(){}
        Manager(nlohmann::json pJson){
            this->encargado = new Encargado(pJson["informacion"]["casa"]["presupuesto"],
                                            pJson["informacion"]["encargado"]["gastoxPedido"]);

            Camion<Ladrillo> camion(pJson["informacion"]["camion"]["maxTiempoViaje"],
                                      pJson["informacion"]["camion"]["minTiempoViaje"],
                                      pJson["informacion"]["camion"]["maxLadrillosxViaje"]);

            this->fabrica = new Fabrica(pJson["informacion"]["fabrica"]["maxTiempoFabricar"],
                                        pJson["informacion"]["fabrica"]["minTiempoFabricar"],
                                        pJson["informacion"]["fabrica"]["ladrilloxPago"],
                                        pJson["informacion"]["fabrica"]["pago"], camion);
            
            this->albanil = new Albanil<Ladrillo>(pJson["informacion"]["albañil"]["maxLadrillosCargados"],
                                                  pJson["informacion"]["albañil"]["maxTiempoColocar"],
                                                  pJson["informacion"]["albañil"]["minTiempoColocar"]);
            
            this->pilaLadrillos = new PilaLadrillos<Ladrillo>();
        }

        Encargado* getEncargado(){
            return encargado;
        }
        
        Fabrica* getFabrica(){
            return fabrica;
        }
        
        PilaLadrillos<Ladrillo>* getPilaLadrillos(){
            return pilaLadrillos;
        }

        void setPilaLadrillos(PilaLadrillos<Ladrillo> *pPila){
            this->pilaLadrillos = pPila;
        }
        
        Albanil<Ladrillo>* getAlbanil(){
            return albanil;
        }
};

#endif