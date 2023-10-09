
#include <iostream>
#include <string>
#include <vector>
#include "../Soporte/queue.cpp"
#include "../Soporte/stack.cpp"
#include "../Soporte/Ladrillo.cpp"
#include "PilaLadrillos.cpp"

#include <sstream>
#include <fstream>
#include "../Json/json.hpp"

#include "../Threads/ThreadGeneral.cpp"

#include "../Casa/Casa.cpp"

#include "../Manager/Manager.cpp"


using namespace std;

auto leerJson(){
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
    
    cout <<  miCasa->getMuros()->at(0).getCantidadLadrillos() << endl;

    Manager manager(json);

    ThreadGeneral hilo;

    hilo.Iniciar(2, "Main");

    hilo.Esperar();

    PilaLadrillos<Ladrillo>* pilaLadrillos = new PilaLadrillos<Ladrillo>();
    string e = "e";
    pilaLadrillos->push(new Ladrillo(1));
    cout << pilaLadrillos->top()->getNum() << endl;
    return 0;
}