#include <stdio.h>

char caractere;

int converter_C(int temperatura){
    return (temperatura*1.8)+32;
}

int converter_F(int temperatura){
    return (temperatura-32)* 5 / 9;
}

void getcharacter(){
    scanf(" %c",&caractere);
    if(caractere!='c' && caractere!='C' && caractere!='F' && caractere!='f'){
        printf("tente novamente\n");
        return getcharacter();
    }
}


int main(){
   int temperatura;
   printf("Digite c para Celsius e F para Farenheit: ");
   getcharacter();
   puts("Digite a temperatura:");
   scanf("%d",&temperatura);
   
   if(caractere == 'c'|| caractere == 'C'){
       temperatura = converter_C(temperatura);
       printf("A temperatura em Farenheit: %d", temperatura);
   }else if (caractere == 'f' || caractere == 'F'){
       temperatura = converter_F(temperatura);
       printf("A temperatura em Celsius: %d", temperatura);
   }
}
