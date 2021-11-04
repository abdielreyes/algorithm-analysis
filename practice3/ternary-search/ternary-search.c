/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 3
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include "stdio.h"
#include "stdlib.h"
int iterativeTernarySearch(int[],int,int,int,int*);
int recursiveTernarySearch(int[],int,int,int,int*);
void generateArray(int*,int);
int main(){
	int *a;
	int c = 0;
	int x = 1500;
	FILE *fp = fopen("out_ternarysearch_iterative.csv","w");
	FILE *fp2 = fopen("out_ternarysearch_recursive.csv","w");
	int i;
	int tsr,tsi;

	for(i = 1;i<1000;i++){
		generateArray(a,i);
		tsr = recursiveTernarySearch(a,0,i,x,&c);
		printf("%d, %d , %d\n",tsr,i,c);
		fprintf(fp2,"%d , %d\n",i,c);
		c=0;
		tsi = iterativeTernarySearch(a,0,i,x,&c);
		printf("%d, %d , %d\n",tsi,i,c);
		fprintf(fp,"%d , %d\n",i,c);
		c=0;
	}
	 
	printf("%d",tsr);


	fclose(fp);
	fclose(fp2);
	return 0;
}
int iterativeTernarySearch(int a[], int left, int right, int x, int *c) {
		while (left <= right) {
			(*c)++;//comparacion
				int mid_a = left + ((right - left) / 3);(*c)++;//operacion
				int mid_b = right - ((right - left) / 3);(*c)++;//operacion
				if (a[mid_a] == x) {
					(*c)++;//comparacion
					(*c)++;//return
					return mid_a;
				}
				if (a[mid_b] == x) {
					(*c)++;//comparacion
					(*c)++;//return
					return mid_b;
				}
				if (x < a[mid_a]) {
					(*c)++;//comparacion
					(*c)++;//return
					right = mid_a - 1;
				} else if (x > a[mid_b]) {
					(*c)++;//comparacion
					(*c)++;//return
					left = mid_b + 1;
				} else {
					left = mid_a + 1;(*c)++;//operacion
					right = mid_b - 1;(*c)++;//operacion
				}
		}
		(*c)++;
		return -1;
}
int recursiveTernarySearch(int a[], int left, int right, int x, int *c) {
		if (left > right) {
			(*c)++;//comparacion
			(*c)++;//return
			return -1;
		}
		(*c)++;
		int mid_a = left + ((right - left) / 3);(*c)++;//operacion
		int mid_b = right - ((right - left) / 3);(*c)++;//operacion

		if (a[mid_a] == x) {
			(*c)++;//comparacion
			(*c)++;//return
			return mid_a;
		}
		if (a[mid_b] == x) {
			(*c)++;//comparacion
			(*c)++;//return
			return mid_b;
		}
		if (x < a[mid_a]) {
			(*c)++;//comparacion
			(*c)++;//return
			return recursiveTernarySearch(a, left, (mid_a - 1), x,c);
		} else if (x > a[mid_b]) {
			(*c)++;//comparacion
			(*c)++;//return
			return recursiveTernarySearch(a, (mid_b + 1), right, x,c);
		} else {
			(*c)++;//return
			return recursiveTernarySearch(a,(mid_a + 1), (mid_b - 1), x, c);
		}
		
		
}
void generateArray(int *a,int n){
	int i;
	for(i = 0 ; i<n;i++){
		a[i]=rand()%1000;
	}
}