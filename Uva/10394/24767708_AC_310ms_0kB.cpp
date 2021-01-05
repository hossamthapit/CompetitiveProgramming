#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;

void file() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}

bool prime[20000005];

void sieve() {
    for (int i = 2; i < 20000005; i++) {
        if (prime[i])continue; 
        for (int k = i+i; k < 20000005; k += i)
            prime[k] = 1;
   }
}

int main() {
    file();

    
    sieve();
    int n;
    vector < pair < int, int > > v;

    for (int i = 2; szz(v) < 100000; i++)
        if (prime[i]+prime[i+2]==0)v.push_back({ i,i + 2 });

    while (cin >> n)cout << "(" << v[n - 1].first << ", " << v[n - 1].second << ")" << endl;


    
}