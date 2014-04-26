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
const int M = 10007;
int n, m, x, y;
int dis[N];
bool in[N];
int dd[N];
bool keyP[N];
int ee[ M * 2 + 7][3], ei;
int ss[N];
int cc[N];
int d[N];
struct ed
{
  int to, len, cost;
};
vector<ed> p[N];
void add2( int f, int t, int m )
{
  ++ei;
  ee[ei][0] = t, ee[ei][1] = m,
    ee[ei][2] = ss[f], ss[f] = ei;
}
void add( vector<ed> array[], int f, int t,
	  int len, int cost)
{
  struct ed tmp;
  tmp.to = t, tmp.len = len, tmp.cost = cost;
  array[f].push_back(tmp);
}
void dfs( int s )
{
  queue<int> que;
  que.push(s);
  for( int i = 1; i <= n; ++i )
    dis[i] = 0, in[i] = false;
  dis[s] = 1;
  in[s] = true;
  for( ; !que.empty(); )
    {
      int v = que.front();
      que.pop();
      in[v] = false;
      for( int i = 0; i < p[v].size(); ++i )
	{
	  int t = p[v][i].to;
	  int tmp = p[v][i].len + dis[v];
	  // cout << s << ' '<< v <<' ' << tmp << ' ' << dis[t]<< ' ' << t <<endl;
	  if( dis[t] == 0 || dis[t] > tmp )
	    {
	      dis[t] = tmp;
	      if( !in[t] )
		{
		  in[t] = true;
		  que.push(t);
		}
	    }
	}
    }
}
bool bfs()
{
  for( int i = 1; i <= n; ++i )
    d[i] = 0;
  d[x] = 1;
  queue<int> que;
  que.push(x);
  for( ; !que.empty(); )
    {
      int v = que.front();
      que.pop();
      for( int i = ss[v]; i; i = ee[i][2] )
	if( ee[i][1] > 0 )
	  {
	    int t = ee[i][0];
	    if( d[t] == 0 )
	      {
		d[t] = d[v] + 1;
		que.push(t);
	      }
	  }
    }
  return d[y] > 0;
}
int coup( int k )
{
  return k + ( k & 1 ? 1 : -1 );
}
int dfs2( int v, int m )
{
  if( v == y )
    return m;
  int rm = m;
  int i = cc[v];
  for( ; i; i = ee[i][2] )
    {
      int t = ee[i][0];
      if( d[v] == d[t] - 1 && ee[i][1] > 0 )
	{
	  int tmp = dfs2( t, min( m, ee[i][1] ) );
	  ee[i][1] -= tmp;
	  m -= tmp;
	  ee[coup(i)][1] += tmp;
	  if( m == 0 )
	    break;
	}
    }
  cc[v] = i;
  return rm - m;
}
int main()
{
  for(;;)
    {
      scanf("%d%d%d%d", &n, &m, &x, &y);
      if( n == 0 && m == 0 )
	break;
      for( int i = 1; i <= n; ++i )
	p[i].resize(0);
      for( int i = 0 ; i < m; ++i )
	{
	  int a, b, len, c;
	  scanf("%d%d%d%d", &a, &b, &len, &c);
	  add( p, a, b, len, c);
	  add( p, b, a, len, c);
	}
      dfs(x);
      for( int i = 1; i <= n; ++i )
	dd[i] = dis[i] - 1;
      dfs(y);
      for( int i = 1; i <= n; ++ i)
	--dis[i];
      for( int i = 1; i<= n; ++i )
	keyP[i] = false;
      for( int i = 1; i <= n; ++i )
	if( dd[i] + dis[i] == dd[y] )
	  {
	    // cout << i << endl;
	    keyP[i] = true;
	  }
      for( int i = 1; i <= n; ++i )
	ss[i] = 0;
      for( int i = 1; i <= n; ++i )
	if( keyP[i] )
	  for( int j = 0; j < p[i].size(); ++j )
	    {
	      int t = p[i][j].to;
	      if( t > i && keyP[t] )
		{
		  int len = p[i][j].len;
		  int cost = p[i][j].cost;
		  if( dd[i] + len == dd[t] || dd[t] + len == dd[i] )
		    {
		      add2( i, t, cost );
		      add2( t, i, cost );
		    }
		  //     cout << i << ' ' << t << ' ' << p[i][j].len << endl;
		  //     add2( i, t, cost);
		  //     add2( t, i, 0);
		  //   }
		  // else if( dd[t] + len == dd[i] )
		  //   {
		  //     cout << i << ' ' << t << ' ' << p[i][j].len << endl;
		  //     add2( t, i, cost);
		  //     add2( i, t, 0);
		  //   }
		}
	    }
      int ans(0);
      for(; bfs(); )
	{
	  for(;;)
	    {
	      int tmp = dfs2(x, 1e9);
	      ans += tmp;
	      if( tmp == 0 )
		break;
	    }
	  for( int i = 1; i <= n; ++i )
	    cc[i] = ss[i];
	}
      printf("%d\n", ans);
    }
  return 0;
}

