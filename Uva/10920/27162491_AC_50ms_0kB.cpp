#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
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
    while (cin >> n >> m && n && m) {

        if (m == 1) {
            cout << "Line = " << (n + 1) / 2 << ", column = " << (n + 1) / 2 << "." << endl;
            continue;
        }
        int sq = 0 , top ;

        for (int i = 1; i ; i+=2) {
            if (m - (i * i) <= 0)break;
            sq++;
            top = i;

        }

        int myRow = n / 2 +1 + sq, myCol = myRow - 1, still = m - top * top;


        if (still <= top + 1) {
            myCol -= (still - 1);
        }
        else if (still <= top * 2 + 2) {
            myCol -= top;
            myRow -= (still - (top+1));
        }
        else if (still <= top * 3 + 3) {
            myCol -= top;
            myRow -= (top + 1);
            myCol += (still - (top * 2 + 2));
        }
        else {
            myCol -= top;
            myRow -= (top + 1);
            myCol += (top + 1);
            myRow += (still - (top * 3 + 3));
        }

        cout << "Line = " << myRow << ", column = " << myCol << "." << endl;
    }

}