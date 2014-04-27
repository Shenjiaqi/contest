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
int p[ N * 2 ][2], poi;
int s[N];
ppi maxV[N][4];
void add( int f, int t )
{
  ++poi;
  p[poi][0] = t, p[poi][1] = s[f], s[f] = poi;
}
void ud( int v, int val, int from )
{
  for( int i = 0; i < 3; ++i )
    if( val >= maxV[v][i].first )
      {
	for( int j = 3; j > i; --j )
	  maxV[v][j] = maxV[v][ j - 1 ];
	maxV[v][i].first = val, maxV[v][i].second = from;
	break;
      }
}
int cal( int v1, int v2 )
{
  if( v1 == 0 || v2 == 0 )
    return 1;
  return v1 + v2 + 1;
}
int exc( int v, int from )
{
  int id1, id2;
  if( from == maxV[v][0].second )
    id1 = 1, id2 = 2;
  else if( from == maxV[v][1].second )
    id1 = 0, id2 = 2;
  else id1 = 0, id2 = 1;
  return cal( maxV[v][id1].first, maxV[v][id2].first );
}
int dfs( int v, int from )
{
  for( int i = s[v]; i; i = p[i][1] )
    {
      int t = p[i][0];
      if( t != from )
	{
	  int tmp = dfs( t, v );
	  ud( v, tmp, t);
	}
    }
  return exc( v, from );
}
void dfs1( int v, int val, int from )
{
  ud( v, val, from );
  for( int i = s[v]; i; i = p[i][1] )
    {
      int t = p[i][0];
      if( t != from )
	dfs1( t, exc( v, t), v);
    }
}
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t )
    {
      int n;
      scanf("%d", &n);
      for( int i = 0; i <= n; ++i )
	{
	  s[i] = 0;
	  for( int j = 0; j < 3; ++j )
	    maxV[i][j].first = maxV[i][j].second = 0;
	}
      poi = 0;
      for( int i = 1; i < n; ++i )
	{
	  int a, b;
	  scanf("%d%d", &a, &b);
	  add( a, b);
	  add( b, a);
	}
      dfs(1, 0);
      dfs1(1, 0, 0);
      int val = 0;
      for( int i = 1; i <= n; ++i )
	val = max( val, exc( i, 0 ) );
      int ans = n - val;
      printf("Case #%d: %d\n", t + 1, ans);
      // if( t == 2 )
      // 	{
      // 	  ppi tmp = exc( 1, 2);
      // 	  cout << tmp.first << ' ' << tmp.second << endl;
      // 	}
    }
  return 0;
}
