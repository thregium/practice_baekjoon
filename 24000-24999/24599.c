#include <stdio.h>

/*
문제 : N(N <= 100)명의 사람들이 OX퀴즈에 낸 답안이 주어진다. 문제 개수는 K(K <= 100)개이다.
답안은 O, X, 내지 않음 셋 중 하나이다. 이때, 정답을 O, X로 각각 정해서
모든 사람이 답을 최대 1개 이하로만 맞추도록 하는 방법이 있는 지 확인하고, 있다면 그러한 방법 중
사전순으로 가장 빠른 것을 구한다.

해결 방법 : 우선, 정답 가운데 하나를 맞추도록 했다면 나머지는 모두 틀리게 해야 한다.
이를 정점과 간선 관계로 바꾸면 2-SAT이 된다. 이제 플로이드-워셜 알고리즘을 통해
각 정점에 대해 이동 가능한 모든 정점을 구해준다.

이 과정이 끝난 다음에는 맨 앞에서부터 F, T 순서대로 가능한 지 확인해보면서 현재까지의 조건에 모순이 없고
그 조건을 추가해도 모순이 생기지 않는 경우 그것을 선택해 나가면 된다.
이 과정에서 둘 다 선택할 수 없는 경우가 생기면 실패한 것이다.

주요 알고리즘 : 그래프 이론, 플로이드, 2-SAT, 그리디 알고리즘

출처 : PacNW 2021 J/W번 // SCUSA 2021D1 E번 // MidC 2021 F번 // NENA 2021 I번
*/

char stu[128][128], res[128];
int reach[256][256];

int main(void) {
    int n, k, r = 1, av;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", stu[i]);
        for (int j = 0; j < k; j++) {
            if (stu[i][j] == 'X') continue;
            for (int jj = 0; jj < k; jj++) {
                if (jj == j || stu[i][jj] == 'X') continue;
                reach[j * 2 + (stu[i][j] == 'T')][jj * 2 + (stu[i][jj] == 'F')] = 1;
            }
        }
    }
    for (int p = 0; p < k * 2; p++) {
        for (int i = 0; i < k * 2; i++) {
            for (int j = 0; j < k * 2; j++) {
                reach[i][j] |= (reach[i][p] & reach[p][j]);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        av = 0;
        if (res[i]) continue;
        if (!reach[i * 2][i * 2 + 1]) {
            av = 1;
            for (int j = 0; j < k; j++) {
                if (j == i) continue;
                if (reach[i * 2][j * 2] && reach[i * 2][j * 2 + 1]) av = 0;
                if (reach[i * 2][j * 2] && res[j] == 'T') av = 0;
                if (reach[i * 2][j * 2 + 1] && res[j] == 'F') av = 0;
            }
            if (av) {
                res[i] = 'F';
                for (int j = 0; j < k * 2; j++) {
                    if (j == i * 2) continue;
                    if (reach[i * 2][j]) res[j >> 1] = ((j & 1) ? 'T' : 'F');
                }
            }
        }
        if (!av && !reach[i * 2 + 1][i * 2]) {
            av = 1;
            for (int j = 0; j < k; j++) {
                if (j == i) continue;
                if (reach[i * 2 + 1][j * 2] && reach[i * 2 + 1][j * 2 + 1]) av = 0;
                if (reach[i * 2 + 1][j * 2] && res[j] == 'T') av = 0;
                if (reach[i * 2 + 1][j * 2 + 1] && res[j] == 'F') av = 0;
            }
            if (av) {
                res[i] = 'T';
                for (int j = 0; j < k * 2; j++) {
                    if (j == i * 2 + 1) continue;
                    if (reach[i * 2 + 1][j]) res[j >> 1] = ((j & 1) ? 'T' : 'F');
                }
            }
        }
        if (!av) r = 0;
    }
    if (!r) printf("-1");
    else printf("%s\n", res);
    return 0;
}