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

char getcharac(){
    int dig = getchar();
    if(dig!='c' && dig!='C' && dig!='m' &&dig!='M'){
        return getcharac();
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

int converter(int centimetros){
    return centimetros/100;
}

int calcular_volume(int altura, int largura, int comprimento){ //recebe valor em metros, calcula metros cubicos e transforma em l
    return altura*largura*comprimento*1000;
}

int main(){
    char medidas;
    int largura, comprimento, profundidade;
    int volume;
    puts("capacidade de uma piscina");
    puts("digite c para centimetros e m para metros:");
    medidas = getcharac();
    
    puts("informe as medidas na unidade escolhida");
    puts("largura:");
    largura = get3dig();
    puts("comprimento:");
    comprimento = get3dig();
    puts("profundidade:");
    profundidade = get3dig();
    
    if (medidas == 'c' || medidas == 'C'){
        largura = converter(largura);
        comprimento = converter(comprimento);
        profundidade = converter(profundidade);
        volume = calcular_volume(profundidade,largura,comprimento);
    }else if(medidas= 'm' || medidas == 'M'){
        volume = calcular_volume(profundidade,largura,comprimento);
    }
    puts("o volume da piscina em litros:");
    putnum(volume);
    
}
