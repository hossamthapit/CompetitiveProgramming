#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast

    ll n , k , s = 0   , l = 1 , r , mid , num ;

    cin >> n >> k ;

	r = n;

	for( ;l < r; ){
		mid = ( l + r ) / 2;
		num = mid;
		for( ; num ;){
			s += num;
			num /= k;
		}
		if ( s < n ) l = mid + 1 ;
		else r = mid ;
		s = 0 ;
	}
	cout << l <<endl;
}
