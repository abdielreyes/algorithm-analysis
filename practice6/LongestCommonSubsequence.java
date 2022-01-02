/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 6 Programacion Dinamica
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/

import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class LongestCommonSubsequence {

    public static void main(String[] args) {
        LongestCommonSubsequence lcs = new LongestCommonSubsequence();
        String file1 = "./and.c";
        String file2 = "./euclides.c";
        String s1 = lcs.fileToString(file1);
        String s2 = lcs.fileToString(file2);

        char[] X = s1.toCharArray();
        char[] Y = s2.toCharArray();

        int m = X.length;
        int n = Y.length;
        lcs.diff(X, Y, m, n);
    }
    
    String fileToString(String path){
        File file = new File(path);
        String str = "";
        try (FileReader fr = new FileReader(file))
        {
            int content;
            while ((content = fr.read()) != -1) {
                char c = (char) content;
                if(c != '\n' && c != ' ' && c != '\t') str = str + c;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;

    }
    void diff(char[] X, char[] Y, int i, int j){
        int lcsLen = lcs(X,Y,i,j)[i][j];
        double percentage = (lcsLen * 100)/(i+j);
        System.out.println("Longest common subsequence length " + lcsLen);
        System.out.println("Percentage of similarity "+ percentage+"%");

        String additions = "";
        String removals = "";
        String unchanged = "";
        int [][] lcs = lcs(X,Y,i,j);
        //Nos movemos a traves de la matriz en diagonal y 
        //conforme se encuentran cambios es que se toma en cuenta que un caracter concidio, se anadio o se quito
        while(i != 0 && j != 0){
            if(i == 0){
                additions+=Y[j-1];          
                j-=1;
            }
            if(j==0){
                removals+=X[i-1];
                i-=1;
            }
            if(X[i-1] == Y[j-1]){
                unchanged+=X[i-1];
                i-=1;
                j-=1;
            }
            if(lcs[i-1][j]<= lcs[i][j-1]){
                additions+=Y[j-1];
                j-=1;
            }else{
                removals+=X[i-1];
                i-=1;
            }
        }
        System.out.println("Additions "+additions+"\n");
        System.out.println("Removals "+removals+"\n");
        System.out.println("Unchanged "+unchanged+"\n");
    }
    int [][]lcs(char[] X, char[] Y, int m, int n) {
        int L[][] = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0){
                    //caso base
                    L[i][j] = 0;
                } else if (X[i - 1] == Y[j - 1]){
                    //si son iguales, es decir que coinciden y aumentamos al contador
                    L[i][j] = L[i - 1][j - 1] + 1;
                }
                else{
                    //comparamos los valores de las celdas anteriores
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }      
            }
            
        }
        //La longitud de la LCS, esta en la ultima posicion de la matriz
        return L;
    }

    int max(int a, int b) {
        if(a>b){
            return a;
        }else{
            return b;
        }
    }

}
