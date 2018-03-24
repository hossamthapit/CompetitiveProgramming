#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std ;

int main()
{

    int n , t ;
    while(cin >> n >> t){

    bitset < 20 > bts ;
    string s , ans;
    ll  mx = 0 , sum = 0 ;


    vector < int > v(t) ;

    for(int i = 0 ; i < t ; i++)
        cin >> v[i];

    for(int i = 1 ; i < (1<<t) ; i++){
        bts = i ;
        s = bts.to_string();
        reverse(all(s));
        for(int k = 0 ; k < 20 ;k++){
            if(s[k]=='1')sum += v[k];
        }
        if(sum <= n && sum >= mx){
            mx = sum;
            ans = s ;
        }
        sum = 0 ;
    }
    for(int i = 0 ; i < 20;i++)
        if(ans[i]=='1')cout << v[i] <<" " ;
    cout << "sum:"<< mx << endl;
    }
}
