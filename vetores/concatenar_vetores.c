//concatenar vetores

#include<time.h>
#include <stdio.h>
#include<stdlib.h>

void preencher_vetor(int tam, int vetor[tam]){
    for(int i=0;i<tam;i++){
        vetor[i]=rand() % 100;
    }
}

void printar_vetor(int tam, int vetor[tam]){
    printf("\n\tValores no vetor: ");
    for(int i=0;i<tam;i++){
        printf("%d ", vetor[i]);
    }
}

void concatenar_vetor( int final[10], int tam, int v1[tam], int v2[tam]){
    for(int i=0;i<tam;i++){
        final[i]=v1[i];
        final[i+tam]=v2[i];
    }
}

int main()
{
    srand(time(NULL));

    int vet1[5], vet2[5];

    preencher_vetor(5, vet1);
    preencher_vetor(5, vet2);
    printar_vetor(5, vet1);
    printar_vetor(5, vet2);

    int v_final[10];
    
    concatenar_vetor(v_final, 5, vet1, vet2);

    printar_vetor(10, v_final);
}
