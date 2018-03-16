#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define all(x) x.begin(),x.end()
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()


{fast

    int t ;
    cin >> t ;
    while(t--){

        int x , sum = 0 , cash;
        bool valid = false ;
        vector <int>ar(21);

        cin >> x >> cash ;

        for(int i = 0 ; i < x ;i++)
            cin >> ar[i];

        string s ;
        bitset<21> bts ;

        ll e = (1<<x);

        for( ;e--;e){
            bts = e ;
            s = bts.to_string();
            reverse(all(s));
            for(int k = 0 ; k < x ;k++){
                if(s[k]=='1')
                    sum+=ar[k];
            }
            if(sum==cash)valid = true ;
            sum = 0 ;
        }
        if(valid)
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
        valid = false ;
    }
}
