
#include "../Objetos/Camion.cpp"
#include "../Objetos/Encargado.cpp"
#include "../Objetos/Fabrica.cpp"
#include "../Objetos/Ladrillo.cpp"
#include "../Objetos/Albanil.cpp"
#include "../Json/json.hpp"

#ifndef MANAGER 

#define MANAGER 1

class Manager{
    private:
        Encargado *encargado;
        Fabrica *fabrica;
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