/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 2
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int perfect(unsigned long long int, int *);
void show_perfects();
void ordered_input(int , int*, FILE *);


int main(){

		FILE *fp;
		fp = fopen("out_perfect_number.csv","w");


		srand(time(0));
		

		int n;
		int c = 0;
		ordered_input(30,&c,fp);
		//show_perfects();
		fclose(fp);
		return 0;
}

int perfect( unsigned long long int n, int *c ){

		unsigned long long int s = 0;(*c)++;(*c)++;//inicializacion y asignacion
		unsigned long long int i;(*c)++;(*c)++;//inicializacion y asignacion
		(*c)++;//asignacion i de for
		for(i = 1; i<n;i++){
		(*c)++;//condicional
				if((n % i) == 0){
						(*c)++;//condicional
						s = s + i;(*c)++;(*c)++;//asignacion y operacion
				}
		(*c)++;//incremento
		}(*c)++;//fin del for
		if(s == n){
				(*c)++;//comparacion

				return 1;(*c)++;//return	
		}else{
				return 0;(*c)++;//return
		}
}
void show_perfects(){
		int c = 0;
		unsigned long long int i=1;
		while(i){
				if(perfect(i,&c)){
						printf("%llu ",i);
						printf("Its perfect\n");
				}
				i++;
		}
}
void ordered_input( int a , int *c, FILE *fp){
		int i;
		for(i=1;i<a;i++){
				printf("\n%d ",i);
				printf(perfect( i ,c)?"El numero es perfecto":"El numero no es perfecto");
				printf(" counter: %d",*c);
				fprintf(fp,"%d , %d\n",i,*c);
				(*c) = 0;
		}
}
