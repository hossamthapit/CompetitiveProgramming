#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast write

    int n , num ;
    while(cin >> num >> n ){

        if(!num&&!n)break;
        bitset < 12 > bts ;
        int sum = 0;

        vector < int > v (n);
        vector < int > res ;
        set < vector < int > > st ;

        for(int i = 0 ; i < n ;i++)
            cin >> v[i];

        string s ;

        for(int i = 1 ; i < (1<<n) ;i++){
            bts = i ;
            s = bts.to_string();
            reverse(all(s));

            for(int k = 0 ; k < 12 ;k++){
                if(s[k]=='1'){
                    sum+=v[k];
                    res.push_back(v[k]);
                }
            }
            if(sum == num)st.insert(res);
            sum = 0 ;
            res.clear();
        }

        cout << "Sums of " << num << ":" << endl;
        if(st.size()){
            set < vector < int > > :: iterator it ;
            it  = st.end();
            it--;
            for( ; ;it--){
                res.clear();
                res = *it ;
                for(int i = 0 ; i < res.size()-1 ;i++)
                    cout << res[i] << "+";
                cout << res[res.size()-1] << endl;
                if(it==st.begin())break;
            }
        }
        else cout << "NONE" <<endl;
        res.clear();
        st.clear();
    }
}
