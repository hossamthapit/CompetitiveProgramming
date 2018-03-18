#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast

    ll t ;
    cin >> t ;
    while(t--){
    ll x , y , z , a , b , c ;
    bool tr = false ;

    cin >> a >> b >> c ;

    for(ll i = -100 ; i <= a ;i++){
        for(ll j = -100 ; j+i <= a ;j++){
            x = i ; y = j ; z = a-(i+j);
            if(x + y + z == a &&  x*y*z == b && x*x+y*y+z*z==c&&x!=y&&y!=z&&x!=z){
                    tr = true;
                    break;
            }
        }
        if(tr)break;
    }

    if(tr)cout  << x << " " << y << " " << z <<endl;
    else cout << "No solution." <<endl;

    }
}
