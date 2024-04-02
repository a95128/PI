#include <stdio.h>

void swap(int v[], int N, int j, int i) {
    int aux;
    aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

int ParesImpares(int v[], int N) {
    int j = 0;
    int count = 0; 
    for (int i = 0; i < N; i++) {
        if (v[i] % 2 != 0) {
            while (j < N && v[j] % 2 != 0) {
                j++;
            }
            if (j < N) {
                swap(v, N, i, j);
                count++; 
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    return count; 
}

void latino(int N, int m[N][N]) {
    for (int i = 0; i < N; i++) {
        m[0][i] = i + 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = m[i - 1][(j + 1) % N]; 
        }
    }
}

int main() {
    int N = 3;
    int m[N][N];

    latino(N, m);

    printf("Quadrado Latino de dimensão %d:\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}