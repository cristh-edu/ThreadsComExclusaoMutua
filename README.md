# Threads Com Exclusão Mútua
* **Matéria:** Sistemas Operacionais
* **Professor:** Júlio Cézar da Silva Costa
* **Curso:** Ciência da Computação
* **Instituição:** Faculdade Única Campus Ipatinga
* **Matéria:** Sincronização de processos/threads com exclusão mútua
* **Integrantes:**
  * Cristhian Eduardo
  * Pedro Bruno
  * Samuel Andrade

## Objetivo 
Garantir a exclusão mútua com algoritmo de Semáforos.

Existem 5 threads dentro desse programa. Utilize o algoritmo de Semáforos para garantir a sincronia entre elas.

A função printer1 tem um buffer com três espaços que aloca o numero da thread que a invocou.
Ao terminar de usar a funcao, ou seja, depois de um sleep de 5 segundos a thread libera o espaço no buffer.
Garanta a exclusão mútua com semáforos fazendo que no máximo três threads por vez possam utilizar a função.
A função printer1 simplesmente coloca no buffer o valor da thread sobrescrevendo as que estão lá, portanto invocar a função é uma região crítica.

O código fonte não pode sofrer grandes alterações, somente as necessárias para implementar o algoritmo de semáforos.