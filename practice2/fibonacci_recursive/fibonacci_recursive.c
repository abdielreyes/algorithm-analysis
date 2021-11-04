/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 2
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include<stdio.h>

int fibonacci(int, int*);

int main(){

		FILE *fp;
		fp = fopen("out_fibonacci_recursive.csv", "w");
		int n = 20, i , c=0;


		for ( i = 1 ; i <= n ; i++ ){
				printf("%d\n", fibonacci(i,&c));
				fprintf(fp,"%d , %d\n",i,c);
				c=0;
		}
		fclose(fp);

		return 0;
}

int fibonacci(int n, int *c){
		if ( n == 0 ){
				(*c)++;//condicional

				(*c)++;//return
				return 0;
		}
		else if ( n == 1 ){
				(*c)++;//condicional

				(*c)++;//return
				return 1;
		}
		else{
				(*c)++;//return
				(*c)++;(*c)++;(*c)++;(*c)++;//suma, fn1 operacion arg , fn2 operacion arg
				return ( fibonacci(n-1,c) + fibonacci(n-2,c) );
		}
}
