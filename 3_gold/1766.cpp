#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int p[32768];
vector<int> nxt[32768];
priority_queue<int, vector<int>, greater<int>> hw;

int main(void) {
    int n, m, a, b, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        nxt[a].push_back(b);
        p[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) hw.push(i);
    }
    for (int i = 0; i < n; i++) {
        t = hw.top();
        hw.pop();
        printf("%d ", t);
        for (int j = 0; j < nxt[t].size(); j++) {
            p[nxt[t][j]]--;
            if (!p[nxt[t][j]]) hw.push(nxt[t][j]);
        }
    }
    return 0;
}