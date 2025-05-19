//calcular raizes de uma equacao de 2 grau
//recebe os coeficientes com argumentos 
//retorna duas raizes a partir de ponteiros (recebidos como argumentos)
//bool -> false se as raizes forem complexas (delta negativo), true se as raizes forem reais

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float calcula_delta(float a, float b, float c){
    return b*b - 4*a*c;
    
}

bool raizes(float *primeira, float *segunda, float a, float b, float c){
    float delta = calcula_delta(a,b,c);
    if(delta<0){
        return false;
    } 
     
    *primeira = (-b + sqrt(delta))/(2*a);
    *segunda = (-b - sqrt(delta))/(2*a);
    
    return true;
}

int main(){
    float a,b,c;
    printf("Entre com os coeficientes da equacao de segundo grau");
    printf("\na: ");
    scanf("%f",&a);
    printf("\nb: ");
    scanf("%f",&b);
    printf("\nc: ");
    scanf("%f",&c);
    
    float primeira, segunda;
    
    if(raizes(&primeira,&segunda,a,b,c)){
        printf("Raizes: %.2f e %.2f", primeira, segunda);
    }else{
        printf("As raizes sao complexas");
    }

}