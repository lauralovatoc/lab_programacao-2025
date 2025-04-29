#include <stdio.h>
#include <stdbool.h>

//imprimir uma string
void impstr(char s[]){
    for(int i =0; s[i] != '\0';i++){
        putchar(s[i]);
    }
}

//retorna o tamanho da string
int tamanho(char s[]){
    int i =0;
    for(i=0; s[i] != '\0';i++){}
    return i;
}

//verifica se um caractere � minusculo
bool minuscula(char c){//retorna true se o caractere for minusculo
    return c>='a' && c<='z';
}

//transforma um caracter em minusculo
char lower_char(char c){
    if(minuscula(c)){
        return c;
    }
    return c +32;
}

//transforma um caracter em maiusculo
char upper_char(char c){
    if(!minuscula(c)){
        return c;
    }
    return c  - 'a' + 'A';
}

//verifica se o caractere � uma vogal
bool vogal(char c){
    c = upper_char(c);
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

//conta e retorna o numero de vogais
int contador_vogais(char s[]){
    int contador=0;
    for(int i =0; s[i] != '\0';i++){
        if(vogal(s[i])){
            contador++;
        }
    }
    return contador;
}

//transforma uma string para que todas as letras sejam maiusculas
void upper_str(char s[]){
    for(int i = 0; s[i] != '\0';i++){
        if(minuscula(s[i])){
            s[i] = upper_char(s[i]);
        }
    }
}

//faz a copia de uma string
void copia(char destino[], char origem[]){
    for(int i = 0; ;i++){
        destino[i]= origem[i];
        if(destino[i]=='\0') break;
    }
}

//concatena duas strings
void concat(char str1[], char str2[]){
    int tam = tamanho(str1);
    str1[tam]= str2[0];
    tam++;

    for(int i=1; str2[i]!='\0';i++){
        str1[tam] = str2[i];
        tam++;
    }
}

//contar e retornar palavras em um string
int contar_palavras(char s[]){
    int contador=0;
    bool in_palavra = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i]!=' ') {
            if (in_palavra==false) {
                in_palavra = true;
                contador++;
            }
        } else {
            in_palavra = false;
        }
    }

    return contador;
}

void formatar(char s[]){
    int cont_letras=0;
    bool in_palavra = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i]!=' ') {
            if (in_palavra==false) {
                //primeira letra da palavra
                in_palavra = true;

                if(minuscula(s[i])){
                    s[i]=upper_char(s[i]);
                }
            }else{
                if(!minuscula(s[i])){
                    s[i]=lower_char(s[i]);
                }
            }
        } else {
            //demais letrar
            in_palavra = false;


        }
    }

}


int main(){
    char str1[100]="laura", str2[100]="lovato";

    concat(str1, str2);

    printf("\n\tStrings concatenadas: ");
    impstr(str1);

    char v[100]="Laura LOVATO camponogara";
    char str_copy[100];

    printf("\n\tString: ");
    impstr(v);

    copia(str_copy, v);

    printf("\n\tTamanho da string: %d", tamanho(v));
    printf("\n\tNumero de vogais: %d", contador_vogais(v));
    printf("\n\tLetras maiusculas: ");

    upper_str(v);
    impstr(v);

    printf("\n\tQuantas palavras tem: %d",contar_palavras(v));

    printf("\n\tFormatar string: ");
    formatar(v);
    impstr(v);

    printf("\n\tCopia da string inicial: ");
    impstr(str_copy);

    puts("");
}
