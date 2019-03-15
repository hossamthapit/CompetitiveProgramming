#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define endl '\n'

void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}

int main(){

    file();

    int i = 1 , k =1 , c = 1 , mx = 1e7;
    vector < pair < int , int > >  vv(10000001) ;
    vv[c]={i,k};

    while(1){

        k++;
        c++;
        vv[c] = {i,k};

        while(i+1>0&&k-1>0){
            c++;
            i++;
            k--;
            vv[c] = {i,k};
            if(c>=mx)goto there;
        }
        c++;
        i++;
        vv[c] = {i,k};

        while(i-1>0&&k+1>0){
            c++;
            i--;
            k++;
            vv[c] = {i,k};
            if(c>=mx)goto there;

        }

        if(c>=mx)goto there;
    }
    there :
    int n ;
    while(cin >> n ){
        cout << "TERM " << n << " IS " << vv[n].first << "/" << vv[n].second << endl;
    }
}
