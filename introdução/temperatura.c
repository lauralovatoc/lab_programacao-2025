#include <stdio.h>

void putnum(int x){
  if (x >= 10) {
    putnum(x / 10);
  }
  putchar('0' + x % 10);
}

int getdig(){
  int dig = getchar()- '0';
  if (dig < 0 || dig > 9){
    return getdig();
  }
  return dig;
}

char gettemp(){
    int dig = getchar();
    if(dig!='c' && dig!='C' && dig!='F' &&dig!='f'){
        return gettemp();
    }
    int y = dig;
    char x = y;
    return x;
}

int get2dig(){
  return 10 * getdig() + getdig();
}

int get3dig(){
  return get2dig()*10 + getdig();
}

int converter_C(int temperatura){
    return (temperatura*1.8)+32;
}

int converter_F(int temperatura){
    return (temperatura-32)* 5 / 9;
}

int main(){
   int temperatura;
   char caractere;
   puts("Digite c para Celsius e F para Farenheit:");
   caractere = gettemp();
   puts("Digite a temperatura:");
   temperatura = get3dig();
   if(caractere == 'c'|| caractere == 'C'){
       temperatura = converter_C(temperatura);
       puts("A temperatura em Farenheit:");
   }else if (caractere == 'f' || caractere == 'F'){
       temperatura = converter_F(temperatura);
       puts("A temperatura em Celsius:");
   }
   putnum(temperatura);
}
