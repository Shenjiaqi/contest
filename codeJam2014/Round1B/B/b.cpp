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
const int N = 40;
ll dp[N];
int pos( ll v)
{
  for( ; ; )
    {
      ll tmp = v & ( -v );
      if( tmp == v )
	break;
      v ^= tmp;
    }
  return __builtin_ctzll(v);
}
ll dfs( int f, ll v, int t, ll k)
{
  // cout << "!" << f << ' ' << v << ' ' << t << ' ' << k << endl;
  if( f < t )
    return t > 0 ? dp[ t - 1 ] : 0;
  ll mk = 1LL << f;
  if( mk & k )
    {
      if( mk & v )
	{
	  return ( 1LL << ( f + t ) ) + dfs( f - 1, v ^ mk, t, k ^ mk );
	}
      return 1LL << (f + 1 + t);
    }
  if( mk & v )
    return dfs( f - 1, v ^ mk, t, k);
  return 2LL * dfs( f - 1, v, t, k);
}
ll cal( ll va, int ca, ll vb, int cb, ll k)
{
  if( ca < cb )
    swap( va, vb ), swap( ca, cb );
  ll msk = ( 1 << ca ) - 1;
  ll t1 = ( ( va & vb ) & ( ~msk ) );
  ll t2 = k & (~msk);
  if( t1 > t2 )
    return 0;
  if( t1 < t2 )
    return ( 1LL << ( ca + cb ) );
  // t1 == t2;
  return dfs( ca - 1, vb & msk, cb, k & msk);
}
int main()
{
  ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t)
    {
      ll a, b, k;
      cin >> a >> b >> k;
      for( int i = 0; i < N; ++i )
	{
	  if( ( 1LL << i ) & k )
	    dp[i] = ( i > 0 ? dp[ i - 1 ] : 0 ) + 
	      ( 1LL << ( 2 * i ) ) * 3LL;
	  else
	    dp[i] = 3LL * ( i > 0 ? dp[ i - 1 ] : 0 );
	}
      ll ans(0);
      int ck = pos(k);
      int ca = pos(a);
      int cb = pos(b);
      ll va(0);
      for( int i = ca; i >= 0; --i )
	if( ( 1LL << i ) & a )
	  {
	    ll vb(0);
	    for( int j = cb; j >= 0; --j )
	      if( ( 1LL << j ) & b )
		{
		  ll tmp = cal( va, i, vb, j, k);
		  ans += tmp;
		  // cout << va << ' ' << ca << ' ' << vb << ' ' << cb <<
		  //   ' ' << k << ' ' << tmp << endl;
		  vb |= 1LL << j;
		}
	    va |= 1LL << i;
	  }
      cout << "Case #" << ( t + 1 ) << ": " << ans << endl;
    }
  return 0;
}
