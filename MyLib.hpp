////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
template <typename T>
std::ostream &operator<<( std::ostream &s, const std::vector<T> &v ){
  s << "[";
  if( !v.empty() ){
    std::copy( v.begin(), v.end(), std::ostream_iterator<T>( s, "," ));
    s << " \b\b"; }
  return s << "]"; }

////////////////////////////////////////////////////////////////////////////////
template <typename Iter>
void add( Iter first_1, Iter last_1, Iter first_2 ){
  typedef typename std::iterator_traits<Iter>::value_type T;
  std::transform( first_1, last_1, first_2, first_1, std::plus<T>() ); }

// log:
