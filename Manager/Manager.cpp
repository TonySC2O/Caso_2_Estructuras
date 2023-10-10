
#include "../Programa/Camion.cpp"
#include "../Programa/Encargado.cpp"
#include "../Programa/Fabrica.cpp"
#include "../Programa/PilaLadrillos.cpp"
#include "../Soporte/Ladrillo.cpp"
#include "../Json/json.hpp"
#include "../Threads/ThreadG.cpp"

#ifndef MANAGER 

#define MANAGER 1

class Manager{
    private:
        Encargado *encargado;
        Fabrica *fabrica;
        Camion<Ladrillo> *camion;
        ThreadG hiloGeneral;
    public:
        Manager(nlohmann::json pJson)
        {
            this->encargado = new Encargado(pJson["informacion"]["casa"]["presupuesto"],
                                            pJson["informacion"]["encargado"]["gastoxPedido"]);

            this->fabrica = new Fabrica(pJson["informacion"]["fabrica"]["maxTiempoFabricar"],
                                        pJson["informacion"]["fabrica"]["minTiempoFabricar"],
                                        pJson["informacion"]["fabrica"]["ladrilloxPago"],
                                        pJson["informacion"]["fabrica"]["pago"]);

            this->camion = new Camion<Ladrillo>(pJson["informacion"]["camion"]["maxTiempoViaje"],
                                      pJson["informacion"]["camion"]["minTiempoViaje"],
                                      pJson["informacion"]["camion"]["maxLadrillosxViaje"]);

            this->hiloGeneral.Iniciar(10, "E");
        }

        Encargado* getEncargado(){
            return encargado;
        }
        
        Fabrica* getFabrica(){
            return fabrica;
        }
        
        Camion<Ladrillo>* getCamion(){
            return camion;
        }
        
};

#endif