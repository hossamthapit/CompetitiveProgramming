#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define all(x) x.begin(),x.end()
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()


{fast

    int x , l , r , mn , ar[16] , min_e = INT_MAX , max_e = INT_MIN , ans=0 , sum = 0;
    cin >> x >> l >> r >> mn ;

    for(int i = 0 ; i < x ;i++)
        cin >> ar[i];
    sort(ar,ar+x);

    string s ;
    bitset<16> bts ;

    ll e = (1<<x);

    for( ;e--;){
        bts = e ;
        if(bts.count()<2)continue;
        s = bts.to_string();
        reverse(all(s));
        for(int k = 0 ; k < 16 ;k++){
            if(s[k]=='1'){
                    sum+=ar[k];
                    if(ar[k]<min_e)min_e=ar[k];
                    if(ar[k]>max_e)max_e=ar[k];
            }
        }
     //   cout << s << " " << max_e << " " << min_e << " " << sum <<endl;
        if(sum>=l&&sum<=r&&max_e-min_e>=mn)ans++;
        min_e = INT_MAX ;
        max_e = sum = 0;
    }
    cout << ans <<endl;

}
