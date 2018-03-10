#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{fast

    int a , c = 0 , k ;
    cin >> a ;

    for(;a>0;)
    {
        k = a%2;
        if(k==1)c++;
        a/=2;
    }

    cout << c <<endl;
}
