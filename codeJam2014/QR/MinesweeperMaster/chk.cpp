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
char s[157];
int main()
{
  FILE* in = fopen("in", "r");
  FILE* out = fopen("out", "r");
  int n;
  fscanf(in, "%d", &n);
  for( int i = 0; i < n; ++i )
    {
      int r, c, m;
      fscanf(in, "%d%d%d", &r, &c, &m );
      int id;
      fscanf(out, "Case #%d:\n", &id);
      int cc = 0;
      for( int j = 0; j < r; ++j )
	{
	  memset( s, 0, sizeof(s));
	  fscanf(out, "%s\n", s);
	  // printf("%s %d\n", s, r);
	  if( s[0] == 'I' )
	    {
	      m = 0, cc = 1;
	      break;
	    }
	  for( int k = 0; k < c; ++k )
	    if( s[k] == 'c' || s[k] == '.')
	      {
		if( s[k] == 'c' )
		  ++cc;
	      }
	    else if( s[k] != '*')
	      {
		printf("%d !%c!\n", id, s[k] );
	      }
	    else --m;
	}
      if( m != 0 || cc != 1)
	cout << id << ' ' << m << endl;
    }
  return 0;
}
