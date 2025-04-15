#include<stdio.h>

//desenha tantos caracteres de tal tipo
void imprime_caracteres(int quant, char tipo){
    int cont = 0;

    while(cont<quant && tipo=='p'){
        putchar('.');
        cont++;
    }
    while(cont<quant && tipo=='a'){
        putchar('*');
        cont++;
    }
}

//calcular astericos
int calcula_asteriscos(int linha, int char_linha){
    if(char_linha==linha){
        return linha;
    } else {
        return 1 + 2*(linha-1);
    }
}

//calcular pontos
int calcular_pontos(int asteriscos, int char_linha){
    return char_linha - asteriscos;
}
//desenha a linha
void print_linha(int pontos, int asteriscos){
    imprime_caracteres(pontos/2, 'p');
    imprime_caracteres(asteriscos, 'a');
    imprime_caracteres(pontos/2,'p');

}

//calcular oq precisa e imprimir a linha
void imprimir_linha(int linha, int caracteres_linha){
    int asteriscos = calcula_asteriscos(linha, caracteres_linha);
    int pontos = calcular_pontos(asteriscos, caracteres_linha);

    print_linha(pontos, asteriscos);
}

//desenha o triangulo
void desenhar_triangulo(int h){
    int linha=1;
    int caracteres_linha = h + (h-1);

    while(linha<=h){
        imprimir_linha(linha, caracteres_linha);

        linha++;
        putchar('\n');
    }

}

//main: recebe altura e imprime triangulo
int main(){
    int altura;
    printf("Digite a altura do triangulo: ");
    scanf("%d", &altura);

    desenhar_triangulo(altura);
}
