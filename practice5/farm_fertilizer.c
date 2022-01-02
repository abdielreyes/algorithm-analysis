/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 5 Algoritmos Greedy
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include "array.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void greedyFarm(int*,int,int,Array*,int*);
void printArray(Array *);
void printArray_(int *,int);
void randomFarm();

int main() {
  srand(time(0));
  randomFarm();
  return 0;
}

void randomFarm(){
  FILE *fp = fopen("greedyFarm.csv","w");
  int c = 0;
  int i;
  for(i=0;i<30;i++){
    //creamos los valores necesarios para el algoritmo
    int n = i+2;//le sumamos 2 para dar 2 extremos al arreglo con valores intermedios
    int d[n];
    int j;
    for(j = 0;j<n;j++){
      d[j] = (rand() % 2*n)+j;
    }
    int r = (rand() % 2*n)+1;//Le sumamos 1 para que no sea 0
    Array s;
    initArray(&s);
    printf("size: %d r: %d\n",n,r);
    printArray_(d,n);
    greedyFarm(d,n,r,&s,&c);
    printArray(&s);
    printf("\n");
    fprintf(fp,"%d , %d\n",n,c);
    freeArray(&s);
    c = 0;
  }
  fclose(fp);
}

void greedyFarm(int *d, int n, int r, Array *s, int *c){
  (*c)++;(*c)++;//costo de 2 declaraciones
  int f = r;
  int i;
  (*c)++;(*c)++;//declaracion y comparacion de for
  //recorremos el arreglo y buscamos la mejor opcion
  for (i = 0; i < n; i++) {
    (*c)++;(*c)++;//comparaciones del if
    if (i == 0 || (i+1) == n) {
      (*c)++;(*c)++;//Costo de 2 instrucciones
      pushArray(s, d[i]);
      f = r+d[i];
    (*c)++;
    } else {
      (*c)++;//Comparacion del if
      if (d[i] > f) {
        (*c)++;(*c)++;//Costo de 2 instrucciones
        pushArray(s, d[i-1]);
        f = r + d[i-1];
      }
    }
  (*c)++;//incremento del for
  }

}

void printArray_(int *a,int n){
  int i;
  for(i = 0; i <n;i++){
    printf("%d ",a[i]);
  }

}
void printArray(Array *a){
  int i;
  for (i = 0; i < a->used; i++) {
    printf("%d ", a->array[i]);
  }
}
