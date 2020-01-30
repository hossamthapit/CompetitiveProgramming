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

vector < vector < int > > v(3,vector < int > (3));
map < vector < vector < int > >  , int > mp;

bool isWin(){
    for(int i = 0 ; i < 3 ;i++){
        if(v[i][0]&&v[i][0]==v[i][1]&&v[i][1]==v[i][2])return true ;
        if(v[0][i]&&v[0][i]==v[1][i]&&v[1][i]==v[2][i])return true ;
    }
    if(v[0][0]&&v[0][0]==v[1][1]&&v[1][1]==v[2][2])return true;
    if(v[0][2]&&v[0][2]==v[1][1]&&v[1][1]==v[2][0])return true;
    return false;
}

void play(int idx = 0, bool turn = 0){

    if(isWin()||idx==9){
        mp[v]=1;
        return ;
    }

    for(int i = 0 ; i < 3 ;i++){
        for(int j = 0 ; j < 3 ;j++){
            if(!v[i][j]){
                v[i][j]=turn+1;
                play(idx+1,!turn);
                v[i][j]=0;
            }
        }
    }
}

int main(){file();

    string s ;
    play();
    while(cin >> s && s!="end"){
        for(int i = 0 ; i < 9;i++)
            if(s[i]=='X')v[i/3][i%3]=1;
            else if(s[i]=='O') v[i/3][i%3]=2;
            else v[i/3][i%3]=0;

        if(mp[v])cout << "valid" << endl;
        else cout << "invalid" << endl;
    }
}
