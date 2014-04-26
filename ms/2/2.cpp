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
ll dp[40][40];
int main()
{
  for( int i = 0; i < 37; ++i )
    {
      dp[i][0] = 1;
      for( int j = 1; j <= i; ++j )
	dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  int t;
  scanf("%d", &t);
  for( int i = 0; i < t; ++i )
    {
      int n0, m1, k;
      scanf("%d%d%d", &n0, &m1, &k);
      if( i > 0 )
	printf("\n");
      if( dp[n0 + m1][m1] >= k )
	{
	  for( int j = n0 + m1; j > 0; --j )
	    if( dp[ j - 1 ][m1] < k )
	      {
		k -= dp[ j - 1 ][m1];
		--m1;
		printf("1");
	      }
	    else printf("0");
	}
      else
	printf("Impossible");
    }
  return 0;
}
