import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class ImageRotator{
	public int c = 0;
	public static void main(String[] args){
		ImageRotator ir = new ImageRotator();
		char [][]a = ir.file_to_array("./test2.txt");
		ir.print_matrix(a);
		a = ir.rotateMatrix(a);
		ir.print_matrix(a);
		a = ir.rotateMatrix(a);
		ir.print_matrix(a);
		System.out.println("");
	}
	char [][] rotateMatrix(char [][]a){
		char [][]b = new char[a.length][a.length];
		for(int i = 0; i<a.length; i++){
			for(int j = 0; j<a.length; j++){
				if(i == j) b[j][i] = a [i][j];
			}
		}
		return b;
	}
	char[][] file_to_array(String FILE){
		char [][] a = null;
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File(FILE)));
			String line;
			int i = 0;
			int size = br.readLine().length();
			br = new BufferedReader(new FileReader(new File(FILE)));
			a = new char[size][size];
			while((line = br.readLine()) != null){
				for(int j = 0; j<line.length(); j++){
					a[i][j] = line.charAt(j);
				}
				i++;
			}
			br.close();
			return a;
		} catch (Exception e) {
			System.out.println("Error loading file");
			return a;
		}
	}
	void print_matrix(char a[][]){
		System.out.println("Size"+a.length);
		for(int i = 0; i<a.length; i++){
			for(int j = 0; j<a.length;j++){
				System.out.print(a[i][j]);
			}
			System.out.println("");
		}
	}
}
