public class Fibonnaci{
   public static void main(String[] args) {
      int n = 10;
      long fib[] = new long[n+1];
      fib[0] = 0;
      fib[1] = 1;
      for(int i = 2; i < n; i++){
        fib[i] = fib[i-1]+fib[i-2];
      }
      System.out.println("fib("+n+") = "+fib[n-1]);
   }
}
