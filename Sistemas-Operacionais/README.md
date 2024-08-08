# Projeto de Sistemas Operacionais

Este repositório contém implementações de diferentes algoritmos relacionados a escalonamento de processos e gerenciamento de memória, que são tópicos apresentados em Sistemas Operacionais.

## Observações dos arquivos

- **FIFO.c:** Implementação do algoritmo de escalonamento First In, First Out (FIFO) para processos ou para substituição de páginas na memória.
  
- **Prioridade.c:** Implementação de um algoritmo de escalonamento baseado em prioridades, onde os processos são executados de acordo com sua prioridade atribuída.

- **Round-Robin.c:** Implementação do algoritmo de escalonamento Round-Robin, onde é separado um tempo (quantum) para cada processo.

- **SQN.c:** Implementação do algoritmo Shortest Job Next (SQN), onde o processo com o menor tempo de execução é selecionado para ser executado primeiro.

- **geraEntrada.c:** Um script ou programa para gerar arquivos de entrada ou conjuntos de dados para testar os algoritmos de escalonamento ou paginação.

- **paginacao.c:** Este arquivo implementa o método LRU (Least Recently Used).

- **paginacaoOPT.c:** Implementação de um algoritmo de substituição de páginas Ótimo, que faz substituições com base no conhecimento antecipado das requisições futuras de páginas.
