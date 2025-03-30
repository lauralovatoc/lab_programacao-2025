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

int get2dig(){
  return 10 * getdig() + getdig();
}

int converter(int temperatura){
    return (temperatura*1.8)+32;
}

int main(){
   int temperatura;
   puts("Digite a temperatura em Celsius");
   temperatura = get2dig();
   temperatura = converter(temperatura);
   puts("A temperatura em Farenheit:");
   putnum(temperatura);
}
