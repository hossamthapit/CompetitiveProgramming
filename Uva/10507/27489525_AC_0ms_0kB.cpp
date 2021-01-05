#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
typedef long long ll;
using namespace std;

void file() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}


int main() {
    file();

    
    int n , m;
    while (cin >> n >> m) {

        string awake; cin >> awake;

        int cnt = 1;
        map < char, int > value;
        vector < vector < int > > adj(n+1);
        vector < int > isWake(n + 1);

        int wakeCnt = szz(awake);

        for (auto e : awake) {
            if (!value[e])value[e] = cnt++;
            isWake[value[e]] = 1;
        }

        for (int i = 0; i < m; i++) {
            char a, b; cin >> a >> b;
            if (!value[a])value[a] = cnt++;
            if (!value[b])value[b] = cnt++;

            adj[value[a]].push_back(value[b]);
            adj[value[b]].push_back(value[a]);
        }

        set < int > sleeps;
        for (int i = 1; i <= n; i++)
            if (!isWake[i])
                sleeps.insert(i);

        int years = 0;
        while (wakeCnt < n && years < 30) {
            set < int > wakeMeUp;
            for (auto e : sleeps) {
                int wakeNearme = 0;
                for (auto k : adj[e]) {
                    wakeNearme += isWake[k];
                }
                if (wakeNearme >= 3)
                    wakeMeUp.insert(e);
            }

            for (auto e : wakeMeUp) {
                sleeps.erase(e);
                isWake[e] = 1;
                wakeCnt++;
            }
            years++;
        }
        if (years == 30)cout << "THIS BRAIN NEVER WAKES UP" << endl;
        else cout << "WAKE UP IN, " << years << ", YEARS" << endl;

    }

}