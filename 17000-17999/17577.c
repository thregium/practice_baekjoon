#include <stdio.h>

/*
문제 : N(N <= 1000)명의 학생들의 M(M <= 50)개 과목에 대한 성적이 주어질 때, 점수의 합이 가장 큰 사람의 점수를 구한다.

해결 방법 : 각 학생들의 점수 합을 계산한 다음, 가장 큰 값을 찾으면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : JDC 2019 A번
*/

int score[1024];

int main(void) {
    int n, m, x, best;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &x);
                score[j] += x;
            }
        }
        best = -1;
        for (int i = 0; i < n; i++) {
            if (score[i] > best) best = score[i];
            score[i] = 0;
        }
        printf("%d\n", best);
    }
    return 0;
}