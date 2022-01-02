/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 7
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
import java.io.FileWriter;
import java.util.Arrays;

public class Hamilton {

    public static void main(String args[]) {
        /*
         * 1 / | 0--2
         */
        //usamos la matriz de adyacencia para crear el grafo
        int[][] m1 = { 
            { 0, 1, 1 }, 
            { 1, 0, 1 }, 
            { 1, 1, 0 } 
        };
        // "a" es el camino a recorrer por el grafo
        int[] a1 = { 0, 1, 2, 0 };
        int[] a12 = { 0, 1, 2 };
        Hamilton.testHamilton(m1, a12);
        Hamilton.testHamilton(m1, a1);
        /*
         * 0----1 
         * | / | 
         * 3----2
         */
        int[][] m2 = { 
            { 0, 1, 0, 1 }, 
            { 1, 0, 1, 1 }, 
            { 0, 1, 0, 1 }, 
            { 1, 1, 1, 0 }
        };
        int[] a2 = { 0, 3, 2, 1 };
        int[] a22 = { 0, 3, 2, 1, 0 };
        Hamilton.testHamilton(m2, a2);
        Hamilton.testHamilton(m2, a22);
        /*
         * 0----1---| 
         * | / |    |
         * 2---4----3
         */

        int[][] m3 = {
            { 0, 1, 0, 0, 1 }, 
            { 1, 0, 1, 1, 1 }, 
            { 0, 1, 0, 1, 0 },
            { 0, 1, 1, 0, 1 },
            { 1, 1, 0, 1, 0 } };
        int[] a3 = { 1, 2, 3, 4, 0, 1 };
        int[] a32 = { 0, 4, 3, 1, 0 };
        Hamilton.testHamilton(m3, a3);
        Hamilton.testHamilton(m3, a32);
        /*
         5--0--1
         |     |
         4--3--2
         */
        int[][]m4 = {
            {0,1,0,0,0,1},
            {1,0,1,0,0,0},
            {0,1,0,1,0,0},
            {0,0,1,0,1,0},
            {0,0,0,1,0,1},
            {1,0,0,0,1,0},
        };
        int[] a4  = {0,1,2,3,4,0};
        int[] a42 = {0,1,2,3,4,5,0};
        Hamilton.testHamilton(m4,a4);
        Hamilton.testHamilton(m4, a42);
        

    }

    static void testHamilton(int[][] m, int[] a) {
        try {
            FileWriter fw = new FileWriter ("./hamilton.csv",true);
            StringBuilder sb = new StringBuilder();

            Graph<Integer> g = new Graph<Integer>();

            g.createGraph(g, m);

            System.out.println("Graph:\n" + g.toString());

            System.out.println(Arrays.toString(a));
            System.out.println("");
            int res[] = g.hamiltonVerification(g, a);
            if (res[0] > 0) {
                System.out.println("Es un ciclo hamiltoniano");
                System.out.println("cycle " + a.length + " steps: " + res[1]);
                sb.append(a.length+" , "+res[1]+"\n");
            } else {
                System.out.println("No es un ciclo hamiltoniano");
                System.out.println("cycle length " + a.length + " steps: " + res[1]);
                sb.append(a.length+" , "+res[1]+"\n");
            }

            fw.write(sb.toString());
            fw.close();
        } catch (Exception e) {
            System.out.println("Error writing file");
            e.printStackTrace();
        }
    }
}
