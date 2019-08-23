#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;

void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
string ar[] = {"fill A" , "fill B" , "pour A B" , "pour B A" , "empty A" , "empty B"};
ll target , aCapacity , bCapacity ;


pair < ll , ll > check(ll a , ll b , int i){
    if(i==1)a = aCapacity;
    else if(i==2)b = bCapacity;
    else if(i==3){ll temp = b ;b = min(b+a,bCapacity);a = max(a-(b-temp),0LL);}
    else if(i==4){ll temp = a ;a = min(b+a,aCapacity);b = max(b-(a-temp),0LL);}
    else if(i==5)a = 0;
    else if(i==6)b = 0;
    return {a,b};
}

bool vis[5000][5000];
void BFS(){
    queue < pair < vector < int > , pair < ll , ll > > > qu ;
    for(int i = 1 ; i <= 6 ;i++){
        vector < int > v ;
        v.push_back(i);
        qu.push({v,check(0,0,i)});
    }

    while(szz(qu)){
        pair < vector < int > , pair < ll , ll > > p = qu.front();
        qu.pop();
        if(vis[p.second.first][p.second.second])continue;
        if(p.second.second==target){
            for(auto e : p.first)
                cout << ar[e-1] << endl;
            cout << "success" << endl;
            break;
        }
        vis[p.second.first][p.second.second]=1;

        for(int i = 1 ; i <= 6 ;i++){
            pair < ll , ll > pp = check(p.second.first,p.second.second,i);
            vector < int > v = p.first;
            v.push_back(i);
            qu.push({v,pp});
        }
    }
}

int main()
{
    file();
    while(cin >> aCapacity >> bCapacity >> target){
        memset(vis,0,sizeof vis);
        BFS();
    }
}
