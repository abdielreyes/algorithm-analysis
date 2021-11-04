/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 3
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include <stdio.h>

int quotient(int,int, int*);

int main(){
		FILE *fp = fopen("out_quotient1.csv","w");

		int c = 0,i;
		for ( i = 0; i < 20; i++)
		{
			int q = quotient(i,1,&c);
			printf("%d ,%d\n",q,c);
			fprintf(fp,"%d , %d\n",i,c);
			c = 0;
		}

		
		return 0;
}

int quotient(int n, int div, int *c){
		int q = 0;(*c)++;(*c)++;//inicializacion y asignacion
		while(n >= div){
			(*c)++;//comparacion

				n=n-div;(*c)++;(*c)++;//asignacion y operacion
				++q;(*c)++;//incremento
		}
		(*c)++;//return
		return q;
}
