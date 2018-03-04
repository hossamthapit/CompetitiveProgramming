//10945 
#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int main()
{fast //ll t;cin>>t;while(t--)
{
   string s ;
   while(getline(cin,s))
    {
        string ss , x  ;
        int sz = s.size();

        for(int i = 0 ; i < sz;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')ss+=(s[i]+32);
            if(s[i]>='a'&&s[i]<='z')ss+=s[i];
        }
        x = ss ;
        reverse(x.begin(),x.end());

        if(ss=="done")break;
        else if(x==ss)cout << "You won't be eaten!" <<endl;
        else cout << "Uh oh.." <<endl;


    }

}
}
