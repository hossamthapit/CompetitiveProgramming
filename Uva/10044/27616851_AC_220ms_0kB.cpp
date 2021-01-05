#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
typedef long long ll;
using namespace std;
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;

void file() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}


vector < string > split(string s , map < char , bool > splitters) {

    string temp;
    vector < string > ret;

    for (auto e : s) {
        if (splitters[e] && szz(temp)) 
                ret.push_back(temp), temp = "";
        else if(!splitters[e] && (szz(temp)||e!=' ') ) temp += e;
    }
    if (szz(temp))ret.push_back(temp);
    return ret;
}

const int MAX = 1000001;
const int OO = 0x3f3f3f;

vector < vector < int > > adj(MAX);
int dist[MAX];

void bfs(int source) {
    queue < pair < int, int > > q;
    memset(dist, -1, sizeof dist);
    q.push({ source,0 });

    while (szz(q)) {
        int u = q.front().first, dis = q.front().second; q.pop();
        if (dist[u] != -1)continue;
        dist[u] = dis;
        for (auto e : adj[u]) {
            if (dist[e] == -1) 
                q.push({ e,dis + 1 });
        }
    }
}


int main() {

    file();

    map < char, bool > splitters = {{',',1},{':',1} };

    int t , T = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cin.ignore(); string s;
        adj = vector < vector < int > >(MAX);

        int id = 1;
        map < string, int > hash;

        for (int i = 0; i < n; i++) {
            getline(cin, s);
            vector < string > temp;
            for (auto e : split(s, splitters))
                temp.push_back(e);
            temp.pop_back();

            vector < int > tempIDS;
            for (int k = 0; k < szz(temp); k += 2) {
                string cur = temp[k] + temp[k + 1];
                if (!hash[cur])
                    hash[cur] = id++;
                tempIDS.push_back(hash[cur]);
            }

            for (auto e : tempIDS)
                for (auto k : tempIDS) 
                    adj[e].push_back(k),adj[k].push_back(e);
        }


        bfs(hash["ErdosP."]);

        cout << "Scenario " << T++ << endl;
        while (m--) {
            getline(cin,s);
            vector < string > temp = split(s, splitters);
            int val = hash[temp[0]+temp[1]];
            if (dist[val] == -1)cout << s << " infinity" << endl;
            else cout << s << " " << dist[val] << endl;

        }

    }

}