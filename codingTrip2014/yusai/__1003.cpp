#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 1007;
const int M = 1007;
int p[N][5];
int pk( int a, int b, int c )
{
  return ( a << 20 ) | ( b << 10 ) | c;
}
void upk( int v, int &a, int &b, int &c )
{
  const int msk = ( 1 << 10 ) - 1;
  c = v & msk;
  b = ( v >> 10 ) & msk;
  a = ( v >> 20 ) & msk;
}
int main()
{
  int n, m;
  for(; scanf("%d%d", &n, &m ); )
    {
      if( n == 0 && m == 0 )
	break;
      for( int i = 0; i < n; ++i )
	{
	  int x1, y1, x2, y2, r, g, b;
	  scanf("%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &r, &g, &b);
	  p[i][0] = x1, p[i][1] = y1, p[i][2] = x2, p[i][3] = y2;
	  p[i][4] = pk( r, g, b );
	}
      for( int i = 0; i < m; ++i )
	{
	  int x, y;
	  scanf("%d%d", &x, &y );
	  int j = n - 1; 
	  for( ; j >= 0; --j )
	    if( x <= p[j][2] && x >= p[j][0] && y <= p[j][3] && y >= p[j][1] )
	      break;
	  int r = 255, g = 255, b = 255;
	  if( j >= 0 )
	    upk( p[j][4], r, g, b );
	  printf("%d %d %d\n", r, g, b );
	}
    }
  return 0;
}
