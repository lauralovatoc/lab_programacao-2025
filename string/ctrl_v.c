//funcao que imita o ctrl v

#include <string.h>
#include <stdio.h>

void ctrl_v(char str[], int index, char substring[]){
    int tam_sub = strlen(substring);
    int tam_str = strlen(str);

    int cont = tam_str+index+tam_sub;

    //colocar o texto original depois de onde a substring entra    /*
    for(int i=index;i<=tam_str;i++){
        str[cont] = str[i];
        cont++;
    }
    */
    for(int i=index+tam_str;i>=index;i--){
        str[cont] = str[i];
        cont--;
    }


    int j=0;
    //adicionar substring no "espaço aberto" pelo laço de repetição
    for(int i=index;i<index+tam_sub;i++){
        str[i]=substring[j];
        j++;
    }
}

void inicializar_string(char v[]){
    printf("Entre com uma linha: ");
    scanf(" %100[^\n]",v);
    printf("\n");
}

int main(){
    int tam = 100, pos;
    char v[tam], sub[20];

    inicializar_string(v);

    printf("Posicao a ser alterada: ");
    scanf("%d", &pos);

    printf("String adicionada: ");
    scanf(" %20[^\n]",sub);

    printf("\n\n\tString incial: %s",v);

    ctrl_v(v, pos, sub);

    printf("\n\tString apos alteracoes: %s", v);

}
