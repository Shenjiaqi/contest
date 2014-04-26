#include <iostream>
using namespace std;
long long cc[34][34];
int main()
{
  for( int c = 0; c < 34; ++c )
    {
      cc[c][0] = 1;
      for( int from = 1; from <= c; from++)
	cc[c][from] = cc[c][from - 1] * ( c - from + 1 ) / from;
    }
  // cout <<cc[4][2] << endl;
  int t;
  cin >> t;
  for( int i = 0; i < t; ++i )
    {
      int n, m, k;
      cin >> n >> m >> k;
      n += m;
      // cout << k << ' ' << cc[n][m] << endl;
      if( cc[n][m] < k )
	cout << "Impossible" << endl;
      else
	{
	  for( ; n > 0; --n )
	    if( k > cc[n-1][m] )
	      {
		k = k - cc[n-1][m];
		m--;
		cout << '1';
	      }
	    else
	      cout << '0';
	  cout << endl;
	}
    }
  return 0;
}
