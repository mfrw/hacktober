/**
 * 
 */

/**
 * @author GUPTA
 *
 */
public class Sorting {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[] = { 3,2, 4, 21, 1, 9, 8};
		quicksort (a, 0, a.length-1) ;
		for ( int i  = 0 ; i < a.length ; i++ )
			System.out.println( a[i]);
	}

	public static void quicksort(int[] a, int low, int high) {
		// TODO Auto-generated method stub
		if ( high >= low )
		{
			int p = partition ( a , low, high);
			quicksort(a, low, p-1);
			quicksort ( a, p+1 , high  );
		}
	}

	public static int partition(int[] a, int low, int high) {
		// TODO Auto-generated method stub
		int i = low - 1;
		int pivot = a[high] ;
		for ( int j = low ; j < high ; j++ ){
			
			if ( a[j ] < pivot ){
				i++;
				int temp =  a[j];
				a[j] = a[i];
				a[i] =  temp;
			}
			
		}
		int temp = a[i+1] ;
		a[i+1 ] = a[high] ;
		a[high ] = temp;
		return i+1;
	}

}
