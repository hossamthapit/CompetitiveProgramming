#include <bits/stdc++.h>
/*_*/
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define write  ofstream file_out ; file_out.open("output.txt");
#define read  ifstream file_in ; file_in.open("input.txt");
#define ll_str(x,y) stringstream sdf;sdf<<x;string str=sdf.str();y=str;
#define str_ll(x,y) stringstream sstr(x);ll val;sstr>>val;y=val;
#define all(x) x.begin(),x.end()
#define endl '\n'
#define szz(x) x.size()
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
using namespace std;


int main()
{
    fast write read

    ll n, s ;
    cin >> n >> s ;
    vector < int > v(n);
    vector < ll > v1;
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];

    ll l = 1, r = n, mid, sum = 0, sov=0, cost=0 , f;

    for(int i = 0 ; i < n ;i++)
        sum+=(n*(i+1))+v[i];

    if(sum<=s){
        cout << n << " " << sum << endl;
        return 0 ;
    }
    sum = 0;
    while(l < r)
    {
        mid = (l+r)/2;
        for(int i = 0 ; i < n ; i++)
        {
            f = (mid*(i+1))+v[i];
            v1.push_back(f);
        }
        sort(all(v1));

        for(int i = 0 ; i < mid ; i++)
            sum += v1[i];
        v1.clear();
        if(sum <= s)
        {
            l = mid+1;
            sov = mid ;
            cost = sum ;
        }
        else
        {
            r = mid ;
        }
        sum = 0 ;
    }
    cout << sov << " " << cost <<endl;

}
