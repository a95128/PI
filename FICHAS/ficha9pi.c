#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

int max(int a, int b) {
    return (a>b) ? a : b;
}

int altura(ABin A) {
    int res=0;
    if(A==NULL) res = 0;
    else {
        res = 1 + max(altura(A->esq), altura(A->dir));
    }
    return res;
}

int nFolhas(ABin A) {
    if(A==NULL) return 0;
    if(A->esq == NULL && A->dir == NULL) return 1;
    return nFolhas(A->esq) + nFolhas(A->dir);
}

ABin maisEsquerda(ABin A) {
    while(A->esq != NULL && A!=NULL) A = A->esq;
    return A;
}

void imprimeNivel(ABin A, int l) {
    if(A!=NULL) {
        if(l == 0) printf("%d\n", A->valor);
        else {
            imprimeNivel(A->esq, l-1);
            imprimeNivel(A->dir, l-1);
        }
    }
}

int procuraE(ABin a, int x) {
    int res = 0;
    if(a!=NULL) {
        if(a->valor == x) res = 1;
        else {
            res = procuraE(a->esq, x) || procuraE(a->dir, x);
        }
    }
}

struct nodo *procura (ABin a, int x) {
    if(a == NULL) return NULL;
    if(a->valor == x) return a;
    else {
        if(a->valor > x) return procura(a->esq, x);
        else return procura(a->dir, x);
    }
}

int nivel (ABin a, int x) {
    int res = 0;
    if(a == NULL) res = -1;
    else {
        if(a->valor == x) res = 0;
        else {
            if(a->valor > x) res = 1 + nivel(a->esq, x);
            else res = 1 + nivel(a->dir, x);
        }
    }
    return res;
}

void imprimeAte (ABin a, int x) {
    if(a!=NULL) {
        if(a->valor < x) printf("%d\n", a->valor);
        else {
            if(a->valor > x) imprimeAte(a->esq, x);
            else imprimeAte(a->dir, x);
        }
    }

}

int main () {
    ABin A = newABin(1, newABin(2, newABin(4, NULL, NULL), newABin(5, NULL, NULL)), newABin(3, NULL, NULL));
    printf("Altura: %d\n", altura(A));
    return 0;
}