#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 1000)개의 점이 있다. Ml(Ml <= 10000)개의 점 쌍은 각각 거리 D_i(D_i <= 10^6) 내에 있어야 하고,
Md(Md <= 10000)개의 점 쌍은 각각 거리 D_j(D_j <= 10^6) 내에 있어야 한다고 할 때,
모든 점을 번호 순으로 차례로 직선상에 놓는 방법이 있는지 구하고, 있다면 그 중 1번과 N번 점이 가장 먼 것의 거리를 구한다.
방법이 없다면 -1을 출력하고, 무한히 멀리 놓을 수 있다면 -2를 출력한다.

해결 방법 : 모든 점들이 있을 수 있는 좌표의 범위를 먼저 지정한다. 1번 점은 0 - 0, 나머지 점들은 0 - 무한대이다.
그 뒤로는 각각의 작은 번호의 점 쌍부터 확인하며 좌표의 범위를 지정해 나간다. 만약 가까워야 하는 점이라면
앞쪽 점의 최솟값과 뒤쪽 점의 최댓값을 갱신할 수 있고, 멀어야 하는 점이라면 앞쪽 점의 최댓값과 뒤쪽 점의 최솟값을
갱신할 수 있다. 그 다음, 그로 인해 앞뒤로 영향을 받는 다른 값들도 갱신해준다.

이를 시행하되, 한 번 만으로는 간접적으로 영향을 받는 경우를 알아낼 수 없기 때문에 N번동안 이를 반복한다.
단, N번 넘도록 갱신이 계속된다면 무한정 갱신이 계속되기 때문에 방법이 없는 것으로 -1을 출력해야 한다.
반복한 다음 N번 점의 최댓값을 출력하되 무한대인 경우는 -2를 출력하도록 한다.

주요 알고리즘 : 그래프 이론, 벨만-포드

출처 : USACO 2005D G3번
*/

int love[1024][1024], hate[1024][1024], range[1024][2];

int main(void) {
    int n, ml, md, a, b, d, r = 1, t = 0;
    //freopen("E:\\PS\\Olympiad\\USA\\3_Gold\\2005_12\\USACO 2005 December\\alldec05\\layout.10.in", "r", stdin);
    scanf("%d %d %d", &n, &ml, &md);
    for (int i = 0; i < ml; i++) {
        scanf("%d %d %d", &a, &b, &d);
        love[a][b] = d;
    }
    for (int i = 0; i < md; i++) {
        scanf("%d %d %d", &a, &b, &d);
        hate[a][b] = d;
    }
    for (int i = 2; i <= n; i++) range[i][1] = INF;
    while (r > 0 && t <= 1000) {
        //N + 1번 반복
        r = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (love[i][j]) {
                    //가까워야 하는 점의 경우
                    if (range[j][1] > range[i][1] + love[i][j]) {
                        //뒤쪽 최댓값 갱신
                        range[j][1] = range[i][1] + love[i][j];
                        for (int k = j - 1; k >= 1; k--) {
                            if (range[k][1] > range[j][1]) range[k][1] = range[j][1];
                        }
                        r = 1;
                    }
                    if (range[i][0] < range[j][0] - love[i][j]) {
                        //앞쪽 최솟값 갱신
                        range[i][0] = range[j][0] - love[i][j];
                        for (int k = i + 1; k <= n; k++) {
                            if (range[k][0] < range[i][0]) range[k][0] = range[i][0];
                        }
                        r = 1;
                    }
                }
                if (hate[i][j]) {
                    //멀어야 하는 경우
                    if (range[j][0] < range[i][0] + hate[i][j]) {
                        //뒤쪽 최솟값 갱신
                        range[j][0] = range[i][0] + hate[i][j];
                        for (int k = j + 1; k <= n; k++) {
                            if (range[k][0] < range[j][0]) range[k][0] = range[j][0];
                        }
                        r = 1;
                    }
                    if (range[i][1] > range[j][1] - hate[i][j]) {
                        //앞쪽 최댓값 갱신
                        range[i][1] = range[j][1] - hate[i][j];
                        for (int k = i - 1; k >= 1; k--) {
                            if (range[k][1] > range[i][1]) range[k][1] = range[i][1];
                        }
                        r = 1;
                    }

                }
            }
        }
        t++;
    }
    if (t > n) printf("-1");
    else if (range[n][1] >= INF) printf("-2");
    else printf("%d", range[n][1]);
    return 0;
}