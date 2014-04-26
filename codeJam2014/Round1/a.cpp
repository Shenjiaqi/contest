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
const int N = 157;
const int L = 47;
const int inf = 1e9;
ll p[2][N];
int main()
{
  int T;
  scanf("%d", &T);
  for( int t = 0; t < T; ++t )
    {
      int n, l;
      scanf("%d%d", &n, &l);
      vector<ll> a[2];
      for( int j = 0; j < 2; ++j )
	for( int k = 0; k < n; ++k )
	  {
	    char s[L];
	    scanf("%s", s);
	    ll tmp(0);
	    for( int m = 0; m < l; ++m )
	      {
		tmp <<= 1;
		if( s[m] == '1' )
		  tmp |= 1;
	      }
	    a[j].push_back(tmp);
	  }
      vector<ll> b;
      for( int i = 0; i < n; ++i )
	for( int j = 0; j < n; ++j )
	  b.push_back( a[0][i] ^ a[1][j] );
      int ans = l + 1;
      set<ll> d;
      for( int i = 0; i < n; ++i )
	d.insert( a[0][i] );
      for( int i = 0; i < b.size(); ++i )
	{
	  ll v = b[i];
	  int num = __builtin_popcountll(v);
	  if( num < ans )
	    {
	      vector<ll> c;
	      int j = 0;
	      for( ; j < n; ++j )
		if( d.find( a[1][j] ^ v ) == d.end() )
		  break;
	      if( j >= n )
		ans = num;
	    }
	}
      printf("Case #%d: ", t + 1 );
      if( ans <= l )
      	printf("%d", ans );
      else
      	printf("NOT POSSIBLE");
      printf("\n");
    }
  return 0;
}
