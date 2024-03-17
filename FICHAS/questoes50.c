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

void insere (int v[], int N, int x) {
    
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
    int r = limpaEspacos(s9);

    printf("%d", r);
    return 0;
}