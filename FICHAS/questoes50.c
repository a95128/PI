#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

//EXERCICIO 7

char *mystrcat(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j;
    char *aux = (char *)malloc(len1 + len2 + 1);
    for (int i = 0; i < len1; i++) {
        aux[i] = s1[i];
    }

    for (int j = 0; j < len2; j++) {
        aux[len1 + j] = s2[j];
    }
    aux[len1 + len2] = '\0'; 
    return aux;
}

//EXERCICIO 8

char *mystrcpy (char *dest, char source[]) {
    int i;
    for(i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0'; // Null terminate the destination string
    return dest;
}

//EXERCICIO 9

int mystrcmp (char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return -1; 
        } else if (s1[i] > s2[i]) {
            return 1;
        }
        i++;
    }

    if (s1[i] != '\0' && s2[i] != '\0'){
        return 0;
    } else if (s1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

//EXERCICIO 10

//EXERCICIO 11

void strrev (char s[]) {
    char aux;
    int length = strlen(s);
    for(int i = 0; i != (length-1)/2; i++) {
        aux = s[length-i-1];
        s[length-i-1] = s[i];
        s[i] = aux;

    }
    printf("%s", s);
}

//EXERCICIO 12

int evogal(char l) {
    if (l=='a' || l=='A' ||
        l=='e' || l=='E' ||
        l=='i' || l=='I' ||
        l=='o' || l=='o' ||
        l=='u' || l=='U') 
        return 0;
}
void strnoV (char s[]) {
    char aux[strlen(s)+1];
    int j = 0;
    for(int i =0; s[i] != '\0' ; i++) {
        if(evogal(s[i]) != 0) {
            aux[j] = s[i];
            j++;
        }
    }
    printf("%s", aux);
}

//EXERCICIO 13

void delete (int i, char s[]) {
    for (i;s[i];i++)
        s[i]=s[i+1];
}

void truncW (char t[], int n){
    int i = 0;
    int comp = 0;
    char c;
    while (t[i])
        if (t[i] == ' ') {
            comp = 0;
            i++;
        } else if (comp<n) {
            comp++;
            i++;
        }
        else {delete (i,t);
            comp++;
        }
    printf("%s",t);
    
}

//EXERCICIO 14

int conta(char c, char s[]) {
    int conta=0;
    for(int i=0; s[i]!='\0';i++) {
        if(s[i]==c){ conta++;};
    }

    return conta;
}

char charMaisfreq (char s[]) {
    char aux=s[0];
    for(int i = 0; s[i]!='\0';i++) {
        if(conta(s[i], s) > conta(aux,s)) {aux = s[i];}
    }
    return aux;
}

//EXERCICIO 15

int iguaisConsecutivos(char s[]) {
    int conta1 = 1;
    int aux = 1; 
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++) {
        if (s[i] == s[i + 1]) {
            conta1++; 
            if (conta1 > aux) {
                aux = conta1;
            }
        } else {
            conta1 = 1; 
        }
    }
    return aux;
}


//EXERCICIO 16

int difConsecutivos (char s[]) {
   int conta1 = 0;
    int aux = 0; 
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++) {
        if (s[i] != s[i + 1]) {
            conta1++; 
            if (conta1 > aux) {
                aux = conta1;
            }
        } else {
            conta1 = 1; 
        }
    }
    return aux;
} 

//EXERCICIO 17

int maiorPrefixo(char s1[], char s2[]) {
    int conta=0;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] == s2[i])
            conta++;
    }
    return conta;
}

//EXERCICIO 18

int maiorSufixo(char s1[], char s2[]) {
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int conta = 0;

    while (length1 > 0 && length2 > 0 && s1[length1 - 1] == s2[length2 - 1]) {
        conta++;
        length1--;
        length2--;
    }

    return conta;
}

//EXERCICIO 19

int sufPref (char s1[], char s2[]) {
    int i = 0;
    int j = 0;
    int r = 0;

    while (s1[i] != '\0') {
        if (s1[i] == s2[j]) {
            r++;
            i++;
            j++;
        } else {
            r = 0;
            j = 0;
            i++;}
    }
    return r;
}

//EXERCICIO 20

