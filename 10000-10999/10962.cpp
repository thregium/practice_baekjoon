#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ed[103000];
int color[103000];
int fin = 0;

void track(int n, int x, int c) {
    int tmp = 0;
    if (x == n) {
        tmp = 1;
        for (int i = 1; i <= n; i++) {
            for (int j : ed[i]) {
                if (color[i] == color[j]) tmp = 0;
            }
        }
        fin = tmp;
        return;
    }
    for (int i = 1; i <= c; i++) {
        color[x] = i;
        tmp = 1;
        for (int j : ed[x]) {
            if (j < x && color[j] == color[x]) {
                tmp = 0;
                break;
            }
        }
        if (tmp) track(n, x + 1, c);
        if (fin) return;
    }
}

int main(void) {
    int n, m, x, y, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        track(n, 1, i);
        if (fin) {
            res = i;
            break;
        }
    }
    if (res == 0) return 1;
    printf("%d\n", res);
    for (int i = 1; i <= res; i++) {
        for (int j = 1; j <= n; j++) {
            if (color[j] == i) printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}