
#include <iostream>
#include <string>
#include "../Soporte/queue.cpp"
#include "../Soporte/stack.cpp"
#include "../Soporte/Ladrillo.cpp"
#include "PilaLadrillos.cpp"

using namespace std;

int main(){

    PilaLadrillos<Ladrillo>* pilaLadrillos = new PilaLadrillos<Ladrillo>();
    string e = "e";
    pilaLadrillos->push(new Ladrillo(1));
    cout << pilaLadrillos->top()->getNum() << endl;
    return 0;
}