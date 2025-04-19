//Função maisRepete(vetor[], tam) que retorna o índice do elemento que mais se repete dentro de vetor.Deve retornar -1 caso não exista

#include<stdio.h>

int maisRepete(int vetor[], int tam){
    int maior_cont = 1;
    int cont = 1, maior_index = -1;
     for(int i=0;i<tam;i++){
        cont =1;
        int num= vetor[i];
        for (int j=i+1;j<tam;j++){
            if(num==vetor[j]){
                cont++;
            }
        }
        if(cont>maior_cont){
            maior_cont = cont;
            maior_index=i;
        }

    }
    return maior_index; //caso nao existe repeticao
}

int main(){
    int N,valor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&N);

    printf("Digite %d termos: ",N);

    int vetor[N];

    for(int i=0;i<N;i++){
    //inicializar vetor
        scanf("%d", &vetor[i]);
    }

    int index = maisRepete(vetor, N);
    if(index==-1){
        printf("Nao ha repeticoes nesse vetor");
    } else{
        printf("O indice do valor que mais se repete no vetor: %d", index);
    }
}
