#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

int sum(ll x ){

    int c = 0 , y;
    while(x>0){
        y=x%10;
        c+=y;
        x/=10;
    }
    return c ;
}
using namespace std;
int main()
{fast
    ll x ;
    cin >> x ;
    ll i = sqrt(x);

    for(ll k = i-100001 ; k <= i+100001;k++)
        if(sum(k)*k+k*k==x&&k>=0){cout << k <<endl; return 0;}
    cout << -1 << endl;
}
