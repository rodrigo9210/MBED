#include "mbed.h"

Serial pc(USBTX, USBRX);
InterruptIn  lectura(PTA1);
InterruptIn  convierte(PTD5);
AnalogIn temperatura(PTB0);

//inicializa variables
bool escala = true;//true: C, false: F.
float almacenado = -1;

//almacena un dato nuevo y lo imprime en la escala guardada
void imprimeTemp(){
    almacenado = temperatura;
    
    if (escala){
        almacenado = almacenado * 100;
        pc.printf("Temperatura en C: %.2f\n", almacenado);
    }
    else {
        almacenado = (almacenado * 900 / 5) + 32;
        pc.printf("Temperatura en F: %.2f\n", almacenado);
    }
}

//cambia la escala y convierte el dato almacenado
void convierteTemp(){
    if (almacenado >= 0){//no se activa si no se almacenado un dato
        escala = !escala;
        if (escala){
            almacenado = (almacenado - 32) * 5 / 9;
            pc.printf("Temperatura en C: %.2f\n", almacenado);
            
        }
        else {
            almacenado = (almacenado * 9 / 5) + 32;
            pc.printf("Temperatura en F: %.2f\n", almacenado);
        }
    }
}



int main() {
    
    lectura.rise(&imprimeTemp);
    convierte.rise(&convierteTemp);
    
    while(1) {
    }
}