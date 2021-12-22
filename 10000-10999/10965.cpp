#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> ed[103000];
int color[103000];

void bfs(int x, int c) {

}

int check(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j : ed[i]) {
            if (color[j] == color[i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int n, m, x, y;
    //freopen("E:\\PS\\Olympiad\\Central Europe\\2015\\ceoi2015\\10960\\calvin5.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    //bfs(1, 1);
    for (int i = 1; i <= n; i++) {
        color[i] = ((i - 1) % 3) + 1;
    }
    if (!check(n)) return 1;
    printf("3\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            if (color[j] == i) printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}