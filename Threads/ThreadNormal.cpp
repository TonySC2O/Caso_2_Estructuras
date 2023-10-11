
//Thread general

#include <string>
#include <iostream>
#include <thread>

using namespace std;

class ThreadNormal{
    private:
        thread hiloComun;
        int tiempo = 0;

        void Ejecutar(int pTime) {
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(3));
                std::cout << "Hilo: " << tiempo << std::endl;

                if(tiempo == pTime){
                    break;
                }
            }
        }

    public:
        void Iniciar(int pTime) {
            hiloComun = thread(&ThreadNormal::Ejecutar, this, pTime);
            hiloComun.join();
        }

};