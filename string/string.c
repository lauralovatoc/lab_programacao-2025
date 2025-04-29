#include <stdio.h>
#include <stdbool.h>

void impstr(char s[]){
    for(int i =0; s[i] != '\0';i++){
        putchar(s[i]);
    }
}

int tamanho(char s[]){
    int i =0;
    for(i=0; s[i] != '\0';i++){}
    return i;
}

bool minuscula(char c){//retorna true se o caractere for minusculo
    return c>='a' && c<='z';
}

char upper_char(char c){
    if(!minuscula(c)){
        return c;
    }
    return c  - 'a' + 'A';
}

bool vogal(char c){
    c = upper_char(c);
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}


int contador_vogais(char s[]){
    int contador=0;
    for(int i =0; s[i] != '\0';i++){
        if(vogal(s[i])){
            contador++;
        }
    }
    return contador;
}

void upper_str(char s[]){
    for(int i = 0; s[i] != '\0';i++){
        if(minuscula(s[i])){
            s[i] = upper_char(s[i]);
        }
    }
}

void copia(char destino[], char origem[]){
    for(int i = 0; ;i++){
        destino[i]= origem[i];
        if(destino[i]=='\0') break;
    }
}


int main(){
    char v[100]="Laura Lovato Camponogara";
    char str_copy[100];

    printf("\n\tString: ");
    impstr(v);

    copia(str_copy, v);

    printf("\n\tTamanho da string: %d", tamanho(v));
    printf("\n\tNumero de vogais: %d", contador_vogais(v));
    printf("\n\tLetras maiusculas: ");

    upper_str(v);
    impstr(v);

    printf("\n\tCopia da string inicial: ");
    impstr(str_copy);

    puts("");
}
