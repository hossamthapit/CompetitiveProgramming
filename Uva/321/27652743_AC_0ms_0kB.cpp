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

bool getBit(ll x, ll idx) {
    return x & (1LL << idx);
}

bool flipBit(ll& x, ll idx) {
    x = (x ^ (1LL << idx));
    return getBit(x, idx);
}


ll setBit(ll x, ll idx) {
    return (x | (1LL << idx));
}

struct state {
    int curRoom;
    ll curState;
    vector < pair < int, int > > path;
    state() {}
    state(int cur, ll on) :curRoom(cur), curState(on) {};
    bool operator < (const state& st)const {
        return szz(path) > szz(st.path);
    }
};

vector < vector < int > > roomDoors;
vector < vector < int > > roomSwitches;


void printPath(vector < pair < int, int > >& v) {
    cout << "The problem can be solved in " << szz(v) << " steps:" << endl;
    for (auto e : v)
        if (e.first == -1)
            cout << "- Move to room " << e.second + 1 << "." << endl;
        else if (e.first)
            cout << "- Switch on light in room " << e.second + 1 << "." << endl;
        else
            cout << "- Switch off light in room " << e.second + 1 << "." << endl;
}

bool bfs(int r) {
    map < pair < ll, int >, bool > vis;
    priority_queue < state > q;

    vis[{1, 0}] = 1;
    q.push(state(0 ,1));

    r--;

    while (szz(q)) {
        state cur = q.top(); q.pop();
        if (cur.curState == (1LL << r)) {
            printPath(cur.path);
            return 1;
        }

        state x;
        for (auto sw : roomSwitches[cur.curRoom]) {
            x = cur;
            ll temp = cur.curState;
            int bit = flipBit(temp, sw);
            if (!getBit(temp, cur.curRoom))continue; // dont close cur room switch
            x.path.push_back({ bit,sw });
            x.curState = temp;
            if (!vis[{x.curState, x.curRoom}])
                q.push(x),vis[{x.curState, x.curRoom}] = 1;

        }
        for (auto e : roomDoors[cur.curRoom]) {
            if (getBit(cur.curState, e) && !vis.count({ cur.curState,e })) {
                x = cur;
                x.path.push_back({ -1,e });
                x.curRoom = e;
                if (!vis[{x.curState, x.curRoom}])
                    q.push(x) , vis[{x.curState, x.curRoom}] = 1;
            }
        }
    }
    return 0;

}


int main() {
    init();

    int r, d, s, T = 1;
    while (cin >> r >> d >> s && (r + d + s)) {

        cout << "Villa #" << T++ << endl;
        roomDoors = roomSwitches = vector < vector < int > >(r);

        for (int i = 0; i < d; i++) {
            int a, b; cin >> a >> b; a--; b--;
            roomDoors[a].push_back(b);
            roomDoors[b].push_back(a);
        }
        for (int i = 0; i < s; i++) {
            int a, b; cin >> a >> b; a--; b--;
            roomSwitches[a].push_back(b);
        }

        if (!bfs(r))
            cout << "The problem cannot be solved." << endl;
        cout << endl;
    }


}