
#include "../Objetos/Camion.cpp"
#include "../Objetos/Encargado.cpp"
#include "../Objetos/Fabrica.cpp"
#include "../Objetos/Ladrillo.cpp"
#include "../Objetos/Albanil.cpp"
#include "../Casa/Casa.cpp"
#include "../Json/json.hpp"

#ifndef MANAGER 

#define MANAGER 1

class Manager{
    private:
        Encargado *encargado;
        Fabrica *fabrica;
        Albanil<Ladrillo> *albanil;

    public:
        Manager(nlohmann::json pJson, Casa *pCasa, int *pTiempo){
            
            Camion<Ladrillo> camion(pJson["informacion"]["camion"]["maxTiempoViaje"],
                                      pJson["informacion"]["camion"]["minTiempoViaje"],
                                      pJson["informacion"]["camion"]["maxLadrillosxViaje"], pCasa, pTiempo);

            this->fabrica = new Fabrica(pJson["informacion"]["fabrica"]["maxTiempoFabricar"],
                                        pJson["informacion"]["fabrica"]["minTiempoFabricar"],
                                        pJson["informacion"]["fabrica"]["ladrilloxPago"],
                                        pJson["informacion"]["fabrica"]["pago"], camion, pTiempo);

            this->encargado = new Encargado(pJson["informacion"]["casa"]["presupuesto"],
                                            pJson["informacion"]["encargado"]["gastoxPedido"], pTiempo, fabrica);
            
            this->albanil = new Albanil<Ladrillo>(pJson["informacion"]["albañil"]["maxLadrillosCargados"],
                                                  pJson["informacion"]["albañil"]["maxTiempoColocar"],
                                                  pJson["informacion"]["albañil"]["minTiempoColocar"], pTiempo, encargado);
            
        }

        Encargado* getEncargado(){
            return encargado;
        }
        
        Fabrica* getFabrica(){
            return fabrica;
        }
        
        Albanil<Ladrillo>* getAlbanil(){
            return albanil;
        }
};

#endif