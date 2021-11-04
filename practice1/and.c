#include <stdio.h>
/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 1
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include <stdlib.h>
#include <time.h>

int and_operator(int *a,int *b, int n, int *c);
void input_array(int *a, int n);
void show_array(int *a, int n);

int main(){
    FILE *fp;
    fp = fopen("out_and.csv","w");
    srand(time(0));

    int i;
    int cont = 0;
    int res;
    //se crean arrays nuevos de tamano i para el algoritmo
    for (int i = 0; i <= 20 ; i++){
        int a[i];
        int b[i];
        input_array(a,i);
        input_array(b,i);
        res = and_operator(a,b,i, &cont);
        show_array(a,i);
        show_array(b,i);
        printf("out:%d, size: %d, count: %d\n",res,i,cont);
        fprintf(fp,"%d,%d\n",i,cont); 
        cont = 0;
    }
    fclose(fp);
    return 0;
}

int and_operator(int *a, int *b,int n, int *c){
    int i;(*c)++;//declaracion
    int and;(*c)++;//declaracion
    int pow;(*c)++;//declaracion
    int decimal;(*c)++;//declaracion
    int weight;(*c)++;//declaracion

    decimal = 0;(*c)++;//asignacion
    weight = 1;(*c)++;//asignacion
    
    //inicializacion de i y operacion(n-1)
    (*c)++;(*c)++;
    for(i = (n-1); i>=0; --i ){
        (*c)++;//condicion
        and = (a[i] & b[i]);(*c)++;
        pow = and * weight;(*c)++;
        //asignacion y suma
        decimal = decimal + pow;(*c)++;(*c)++;
        //asignacion, operacion
        weight = weight * 2;(*c)++;(*c)++;

        (*c)++;//decremento
    }
    (*c)++;//fin del for

    (*c)++;//return
    return decimal;
}

void input_array(int *a, int n){
    int i;
    for(i=0;i<n;++i){
	a[i] = rand() % 2;
    }
}
void show_array(int *a, int n){
    int i;
    for(i=0;i<n;++i){
	printf("%d ",a[i]);
    }
    printf("\n");
}
