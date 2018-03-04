//494 
#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int main()
{fast // ll T;cin>>T;while(T--)
{
    string x ;
    int c = 0 ;

    while(getline(cin,x))
    {
        string s ;
        int sz = x.size();

        // clear punctuations
        for(int i = 0 ; i < sz;i++)
        {
            if((x[i]>='a'&&x[i]<='z')||(x[i]>='A'&&x[i]<='Z')||x[i]==' ')s+=x[i];
        }
        //clear consecutive spaces
        x="";
        sz = s.size();
        for(int i = 0 ; i < sz;i++)
        {
            if(s[i]==' '&&s[i+1]==' ');
            else x+=s[i];
        }
        // clear first & last spaces
        sz = x.size();
        if(x[sz-1]==' ')x.erase(sz-1,1);
        if(x[0]==' ')x.erase(0,1);
        //count spaces
        sz = x.size();
        for(int i = 0 ; i < sz;i++)
        {
            if(x[i]==' ')c++;
        }
        if(s>" ")cout << c+1 <<endl;
        c=0 ;
    }
}
}
