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

    // Two cases for win.
    // 1.Pick a cow and switch to a car:
    // 2.Pick a car and switch to a car:

    double cow, car, k;
    while (cin >> cow >> car >> k) {
        double p1 = cow / (cow + car) * car / (car + cow - k - 1);
        double p2 = car / (cow + car) * (car - 1) / (car + cow - k - 1);

        cout << fixed << setprecision(5) << p1+p2 << endl;
    
    }

    

}