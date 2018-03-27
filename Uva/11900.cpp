#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast write

    int t  ;
    cin >> t ;
    for( int y = 1 ; y <= t ; y++ ){

        int n , egg , gram , s = 0 , c = 0 ;

        cin >> n >> egg >> gram ;

        vector < int > v (n);

        for(int i = 0 ; i < n ;i++)
            cin >> v[i];

        for(int i = 1 ; i <= n ; i++){
            s += v[i-1] ;
            if( s > gram || i > egg ) break ;
            c++ ;
        }
       cout << "Case " << y << ": " << c << endl;
    }
}
