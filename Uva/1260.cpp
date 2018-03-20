#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast

    int t ;
    cin >> t ;
    while(t--){

        int n , ans = 0 ;
        cin >> n ;

        vector < int > v(n);

        for(int i = 0 ; i < n ;i++)
            cin >> v[i];

       for(int i = 1 ; i < n ;i++){
            for(int k = i-1 ;k>=0 ;k-- ){
                if(v[k] <= v[i])ans++;
            }
       }
       cout << ans <<endl;
    }

}
