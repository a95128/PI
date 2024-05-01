#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT[5];
    float teste;
} Aluno;

void imprime (Aluno t[], int N) {
    for(int i = 0; i<N; i++) {
        printf("Numero: %d\n", t[i].numero);
        printf("Nome: %s\n", t[i].nome);
        printf("MiniT: ");
        for(int j = 0; j<5; j++) {
            printf("%d ", t[i].miniT[j]);
        }
        printf("\n");
        printf("Teste: %f\n", t[i].teste);
    }

}

int nota(Aluno a) {
    int res = 0;
    int notaFinal = 0;
    int somaMT = 0;
    for(int i = 0; i<5; i++) {
        somaMT += a.miniT[i];
    }
    notaFinal = (somaMT / 5 ) * 0.20 + a.teste * 0.80;
    if(notaFinal >= 9.5) { res = notaFinal;}
    else {res = 0;}
    return res;
}

int procuraNum (int num, Aluno t[], int N) {
    int indice = -1;
    for(int i = 0; i<N; i++) {
        if(t[i].numero == num) {
            indice = i;
        }
    }
    return indice;
}

void swap_aluno(Aluno v[], int i, int j) {
    Aluno temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int contaMaior(Aluno t[], int N, int x) {
    int conta = 0;
    for(int i = 0; i<N; i++) {
        if(t[i].numero < x) {
            conta++;
        }
    }
    return conta;
}


void criaIndPorNum (Aluno t [], int N, int ind[]) {
    for(int i = 0; i < N; i++) {
        ind[i] = contaMaior(t, N, t[i].numero);
    }

    for(int i = 0; i < N; i++) {
        printf("%d ", ind[i]);
 }
 }

 void ordenaPorNum (Aluno t [], int N) {
    int indice[N];
    criaIndPorNum(t, N, indice);
    Aluno aux[N];
    for(int i = 0; i<N; i++) {
        aux[indice[i]] = t[i];
    }
    imprime(aux, N);
}

void imprimeTurma (int ind[], Aluno t[], int N) {
    criaIndPorNum(t, N, ind);
    for(int i = 0; i<N; i++) {
        printf("Numero: %d\n", t[ind[i]].numero);
        printf("Nome: %s\n", t[ind[i]].nome);
        printf("MiniT: ");
        for(int j = 0; j<5; j++) {
            printf("%d ", t[ind[i]].miniT[j]);
        }
        printf("\n");
        printf("Teste: %f\n", t[ind[i]].teste);
        
    }
}


void criaIndPorNome(Aluno t[], int N, int ind[]) {
    // Cria um array auxiliar para verificar quais nomes já foram processados
    int processados[N];
    for (int i = 0; i < N; i++) {
        processados[i] = 0;
    }

    // Preenche os índices de acordo com a ordem alfabética dos nomes dos alunos
    for (int i = 0; i < N; i++) {
        int menor_indice = -1;
        char menor_nome[100] = ""; // Assumindo que o nome do aluno tem no máximo 100 caracteres

        // Encontra o próximo nome menor que ainda não foi processado
        for (int j = 0; j < N; j++) {
            if (!processados[j] && (menor_indice == -1 || strcmp(t[j].nome, menor_nome) < 0)) {
                menor_indice = j;
                strcpy(menor_nome, t[j].nome);
            }
        }

        // Marca o nome como processado e armazena o índice
        processados[menor_indice] = 1;
        ind[i] = menor_indice;
    }

        for(int i = 0; i < N; i++) {
        printf("%d ", ind[i]);
 }

    
}


int main() {
    Aluno a = {4444, "Andre", {2,1,0,2,2}, 12.5};
    Aluno b = {5555, "Joao", {2,2,2,2,2}, 10.5};
    Aluno c = {666, "Maria", {2,2,2,2,2}, 9.0};
    Aluno d ={7777, "Joana", {2,2,2,2,1}, 18.5};
    int res = nota(a);
    Aluno t[4] = {a,b,c,d};
    Aluno t2[4]= {{4444, "Andre", {2,1,0,2,2}, 10.5}
                ,{7777, "Maria", {2,2,2,2,2}, 18.5}
                ,{2222, "Joana", {2,2,2,1,0}, 14.5}
                ,{3333, "Paulo", {0,0,2,2,2}, 8.7}
                };
    int res2 = procuraNum(666, t, 4);
    printf("%d\n", res2);
    //ordenaPorNum(t2, 4);
    int ind[4];
    //criaIndPorNum(t2, 4, ind);
    //imprimeTurma(ind, t2, 4);
    criaIndPorNome(t2, 4, ind);

    return 0;
}