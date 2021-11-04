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

		FILE *fp = fopen("out_quotient3.csv","w");

		int c = 0,i;
		for ( i = 0; i < 20; i++)
		{
			int q = quotient(i,1,&c);
			printf("%d ,%d\n",q,c);
			fprintf(fp,"%d , %d\n",i,c);
			c = 0;
		}
		fclose(fp);

		return 0;
}

int quotient(int n, int div, int *c){

		if(div>n){
			(*c)++;//comparacion
			(*c)++;//return
			return 0;
		}else{
			(*c)++;//llamada a la funcion
			return (1 + quotient(n-div,div,c));
		}

}
