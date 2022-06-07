#include <stdio.h>	 /* scanf() */
#include <process.h> /* _beginthread() */
#include <windows.h> // Sleep()
#include <semaphore.h>

void thread1(void *);		   // Prot�tipo da fun��o que representam as threads.
void thread2(void *);		   // Prot�tipo da fun��o que representam as threads.
void thread3(void *);		   // Prot�tipo da fun��o que representam as threads.
void thread4(void *);		   // Prot�tipo da fun��o que representam as threads.
void thread5(void *);		   // Prot�tipo da fun��o que representam as threads.
int printer1(int id, int pos); // fun��o que imprime o valor da thread na tela.
int buffer_pos;				   // vari�vel global posi��o escrita buffer 0, 1 ou 2.
int buffer[3];				   // buffer de impress�o compartilhado.
sem_t semafaro1, semafaro2, semafaro3;

int main()
{
	sem_init(&semafaro1, 0, 0);
	sem_post(&semafaro1);
	sem_init(&semafaro2, 0, 0);
	sem_post(&semafaro2);
	sem_init(&semafaro3, 0, 0);
	sem_post(&semafaro3);
	_beginthread(thread1, 0, NULL); // chama a fun��o e faz dela uma thread
	_beginthread(thread2, 0, NULL); // chama a fun��o e faz dela uma thread
	_beginthread(thread3, 0, NULL); // chama a fun��o e faz dela uma thread
	_beginthread(thread4, 0, NULL); // chama a fun��o e faz dela uma thread
	_beginthread(thread5, 0, NULL); // chama a fun��o e faz dela uma thread

	system("PAUSE");

	sem_destroy(&semafaro1);
	sem_destroy(&semafaro2);
	sem_destroy(&semafaro3);
	return (0);
}

void thread1(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
{
	int ret, pos;
	for (;;)
	{
		ret = 0;
		if (sem_trywait(&semafaro1) == 0)
			ret = 1;
		else if (sem_trywait(&semafaro2) == 0)
			ret = 2;
		else if (sem_trywait(&semafaro3) == 0)
			ret = 3;
		if (ret != 0)
		{
			pos = printer1(1, buffer_pos); // imprimir
			buffer_pos = pos;
			printf("Thread1 imprimindo..... %d\n", pos);
			Sleep(5000);
			printf("Thread1 terminou de imprimir ..... %d\n", pos);
			if (ret == 1)
				sem_post(&semafaro1);
			if (ret == 2)
				sem_post(&semafaro2);
			if (ret == 3)
				sem_post(&semafaro3);
		}
	}
}

void thread2(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
{
	int ret, pos;
	for (;;)
	{
		ret = 0;
		if (sem_trywait(&semafaro1) == 0)
			ret = 1;
		else if (sem_trywait(&semafaro2) == 0)
			ret = 2;
		else if (sem_trywait(&semafaro3) == 0)
			ret = 3;
		if (ret != 0)
		{
			pos = printer1(1, buffer_pos); // imprimir
			buffer_pos = pos;
			printf("Thread2 imprimindo..... %d\n", pos);
			Sleep(5000);
			printf("Thread2 terminou de imprimir ..... %d\n", pos);
			if (ret == 1)
				sem_post(&semafaro1);
			if (ret == 2)
				sem_post(&semafaro2);
			if (ret == 3)
				sem_post(&semafaro3);
		}
	}
}

void thread3(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
{
	int ret, pos;
	for (;;)
	{
		ret = 0;
		if (sem_trywait(&semafaro1) == 0)
			ret = 1;
		else if (sem_trywait(&semafaro2) == 0)
			ret = 2;
		else if (sem_trywait(&semafaro3) == 0)
			ret = 3;
		if (ret != 0)
		{
			pos = printer1(1, buffer_pos); // imprimir
			buffer_pos = pos;
			printf("Thread3 imprimindo..... %d\n", pos);
			Sleep(5000);
			printf("Thread3 terminou de imprimir ..... %d\n", pos);
			if (ret == 1)
				sem_post(&semafaro1);
			if (ret == 2)
				sem_post(&semafaro2);
			if (ret == 3)
				sem_post(&semafaro3);
		}
	}
}

void thread4(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
{
	int ret, pos;
	for (;;)
	{
		ret = 0;
		if (sem_trywait(&semafaro1) == 0)
			ret = 1;
		else if (sem_trywait(&semafaro2) == 0)
			ret = 2;
		else if (sem_trywait(&semafaro3) == 0)
			ret = 3;
		if (ret != 0)
		{
			pos = printer1(1, buffer_pos); // imprimir
			buffer_pos = pos;
			printf("Thread4 imprimindo..... %d\n", pos);
			Sleep(5000);
			printf("Thread4 terminou de imprimir ..... %d\n", pos);
			if (ret == 1)
				sem_post(&semafaro1);
			if (ret == 2)
				sem_post(&semafaro2);
			if (ret == 3)
				sem_post(&semafaro3);
		}
	}
}

void thread5(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
{
	int ret, pos;
	for (;;)
	{
		ret = 0;
		if (sem_trywait(&semafaro1) == 0)
			ret = 1;
		else if (sem_trywait(&semafaro2) == 0)
			ret = 2;
		else if (sem_trywait(&semafaro3) == 0)
			ret = 3;
		if (ret != 0)
		{
			pos = printer1(1, buffer_pos); // imprimir
			buffer_pos = pos;
			printf("Thread5 imprimindo..... %d\n", pos);
			Sleep(5000);
			printf("Thread5 terminou de imprimir ..... %d\n", pos);
			if (ret == 1)
				sem_post(&semafaro1);
			if (ret == 2)
				sem_post(&semafaro2);
			if (ret == 3)
				sem_post(&semafaro3);
		}
	}
}

int printer1(int id, int pos)
{ // retorna a posicao se a thread foi para o buffer.
	if (pos <= 3)
	{
		buffer[pos] = id;
		pos++;
	}
	else
	{
		pos = 0;
		buffer[pos] = id;
		pos++;
	}
	return pos;
}
