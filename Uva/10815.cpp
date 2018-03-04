//10815 
#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

string ar[100000];

int main()
{fast //ll t;cin>>t;while(t--)
{
   int c = 0 ;
   
   string x ;
   while(cin >> x)
    {
        int sz ;
        string s;
        
        sz = x.size();

        // clear punctuations
        for(int i = 0 ; i < sz;i++)
        {
            if(x[i]>='A'&&x[i]<='Z')x[i]=tolower(x[i]);
            if(x[i]>='a'&&x[i]<='z')s+=x[i];
            else if(s>""){ar[c++]=s;s="";}
        }
        if(s>"")ar[c++]=s;
    }

    sort(ar,ar+c);

    for(int i = 0 ; i < c ;i++)
        if(ar[i]!=ar[i+1])cout << ar[i] <<endl;

}
}
