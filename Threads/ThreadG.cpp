#include <string>
#include <iostream>
#include <thread>

using namespace std;

class ThreadG{
    private:
        thread hilo;
        int tiempo = 0;

        void Ejecutar(int pTime, string pAccion){
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                cout << tiempo << endl;
                if(tiempo == pTime){
                    break;
                }
            }
        }

    public:
        void Iniciar(int pTime, string pAccion){
            hilo = thread(&ThreadG::Ejecutar, this, pTime, pAccion);
            hilo.join();
        }

};