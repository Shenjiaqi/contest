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
map< vector<int>,int> mapp;
int main()
{
  const int n = 10;
  for( int t = 0; t < 10000; ++t )
    {
      vector<int> p;
      for( int i = 0; i < n; ++i )
	p.push_back(i);
      for( int i = 0; i < n; ++i )
	{
	  int t = rand() % ( n - i);
	  swap( p[i], p[i + t] );
	}
      ++mapp[p];
    }
  for( auto i : mapp )
    {
      // cout << i.second << ":\n";
      // for( auto j : i.first )
      // 	cout << j << ' ' ;
      // cout << endl;
      cout << i.second << ' ' ;
    }
  return 0;
}
