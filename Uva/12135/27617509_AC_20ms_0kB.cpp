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

int main() {
    init();

    int t, T = 1 , n;
    cin >> t;
    while (t--) {
        int m;
        cin >> n >> m;
        int switches[40];
        memset(switches, 0, sizeof switches);
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            for (int k = 0; k < x; k++) {
                int a; cin >> a;
                switches[i] |= (1 << a);
            }
        }

        int ans[100000];
        memset(ans, 0, sizeof ans);
        queue < int > q;
        ans[0] = 1;
        q.push(0);

        while (szz(q)) {
            int u = q.front(); q.pop();
            for (int i = 0; i < m; i++) {
                ll neww = (u ^ switches[i]);
                if (!ans[neww])
                    q.push(neww), ans[neww] = ans[u] + 1;
            }
        }

        int w;
        cin >> w;
        cout << "Case " << T++ << ":" << endl;
        while (w--) {
            string s; cin >> s;
            reverse(all(s));
            ll num = 0;
            for (int i = 0; i < szz(s); i++)
                if(s[i]=='1')num += (1 << i);

            if (ans[num])
                cout << ans[num]-1 << endl;
            else
                cout << -1 << endl;
        }
        cout << endl;


    }


}