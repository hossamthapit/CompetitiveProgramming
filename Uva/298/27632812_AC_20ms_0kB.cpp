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

bool blocked[33][33];

struct movement{
    int x, y, xSpeed, ySpeed;
    movement(int x , int y , int xSpeed , int ySpeed):x(x),y(y),xSpeed(xSpeed),ySpeed(ySpeed){}
};


bool valid(int x, int y, int n, int m) {
    return (x >= 0 && y >= 0 && x < n&& y < m);
}

bool bfs(int n, int m, int xs, int ys, int xe, int ye) {
    int dist[33][33][10][10];
    memset(dist, 0, sizeof dist);
    dist[xs][ys][3][3] = 1;
    queue < movement > q;
    q.push(movement(xs, ys, 0, 0));

    while (szz(q)) {
        movement u = q.front(); q.pop();

        if (u.x == xe && u.y == ye) {
            cout << "Optimal solution takes " << dist[u.x][u.y][u.xSpeed+3][u.ySpeed+3]-1 << " hops." << endl;
            return 1;
        }

        for (int i = -1; i <= 1; i++) {
            for (int k = -1; k <= 1; k++) {
                int spX = u.xSpeed + i, spY = u.ySpeed + k;
                if (abs(spX) > 3 || abs(spY) > 3)continue;
                int xx = u.x + spX, yy = u.y + spY;
                if (!valid(xx, yy, n, m) || dist[xx][yy][spX+3][spY+3] || blocked[xx][yy])continue;
                dist[xx][yy][spX+3][spY+3] = dist[u.x][u.y][3+u.xSpeed][3+u.ySpeed] + 1;
                q.push(movement(xx, yy, spX, spY));
            }
        }
    }
    return 0;
}

int main() {
    init();
    
    int t;
    cin >> t;
    while (t--) {
        memset(blocked, 0, sizeof blocked);
        int n, m , xs , ys , xe, ye; 
        cin >> n >> m >> xs >> ys >> xe >> ye;
        int q; cin >> q;
        while (q--) {
            int x, x1, y, y1; cin >> x >> x1 >> y >> y1;
            for (int i = x; i <= x1; i++)
                for (int k = y; k <= y1; k++)
                    blocked[i][k] = 1;
        }

        if (!bfs(n, m, xs, ys, xe, ye))cout << "No solution." << endl;

    }
    


}
