//throwing cards away 10935
#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

string binary()
{

}
int main()
{fast
    ll x ;

    while(cin >> x)
    {
        bitset<32> s(x);

        string a , b ;
        bool z=1 ;
        if(!x)return 0;

        for(int i = 0 ; i < 32 ; i++)
        {
            if(s[i]==1&&z==1){a+="1";z=0;s[i]=0;}
            else a += "0";
            if(s[i]==1&&z==0)z=1;
        }
        reverse(a.begin(),a.end());
        bitset<32> s2(a);

        ll xx = s.to_ulong();
        ll yy = s2.to_ulong();
        cout << yy  << " " << xx <<endl;


    }

}
