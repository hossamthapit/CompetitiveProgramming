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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}

int row[8], col[8], d1[16], d2[16], x, y;

set < vector < int > > st;
vector < int > temp;

void solve(int i) {

    if (szz(temp) == 8) {
        st.insert(temp);
        return;
    }
    if (i == 8)return;

    for (int j = 0; j < 8; j++) {
        if (row[i] || col[j] || d1[i - j + 8] || d2[i + j])continue;

        if (i != x || y != j)
            if (x == i || y == j || x - y == i - j || x + y == i + j)continue;

        row[i] = col[j] = d1[i - j + 8] = d2[i + j] = 1;
        temp.push_back(j);
        solve(i + 1);
        row[i] = col[j] = d1[i - j + 8] = d2[i + j] = 0;
        temp.pop_back();
    }
}

int main() {
    file();

    int t;
    cin >> t;
    while (t--) {

        cin >> y >> x;
        x--; y--;

        solve(0);

        int k = 1;
        cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n" << endl;
        for (auto e : st) {
            if (k + 1 <= 10)cout << " ";
            cout << k++ << "     ";
            for (auto r : e)
                cout << " " << r + 1;
            cout << endl;
        }
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(d1, 0, sizeof d1);
        memset(d2, 0, sizeof d2);
        st.clear();
        temp.clear();
        if (t)cout << endl;
    }



}