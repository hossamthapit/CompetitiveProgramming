#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast write

    int n , q , k , p =1;

    while(cin >> n >> q){

        if(!n&&!q)break;

        vector < int > v (n);
        map < int , int > mp;

        for(int i = 0 ; i < n ;i++){
            cin >> v[i];
        }
        sort(all(v));

        for(int i = 0 ; i < n ;i++)
            if(mp[v[i]]==0)mp[v[i]]=i+1;

        cout << "CASE# " << p++ <<":\n" ;
        while(q--){
            cin >> k ;
            if(mp[k]!=0)
                cout << k << " found at " << mp[k]<<endl;
            else cout << k << " not found\n";
        }
        mp.clear();
        v.clear();
    }
}
