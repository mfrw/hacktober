import java.io.*;
import java.util.*;

public class subSquare{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int i = 0; i < t; i++){
			int n = Integer.parseInt(br.readLine());
			String tmp = br.readLine();
			char arr[][] = new char[n][n];
			int index = 0;
			for(int a = 0; a < n; a++){
				for(int b = 0; b < n; b++){
					arr[a][b] = tmp.charAt(index);
					index++;
					index++;
				}
			}
			int out = findSubSquare(n, arr);
			System.out.println(out);
		}
	}

	public static int findSubSquare(int n, char[][] arr){
		int hor[][] = new int[n][n];
		int ver[][] = new int[n][n];
		int max = 1;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(arr[i][j] == 'O'){
					hor[i][j] = ver[i][j] = 0;
				}
				else{
					hor[i][j] = j == 0 ? 1 : hor[i][j - 1] + 1;
					ver[i][j] = i == 0 ? 1 : ver[i - 1][j] + 1;
				}
			}
		}

		for(int i = n - 1; i >= 0; i--){
			for(int j = n - 1; j >= 0; j--){
				int small = getMin(hor[i][j], ver[i][j]);
				
				while(small > max){
					if(ver[i][j - small + 1] >= small && hor[i - small + 1][j] >= small)
						max = small;
					small--;
				}
			}
		}
		return max;	
	}

	public static int getMin(int a, int b){
		if(a > b)
			return b;
		return a;
	}
}