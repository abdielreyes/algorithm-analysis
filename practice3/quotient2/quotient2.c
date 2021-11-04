/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 3
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include "stdio.h"

int quotient(int,int,int*);

int main(){
		
		FILE *fp = fopen("out_quotient2.csv","w");

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


int quotient(int n,int div,int *c){
		int dd = div;(*c)++;(*c)++;//inicializacion y asignacion
		int q = 0;(*c)++;(*c)++;//inicializacion y asignacion
		int r = n;(*c)++;(*c)++;//inicializacion y asignacion
		while(dd <= n){
				(*c)++;//comparacion

				(*c)++;(*c)++;//asignacion y operacion
				dd = 2*dd;
		}
		while(dd > div){
				(*c)++;//comparacion


				dd = dd/2;(*c)++;(*c)++;//asignacion y operacion
				q = 2*q;(*c)++;(*c)++;//asignacion y operacion

				if(dd<=r){
						(*c)++;//comparacion

						r = r-dd;(*c)++;(*c)++;//asignacion y operacion
						q=1+1;(*c)++;(*c)++;//asignacion y operacion
				}
		}
		(*c)++;//return
		return q;
}
