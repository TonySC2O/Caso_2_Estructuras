
//Thread general

#include <string>
#include <iostream>
#include <thread>

class ThreadGeneral{
    public:
        ThreadGeneral(){}

        void Ejecutar(int pTime, string pAccion) {
            
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Hilo: " << tiempo << std::endl;
                if(pAccion != "Main"){
                    if(tiempo == pTime){
                        break;
                    }
                }else if(tiempo == 5){
                    break;
                }
            }
        }

        void Iniciar(int pTime, string pAccion) {
            hilo = thread(&ThreadGeneral::Ejecutar, this, pTime, pAccion);
        }

        void Esperar() {
            if (hilo.joinable()) {
                hilo.join();
            }
        }

    private:
        thread hilo;
        int tiempo = 0;
};
