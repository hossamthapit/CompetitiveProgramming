#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define rt return 
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;

void file() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}

int MAX = 10000001;
int isNotPrime[10000005];

void sieve() {

    for (int i = 2; i < MAX; i++) {
        if (isNotPrime[i])continue;
        for (int k = i * 2; k < MAX; k += i)
            isNotPrime[k] = 1;
    }
}

int main() {
    file();

    sieve();

    set < int > st;
    for (int i = 2; i < MAX; i++) {
        if (!isNotPrime[i])st.insert(i);
    }
    ll n;
    while (cin >> n) {

        vector < int > vv;
        if (n > 7)
            for (int i = 6; i >= 0; i -= 2) {
                int m = *(--st.upper_bound(n - i));
                n -= m;
                vv.push_back(m);
            }
        if (n != 0)cout << "Impossible." << endl;
        else {
            cout << vv[0];
            for (int i = 1; i < 4; i++)
                cout << " " << vv[i];
            cout << endl;
        }
    }



}