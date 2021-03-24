#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <queue>
using namespace std;

int vis[1048576];
char s[128];
queue<pair<int, pair<long long, long long>>> q;

void bfs(int n, int x) {
    pair<long long, long long> y;
    x %= n;
    q.push(pair<int, pair<long long, long long>>(x, pair<long long, long long>(0, 1)));
    vis[x] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        vis[x] = 1;
        if (x == 0) break;
        y.first *= 2;
        y.first += y.second * 2 >> 50;
        y.second = (y.second * 2) & ((1LL << 50) - 1);
        if (!vis[(x * 10) % n]) {
            vis[(x * 10) % n] = 1;
            q.push(pair<int, pair<long long, long long>>((x * 10) % n, y));
        }
        y.first += (y.second + 1) >> 50;
        y.second = (y.second + 1) & ((1LL << 50) - 1);
        if (!vis[(x * 10 + 1) % n]) {
            vis[(x * 10 + 1) % n] = 1;
            q.push(pair<int, pair<long long, long long>>((x * 10 + 1) % n, y));
        }
    }
    while (q.size()) q.pop();
    int p = 0;
    for (int i = 49; i >= 0; i--) {
        if (p == 0) {
            if ((y.first >> i) & 1) {
                s[p++] = '1';
            }
            else continue;
        }
        else s[p++] = ((y.first >> i) & 1) ? '1' : '0';
    }
    for (int i = 49; i >= 0; i--) {
        if (p == 0) {
            if ((y.second >> i) & 1) {
                s[p++] = '1';
            }
            else continue;
        }
        else s[p++] = ((y.second >> i) & 1) ? '1' : '0';
    }
    return;
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        bfs(n, 1);
        printf("%s\n", s);
        memset(vis, 0, sizeof(int) * n);
        memset(s, 0, sizeof(char) * 128);
    }
    return 0;
}