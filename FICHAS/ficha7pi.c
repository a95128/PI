#include <stdio.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista(Palavras p) {
    Palavras aux;
    while(p != NULL) {
        aux = p;
        p = p->prox;
        free(aux->palavra);
        free(aux);
    }
}

int quantasP (Palavras l) {
    int i = 0;
    while(l != NULL) {
        i++;
        l=l->prox;
    }
    return i;
}

void listaPal (Palavras l) {
    while(l != NULL) {
        printf("%s\n", l->palavra);
        l=l->prox;
    }
}

char * ultima(Palavras l) {
    while(l->prox!=NULL) {
        l=l->prox;
        if(l->prox == NULL) return l->palavra;
    }
}

Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = p;
    new->ocorr = 1;
    new->prox = l;
    return l;
}

Palavras acrescentaFim(Palavras l, char *p) {
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = p;
    new->ocorr = 1;
    new->prox = NULL;
    while(l->prox != NULL) {
        l=l->prox;
        if(l->prox==NULL) {
            l->prox = new;
        }
    }
    return l;
}

Palavras acrescenta (Palavras l, char *p) {
    Palavras new = malloc(sizeof(struct celula));
    new->palavra=p;
    new ->ocorr = 1;
    new->prox = NULL;

    while(l->prox != NULL) {
        if(strcmp(l->palavra, p) == 0) {
            l->ocorr++;
        }
        l=l->prox;
        if(l->prox == NULL) {
            l->prox = new;
        }
    }
    return l;
}

struct celula *maisFreq(Palavras l) {
    Palavras aux;
    aux->palavra=l->palavra;
    aux->ocorr=l->ocorr;

    while(l != NULL) {
        if(l->ocorr > aux->ocorr) {
            aux->palavra = l->palavra;
            aux->ocorr = l->ocorr;
            l=l->prox;
        }
        else {
            l=l->prox;
        }
    }

}


int main() {
    Palavras dic = NULL;
    libertaLista(dic);

    return 0;
}