int contaPal (char s[]) {
    int conta = 0;
    for(int i = 0; s[i]!='\0';i++) {
        if(s[i]!=' ' && s[i+1]==' '|| s[i]!=' ' && s[i+1]=='\0' ) {
            conta++;
        }
    }
    return conta;
}

//EXERCICIO 21

int contaVogais(char s[]) {
    int conta = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A' || s[i] == 'a' || 
            s[i] == 'E' || s[i] == 'e' || 
            s[i] == 'I' || s[i] == 'i' || 
            s[i] == 'O' || s[i] == 'o' || 
            s[i] == 'U' || s[i] == 'u') {
            conta++;
        }
    }
    return conta;
}

//EXERCICIO 22

int contemchar(char s, char p[]) {
    for (int i = 0; p[i] != '\0'; i++) {
        if (s == p[i]) return 1;
    }
    return 0;
}

int contida(char a[], char b[]) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (contemchar(a[i], b) == 0) return 0;
    }
    return 1;
}

//EXERCICIO 23

int palindorome (char s[]) {
    int length = strlen(s);
    char t[length + 1];
    strcpy(t,s);
    for(int i = 0; s[i]!='\0'; i++) {
        if(t[i] !=  s[length-1-i]) return 0;
    }
    return 1;
}

//EXERCICIO 24

int remRep(char x[]) {
    int len = 1; 
    char prev = x[0];

    for (int i = 1; x[i] != '\0'; i++) {
        if (x[i] != prev) { 
            x[len] = x[i];
            len++;
            prev = x[i];
        }
    }
    x[len] = '\0'; 
    return len;
}

//EXERCICIO 25

int limpaEspacos(char t[]) {
    int length = strlen(t);
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; i++) {
        if (!(t[i] == ' ' && t[i + 1] == ' ')) { 
            t[j++] = t[i];
        }
    }
    t[j] = '\0'; 

    return j; 
}

//EXERCICIO 26

void insere (int s[], int N, int x){
    s[N]=x;
    while (N>0) {
        if (s[N]>=s[N-1]) {N--;}
        else {
            int y = s[N-1];
            s[N-1]=s[N];
            s[N] = y;
        }
    }
}

//EXERCICIO 27

 void merge (int r [], int a[], int b[], int na, int nb) {
    for(int i = 0; i<na;i++) {
        r[i] = a[i];
    }

    for(int j =0; j<nb;j++) {
        insere(r, na+j, b[j]);
    }
 }

//EXERCICIO 28

int crescente (int a[], int i, int j) {
    for(int t = i; t < j; t++) {
        if(a[t]>a[t+1]) return 0;
    }
    return 1;
}

//EXERCICIO 29


int retiraNeg(int v[], int N) {
    int count = 0; 

    for (int i = 0; i < N-1; i++) {
        if (v[i] >= 0) { 
            v[count] = v[i]; 
            count++; 
    }
    }
    return count; 
}

//EXERCICIO 30

int contaocorrencias(int v[], int N, int x) {
    int conta=0;
    for(int i = 0; i<N;i++) {
        if(v[i] == x) conta++;
    }
    return conta;
}

int menosFreq(int v[], int N) {
    int menos_frequente = v[0];
    for (int i = 1; i < N; i++) {
        if (contaocorrencias(v, N, v[i]) < contaocorrencias(v, N, menos_frequente)) {
            menos_frequente = v[i];
        }
    }

    return menos_frequente;
}

//EXERCICIO 31

int maisFreq(int v[], int N) {
    int mais_frequente = v[0];
    for (int i = 1; i < N; i++) {
        if (contaocorrencias(v, N, v[i]) > contaocorrencias(v, N, mais_frequente)) {
            mais_frequente = v[i];
        }
    }

    return mais_frequente;
}

//EXERCICIO 32

int maxCresc(int v[], int N) {

    int max = 1; 
    int count = 1; 

    for (int i = 1; i < N; i++) {
        if (v[i] > v[i - 1]) { 
            count++;
            if (count > max) { 
                max = count;
            }
        } else { 
            count = 1;
        }
    }

    return max; 
}

//EXERCICIO 33

