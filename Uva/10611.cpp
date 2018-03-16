#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{fast

    int n , q , a , l;
    cin >> n ;

    vector <int> ar ;

    for(int i = 0 ; i < n ;i++){
        cin >>a ;
        ar.push_back(a);
    }

    cin >> q ;

    vector <int> :: iterator up,lo ,mx,mn;

     mx = max_element(ar.begin(),ar.end());
     mn = min_element(ar.begin(),ar.end());

    while(q--){
        cin >> l ;

        up = upper_bound(ar.begin(),ar.end(),l);
        lo = lower_bound(ar.begin(),ar.end(),l);
        lo--;

        if(up>mx||up==lo||*up==0)
            cout << *lo << " X" <<endl;
        else if (lo<mn)
            cout << "X " << *up <<endl;

        else
            cout << *lo << " " << *up <<endl;
    }
}
