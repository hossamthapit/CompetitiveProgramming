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

bool comp(pair < string , string > p1 , pair < string , string > p2){
    if(szz(p1.second)>szz(p2.second))return 1;
    else if(szz(p1.second)<szz(p2.second))return 0;
    else return p1.second > p2.second;
}

int main(){file();

    string s ;
    vector < pair < string , string > > tre;
    map < string , bool > mp;
    bool valid = 1 ;

    while(cin >> s){
        string num  , path ;
        int cntR = 0 , cntL = 0;
        for(auto e : s)
            if(isdigit(e))num+=e;
            else if(isalpha(e))path+=e;

        if(szz(s)==2){
            bool valid = 1 ;
            sort(all(tre),comp);
            reverse(all(tre));

            if(szz(tre[0].second)||!szz(tre))valid = 0;
            mp["R"]=1;
            mp["L"]=1;
            for(int i = 1 ; i < szz(tre);i++){
                if(!mp[tre[i].second]){
                    valid=0;
                    break;
                }
                else {
                    mp[tre[i].second]=0;
                    mp[tre[i].second+'L']=1;
                    mp[tre[i].second+'R']=1;
                    mp[tre[i].second+'L']=1;
                }
            }
            if(!valid)cout << "not complete" << endl;
            else {
                cout << tre[0].first;
                for(int i = 1 ; i < szz(tre);i++)
                    cout << " " << tre[i].first;
                cout << endl;
            }
            tre.clear();
            mp.clear();
        }
        else {
            tre.push_back({num,path});
        }
    }
}
