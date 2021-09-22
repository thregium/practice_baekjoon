#include <stdio.h>

/*
문제 : N명의 학생들과 M(N, M <= 100)개의 카드들이 있다. 각 학생들은 Ai(Ai <= 1000)의 값이 적힌 번호표가 있다.
이때, 1번부터 M번까지의 카드들을 차례로 이동시키며 인접한 카드의 값이 Aj % i > A(j + 1) % i인 경우의
j번째 학생과 j + 1번째 학생의 번호표를 교환한다. M개의 카드가 전부 이동하면 번호표를 교환한 결과를 구한다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JOI 2016예 2번
*/

int a[128];

int main(void) {
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j] % i > a[j + 1] % i) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}