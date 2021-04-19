#include "mbed.h"
#include<stdio.h>

void convertidor(char*, long int);
void imprimeNumsSeg1(char*);
void imprimeNumsSeg2(char*);

//segmentos decenas
DigitalOut ledG1(PTB8);
DigitalOut ledF1(PTB9);
DigitalOut ledA1(PTB10);
DigitalOut ledB1(PTB11);
DigitalOut ledC1(PTE2);
DigitalOut ledD1(PTE3);
DigitalOut ledE1(PTE4);

//segmentos unidades
DigitalOut ledG2(PTE5);
DigitalOut ledF2(PTE20);
DigitalOut ledA2(PTE21);
DigitalOut ledB2(PTE22);
DigitalOut ledC2(PTE23);
DigitalOut ledD2(PTE29);
DigitalOut ledE2(PTE30);

//botones
DigitalIn cambio(PTA2);
DigitalIn subeVelocidad(PTA1);
DigitalIn bajaVelocidad(PTE0);
DigitalOut direccion(LED1);


int main() {

    //condiciones iniciales
    long int i = 0;
    char nums[2];
    double tiempo = 2.0;
    int velocidad = 1;
    
    //ciclo
    while(1){
        //verifica si hay cambio de direccion
        if(cambio){
            direccion = !direccion;
        }

        //verifica si fue presionado PTA1
        if(subeVelocidad){
            switch(velocidad) {
                case 1:
                    velocidad = 2;
                    tiempo = 1.0;
                    break;
                case 2:
                    velocidad = 3;
                    tiempo = 0.5;
                    break;
                case 3:
                    velocidad = 4;
                    tiempo = 0.2;
                    break;
                case 4:
                    velocidad = 4;
                    tiempo = 0.2;
                    break;
                }
        }

        //verifica si fue presionado PTE0
        if(bajaVelocidad){
            switch(velocidad) {
                case 1:
                    velocidad = 1;
                    tiempo = 2.0;
                    break;
                case 2:
                    velocidad = 1;
                    tiempo = 2.0;
                    break;
                case 3:
                    velocidad = 2;
                    tiempo = 1.0;
                    break;
                case 4:
                    velocidad = 3;
                    tiempo = 0.5;
                    break;
                }
        }

        //si la direccion es ascendente
        if (direccion == 0){
            convertidor(nums, i);
            imprimeNumsSeg1(nums);
            imprimeNumsSeg2(nums);
            i++;
            if(i == 256)
                i = 0;
            wait(tiempo);
        }

        //si la direccion es descendente
        if (direccion == 1){
            convertidor(nums, i);
            imprimeNumsSeg1(nums);
            imprimeNumsSeg2(nums);
            i--;
            if(i == -1)
                i = 255;

            wait(tiempo);
        }

    }//while

}

