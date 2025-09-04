#include <stdio.h>
#define MAX 5 //Define o tamanho maximo da fila
int fila[MAX];
int inicio = 0, fim = -1, qtd = 0; // controlam onde inserir/remover e quantos elementos existem.

void enqueue(int valor){
    // Insere elemento no fim da fila (se não estiver cheia).
    if (qtd == MAX){
        printf("Fila está Cheia!\n");
        return;
    }
    fim = (fim + 1) % MAX;
    fila[fim] = valor;
    qtd++;
}

int dequeue(){
    // Remove o elemento do início (se não estiver vazia).
    if (qtd == 0){
        printf("A fila está vazia!");
        return -1;
    }
    int valor = fila[inicio];
    inicio = (inicio + 1) % MAX;
    qtd--;
    return valor;
}

void mostrarFila(){
    // Percorre os elementos ativos da fila em ordem.
    printf("Fila:... ");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", fila[(inicio + i) % MAX]);
    }
    printf("\n");
}

int main(){
    // Simula a entrada e saída de pessoas da fila.
    enqueue(10);
    enqueue(20);
    enqueue(30);
    mostrarFila();
    printf("Saiu: %d\n", dequeue());
    mostrarFila();
    return 0;
}
