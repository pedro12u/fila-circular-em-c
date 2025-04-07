#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;      
    int capacity;   
    int front;      
    int rear;      
    int count;    
} Queue;

void initQueue(Queue *q, int capacity) {
    q->data = (int *) malloc(capacity * sizeof(int));
    if(q->data == NULL) {
        printf("Erro ao alocar memoria para a fila.\n");
        exit(EXIT_FAILURE);
    }
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    for (int i = 0; i < capacity; i++) {
        q->data[i] = 0;
    }
}

int isFull(Queue *q) {
    return (q->count == q->capacity);
}

int isEmpty(Queue *q) {
    return (q->count == 0);
}

int enqueue(Queue *q, int value) {
    if (isFull(q)) {
        return -1; 
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
    q->count++;
    return 0;
}

int dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {
        return -1;
    }
    *value = q->data[q->front];
    q->data[q->front] = 0;
    q->front = (q->front + 1) % q->capacity;
    q->count--;
    return 0;
}

void printQueue(Queue *q) {
    printf("Estado da fila: ");
    for (int i = 0; i < q->capacity; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite o tamanho da fila: ");
    scanf("%d", &n);
    
    Queue q;
    initQueue(&q, n);
    
    int opcao, valor, ret;
    
    printf("\nFila inicializada com %d elementos preenchidos com 0.\n", n);
    printQueue(&q);
    
    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserir (enfileirar)\n");
        printf("2. Retirar (desenfileirar)\n");
        printf("3. Verificar se a fila possui lugar\n");
        printf("4. Mostrar fila\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                if (isFull(&q)) {
                    printf("Nao e possivel inserir. A fila esta cheia.\n");
                } else {
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    ret = enqueue(&q, valor);
                    if(ret == 0)
                        printf("Valor %d inserido com sucesso.\n", valor);
                    else
                        printf("Erro ao inserir o valor.\n");
                }
                break;
            case 2:
                ret = dequeue(&q, &valor);
                if(ret == 0)
                    printf("Valor %d retirado da fila.\n", valor);
                else
                    printf("A fila esta vazia. Nao ha elementos a serem retirados.\n");
                break;
            case 3:
                if(isFull(&q))
                    printf("A fila esta cheia.\n");
                else
                    printf("Ainda ha espaco na fila para insercao.\n");
                break;
            case 4:
                printQueue(&q);
                break;
            case 5:
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while(opcao != 5);
    
    free(q.data);
    return 0;
}

