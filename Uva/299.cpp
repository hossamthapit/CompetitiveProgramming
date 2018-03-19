#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast

    int t ;
    cin >> t ;
    while(t--){

    int n , c = 0;
    cin >> n ;

    vector < int > v( n );

    for( int i = 0 ; i < n ; i++ )
        cin >> v[i];

    for( int i = 0 ; i < n ; i++ ){

        for( int j = i+1 ; j < n ; j++ ){
            if( v[i] > v[j] ) c++;
        }
    }
    cout << "Optimal train swapping takes " << c <<  " swaps." <<endl;
    }
}
