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
int cnt[512][2];
int main()
{
  for( int i = 1;; ++i)
    {
      bool ok = true;
      int num(0);
      for(;; ++num)
	{
	  char tmp;
	  if( EOF == scanf("%c", &tmp) )
	    break;
	  if( tmp == '\n' )
	    break;
	  if( ! ( ( tmp <= '9' && tmp >= '0' ) || 
		  ( tmp <= 'z' && tmp >= 'a' ) ) )
	    ok = false;
	  if( cnt[tmp][1] != i )
	    cnt[tmp][0] = 0, cnt[tmp][1] = i;
	  ++cnt[tmp][0];
	}
      if( num == 0 )
	break;
      if( i > 1 )
	printf("\n");
      if( ok )
	{
	  list< pair<char,int> > l;
	  for( int j = '0'; j <= '9'; ++j )
	    if( cnt[j][1] == i && cnt[j][0] )
	      l.push_back( make_pair( (char)j, cnt[j][0] ) );
	  for( int j = 'a'; j <= 'z'; ++j )
	    if( cnt[j][1] == i && cnt[j][0] )
	      l.push_back( make_pair( (char)j, cnt[j][0] ) );
	  for( ; !l.empty(); )
	    {
	      list< pair<char,int> > :: iterator ii = l.begin();
	      for( ; ii != l.end(); )
		{
		  printf("%c", ii->first);
		  --(ii->second);
		  if( ii->second == 0 )
		    {
		      list< pair<char,int> > :: iterator jj = ii;
		      ++ii;
		      l.erase( jj );
		    }
		  else ++ii;
		}
	    }
	}
      else printf("<invalid input string>");
    }
  return 0;
}
