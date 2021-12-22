#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : 주어진 그래프의 최소한의 색을 사용하는 컬러링을 구한다.

해결 방법 : 주어진 그래프는 이분 그래프이다. 따라서, 이분 그래프의 두 부분을 찾아서 나누어 주면 된다.

주요 알고리즘 : 그래프 이론, 이분 그래프, BFS

출처 : CEOI 2015 5-10번
*/

vector<int> ed[103000];
queue<int> q;
int color[103000];

void bfs(int x) {
    q.push(x);
    color[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (color[i] == 0) {
                color[i] = (!(color[x] - 1)) + 1;
                q.push(i);
            }
        }
    }
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
    //freopen("E:\\PS\\Olympiad\\Central Europe\\2015\\ceoi2015\\10960\\calvin10.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    bfs(1);
    if (!check(n)) return 1;
    printf("2\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            if (color[j] == i) printf("%d ", j);
            if (color[j] == 0) {
                return 1;
            }
        }
        printf("\n");
    }
    return 0;
}