#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int ar[1001];

using namespace std;
int main()
{fast
    int x ;
    cin >> x ;
    
    for(int i = 0; i <x ;i++)
        cin >> ar[i];

    sort(ar,ar+x);

    for(int i = 0,j = x-1 ; i<=j ; i++,j--){
        if(i!=j)cout << ar[i] << " " ;
        cout << ar[j] << " " ;
    }
}
