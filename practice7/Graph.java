/*
  Instituto Politecnico Nacional
  Escuela Superior de Computo
  Analisis de algoritmos - 3CV12
  Practica 7
  Reyes Rodriguez Enrique Abdiel
  Chavez Hernandez Juan Diego
*/
import java.util.*;

public class Graph<T> {

    private Map<T, List<T>> map = new HashMap<>();

    public void addVertex(T s) {
        map.put(s, new LinkedList<T>());
    }


    public void addEdge(T source, T destination, boolean bidirectional) {

        if (!map.containsKey(source))
            addVertex(source);

        if (!map.containsKey(destination))
            addVertex(destination);

        map.get(source).add(destination);
        if (bidirectional == true) {
            map.get(destination).add(source);
        }
    }

    public void getVertexCount() {
        System.out.println("The graph has "
                + map.keySet().size()
                + " vertex");
    }

    public void getEdgesCount(boolean bidirection) {
        int count = 0;
        for (T v : map.keySet()) {
            count += map.get(v).size();
        }
        if (bidirection == true) {
            count = count / 2;
        }
        System.out.println("The graph has "
                + count
                + " edges.");
    }

    public void hasVertex(T s) {
        if (map.containsKey(s)) {
            System.out.println("The graph contains "
                    + s + " as a vertex.");
        } else {
            System.out.println("The graph does not contain "
                    + s + " as a vertex.");
        }
    }

    public void hasEdge(T s, T d) {
        if (map.get(s).contains(d)) {
            System.out.println("The graph has an edge between "
                   + s + " and " + d + ".");
        } else {
            System.out.println("The graph has no edge between "
                    + s + " and " + d + ".");
        }
    }
    public void createGraph(Graph<Integer> g,int[][] m){
        for (int i = 0; i < m.length; i++) {
            
            for (int j = 0; j < m[i].length; j++) {
                if(m[i][j]==1) g.addEdge(i, j, false);
                
            }
        }
    }
    public int[] hamiltonVerification(Graph<Integer> g, int[] path){
        //Recorremos el camino dado y por cada elemento analizamos si existe un 
        //camino disponible en el grafo
        //Tambien se analiza si es que termina en donde empieza y si el numero de vertices recorridos 
        //es el numero de vertices del grafo
        int[] res = {0,0};
        int size = g.map.keySet().size(); res[1]++;
        
        res[1]++;res[1]++;
        for(int i = 0;i<path.length;i++){
            
            res[1]++;
            if(((i+1)>=path.length)){
                res[1]++;
                if((path[i] == path[0])&&((i)==size)){
                    res[0]=1;res[1]++;
                }
            }
            else if(!(map.get(path[i]).contains(path[i+1]))){
                res[0]=0;res[1]++;
            }
            res[1]++;
        }
        
        return res;
    }

    @Override
    public String toString(){
        StringBuilder builder = new StringBuilder();
 
        for (T v : map.keySet()) {
            builder.append(v.toString() + ": ");
            for (T w : map.get(v)) {
                builder.append(w.toString() + " ");
            }
            builder.append("\n");
        }
 
        return (builder.toString());
    }
}
