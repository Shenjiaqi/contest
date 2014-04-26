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
int in()
{
  int r, a(0);
  scanf("%d", &r);
  for( int i = 0; i < 4; ++i )
    {
      int v[4];
      scanf("%d%d%d%d", v, v + 1, v + 2, v + 3);
      if( i + 1 == r )
	a = ( 1 << v[0] ) | ( 1 << v[1] ) | ( 1 << v[2] ) |
	  ( 1 << v[3] );
    }
  return a;
}
int main()
{
  int t;
  scanf("%d", &t);
  for( int i = 0; i < t ; ++i)
    {
      int a = in();
      a &= in();
      if( i > 0 )
	printf("\n");
      printf("Case #%d: ", i + 1);
      if( a == 0 )
	printf("Volunteer cheated!");
      else if( ( a & ( - a ) ) == a )
	printf("%d", __builtin_ctz(a));
      else printf("Bad magician!");
    }
  return 0;
}
