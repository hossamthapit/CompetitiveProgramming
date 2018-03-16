#include <bits/stdc++.h>
// *__*
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main()
{
    fast
    int t ;
    cin >> t ;
    while(t--)
    {
        int n , car , a , b , mx = INT_MIN , s = 0 ;

        cin >> n >> car ;
        vector<vector<int> > ar (n+4, vector <int> (n+4, 0));

        for(int i = 1 ; i <= n ;i++)
        {
            cin >> a >> b ;
            ar[a+1][i]=1;
            ar[b+2][i]=-1;
        }
        for(int i = 1 ; i <= n ;i++)
            for(int k = 1 ; k <= n ;k++)
                ar[k][i]+=ar[k-1][i];

        for(int i = 1 ; i <= n ;i++)
            for(int k = 1 ; k <= n ;k++)
                ar[i][k]+=ar[i][k-1];


        int c = 0 ;
        for(int i = 1 ; i+car <= n+1 ;i++)
        {
            for(int k = i ; ;k++)
            {
                if(c==car){c=0;break;}
                s+=ar[k][n];
                c++;
            }
            if(s>mx)mx=s;
            s = 0 ;
        }
        cout << (car*n)-mx <<endl;
    }

}
