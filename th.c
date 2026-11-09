#include <stdio.h>
#include <stdlib.h>
#include "th.h"

int funcao_hash(int chave, int tamanho) {
    return abs(chave) % tamanho;
}

TabelaHash* criar_tabela(int tamanho) {
    TabelaHash* th = (TabelaHash*)malloc(sizeof(TabelaHash));
    th->tamanho = tamanho;
    th->tabela = (No**)calloc(tamanho, sizeof(No*));
    return th;
}

// Procura o nó com o valor no balde certo. Retorna NULL se não existir.
static No* procurar_no(TabelaHash* th, int valor) {
    No* atual = th->tabela[funcao_hash(valor, th->tamanho)];
    while (atual != NULL && atual->valor != valor) {
        atual = atual->prox;
    }
    return atual;
}

// Soma 1 à contagem do valor. Se o valor ainda não existe, cria com contagem 1.
void incrementar(TabelaHash* th, int valor) {
    No* no = procurar_no(th, valor);
    if (no != NULL) {
        no->contagem++;
        return;
    }
    int indice = funcao_hash(valor, th->tamanho);
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->contagem = 1;
    novo->prox = th->tabela[indice];
    th->tabela[indice] = novo;
}

// Retorna quantas vezes o valor foi incrementado (0 se nunca foi).
int frequencia(TabelaHash* th, int valor) {
    No* no = procurar_no(th, valor);
    if (no == NULL) {
        return 0;
    }
    return no->contagem;
}

void liberar_tabela(TabelaHash* th) {
    for (int i = 0; i < th->tamanho; i++) {
        No* atual = th->tabela[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(th->tabela);
    free(th);
}
