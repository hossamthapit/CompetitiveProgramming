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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
vector < string > grid ;

bool valid(int i , int j){
    return (i>=0 && j>=0 && i < szz(grid) && j < szz(grid[i]));
}

void spread(int i , int j){
    if(grid[i][j]!='*'&&grid[i][j]!=' ')return ;
    grid[i][j]='#';
    for(int e = 0 ; e < 4;e++){
        int x = dx[e]+i , y = dy[e]+j;
        if(valid(x,y))
            spread(x,y);
    }
}


int main(){file();

    int t ;
    cin >> t ;
    cin.ignore();
    while(t--){
        string s ;
        while(getline(cin, s)&&s[0]!='_')grid.push_back(s);
        for(int i = 0 ; i < szz(grid);i++)
            for(int k = 0 ; k < szz(grid[i]);k++)
               if(grid[i][k]=='*')spread(i,k);

        for(auto e : grid)cout << e << endl;
        cout << s << endl;
        grid.clear();
    }

}
