#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <>

int somaimpares() {
	int i; 
	int soma = 0;
	
	for(i =1; i <= 10; i+=2) soma += i;
	
	return soma;
}

int somapares() {
	int i; 
	int soma = 0;
	
	for(i =2; i <= 10; i+=2) soma += i;
	
	return soma;
}

int main() {
          
   // int total = impares + pares;       
	pid_t pid = fork ();
	if (pid < 0) {
		perror ("erro no fork");
		exit(1); 
	}  
	
	if (pid == 0) { // processo filho
		int impares = somaimpares();
		printf("Soma dos impares de 1 a 10: %d\n\n", impares);
	}
	else { // processo pai
		int pares = somapares(); 
		printf("Soma dos pares de 1 a 10: %d\n\n", pares);
	}
    
   
    //printf("Soma dos valores: %d\n\n", total);
}

