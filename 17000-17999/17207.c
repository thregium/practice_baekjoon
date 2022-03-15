#include <stdio.h>
#define INF 1012345678

/*
문제 : 5명의 5가지 일에 대한 난이도와 소요 시간이 주어질 때, 각 사람의 일의 양 합을
문제에 주어진 방식대로 구한 후 그 값이 가장 작은 사람을 구한다. 주어지는 모든 수는 100 이하의 자연수이다.

해결 방법 : 문제에 주어진 방식대로 구하면 행렬곱이 된다. 행렬곱을 구한 후 각 행별로 합을 찾으면
그것이 그 사람의 일의 양 합이 된다. 이 값의 최솟값인 사람을 그 후 찾으면 된다.

주요 알고리즘 : 수학, 선형대수학, 구현

출처 : 중앙대 2019N G번
*/

char* name[] = { "Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };
int a[5][5], b[5][5], c[5][5], w[5];

int main(void) {
    int r = INF, rn = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            w[i] += c[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        if (w[i] <= r) {
            r = w[i];
            rn = i;
        }
    }
    if (rn < 0) return 1;
    printf("%s", name[rn]);
    return 0;
}