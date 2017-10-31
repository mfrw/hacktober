import java.io.*;
import java.util.*;

public class reverseWordString{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		int i = 0;
		while(i < t){
			char arr[] = br.readLine().toCharArray();
			reverse(arr, 0, arr.length - 1);
			int l = arr.length;
			int j = 0, s = 0, e;
			while(j < l){
				if(arr[j] == '.' || (j + 1 == l)){
					if(j + 1 != l)
						e = j;
					else
						e = j + 1;
					reverse(arr, s, e - 1);
					s = j + 1;
				}
				j++;
			}
			System.out.println(arr);
			i++;
		}
	}

	public static void reverse(char[] word, int s, int e){
		char tmp;
		while(s < e){
			tmp = word[s];
			word[s++] = word[e];
			word[e--] = tmp;
		}
	}
}