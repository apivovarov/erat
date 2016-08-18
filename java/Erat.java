public class Erat {
 public static void main(String[] args) {
  String strN = args[0];
  int max = Integer.parseInt(strN);
  long t = System.currentTimeMillis();
  boolean[] sieve = new boolean[max];
  for (int i = 0; i < max; i++) sieve[i] = true;
  sieve[0] = false;
  sieve[1] = false;
  int lim = (int) Math.sqrt(max);
  for (int n = 2; n < lim; n++) {
   if (sieve[n]) {
    for (int j = 2 * n; j < max; j += n)

     sieve[j] = false;
   }
  }
  t = System.currentTimeMillis() - t;
  System.out.println("Time: " + t + " ms");
 }
}
