
#include "../Programa/Camion.cpp"
#include "../Programa/Encargado.cpp"
#include "../Programa/Fabrica.cpp"
#include "../Programa/PilaLadrillos.cpp"
#include "../Soporte/Ladrillo.cpp"
#include "../Json/json.hpp"

#ifndef MANAGER 

#define MANAGER 1

class Manager{
    private:
        Encargado *encargado;
        Fabrica *fabrica;
        PilaLadrillos<Ladrillo> *pilaLadrillos;
    public:
        Manager(){}
        
        Manager(nlohmann::json pJson)
        {
            this->encargado = new Encargado(pJson["informacion"]["casa"]["presupuesto"],
                                            pJson["informacion"]["encargado"]["gastoxPedido"]);

            Camion<Ladrillo> camion(pJson["informacion"]["camion"]["maxTiempoViaje"],
                                      pJson["informacion"]["camion"]["minTiempoViaje"],
                                      pJson["informacion"]["camion"]["maxLadrillosxViaje"]);

            this->fabrica = new Fabrica(pJson["informacion"]["fabrica"]["maxTiempoFabricar"],
                                        pJson["informacion"]["fabrica"]["minTiempoFabricar"],
                                        pJson["informacion"]["fabrica"]["ladrilloxPago"],
                                        pJson["informacion"]["fabrica"]["pago"], camion);


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
};

#endif