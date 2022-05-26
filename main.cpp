#include <stdio.h> /* scanf() */
#include <process.h> /* _beginthread() */
#include <windows.h> // Sleep()

void thread1(void *); // Protótipo da função que representam as threads.
void thread2(void *); // Protótipo da função que representam as threads.
void thread3(void *); // Protótipo da função que representam as threads.
void thread4(void *); // Protótipo da função que representam as threads.
void thread5(void *); // Protótipo da função que representam as threads.
int printer1(int id, int pos); // função que imprime o valor da thread na tela.
int buffer_pos;    // variável global posição escrita buffer 0, 1 ou 2.
int  buffer[3]; // buffer de impressão compartilhado.
int main()
{     
     _beginthread(thread1,0,NULL); // chama a função e faz dela uma thread
     _beginthread(thread2,0,NULL); // chama a função e faz dela uma thread
     _beginthread(thread3,0,NULL); // chama a função e faz dela uma thread
     _beginthread(thread4,0,NULL); // chama a função e faz dela uma thread
     _beginthread(thread5,0,NULL); // chama a função e faz dela uma thread
     
	  system("PAUSE");
	
     return(0);
}

void thread1(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
 	int ret,pos;
    for(;;){
     	pos=printer1(1,buffer_pos); // imprimir
		buffer_pos = pos;
		printf("Thread1 imprimindo..... %d\n", pos);
		Sleep(5000);
    	printf("Thread1 terminou de imprimir ..... %d\n", pos);
    }
}

void thread2(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
    int ret,pos;
	for(;;){
     	pos=printer1(1,buffer_pos); // imprimir
		buffer_pos = pos;
		printf("Thread2 imprimindo..... %d\n", pos);
		Sleep(5000);
    	printf("Thread2 terminou de imprimir ..... %d\n", pos);
    }
}

void thread3(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
     int ret,pos;
	 for(;;){
     	pos=printer1(1,buffer_pos); // imprimir
		buffer_pos = pos;
		printf("Thread3 imprimindo..... %d\n", pos);
		Sleep(5000);
    	printf("Thread3 terminou de imprimir ..... %d\n", pos);
    }
    
}

void thread4(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
	int ret,pos;
   for(;;){
     	pos=printer1(1,buffer_pos); // imprimir
		buffer_pos = pos;
		printf("Thread4 imprimindo..... %d\n", pos);
		Sleep(5000);
    	printf("Thread4 terminou de imprimir ..... %d\n", pos);
    }
}
 
void thread5(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
	int ret,pos;
    for(;;){
     	pos=printer1(1,buffer_pos); // imprimir
	    buffer_pos = pos;
		printf("Thread5 imprimindo..... %d\n", pos);
		Sleep(5000);
    	printf("Thread5 terminou de imprimir ..... %d\n", pos);
    }
}
 
int printer1(int id, int pos){ // retorna a posicao se a thread foi para o buffer.
	if(pos <= 3){
		buffer[pos]=id;
		pos++;
	}
	else{
		pos = 0;
		buffer[pos]=id;
		pos++;
	}
	return pos;
}
 
