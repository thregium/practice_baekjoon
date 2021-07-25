#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : 좌표평면 위에 N(N <= 5000)개의 도미노가 있다. 모든 도미노 끝부분에 대해 주변 칸들 중 하나에는 같은 수인 부분이 있도록
도미노에 수들을 적으려고 한다. 각 수들은 최대 2회씩만 적을 수 있고, 한 도미노에 같은 수를 적을 수는 없다면
그렇게 수들을 적는 방법이 있는지 확인하고 있다면 그러한 방법 중 하나를 출력한다.

해결 방법 : 인접한 조각끼리 연결해본다. 이때 좌표평면을 체스판 형태로 분해하면 각 색깔끼리는 이분 그래프 형태가 된다.
따라서, 이들을 이분 매칭을 통해 짝지어준 다음 짝을 짓지 못한 칸이 있다면 방법이 없는 것이고,
있다면 짝지은 방법을 출력하면 된다.

주요 알고리즘 : 이분 매칭

출처 : GCPC 2020 D번
*/

int grid[10240][10240], dominos[5120], left[5120], right[5120], vis[5120], res[5120];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<int> ed[5120];

int match(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (right[i] == 0 || (!vis[right[i]] && match(right[i]))) {
            left[x] = i;
            right[i] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, x1, y1, x2, y2, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        grid[x1][y1] = i;
        grid[x2][y2] = i;
        if ((x1 + y1) & 1) {
            for (int d = 0; d < 4; d++) {
                if (grid[x1 + dxy[d][0]][y1 + dxy[d][1]] > 0 && grid[x1 + dxy[d][0]][y1 + dxy[d][1]] != i) {
                    ed[grid[x1 + dxy[d][0]][y1 + dxy[d][1]]].push_back(i);
                }
                if (grid[x2 + dxy[d][0]][y2 + dxy[d][1]] > 0 && grid[x2 + dxy[d][0]][y2 + dxy[d][1]] != i) {
                    ed[i].push_back(grid[x2 + dxy[d][0]][y2 + dxy[d][1]]);
                }
            }
            dominos[i] = 1;
        }
        else {
            for (int d = 0; d < 4; d++) {
                if (grid[x1 + dxy[d][0]][y1 + dxy[d][1]] > 0 && grid[x1 + dxy[d][0]][y1 + dxy[d][1]] != i) {
                    ed[i].push_back(grid[x1 + dxy[d][0]][y1 + dxy[d][1]]);
                }
                if (grid[x2 + dxy[d][0]][y2 + dxy[d][1]] > 0 && grid[x2 + dxy[d][0]][y2 + dxy[d][1]] != i) {
                    ed[grid[x2 + dxy[d][0]][y2 + dxy[d][1]]].push_back(i);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!left[i]) {
            for (int j = 1; j <= n; j++) vis[j] = 0;
            if (match(i)) r++;
        }
    }
    if (r < n) printf("impossible");
    else {
        for (int i = 1; i <= n; i++) {
            res[left[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (dominos[i]) printf("%d %d\n", res[i], i);
            else printf("%d %d\n", i, res[i]);
        }
    }
    return 0;
}