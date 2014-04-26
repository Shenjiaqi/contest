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
int main()
{
  int t;
  scanf("%d", &t);
  for( int i = 0 ; i < t; ++i )
    {
      int r, c, m;
      scanf("%d%d%d", &r, &c, &m );
      int left = r * c - m;
      printf("Case #%d:\n", i + 1);
      if( r == 1 || c == 1 )
	{
	  for( int x = 0; x < r; ++x )
	    {
	      for( int y = 0; y < c; ++y )
		if( x || y )
		  {
		    if( left > 0 )
		      {
			--left;
			printf(".");
		      }
		    else printf("*");
		  }
		else
		  {
		    --left;
		    printf("c");
		  }
	      printf("\n");
	    }
	}
      else if( r == 2 || c == 2 )
	{
	  if( left == 1 )
	    {
	      for( int x = 0; x < r; ++x )
		{
		  for( int y = 0; y < c; ++y )
		    if( x || y )
		      printf("*");
		    else printf("c");
		  printf("\n");
		}
	    }
	  else if( left == 2 || left % 2 )
	    printf("Impossible\n");
	  else
	    for( int x = 0; x < r; ++x )
	      {
		for( int y = 0; y < c; ++y )
		  if( x || y )
		    {
		      if( r == 2 )
			{
			  if( y < left / 2 )
			    printf(".");
			  else printf("*");
			}
		      else if( x < left / 2 )
			printf(".");
		      else printf("*");
		    }
		  else printf("c");
		printf("\n");
	      }
	}
      else
	{
	  if( left == 1 )
	    {
	      for( int x = 0; x < r; ++x )
		{
		  for( int y = 0; y < c; ++y )
		    if( x || y )
		      printf("*");
		    else printf("c");
		  printf("\n");
		}
	    }
	  else if( left < 9 )
	    {
	      if( ( left & 1 ) || left == 2 )
		printf("Impossible\n");
	      else
		{
		  int cc = left == 8 ? 3 : 2;
		  for( int x = 0; x < r; ++x )
		    {
		      for( int y = 0; y < c; ++y )
			if( x || y )
			  {
			    if( y < cc && left > 0 )
			      {
				--left;
				printf(".");
			      }
			    else printf("*");
			  }
			else
			  {
			    --left;
			    printf("c");
			  }
		      printf("\n");
		    }
		}
	    }
	  else
	    {
	      int cc = 3;
	      for( ; ( left + cc - 1 ) / cc > r; ++cc )
		;
	      // cout << left << ' ' << cc << endl;
	      if( ( left % cc ) == 1 )
		{
		  for( int x = 0; x < r; ++x )
		    {
		      for( int y = 0; y < c; ++ y )
			if( x || y )
			  {
			    if( left > 0 && y < cc && ( y == 0 || left != 2 ) )
			      {
				--left;
				printf(".");
			      }
			    else printf("*");
			  }
			else
			  {
			    --left;
			    printf("c");
			  }
		      printf("\n");
		    }
		}
	      else
		for( int x = 0; x < r; ++x )
		  {
		    for( int y = 0; y < c; ++y )
		      if( x || y )
			{
			  if( left > 0 && y < cc )
			    {
			      --left;
			      printf(".");
			    }
			  else
			    printf("*");
			}
		      else
			{
			  --left;
			  printf("c");
			}
		    printf("\n");
		  }
	    }
	}
    }
  return 0;
}
