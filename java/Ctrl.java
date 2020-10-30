// * * * * * * * * * * * * * * * * * * * [48]
import java.io.*;   // I/O man!
import java.util.*; // ArrayList<E>
//_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ [72]
class Graph {
  private int     n;
  private int[][] g;
  private static void add( int[] a, int[] b ){
    for( int j = 0; j < a.length; ++j ){
      a[j] += b[j]; }}
  private static boolean isCtrl( int p ){
    return ( p > 50 ); }
  Graph( int n, ArrayList<int[]> bf ){
    this.n = n;
    g = new int[n][n];
    for( int[] r: bf ){
      int i = r[0];
      int j = r[1];
      int p = r[2];
      g[i][j] = p; }}
  @Override
  public String toString() {
    String s = new String();
    for( int[] r: g ){
      s += "[";
      for ( int p: r ){
        s += String.format("%3d", p ); }
      s += " ]\n"; }
    return s; }
  public int getSiz() { return n; }
  public void cash( int i ){
    // [0 Staät]
    boolean[] ckd = new boolean[n]; // Set to false.
    boolean moar;
    do {
      moar = false;
      for( int j = 0; j < n; ++j ){
        if( !ckd[j] && isCtrl( g[i][j] )){
          add( g[i], g[j] );
          ckd[j] = true;
          moar = true; }}
    } while( moar ); }
  public void cap() {
    for( int j = 0; j < n; ++j ){
      cash( j ); }}
  public void dmp() {
    for( int i = 0; i < n; ++i ){
      System.out.format("%d: ", i + 1);
      for( int j = 0; j < n; ++j ){
        if( isCtrl( g[i][j] )){
          System.out.format("%d ", j + 1);
        }}
      System.out.println(); }}}
public class Ctrl {
  private static InputStreamReader f_in;
  private static BufferedReader    f_br;
  private static ArrayList<int[]>  f_bf; // buffer
  public static void dOthEMAth() throws IOException {
    /** Append new line to the input */
    int n = 0; // Number of companies
    String s;
    while(( s = f_br.readLine()) != null ){
      if( s.isEmpty() ){
        Graph g = new Graph( n, f_bf );
        System.out.println( g );
        g.cap();
        System.out.println( g );
        g.dmp();
        n = 0;        //
        f_bf.clear(); // Reset
      } else {
        String[] sp = s.split(" ");
        int i = Integer.parseInt( sp[0] );
        int j = Integer.parseInt( sp[1] );
        int p = Integer.parseInt( sp[2] );
        n = Math.max( n, Math.max( i, j ));
        f_bf.add( new int[]{ i - 1, j - 1, p }); }}}
  
  public static void main( String[] args ){
    try {
      f_in = new InputStreamReader( System.in );
      f_br = new BufferedReader( f_in );
      f_bf = new ArrayList<>();
      dOthEMAth();
    } catch( IOException io ){
      io.printStackTrace(); }}}
// log:
