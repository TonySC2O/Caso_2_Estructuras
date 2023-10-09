
//Thread general

#include <string>
#include <iostream>
#include <thread>
#include "../Programa/Main.cpp"

class ThreadGeneral{
    public:
        ThreadGeneral(){}

        void Iniciar(int pTime, string pAccion) {
            hilo = thread(&ThreadGeneral::Ejecutar, this, pTime, pAccion);
            hilo.join();
        }

    private:
        thread hilo;
        int tiempo = 0;

        void Ejecutar(int pTime, string pAccion) {
            
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Hilo: " << tiempo << std::endl;

                runnable(pAccion);

                if(tiempo == pTime){
                    break;
                }
            }
        }

};
