
#include <iostream>
#include <string>
#include <vector>

#include <sstream>
#include <fstream>
#include "../Json/json.hpp"

#include "../Casa/Casa.cpp"

#include "../Manager/Manager.cpp"

#include "../Threads/ThreadGeneral.cpp"


using namespace std;

nlohmann::json leerJson(){
    ifstream fJson("../Json/config.json");
    stringstream buffer;
    buffer << fJson.rdbuf();
    return nlohmann::json::parse(buffer.str());
}

int main(){
    
    // Se consiguen los datos del json.
    nlohmann::json json = leerJson();
    // Se crea la casa.
    Casa miCasa(json["informacion"]["casa"]["ladrillosxMuros"], 
                json["informacion"]["casa"]["presupuesto"]);

    cout << miCasa.getMuros()->at(0).getCantidadLadrillos() << endl;

    Manager manager(json);

    ThreadGeneral hiloGeneral(manager, miCasa);

    hiloGeneral.Iniciar();

    return 0;
}