#include <iostream>
#include <bits/stdc++.h>
// *__*

typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi = 3.14159265;
const ll mod=1000000007;

using namespace std;

int main()
{
    int x ;

    while(cin >> x )
    {
        int c = 0 ;

        if(x==0)break;

        vector<vector< int > > v ( x, std::vector<int> ( x, 0 ) );
        vector<int>col(x,0);   // store one's number in row
        vector<int>row(x,0);   // store one's number in col

        for(int i = 0 ; i < x ;i++)
        {
            for(int k = 0 ; k < x ; k++)
            {
                cin >> v[i][k];
                if(v[i][k])c++;
            }
            row[i]=c;
            c = 0 ;
        }

        for(int i = 0 ; i < x ;i++)
        {
            for(int k = 0 ; k < x ; k++)
            {
                if(v[k][i])col[i]++;
            }
        }

        int g = 0 , a = -1 , b = -1 ;

        for(int i = 0 ; i < x ;i++)
        {
            if(row[i]==0)g++;
            else if(row[i]%2==0)g++;
            else a = i+1;
        }

        for(int i = 0 ; i < x ;i++)
        {
            if(col[i]==0)g++;
            else if(col[i]%2==0)g++;
            else b = i+1;
        }

        if(x*2==g)cout << "OK" <<endl;
        else if(x*2==g+2&&b!=-1&&a!=-1)cout <<"Change bit ("<<a<<','<<b << ")" <<endl;
        else cout << "Corrupt" <<endl;






    }



}
