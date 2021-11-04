/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 1
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
#include <stdio.h>
#include <stdlib.h>
int euclides(int n, int m, int *c);

int main(){

  FILE *fp;
  fp = fopen("out_euclides_normal.csv","a");

  int fib[21] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946};
  int c = 0,max=20,i;
  //aqui se recorre el arreglo de la serie y se ingresan los datos a el metodo euclides
  for(i = 0; i < max; i++){
    int r = euclides(fib[i],fib[i+1],&c);
    printf("MCD(%d,%d) = %d, c = %d\n",fib[i],fib[i+1],r,c);  
    fprintf(fp,"%d,%d\n",fib[i+1],c); 
    c=0;
  }

  /*
  int m,n,c=0;
  printf("m: ");
  scanf("%d",&m);
  printf("n: ");
  scanf("%d",&n);
  
  int res = euclides(m,n,&c);
  printf("%d,%d : %d , %d\n",m,n,res,c);
  fprintf(fp,"%d,%d\n",n,c);
  */

  fclose(fp);
  return 0;
}
int euclides(int m, int n, int *c){
  int r;(*c)++;//inicializacion

  while(n != 0){
    (*c)++;//condicion 
    //asignacion y operacion
    r= (m%n);(*c)++;(*c)++;
    //asignacion
    m = n;(*c)++;
    //asignacion
    n = r;(*c)++;
  
  }
  //fin de while
  (*c)++;

  //return
  (*c)++;
  return m;
}
