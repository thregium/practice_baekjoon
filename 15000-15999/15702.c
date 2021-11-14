#include <stdio.h>

/*
문제 : N(N <= 100)개의 문제의 배점과 M(M <= 100)명의 채점 결과, 수험 번호가 주어질 때, 가장 점수가 높은 학생의
수험 번호와 받은 점수를 구한다. 단, 이러한 학생이 여럿인 경우 수험 번호가 가장 낮은 학생을 출력한다.

해결 방법 : 각 학생의 점수를 구한 다음 최댓값보다 높다면 최댓값과 학생을 갱신한다. 같은 경우에는
수험번호를 비교해서 수험번호가 더 작다면 학생만 갱신한다.
모든 학생을 확인했다면 최댓값과 수험 번호를 출력하면 된다.

주요 알고리즘 : 구현
*/

int prob[128], score[128], num[128];

int main(void) {
    int n, m, best = -1, bn = -1;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &prob[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &num[i]);
        for (int j = 0; j < n; j++) {
            scanf(" %c", &c);
            if (c == 'O') score[i] += prob[j];
        }
        if (score[i] > best) {
            best = score[i];
            bn = num[i];
        }
        else if (score[i] == best) {
            if (num[i] < bn) bn = num[i];
        }
    }
    if (bn < 0) return 1;
    printf("%d %d", bn, best);
    return 0;
}