int elimRep(int v[], int n) {
    int unique_count = 1; // Contador para manter o número de elementos únicos encontrados até agora
    int flag[n]; // Array de flags para marcar os elementos já vistos

    for (int i = 0; i < n; i++) {
        flag[i] = 0; // Inicializa todas as flags como 0 (indicando que ainda não foram vistos)
    }

    for (int i = 1; i < n; i++) {
        int j;
        for (j = 0; j < unique_count; j++) {
            if (v[i] == v[j]) { // Se o elemento já estiver presente
                break; // Não adiciona este elemento ao vetor resultante
            }
        }
        if (j == unique_count) { // Se o elemento não estiver presente, adiciona-o ao vetor resultante
            v[unique_count] = v[i];
            unique_count++;
        }
    }

    return unique_count; // Retorna o número de elementos únicos no vetor resultante
}

//EXERCICIO 34

int elimRepOrd(int v[], int n) {
    int count = 1; 

    for (int i = 1; i < n; i++) {
        if (v[i] != v[count - 1]) { 
            v[count] = v[i]; 
            count++;
        }
    }

    return count; 
}

//EXERCICIO 35

int contem3(int num, int v[], int N) {
    for(int i = 0; i < N; i++) {
        if(v[i] == num) return 1;
    }
    return 0;
}

int comunsOrd(int a[], int na, int b[], int nb) {
    int count=0;
    for(int i=0;i<nb;i++) {
        if(contem3(b[i],a,na)==1) count++;
    }
    return count;
}

//EXERCICIO 36

int comuns(int a[], int na, int b[], int nb) {
    int count=0;
    for(int i=0;i<nb;i++) {
        if(contem3(b[i],a,na)==1) count++;
    }
    return count;
}

//EXERCICIO 37

int minInd (int v[], int n) {
    int indice = 0;
    int numero = v[0];
    for(int i = 0; i < n;i++) {
        if(v[i] < numero) {
           numero = v[i];
           indice = i;
        }
        if(v[i]==numero) {
            numero=v[i];
            if(indice>i) indice = i;
        }
    }
    return indice;
}

//EXERCICIO 38

void somasAc (int v[], int Ac [], int N) {
    int soma=0;
    for(int i=0; i < N;i++) {
        soma +=v[i];
        Ac[i] = soma;
    }

}

//EXERCICIO 39
int triSup(int N, float m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j && m[i][j] != 0) 
                return 0; 
        }
    }
    return 1;
}

//EXERCICIO 40

void transposta (int N, float m [N][N]) {
    float arr [N][N];
    int i = 0, p = 0;

    while (p<N){
        int i = 0;
        while (i<N){
            arr [p][i]= m [i][p];
            i++;
        }
        p++;
    }

    i=0;
    while (i<N){
        int c = 0;
        while(c<N){
            m [i][c]=arr [i][c];
            c++;
        }
        i++;
    }
}

//EXERCICIO 41

void addTo (int N, int M, int a [N][M], int b[N][M]) {
    for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] += b[i][j];
            }
        }
}

//EXERCICIO 42

int unionSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        if (v1[i] == 1 || v2[i] == 1) {
            r[i] = 1; 
        } else {
            r[i] = 0; 
        }
    }
}

//EXERCICIO 43

int intersectSet (int N, int v1[N], int v2[N], int r[N]) {
        for (int i = 0; i < N; i++) {
        if (v1[i] == 1 && v2[i] == 1) {
            r[i] = 1; 
        } else {
            r[i] = 0; 
        }
    }

}

//EXERCICIO 44 

int unionMSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] + v2[i]; 
    }
}

//EXERCICIO 45

int intersectMSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        if (v1[i] < v2[i]) {
            r[i] = v1[i]; 
        } else {
            r[i] = v2[i];
        }
    }
}

//EXERCICIO 46

int cardinalMSet(int N, int v[N]) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += v[i]; 
    }
    return total;
}

//EXERCICIO 47


typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    for(int i = 0; i < N; i++) {
        if(mov[i]== Norte) inicial.y += 1;
        if(mov[i]== Sul) inicial.y -= 1;
        if(mov[i]== Este) inicial.x += 1;
        if(mov[i]== Oeste) inicial.x -= 1;
    }
    return inicial;
}

