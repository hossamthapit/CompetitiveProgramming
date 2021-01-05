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

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)return 0;
    return 1;
}

bool dist(int s , int x) {
    int c = 0;
    while (x) {
        c += ((x % 10) != (s % 10));
        x /= 10;
        s /= 10;
    }
    return c == 1;
}


map < string, int > dp;
vector < int > primes;
vector < vector < int > > adj;


int bfs(int s, int e) {

    vector < int > vis(2000);
    queue < pair < int, int > > q;
    q.push({ s,0 });
    while (szz(q)) {
        pair < int, int > p = q.front(); q.pop();
        if (vis[p.first])continue;
        if (p.first == e)return p.second;
        vis[p.first] = 1;
        for (auto e : adj[p.first])
            if (!vis[e])
                q.push({ e,p.second + 1 });
    }
    return -1;
}

int main() {

    file();

    int idx = 1;
    map < int, int > id;
    for (int i = 1000; i <= 9999; i++)
        if (isPrime(i)) {
            primes.push_back(i);
            id[i] = idx++;
        }
    adj = vector < vector < int > >(idx);

    for (int i = 0; i < szz(primes); i++) {
        for (int k = 0; k < szz(primes); k++) {
            if (dist(primes[i], primes[k])) {
                adj[id[primes[i]]].push_back(id[primes[k]]);
                adj[id[primes[k]]].push_back(id[primes[i]]);
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << bfs(id[a], id[b]) << endl;
    }


}