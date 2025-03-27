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

int get3dig(){
  return get2dig()*10 + getdig();
}

int verificar_imc(int peso,int altura){
	return (peso*10000)/(altura*altura);
}

int main(){
	int peso, altura;
 	puts("Seu peso em kg:");
        peso = get3dig();
 	puts("Sua altura em cm:");
  	altura = get3dig();
  	int imc = verificar_imc(peso, altura);
	puts("Seu imc equivale a ");
	putnum(imc);
}
