#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast

    int x ;

    while(cin >> x)
    {
        if(!x)return 0;
        int c = 0 , mx = 0 , p =0 ;
        string s ;
        cin.ignore();
        vector < int > v(x) ;

        for(int i = 0 ; i < x ;i++)
        {
            getline(cin , s);
            for(int k = 0 ; k < 25;k++)
            {
                if(s[k]=='X')c++;
            }
            if(c>mx)mx=c;
            v[i]=c;
            c = 0 ;
        }
        int ans = 0 ;
        for(int i = 0 ; i < x ;i++)
        {
            ans+=(mx-v[i]);
        }
       cout << ans <<endl;
    }
}
