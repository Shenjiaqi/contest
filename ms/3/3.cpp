#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 57;
int p[N];
int count( int n)
{
  int r(0);
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < i; ++j )
      if( p[j] > p[i] )
	++r;
  return r;
}
int main()
{
  for( int t = 0;; ++t)
    {
      int n(0);
      for(;;)
	{
	  int num;
	  if( EOF == scanf("%d", &num) )
	    break;
	  p[n] = num;
	  ++n;
	  char c;
	  if( EOF == scanf("%c", &c) )
	    break;
	  if( c == '\n' )
	    break;
	}
      if( n == 0 )
	break;
      int ans = count(n);
      // printf("%d", ans);
      // for( int i = 0; i < n; ++i )
      // 	printf("%d ", p[i] );
      for( int i = 0; i < n; ++i )
	for( int j = i + 1; j < n; ++j )
	  if( p[i] > p[j] )
	    {
	      swap( p[i], p[j] );
	      ans = min( ans, count(n) );
	      swap( p[i], p[j] );
	    }
      if( t > 0 )
	printf("\n");
      printf("%d", ans);
    }
  return 0;
}
