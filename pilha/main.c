#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERACOES 100
#define MAX_TAM_OPERACAO 100

typedef struct {
    char operacoes[MAX_OPERACOES][MAX_TAM_OPERACAO];
    int topo;
} PilhaOperacoes;

void inicializar(PilhaOperacoes *pilha) {
    pilha->topo = -1;
}

int esta_vazia(PilhaOperacoes *pilha) {
    return pilha->topo == -1;
}

int esta_cheia(PilhaOperacoes *pilha) {
    return pilha->topo == MAX_OPERACOES - 1;
}

// push: adiciona uma operação na pilha
int push(PilhaOperacoes *pilha, const char *operacao) {
    if (esta_cheia(pilha)) {
        return 0; // falha ao adicionar
    }
    pilha->topo++;
    strncpy(pilha->operacoes[pilha->topo], operacao, MAX_TAM_OPERACAO - 1);
    pilha->operacoes[pilha->topo][MAX_TAM_OPERACAO - 1] = '\0';
    return 1; // sucesso
}

// pop: remove a operação do topo e copia para buffer
int pop(PilhaOperacoes *pilha, char *buffer, size_t buffer_size) {
    if (esta_vazia(pilha)) {
        return 0; // pilha vazia
    }
    strncpy(buffer, pilha->operacoes[pilha->topo], buffer_size - 1);
    buffer[buffer_size - 1] = '\0';
    pilha->topo--;
    return 1; // sucesso
}

// top: copia a operação do topo para buffer sem remover
int top(PilhaOperacoes *pilha, char *buffer, size_t buffer_size) {
    if (esta_vazia(pilha)) {
        return 0; // pilha vazia
    }
    strncpy(buffer, pilha->operacoes[pilha->topo], buffer_size - 1);
    buffer[buffer_size - 1] = '\0';
    return 1; // sucesso
}

void mostrar_historico(PilhaOperacoes *pilha) {
    if (esta_vazia(pilha)) {
        printf("Nenhuma operação no histórico.\n");
        return;
    }
    printf("Histórico atual de operações:\n");
    for (int i = 0; i <= pilha->topo; i++) {
        printf("%d. %s\n", i + 1, pilha->operacoes[i]);
    }
}

int main() {
    PilhaOperacoes pilha;
    char buffer[MAX_TAM_OPERACAO];

    inicializar(&pilha);

    push(&pilha, "Escreveu palavra \"Olá\"");
    push(&pilha, "Escreveu palavra \"mundo\"");

    mostrar_historico(&pilha);

    if (top(&pilha, buffer, sizeof(buffer))) {
        printf("Operação no topo: \"%s\"\n", buffer);
    } else {
        printf("Pilha vazia.\n");
    }

    if (pop(&pilha, buffer, sizeof(buffer))) {
        printf("Desfez a operação: \"%s\"\n", buffer);
    } else {
        printf("Nenhuma operação para desfazer.\n");
    }

    mostrar_historico(&pilha);

    return 0;
}
