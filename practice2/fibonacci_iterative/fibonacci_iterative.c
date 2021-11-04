/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 2
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include <stdio.h>
void fibonacci(int,int*,FILE *);
int main() {
    
		FILE *fp;
		fp = fopen("out_fibonacci_iterative.csv", "w");
		int c = 0;
		
		int n=22,i;
		for(i=1;i<=n;i++){
				
				fibonacci(i,&c, fp);
				fprintf(fp,"%d , %d\n",i,c);
				c=0;
		}
    
    fclose(fp);

    return 0;
}
void fibonacci(int n, int *c, FILE *fp){
		int i;(*c)++;//inicializacion
		int t1 = 0;(*c)++;(*c)++;//inicializacion y asignacion
		int t2 = 1;(*c)++;(*c)++;//inicializacion y asignacion
		int nt;(*c)++;//inicializacion
		
		(*c)++;//inicializacion i for
		for (i = 1; i <= n; ++i) {
				//comparacion
				printf("%d, ", t1);(*c)++;//operacion
				nt = t1 + t2;(*c)++;(*c)++;//operacion y asignacion
				t1 = t2;(*c)++;//asignacion
				t2 = nt;(*c)++;//asignacion

				(*c)++;//incremento
		}(*c)++;//fin del for
		printf("\n");(*c)++;//operacion


}
