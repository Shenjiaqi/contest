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
ld eps = 1e-13;
int main()
{
  int t;
  ios::sync_with_stdio(0);
  cin >> t;
  for( int i = 0; i < t; ++i )
    {
      ld c, f, x;
      cin >> c >> f >> x;
      ld rate = 2.0;
      ld ans = x / rate;
      for(ld usd = 0; usd < ans - eps;)
	{
	  usd += c / rate;
	  rate += f;
	  ld tmp = usd + x / rate;
	  ans = min( ans, tmp );
	}
      if( i > 0 )
	printf("\n");
      printf("Case #%d: %.7lf", i + 1, (double)ans);
    }
  return 0;
}
