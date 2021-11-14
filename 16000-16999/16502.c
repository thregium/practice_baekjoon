#include <stdio.h>

/*
문제 : 4개의 정점 가운데 1곳에 무작위한 곳에서 시작한다. 매 분마다 각 정점에서 이동하는 정점과 그 확률이 주어지면
T(T <= 10)분 후 각 위치에 있을 확률을 구한다.

해결 방법 : 각 확률을 입력받은 다음, 25%, 25%, 25%, 25%에서 시작하여 매번 다음 시간의 확률을 계산해 나간다.
T번째까지 계산한 후 그때의 확률을 구하면 된다.

주요 알고리즘 : 수학, 확률론, 시뮬레이션

출처 : 한양대E 2018B G번
*/

double mat[4][4], prob[16][4];

int main(void) {
    int t, m;
    char ca, cb;
    double dt;
    scanf("%d%d", &t, &m);
    for (int i = 0; i < m; i++) {
        scanf(" %c %c %lf", &ca, &cb, &dt);
        mat[ca - 'A'][cb - 'A'] = dt;
    }
    prob[0][0] = 0.25, prob[0][1] = 0.25, prob[0][2] = 0.25, prob[0][3] = 0.25;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                prob[i + 1][k] += prob[i][j] * mat[j][k];
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        printf("%f\n", prob[t][i] * 100.0);
    }
    return 0;
}