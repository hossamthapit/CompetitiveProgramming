//throwing cards away 10935
#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int main()
{fast
    int x ;

    while(cin >> x)
    {

        if(x==0)return 0;
        vector<int>v;
        for (int i=1; i<=x; i++)v.push_back(i);

        int sz = v.size();

        cout << "Discarded cards: ";
        for(;;)
        {
            if(sz==1)break;
            else if(sz==2)cout <<v[0];
            else cout <<v[0] << ", ";

            sz--;
            v.erase(v.begin()+0);
            v.push_back(v[0]);
            v.erase(v.begin()+0);
        }
        cout << "\nRemaining card: "<<v[0]<<endl;
        }

}
