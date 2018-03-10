#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast
    int m , n ;

    while(cin >> n >> m ){

        if(!n&&!m)break;
        map < int , int > mp ;

        for(int i = 0 ; i < n ;i++)
        {
            int a ;
            cin >> a ;
            mp[a]++;
        }
        int c = 0 ;

        for(int i = 0 ; i < m ;i++)
        {
            int a ;
            cin >> a ;
            if(mp[a])c++;
        }
        cout << c << endl;

    }

}
