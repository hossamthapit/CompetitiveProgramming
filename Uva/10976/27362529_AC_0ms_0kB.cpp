#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1};
int dy[] = { 1,-1,0,0,1,-1,1,-1};
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
    
    int n;
    while (cin >> n) {

        vector < pair < int , int > > ans;

        for (int i = n+1; i <= n * 2; i++) {
            int nom = i - n;
            int dem = n * i;
            if (dem % nom == 0 && dem / nom >= i) {
                ans.push_back({ dem / nom,i });
            }
        }
        cout << szz(ans) << endl;
        for (auto e : ans) {
            cout << "1/" << n << " = ";
            cout << "1/" << e.first << " + ";
            cout << "1/" << e.second << endl;
        }

    }
}