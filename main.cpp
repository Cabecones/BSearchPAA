#include<stdio.h>

int encontrar_indice_inferior(long int indice_atual, long int x, long int i, long int v[]) {
    long int tempI;
    tempI = indice_atual;

    while (tempI > i && v[tempI] == v[tempI-1]) {
        tempI--;
    }

    return tempI;
}

int busca_binaria(long int x, long int i, long int j, long int v[]) {
    long int meio;

    return (i > j || v[i] > x || v[j] < x) ? -1 :
           (x == v[meio = (i + j) / 2]) ? encontrar_indice_inferior(meio, x, i, v) :
           (v[meio] < x) ? busca_binaria(x, meio+1, j, v) :
           busca_binaria(x, i, meio-1, v);
}

int main() {
    long int n, q, k;
    long int array[100000];
    scanf ("%ld %ld", &n, &q);
    for (int l = 0; l < n; l++)
        scanf ("%ld", &array[l]);
    for (int l = 0; l < q; l++) {
        scanf ("%ld", &k);
        printf ("%d\n", busca_binaria(k, 0, n-1, array));
    }

    return 0;
}
