////////////////////////////////////////////////
#include <tuple>
#include <sstream>
#include "MyLib.hpp"
using namespace std;
////////////////////////////////////////////////
typedef tuple<int,int,int> triple_T;
typedef vector<vector<int>> graph_T;
////"""",,,,****    //````,,,,    ====____
//// Dump graph g.
ostream &operator<<( ostream &os, 
/*                */ const graph_T &g ){
  for( auto &row: g ){ os << row << '\n'; }
  return os; }

////````____====    ````////====____    ````====
void clear_graph( graph_T &g ){
  for( auto &row: g ){ row.clear(); }
  g.clear(); }

////****....    ====````,,,,\\\\____%%%%''''____
//// A graph is represented as a 2D array with
//// [i, j]-th element equal to p%.
void set_graph( graph_T &g,
/*           */ const vector<triple_T> &triples,
/*           */ const int n ){
  clear_graph( g );
  g.resize( n, vector( n, 0 ));
  for( auto &triple: triples ){
    auto [i, j, p] = triple;
    g[--i][--j] = p; }}

////,,,,````....\\\\---->>>>____////    ****____
bool Ctrl( const int p ){ return ( p > 50 ); }

////====''''____    ,,,,....\\\\----****,,,,%%%%
//// Capitalize shares from controled companies.
void capitalize( graph_T &g, int i ){
  // row - { p[i,j] | 0 <= j < n }:
  vector<int> &row = g[i];
  // n - number of companies:
  const int n = row.size();
  // added - boolean vector 2 keep track on the
  // companies i controls, their shares (p) are
  // added 2 i (capitalized), so we need a way
  // 2 prevent them being added more than once:
  vector<bool> added( n, false );
  while( true ){
    // x - We need moar than one loop, to 
    // capitalize all shares becoz the number of
    // controled companies might change, so x
    // will hold the number of transactions per
    // loop, if it's still zero, we are done:
    int x = 0; 
    for( int j = 0; j < n; ++j ){
      if( added[j] ){ continue; }
      int p = row[j];
      if( Ctrl( p )){
        add( row.begin(), row.end(), g[j].begin() );
        ++x;
        added[j] = true; }}
    if( x == 0 ){ break; }}}

////____====''''****,,,,\\\\    ====* * ~~~~""""
//// Dump the answers:
//// i controls j k l ..
//// ..
void dmp( const graph_T &g ){
  const int n = g[0].size();
  vector<int> buf;
  for( int i = 0; i < n; ++i ){
    for( int j = 0; j < n; ++j ){
      if( Ctrl( g[i][j] )){
        buf.push_back( j + 1 ); }}
    cout << i + 1 << ": " << buf << '\n';
    buf.clear(); }}

////    ====,,,,````____****>>>>....%%%%____::::
//// 
int main( int argc, char *argv[] ){
  string line; // stdin
  int i, j, p; // i has p% of j
  int n = 0;   // maximum company number
  vector<triple_T> triples; // i, j, p
  graph_T g;
  while( getline( cin, line )){
    if( line.empty() ){
      set_graph( g, triples, n );
      cout << g << '\n';
      for( int j = 0; j < n; ++j ){
        capitalize( g, j ); }
      dmp( g );
      puts("");
      n = 0;
      triples.clear(); }
    else {
      istringstream( line ) >> i >> j >> p;
      n = max( n, max( i, j ));
      triples.push_back({ i, j, p }); }}}
// log:
