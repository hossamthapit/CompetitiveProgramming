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

void gen(int n , int steps) {
    string ar1[] = { "move","pile" };
    vector < int > v2(n) , v4(n);
    for (int i = 1; i <= n; i++)
        v2[i - 1] = v4[i - 1] = i;
    string ar3[] = { "over","onto" };

    cout << steps << endl;
    for (int i = 0; i < steps; i++) {
        random_shuffle(ar1, ar1 + 2);
        random_shuffle(ar3, ar3 + 2);
        random_shuffle(all(v2));
        random_shuffle(all(v4));

        cout << ar1[0] << " " << v2[0] << " " << ar3[0] << " " << v4[0] << endl;
    }
    cout << "quit" << endl;
}


int main() {
    file();

    //gen(15, 17);
    //return 0;

    int n;
    cin >> n;
    vector < stack < int > > v(n);

    for (int i = 0; i < n; i++)
        v[i].push(i);

    vector < int > cur(n), prev(n);

    for (int i = 0; i < n; i++)cur[i] = i;
    for (int i = 0; i < n; i++)prev[i] = i;

    string s1, s2;
    int a, b;

    while (cin >> s1 && s1 != "quit" && cin >> a >> s2 >> b) {
        if (cur[a] == cur[b])continue;
        if (s1 == "move") {
            while (v[cur[b]].top() != b && s2 == "onto") {
                int val = v[cur[b]].top();
                v[cur[b]].pop();

                v[val].push(val);
                cur[val] = val;
            }
            while (v[cur[a]].top() != a) {
                int val = v[cur[a]].top();
                v[cur[a]].pop();

                v[val].push(val);
                cur[val] = val;
            }
            v[cur[a]].pop();
            cur[a] = cur[b];
            v[cur[b]].push(a);
        }
        else {
            while (v[cur[b]].top() != b && s2 == "onto") {
                int val = v[cur[b]].top();
                v[cur[b]].pop();

                v[val].push(val);
                cur[val] = val;
            }

            deque < int > dq;
            while (v[cur[a]].top() != a) {
                int val = v[cur[a]].top();
                v[cur[a]].pop();
                dq.push_back(val);
            }

            dq.push_back(a);
            v[cur[a]].pop();

            while (szz(dq)) {
                v[cur[b]].push(dq.back());
                cur[dq.back()] = cur[b];
                dq.pop_back();
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << ":";
        deque < int > ans;
        while (v[i].size()) {
            ans.push_front(v[i].top());
            v[i].pop();
        }
        for (int k = 0; k < szz(ans); k++)
            cout << " " << ans[k];
        cout << endl;
        //if(i!=n-1)cout << endl;
    }


}