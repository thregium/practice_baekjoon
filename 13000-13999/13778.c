#include <stdio.h>
#include <string.h>
#define INF 1012345678

/*
문제 : N(N <= 120)명의 의원들의 번호와 이름이 각각 주어지고 한 행동에 대한 점수 변화가 A(A < 200)번 주어질 때,
가장 점수가 높은 의원과 낮은 의원의 이름들을 번호 순으로 전부 출력한다.

해결 방법 : 각 의원의 번호와 이름들을 대응시킨 후, 행동에 대해 각 번호의 의원들의 점수를 추적한다.
그 후, 가장 높은 점수와 가장 낮은 점수를 찾고, 번호 순으로 탐색하며 그와 같은 점수인 의원들의 이름들을 출력하면 된다.

주요 알고리즘 : 구현

출처 : NZPC 2016 H번
*/

char mp[128][32];
int score[128];

int main(void) {
    int n, x, lo = INF, hi = -INF;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &x);
        fgets(mp[x], 30, stdin);
        if (mp[x][strlen(mp[x]) - 1] == '\n') mp[x][strlen(mp[x]) - 1] = '\0';
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &x, &c);
        if (c == 'S') score[x] += 10;
        else if (c == 'A') score[x] += 7;
        else if (c == 'Q') score[x] += 5;
        else if (c == 'F') score[x] += 4;
        else if (c == 'D') score[x] -= 5;
        else if (c == 'L') score[x] -= 8;
        else if (c == 'E') score[x] -= 10;
    }
    for (int i = 1; i <= 120; i++) {
        if (mp[i][0] == '\0') continue;
        if (score[i] > hi) hi = score[i];
        if (score[i] < lo) lo = score[i];
    }
    printf("%d ", hi);
    for (int i = 1; i <= 120; i++) {
        if (mp[i][0] == '\0') continue;
        if (score[i] < hi) continue;
        printf("%s ", mp[i]);
    }
    printf("\n%d ", lo);
    for (int i = 1; i <= 120; i++) {
        if (mp[i][0] == '\0') continue;
        if (score[i] > lo) continue;
        printf("%s ", mp[i]);
    }
    return 0;
}