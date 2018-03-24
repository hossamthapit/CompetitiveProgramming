#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std ;

int main()
{
    ll n , s ;
    while(cin >> n >> s){
    
    ll  l = 0 , r = 1 , mn = INT_MAX , sum = 0 ;

    vector < int > v(n) ;

    for(int i = 0 ; i < n ;i++)
        cin >> v[i];

    sum = v[l];

    while(r <=  n){

        if(sum < s)
            sum += v[r++];

        else if(sum >= s){
            if( r - l < mn )mn = r - l ;
                sum -= v[l];
                l++;
        }
    }

        if(mn==INT_MAX)cout << 0 <<endl;
        else cout << mn << endl;
    }
}
