#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 }; int dy[] = { 1,-1,0,0,1,-1,1,-1 }; typedef long long ll; using namespace std;
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin)); if (freopen("output.txt", "w", stdout));
#endif
}

int def[3][3] = { {0,1,2},{3,4,5},{6,7,8} };
char dir[] = { 'l','r','d','u' };
map < pair < int, int >, int > getDir;

bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < 3 && y < 3);
}

void setDir() {
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 4; j++) {
                int xx = dx[j] + i, yy = dy[j] + k;
                if (valid(xx, yy)) {
                    getDir[{def[i][k], j}] = def[xx][yy];
                }
                else getDir[{def[i][k], j}] = -1;
            }
        }
    }
}


string solved = "12345678x";

map < string, string > ans;


struct state {
    int location;
    string curState;
    string path;
    state(int location, string st, string path) :location(location), curState(st), path(path) {};
};

string bfs() {

    queue < state > q;

    q.push(state(8, solved, ""));
    ans[solved] = "";


    while (szz(q)) {
        state u = q.front(); q.pop();

        for (int j = 0; j < 4; j++) {
            string temp = u.curState;

            int newIdx = getDir[{u.location, j}], curIdx = u.location;
            if (newIdx != -1) {
                swap(temp[newIdx], temp[curIdx]);
                if (!ans.count(temp)) {
                    q.push(state(newIdx, temp, dir[j] + u.path));
                    ans[temp] = (dir[j] + u.path);
                }
            }
        }
    }

    return "unsolvable";
}

int main() {
    init();

    int t;
    cin >> t;
    setDir();

    bfs();
    while (t--) {
        string s = "000000000";
        for (int i = 0; i < 9; i++)
            cin >> s[i];

        if (ans.count(s))cout << ans[s] << endl;
        else cout << "unsolvable" << endl;
        if(t)cout << endl;
    }



}