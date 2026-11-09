#include <stdio.h>
#include <stdlib.h>
#include "th.h"

// Retorna quantos pares (i, j), com i < j, têm v[i] + v[j] igual a k
long long contaPares(int* v, int n, int k) {
    // Implemente aqui usando o TAD TabelaHash (veja th.h)
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printf("%lld\n", contaPares(v, n, k));

    free(v);
    return 0;
}
