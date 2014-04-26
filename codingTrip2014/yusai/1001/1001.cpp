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
const int M = 10007;
int fa[M][3], fai;
int gfa( int v )
{
  if( fa[v][1] != fai )
    {
      fa[v][0] = v, fa[v][2] = 0, fa[v][1] = fai;
    }
  int tf = fa[v][0];
  if( tf != v )
    {
      int tmp = gfa(tf);
      if( tmp != fa[v][0] )
	{
	  fa[v][0] = tmp;
	  if( fa[v][2] && fa[tf][2] )
	    {
	      if( fa[v][2] != fa[tf][2] )
		fa[v][2] = 3 - fa[v][2];
	      else
		fa[v][2] = 0;
	    }
	}
    }
  return fa[v][0];
}
bool merge( int a, int b, int t )
{
  int ta = gfa(a), tb = gfa(b);
  if( ta != tb )
    {
      if( ta == a || tb == b )
	{
	  fa[b][0] = a;
	  fa[b][2] = t;
	  return true;
	}
      if( t == 0 )
	{
	  if( fa[a][2] == fa[b][2] )
	    {
	      fa[tb][0] = a;
	      fa[tb][2] = 0;
	      return true;
	    }
	  return false;
	}
      if(  ( fa[a][2] == 0 && fa[b][2] == 2 )||
	   ( fa[a][2] == 1 && fa[b][2] == 0 ) ||
	   ( fa[a][2] == 2 && fa[b][2] == 1 ) )
	{
	  fa[tb][0] = a;
	  fa[tb][2] = 0;
	  return true;
	}
      return false;
    }
  else
    {
      if( t == 0 )
	return fa[a][2] == fa[b][2];
      a = fa[a][2], b = fa[b][2];
      return ( a == 0 && b == 2 ) ||
	( a == 1 && b == 0 ) ||
	( a == 2 && b == 1 );
    }
  assert(0);
  return true;
}
int main()
{
  int k;
  scanf("%d", &k);
  for( int i = 0; i < k; ++i )
    {
      fai = i + 1;
      int m, n;
      scanf("%d%d", &m, &n );
      int ans(0);
      for( int j = 0; j < n; ++j )
	{
	  int t, a, b, c;
	  scanf("%d%d%d", &t, &a, &b);
	  // cout << t  << ' ' << a << ' ' << b << endl;
	  if( a > m || b > m || !merge( a, b, t - 1 ) )
	    {
	      // cout << j + 1 << endl;
	      ++ans;
	    }
	}
      if( i > 0 )
      	printf("\n");
      printf("%d", ans);
    }
  return 0;
}