//EXERCICIO 48


int caminho(Posicao inicial, Posicao final, Movimento mov[], int N) {
    int dif_x = final.x - inicial.x;
    int dif_y = final.y - inicial.y;

    int total_movimentos = 0;

    while (dif_y > 0 && total_movimentos < N) {
        mov[total_movimentos++] = Norte;
        dif_y--;
    }
    while (dif_y < 0 && total_movimentos < N) {
        mov[total_movimentos++] = Sul;
        dif_y++;
    }
    while (dif_x > 0 && total_movimentos < N) {
        mov[total_movimentos++] = Este;
        dif_x--;
    }
    while (dif_x < 0 && total_movimentos < N) {
        mov[total_movimentos++] = Oeste;
        dif_x++;
    }

    if (total_movimentos < N && (dif_x != 0 || dif_y != 0)) {
        return -1;
    }

    return total_movimentos;
}

//EXERCICIO 49

int maisCentral(Posicao pos[], int N) {
    int indice_mais_central = 0;
    double menor_distancia = __INT_MAX__;; 

    for (int i = 0; i < N; i++) {
        double distancia = pos[i].x * pos[i].x + pos[i].y * pos[i].y;
        if (distancia < menor_distancia) {
            menor_distancia = distancia;
            indice_mais_central = i;
        }
    }

    return indice_mais_central;
}

//EXERCICIO 50

int vizinhos(Posicao p, Posicao pos[], int N) {
    int adjacencias = 0;

    for (int i = 0; i < N; i++) {
        if ((abs(pos[i].x - p.x) <= 1) && (abs(pos[i].y - p.y) <= 1) && (pos[i].x != p.x || pos[i].y != p.y)) {
            adjacencias++;
        }
    }

    return adjacencias;
}


int main() {
    char s1[] = "hello";
    char s2[] = "world";
    char s3[] = "liberdade, igualdade e fraternidade";
    char s4[] = "aabcccaac";
    char s5[] = "braga";
    char s6[] = "bracara augusta";
    char s7[] = "bracarense";
    char s8[] = "totalidade";
    char s9[] = "aaaba  a fas das  sad";
    //char* result = mystrcat(s1,s2);
    //printf("%s\n", result);
    //char dest[50];
    //char source[] = "Copying this string";
    //mystrcpy(dest, source);
    //printf("%s\n", dest);
    //strrev(s1);
    //strnoV(s2);
    //truncW(s3,4);
    //char r = charMaisfreq(s3);
    //int r = iguaisConsecutivos(s4);
    //int r = difConsecutivos(s1);
    //int r = maiorPrefixo(s1,s2);
    //int r = maiorSufixo(s5,s6);
    //int r = sufPref(s7,s8); 
    //int r = contaPal(s9);
    //int r = contaVogais(s8);
    //int r = contida(s5, s6);
    //int r = palindorome(s9);
    //int r = remRep(s9);
    //int r = limpaEspacos(s9);
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 9, 6, 7 ,8,3,1,3, 5};
    int c[] = {1,2,3,4,3,4,2,1,9,1,2,7};
    int d[] = {1, 2, 3, 2, 1, 4, 10, 12, 5, 4};
    //int na = sizeof(a) / sizeof(a[0]);
    //int nb = sizeof(b) / sizeof(b[0]);
    //int r[na + nb];
    //merge(r, a, b, na, nb);
    //int r = crescente(a, 2,4);
    //int r = retiraNeg(a, 5);
    //int r = menosFreq(c, 11);
    //int r = maisFreq(c,12);
    //int r = maxCresc(d,10);
    //int r = comunsOrd(a,5,b,7);
    //int r = comuns(a,5,b,7);
    //int r = minInd(b,9);
    Posicao inicial = {4, 5};
    Movimento movimentos[] = {Norte, Este, Este, Oeste};

    Posicao final = posFinal(inicial, movimentos, sizeof(movimentos) / sizeof(Movimento));

    printf("Posição final: (%d, %d)\n", final.x, final.y);

    // Verifica se a matriz é triangular superior
    
    //printf("%d", r);

    return 0;
}