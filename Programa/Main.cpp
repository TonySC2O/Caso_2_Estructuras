#include <iostream>
#include <string>
#include <vector>

#include <sstream>
#include <fstream>

#include "Json/json.hpp"
#include "Casa/Casa.cpp"
#include "Manager/Manager.cpp"
#include "Threads/ThreadPrincipal.cpp"


using namespace std;

nlohmann::json leerJson(){
    ifstream fJson("Json/config.json");
    stringstream buffer;
    buffer << fJson.rdbuf();
    return nlohmann::json::parse(buffer.str());
}

int main(){
    
    // Se consiguen los datos del json.
    nlohmann::json json = leerJson();
    // Se crea la casa.
    Casa casa(json["informacion"]["casa"]["ladrillosxMuros"], 
                json["informacion"]["casa"]["presupuesto"]);

    cout << casa.getMuros()->at(0).getCantidadLadrillos() << endl;

    int tiempo = 0;

    Manager manager(json, &casa, &tiempo);

    ThreadPrincipal hiloPrincipal(&manager, &casa, &tiempo);

    hiloPrincipal.Iniciar();

    return 0;
}