void convertidor(char* leds, long int decNum){
    long int aux;
    int i = 1,j,temp;
    int k = 0;
    char hexNum[100];
    aux = decNum;

    //convierte
    while(aux != 0){
        temp = aux % 16;
        if(temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexNum[i++] = temp;
        aux = aux / 16;
    }

    //llena el arreglo del main
    for (j = i-1; j>0; j--){
        leds[k] = hexNum[j];
        k++;
    }

    //si el numero es cero llena mabas posiciones con ceros
    if (decNum == 0){
        leds[1] = '0';
        leds[0] = '0';
    }

    //si el numero es menos que 16 recorre para tener un espacio con cero
    if(decNum < 16){
        leds[1] = leds[0];
        leds[0] = '0';
    }
}

//enciende los leds de decenas de acuerdo a los datos
void imprimeNumsSeg1(char* nums){
    switch(nums[0]) {
    case '0':
        ledG1 = 0;
        ledF1 = 1;
        ledA1 = 1;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 1;
        ledE1 = 1;
        break;
    case '1':
        ledG1 = 0;
        ledF1 = 0;
        ledA1 = 0;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 0;
        ledE1 = 0;
        break;
    case '2':
        ledG1 = 1;
        ledF1 = 0;
        ledA1 = 1;
        ledB1 = 1;
        ledC1 = 0;
        ledD1 = 1;
        ledE1 = 1;
        break;
    case '3':
        ledG1 = 1;
        ledF1 = 0 ;
        ledA1 = 1;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 1;
        ledE1 = 0 ;
        break;
    case '4':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 0 ;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 0 ;
        ledE1 = 0 ;
        break;
    case '5':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 1;
        ledB1 = 0 ;
        ledC1 = 1;
        ledD1 = 1;
        ledE1 = 0 ;
        break;
    case '6':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 1;
        ledB1 = 0 ;
        ledC1 = 1;
        ledD1 = 1;
        ledE1 = 1;
        break;
    case '7':
        ledG1 = 0 ;
        ledF1 = 0 ;
        ledA1 = 1;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 0 ;
        ledE1 = 0 ;
        break;
    case '8':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 1;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 1;
        ledE1 = 1;
        break;
    case '9':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 1;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 0 ;
        ledE1 = 0 ;
        break;
    case 'A':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 1;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 0 ;
        ledE1 = 1;
        break;
    case 'B':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 0 ;
        ledB1 = 0 ;
        ledC1 = 1;
        ledD1 = 1;
        ledE1 = 1;
        break;
    case 'C':
        ledG1 = 1;
        ledF1 = 0 ;
        ledA1 = 0 ;
        ledB1 = 0 ;
        ledC1 = 0 ;
        ledD1 = 1;
        ledE1 = 1;
        break;
    case 'D':
        ledG1 = 1;
        ledF1 = 0 ;
        ledA1 = 0 ;
        ledB1 = 1;
        ledC1 = 1;
        ledD1 = 1;
        ledE1 = 1;
        break;
    case 'E':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 1;
        ledB1 = 0 ;
        ledC1 = 0 ;
        ledD1 = 1;
        ledE1 = 1;
        break;
    case 'F':
        ledG1 = 1;
        ledF1 = 1;
        ledA1 = 1;
        ledB1 = 0 ;
        ledC1 = 0 ;
        ledD1 = 0 ;
        ledE1 = 1;
        break;
  }
}

//enciende los leds de unidades de acuerdo a los datos
void imprimeNumsSeg2(char* nums){
    switch(nums[1]) {
    case '0':
        ledG2 = 0;
        ledF2 = 1;
        ledA2 = 1;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 1;
        ledE2 = 1;
        break;
    case '1':
        ledG2 = 0;
        ledF2 = 0;
        ledA2 = 0;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 0;
        ledE2 = 0;
        break;
    case '2':
        ledG2 = 1;
        ledF2 = 0;
        ledA2 = 1;
        ledB2 = 1;
        ledC2 = 0;
        ledD2 = 1;
        ledE2 = 1;
        break;
    case '3':
        ledG2 = 1;
        ledF2 = 0 ;
        ledA2 = 1;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 1;
        ledE2 = 0 ;
        break;
    case '4':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 0 ;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 0 ;
        ledE2 = 0 ;
        break;
    case '5':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 1;
        ledB2 = 0 ;
        ledC2 = 1;
        ledD2 = 1;
        ledE2 = 0 ;
        break;
    case '6':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 1;
        ledB2 = 0 ;
        ledC2 = 1;
        ledD2 = 1;
        ledE2 = 1;
        break;
    case '7':
        ledG2 = 0 ;
        ledF2 = 0 ;
        ledA2 = 1;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 0 ;
        ledE2 = 0 ;
        break;
    case '8':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 1;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 1;
        ledE2 = 1;
        break;
    case '9':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 1;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 0 ;
        ledE2 = 0 ;
        break;
    case 'A':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 1;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 0 ;
        ledE2 = 1;
        break;
    case 'B':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 0 ;
        ledB2 = 0 ;
        ledC2 = 1;
        ledD2 = 1;
        ledE2 = 1;
        break;
    case 'C':
        ledG2 = 1;
        ledF2 = 0 ;
        ledA2 = 0 ;
        ledB2 = 0 ;
        ledC2 = 0 ;
        ledD2 = 1;
        ledE2 = 1;
        break;
    case 'D':
        ledG2 = 1;
        ledF2 = 0 ;
        ledA2 = 0 ;
        ledB2 = 1;
        ledC2 = 1;
        ledD2 = 1;
        ledE2 = 1;
        break;
    case 'E':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 1;
        ledB2 = 0 ;
        ledC2 = 0 ;
        ledD2 = 1;
        ledE2 = 1;
        break;
    case 'F':
        ledG2 = 1;
        ledF2 = 1;
        ledA2 = 1;
        ledB2 = 0 ;
        ledC2 = 0 ;
        ledD2 = 0 ;
        ledE2 = 1;
        break;
  }
}
