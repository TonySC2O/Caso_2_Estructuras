
//Thread general

#include <string>
#include <iostream>
#include <thread>


class ThreadGeneral{
    public:
        void Ejecutar() {
            // Coloca aquí el código que deseas ejecutar en el hilo
            while(true){
                tiempo++;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Hilo: " << tiempo << std::endl;
                if(tiempo == 10){
                    break;
                }
            }
        }

        void Iniciar() {
            // Crea un hilo y ejecuta el método Ejecutar en ese hilo
            hilo = thread(&ThreadGeneral::Ejecutar, this);
        }

        void Esperar() {
            // Espera a que el hilo termine su ejecución
            if (hilo.joinable()) {
                hilo.join();
            }
        }

    private:
        thread hilo;
        int tiempo = 0;
};
