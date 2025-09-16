#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 100  
#define STR 50    
// Estrutura da Pilha
typedef struct {
    char itens[MAX][STR]; 
    int topo;
} Pilha;
 
// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}
 
// Verifica se está vazia
int vazia(Pilha *p) {
    return p->topo == -1;
}
 
// Verifica se está cheia
int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}
 
// Empilhar (registrar operação)
void push(Pilha *p, char operacao[]) {
    if (cheia(p)) {
        printf(" Pilha cheia! Não é possível registrar mais operações.\n");
    } else {
        p->topo++;
        strcpy(p->itens[p->topo], operacao);
        printf(" Operação registrada: %s\n", operacao);
    }
}
 
// Desempilhar (desfazer última operação)
void pop(Pilha *p) {
    if (vazia(p)) {
        printf(" Nenhuma operação para desfazer.\n");
    } else {
        printf("↩ Desfez: %s\n", p->itens[p->topo]);
        p->topo--;
    }
}
 
// Mostrar histórico
void mostrar(Pilha *p) {
    if (vazia(p)) {
        printf(" Histórico vazio.\n");
    } else {
        printf("\n Histórico de operações:\n");
        for (int i = 0; i <= p->topo; i++) {
            printf("%d. %s\n", i + 1, p->itens[i]);
        }
    }
}
 
// Programa principal
int main() {
    Pilha pilha;
    inicializar(&pilha);
    int opcao;
    char operacao[STR];
 
    do {
        printf("\n===== MENU =====\n");
        printf("1 - Realizar operação\n");
        printf("2 - Desfazer última operação\n");
        printf("3 - Mostrar histórico\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer do Enter
 
        switch (opcao) {
            case 1:
                printf("Digite a operação: ");
                fgets(operacao, STR, stdin);
                operacao[strcspn(operacao, "\n")] = '\0'; // remover \n
                push(&pilha, operacao);
                break;
            case 2:
                pop(&pilha);
                break;
            case 3:
                mostrar(&pilha);
                break;
            case 0:
                printf(" Encerrando:\n");
                break;
            default:
                printf(" Opção inválida!\n");
        }
    } while (opcao != 0);
 
    return 0;
}
 