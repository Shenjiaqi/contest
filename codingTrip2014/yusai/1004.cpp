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
const int N = 17;
int p[N];
int main()
{
  int n;
  for( ;scanf("%d", &n); )
    {
      if( n == 0 )
	break;
      int mx = 0, mi = 107;
      for( int i = 0; i < n ; ++i )
	{
	  scanf("%d", p + i);
	  mx = max( mx, p[i] );
	  mi = min( mi, p[i] );
	}
      // sort( p, p + n, greater<int>() );
      // bool w = false;
      // if( n == 1 )
      // 	w = true;
      // else if( n == 2 )
      // 	w = p[0] == p[1] ? false : true;
      // else
      // 	w = true;
      printf("%s\n", mx != mi ? "Win" : "Lose" );
    }
  return 0;
}
