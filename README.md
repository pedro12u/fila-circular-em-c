# Fila Circular em C
Este projeto foi desenvolvido como parte da atividade da disciplina **Estruturas, Pesquisa e Ordenação de Dados**, com o objetivo de praticar a implementação de uma **fila circular** utilizando a linguagem C.

Trabalho realizado em parceria com o colega **Giovanne Leite**.

## 🧱 Estrutura da Fila
A fila é representada por uma struct `Queue`, contendo:

- `int *data`: vetor dinâmico que armazena os elementos
- `int capacity`: capacidade máxima da fila
- `int front`: índice do primeiro elemento
- `int rear`: índice da próxima posição para inserção
- `int count`: número atual de elementos

## ⚙️ Funções Implementadas

### `initQueue(Queue *q, int capacity)`
Inicializa a fila com a capacidade informada e aloca memória para o vetor.

---

### `isFull(Queue *q)`
Verifica se a fila está cheia.

---

### `isEmpty(Queue *q)`
Verifica se a fila está vazia.

---

### `enqueue(Queue *q, int value)`
Adiciona um elemento à fila se houver espaço.

---

### `dequeue(Queue *q, int *value)`
Remove o elemento do início da fila se houver elementos.

---

### `printQueue(Queue *q)`
Imprime o estado atual da fila, incluindo espaços vazios.

---

## 🎯 Objetivo

O foco da atividade foi reforçar conceitos de estruturas de dados dinâmicas, manipulação de memória, controle de índices em estruturas circulares e lógica de filas, dentro do contexto da disciplina.
