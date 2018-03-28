#include <bits/stdc++.h>
#include <bitset>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()
 
using namespace std;
int main()
{fast write
 
    int n , c = 1 ;
    string s ;
 
    cin >> n ;
 
    vector < int > v (n) , v1 , v2 ;
    bitset < 10 > pts ;
    set < int > st;
 
    for( int i = 0 ; i < n ; i++ )
        cin >> v[i];
 
    for( int i = 1 ; i < (1<<n) ; i++ ){
        pts = i ;
        s = pts.to_string();
        reverse( all( s ) );
        for( int k = 0 ; k < n ; k++ ){
            if(s[k]=='1'){
                v1.push_back( v[k] );
                st.insert(v[k]);
            }
        }
        v2 = v1 ;
        sort( all( v2 ) );
 
        if( v2 == v1 && st.size() > c)c = st.size() ;
        v2.clear();
        v1.clear();
        st.clear();
    }
    cout << c << endl;
}
