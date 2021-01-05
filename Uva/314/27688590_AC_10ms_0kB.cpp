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

struct cellMove {
    int x, y, cnt, direction;
    cellMove(int _x, int _y, int _direction, int _cnt) :x(_x), y(_y), direction(_direction), cnt(_cnt) {};
};

int n, m;
bool ar[55][55];
bool vis[55][55][4];

bool isValidCell(int x, int y) {
    if (x <= 0 or y <= 0 or x >= n or y >= m)
        return false;
    if (ar[x][y])
        return false;
    if (ar[x][y - 1])
        return false;
    if (ar[x - 1][y])
        return false;
    if (ar[x - 1][y - 1])
        return false;
    return true;
}

int N = 0, E = 1, S = 2, W = 3;

int solve() {

    memset(vis, 0, sizeof vis);
    int moves[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    for (int i = 0; i < n; i++)
        for (int k = 0; k < m; k++)
            cin >> ar[i][k];
    string dir;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey >> dir;

    int direction;
    if (dir[0] == 'n')direction = 0;
    else if (dir[0] == 'e')direction = 1;
    else if (dir[0] == 's')direction = 2;
    else direction = 3;

    queue < cellMove > q;
    if (isValidCell(sx, sy))q.push(cellMove(sx, sy, direction, 0));
    vis[sx][sy][direction] = 1;

    while (szz(q)) {
        cellMove p = q.front(); q.pop();
        if (p.x == ex && p.y == ey)
            return p.cnt;

        for (int k = 1; k <= 3; k += 2)
            if (!vis[p.x][p.y][(p.direction + k) % 4])
                vis[p.x][p.y][(p.direction + k) % 4] = 1, q.push(cellMove(p.x, p.y, (p.direction + k) % 4, p.cnt + 1));

        for (int i = 1; i <= 3; i++) {
            int x = p.x + moves[p.direction][0] * i, y = p.y + moves[p.direction][1] * i;
            if (isValidCell(x, y)) {
                if (!vis[x][y][p.direction])
                    vis[x][y][p.direction] = 1, q.push(cellMove(x, y, p.direction, p.cnt + 1));
            }
            else
                break;
        }
    }
    return -1;
}

int main() {
    init();

    while (cin >> n >> m && (n + m))
        cout << solve() << endl;


}