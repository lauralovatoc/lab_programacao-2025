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
/*
int converter_metragem(int hm){ //converte hm em  km
    return hm/10;
}

int converter_moeda(int valor){
    return valor/100;
}
*/
int gasolina_percurso(int gasolina, int consumo, int distancia){
    int litros = distancia * 10 / consumo;
    return litros * gasolina /100;
}


int main(){
    int valor, consumo_medio, distancia; //valor do litro da gasolina em centavos //quantos litros usa pra rodar 1hm(1km=10hm)
    puts("digite o valor da gasolina em centavos:");
    valor = get3dig();
    puts("digite o consumo medio do seu carro em Hm:");
    consumo_medio = get3dig();
    puts("digite a distancia a ser percorrida em Km:");
    distancia = get3dig();
    
    //consumo_medio = converter_metragem(consumo_medio);
    //valor = converter_moeda(valor);
    
    int valor_total = gasolina_percurso(valor, consumo_medio, distancia);
    puts("Para fazer a distancia digitada com o consumo medio do seu carro, você vai gastar R$");
    putnum(valor_total);
}
