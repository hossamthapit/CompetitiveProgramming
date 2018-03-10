#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast
    int m , n ;
    cin >> n >> m ;

    map < string , int > mp ;

    while(n--){
        string  w ;
        int  c ;
        cin >> w >> c ;
        mp[w]=c;
    }

    while(m--){
        string s ;
        int c = 0 ;
            while(cin >> s ){
                c += mp[s];
                if(s==".")break;
            }
        cout << c <<endl;
    }

}
