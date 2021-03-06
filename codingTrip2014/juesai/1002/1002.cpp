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
const int N = 10007;
int p[N][2];
int n;
vector<int> p0, p1, p2;
int midX, midY;
int corss( int x1, int y1, int x2, int y2 )
{
  return x1 * y2 - x2 * y1;
}
int dis2( int x, int y )
{
  return x * x + y * y;
}
bool cmp( int a, int b )
{
  int xA = p[a][0] - midX, yA = p[a][1] - midY;
  int xB = p[b][0] - midX, yB = p[b][1] - midY;
  int tmp = cross( xA, yA, xB, yB );
  if( tmp == 0 )
    return dis2( xA, yA ) < dis2( xB, yB );
  return tmp > 0;
}
int cr( int a, int b, int c )
{
  return cross( p[a][0] - p[c][0], p[a][1] - p[c][1],
    p[b][0] - p[c][0], p[b][1] - p[c][1] );
}
void add( vector<int> & q )
{
  for( int i = 0; i < q.size(); ++i)
    if( p2.size() < 2 )
      p2.push_back(q);
    else
      {
	int j = p2[2].size() - 1;
	int a = p2[j], b= p2[j - 1];
	int c = q[i];
	if( cr( a, b, c)  >= 0 )
	  --i, p2.pop_back();
	else
	  p2.push_back(c);
      }
}
ld dis( int d0, int d1, int x0, int y0, int x1, int y1 )
{
  
}
int main()
{
  for(;;)
    {
      if( EOF == scanf("%d", &n) )
	break;
      midX = 0, midY = 0;
      for( int i = 0; i < 2; ++i )
	part[2].resize(0);
      for( int i = 0; i < n; ++i )
	{
	  scanf("%d%d", &p[i][0], &p[i][1] );
	  midX += p[i][0], midY += p[i][1];
	  if( ( y == 0 && x >= 0 ) ||
	      y > 0 )
	    p0.push_back(i);
	  else p1.push_back(i);
	}
      midX /= n, midY /= n;
      sort( p0.begin(), p0.end(), cmp );
      sort( p1.begin(), p1.end(), cmp );
      p2.resize(0);
      add( p0 );
      add( p1 );
      int q[4] = { 0 };
      int dir[4][0];
      dir[0][0] = p[1][0] - p[0][0], dir[0][1] = p[1][1] - p[0][1];
      for( int i = 1; i < 4; ++i )
	{
	  dir[i][0] = -dir[i-1][1], dir[i][1] = dir[i-1][0];
	  int t = q[ i - 1 ] + 1;
	  for( ; ; ++t)
	    {
	      int tmp = cross( p[t + 1][0] - p[t][0], p[ t + 1 ][1] - p[t][1],
			       dir[i][0], dir[i][1] );
	      if( tmp < 0 )
		break;
	    }
	  q[i] = t - 1;
	}
      int ans = 1e9;
      for( int i = q[1]; q[0] < i; )
	{
	  int t = q[0];
	  int tt = q[2];
	  int x = p[t+1][0] - p[t][0], y p[t+1][1] - p[t][1];
	  int a = dist( x, y,
			p[t][0], p[t][1],
			p[tt][0], p[tt][1] );
	  t = q[1], tt = q[3];
	  int b = dis( -y, x, p[t][0], p[t][1], p[tt][0], p[tt][1] );
	  ans = min( ans, a * b );
	  ++q[0];
	  int dir[4][2];
	  dir[0][0] = p[q[0] + 1][0] - p[q[0]][0],
	    dir[0][1] = p[q[0] + 1][1] - p[q[0]][1];
	  for( int j = 1; j < 4; ++j )
	    {
	      dir[j][0] = -dir[j - 1][1], dir[j][1] = dir[j - 1][0];
	      for( ; ; ++q[j])
		{
		  int tmp = cross( p[q[j] + 1][0] - p[q[j]][0],
				   p[q[j] + 1][1] - p[q[j]][1],
				   dir[j][0], dir[j][1] );
		  if( tmp < 0 )
		    break;
		}
	      --q[j];
	    }
	}
      printf("%d\n", ans);
      return 0;
    }
}
