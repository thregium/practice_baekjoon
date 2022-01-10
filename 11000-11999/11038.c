#include <stdio.h>

/*
문제 : 내림차순으로 정렬된 M(M <= 200)명의 시험 성적이 주어질 때, 합격자의 수를 구한다.
합격자의 수는 다음 규칙을 통해 정해진다. NM명 이상 NX명 이하(NM < NX < M)의 값 가운데
합격자와 불합격자의 점수 차이가 가장 큰 값, 그러한 값이 여럿이라면 그 중 가장 큰 값이 정해진다.

해결 방법 : 문제에 주어진 조건을 구현한다. 탐색 범위에 유의한다.

주요 알고리즘 : 구현

출처 : JDC 2015 A번
*/

int p[256];

int main(void) {
    int m, nm, nx, best = 0, bn = -1;
    while (1) {
        scanf("%d %d %d", &m, &nm, &nx);
        if (m == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d", &p[i]);
        }
        best = 0, bn = -1;
        for (int i = nm; i <= nx; i++) {
            if (p[i - 1] - p[i] >= best) {
                best = p[i - 1] - p[i];
                bn = i;
            }
        }
        printf("%d\n", bn);
    }
    return 0;
}