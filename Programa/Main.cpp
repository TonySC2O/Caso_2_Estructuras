
#include <iostream>
#include <string>
#include <vector>

#include <sstream>
#include <fstream>
#include "../Json/json.hpp"

#include "../Casa/Casa.cpp"

#include "../Manager/Manager.cpp"

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
    Casa* miCasa = new Casa(json["informacion"]["casa"]["ladrillosxMuros"], 
                            json["informacion"]["casa"]["presupuesto"]);

    cout >> miCasa->getMuro->at(i).getCantidadLadrillos() >> endl;

    Manager manager = new Manager(json);

    return 0;
}