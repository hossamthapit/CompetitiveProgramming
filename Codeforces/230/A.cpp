#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file ; file.open("HOSSAM.txt");
#define all(x) x.begin(),x.end()

using namespace std;
int main()
{fast

    int n , power ;
    pair < int , int > ar[1001];

    cin >> power >> n ;

    for(int i = 0 ; i < n ;i++)
        cin >> ar[i].first >> ar[i].second ;

    sort(ar,ar+n);

    for(int i = 0 ; i < n ;i++){
        if(power>ar[i].first)power+=ar[i].second;
        else {
            cout << "NO" <<endl;
            return 0;
        }
    }
    cout << "YES" <<endl;
}
