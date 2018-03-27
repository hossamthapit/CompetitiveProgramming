#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast write

    int x ;
    while(cin >> x){

        if(!x)break;

        int sz , c = 0 , mx;
        multiset < int > st ;
        multiset < int > :: iterator stit;
        vector < vector < int > > v (x , vector <int> (5));
        map < vector < int > , int > mp ;
        map < vector < int > , int > :: iterator it ;

        for(int i = 0 ; i < x ;i++)
            for(int j = 0 ; j < 5 ;j++)
                cin >> v[i][j] ;

        for(int i = 0 ; i < x ;i++)
            sort(all(v[i]));

        for(int i = 0 ; i < x ;i++)
            mp[v[i]]++;

        for(it = mp.begin() ; it != mp.end() ; it++)
          st.insert(it->second) ;

        stit = st.end();
        stit--;
        mx = *stit ;

        stit--;
        sz = st.size()-1;
        while(sz--){
            if(*stit==mx)c++;
            stit--;
        }
        (mx==1 ? cout << x << endl : cout << mx+(mx*c) << endl);
        v.clear();
        mp.clear();
        st.clear();
    }
}
