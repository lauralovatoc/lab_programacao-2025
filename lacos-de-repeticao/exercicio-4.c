/*Um laboratório tem duas colônias de bactérias. A primeira tem 5000 indivíduos, e a população dobra a cada hora.
A segunda tem 100000 indivíduos, que têm sua população multiplicada por 1,8 a cada hora. Faça um programa, usando repetição, 
para calcular quantas horas serão necessárias para que a população da primeira colônia seja maior que da segunda.
*/

#include <stdio.h>

int main(){
    float fst_b = 5000, scn_b = 100000;
    int horas=0;
    
    while(scn_b>=fst_b){
        fst_b *= 2;
        scn_b *= 1.8;
        horas++;
    }
    printf("Demorou %d horas", horas);
}
