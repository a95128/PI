#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

//EXERCICIO 1

int nota (Aluno a) {
    float media_mini = 0.0;
    for(int i = 0; i< 6; i++) {
        media_mini += a.miniT[i];
    }
    media_mini = media_mini / 6;

    float nota_final = media_mini * 0.2 + a.teste * 0.8;

    int nota = roundf(nota_final);
    if(nota < 10) return 0;
    else { return nota;}
}

//EXERCICIO 2

int procuraNum (int num, Aluno t[], int N) {
    int indice = -1;
    for(int i = 0; i < N;i++){
        if(num == t[i].numero) indice = i;
    }

    return indice;
}

//EXERCICIO 3

void swap_aluno(t,i,j) {
    Aluno tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}

void ordenaPorNum(Aluno t[], int N) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N-1; j++) {
            if(t[j].num > t[j+1].num) {
                swap_aluno(t, j, j+1);
            }
        }
    }
}

//EXERCICIO 6

void criaIndPorNum (Aluno t [], int N, int ind[]) {
    int i , j;
    for(int i = 0; i < N ; i++) {
        for(int j = 0; j < N-i-1; j++ ) {
            if(t[ind[j]].numero > t[ind[j+1]].numero) {
                swap(ind, j, j+1);
            }
        }
    }
}

//EXERCICIO 7

void criaIndPorNum (Aluno t [], int N, int ind[]) {
    int i , j;
    for(int i = 0; i < N ; i++) {
        for(int j = 0; j < N-i-1; j++ ) {
            if(t[ind[j]].nome > t[ind[j+1]].nome) {
                swap(ind, j, j+1);
            }
        }
    }
}


int main() {
     Aluno aluno1;

    aluno1.numero = 1;
    strcpy(aluno1.nome, "João Silva");
    aluno1.miniT[0] = 80;
    aluno1.miniT[1] = 75;
    aluno1.miniT[2] = 90;
    aluno1.miniT[3] = 85;
    aluno1.miniT[4] = 88;
    aluno1.miniT[5] = 92;
    aluno1.teste = 85.5;
    int c = nota(aluno1);
    printf("%d",c);
    Aluno aluno2;

    aluno2.numero = 2;
    strcpy(aluno2.nome, "João Silva");
    aluno2.miniT[0] = 10;
    aluno2.miniT[1] = 75;
    aluno2.miniT[2] = 90;
    aluno2.miniT[3] = 15;
    aluno2.miniT[4] = 11;
    aluno2.miniT[5] = 92;
    aluno2.teste = 15.5;

    Aluno aluno3;

    aluno3.numero = 3;
    strcpy(aluno3.nome, "João Silva");
    aluno3.miniT[0] = 10;
    aluno3.miniT[1] = 75;
    aluno3.miniT[2] = 90;
    aluno3.miniT[3] = 15;
    aluno3.miniT[4] = 11;
    aluno3.miniT[5] = 92;
    aluno3.teste = 15.5;
    
    
    Aluno numeros[3] = {aluno1, aluno2, aluno3};
    int res = procuraNum(2, numeros, 3);
    printf("%d", res); 
    return 0;
}