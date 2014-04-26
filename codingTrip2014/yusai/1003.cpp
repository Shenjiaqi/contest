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
int p[ N * N * 4 ];
void init( )
{
  p[lev][0] = 1 | pk( 255, 255, 255 );
}
void st( int lev, int x1, int y1, int x2, int y2, int val,
	 int xx1, int yy1, int xx2, int yy2)
{}
int main()
{
  int n, m;
  for(; scanf("%d%d", &n, &m ); )
    {
      if( n == 0 && m == 0 )
	break;
      init( );
      for( int i = 0; i < n; ++i )
	{
	  int x1, y1, x2, y2, r, g, b;
	  scanf("%d%d%d%d", &x1, &y1, &x2, &y2, &r, &g, &b);
	}
      for( int i = 0; i < m; ++i )
	{
	  int x, y;
	  scanf("%d%d", &x, &y );
	  int v = que( x, y );
	  int r, g, b;
	  upk( v, r, g, b );
	  printf("%d %d %d\n", r, g, b );
	}
    }
  return 0;
}
