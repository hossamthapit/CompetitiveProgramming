#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

struct edge{
    int from , to , w ;
    edge(){};
    edge(int from , int to , int w ):from(from),to(to),w(w){}
};

bool foundNegative(vector < edge > &edgeList , int  n , int from){
    vector < int >dist(n,INT_MAX);
    dist[from]=0;

    for(int maxE = 0 , r = 0 ;maxE < n ;++maxE ,r=0){
        for(int j = 0 ; j < szz(edgeList);j++){
            edge ne = edgeList[j];
            if(dist[ne.to]>dist[ne.from]+ne.w){
                dist[ne.to] = dist[ne.from]+ne.w ;
                r = 1 ;
                if(maxE==n-1)
                    return 1;
            }
        }
        if(!r)break;
    }
    return 0 ;
}


int main(){file();

    int n , m , t;
    cin >> t ;
    while(t--){
        cin >> n >> m ;
        vector < edge > edges(m);
        for(int i = 0 ; i < m ;i++){
            cin >> edges[i].from >> edges[i].to >> edges[i].w ;
        }
        if(foundNegative(edges,n,0))cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
}
