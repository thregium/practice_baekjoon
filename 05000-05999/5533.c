#include <stdio.h>

/*
문제 : N(N <= 200)명의 사람들이 100 이하의 자연수를 적어 낸다. 이 사람들 중 같은 자연수를 적은 사람이 없다면
적은 자연수와 같은 점수를 얻는다. 이를 3번 하며 적은 자연수들이 주어질 때, 각 사람들의 점수를 구한다.

해결 방법 : 각 사람들이 적은 수들을 입력받은 다음, 각 게임에서 참가자마다 자신과 같은 자연수를 적은 사람이 있는지를 확인한다.
그러한 경우가 없다면 그 사람의 점수에 그 참가자가 적은 수를 추가한다. 이를 3번 반복한 다음,
각 참가자의 점수를 출력하면 된다.

주요 알고리즘 : 브루트 포스, 구현

출처 : JOI 2013예 2번
*/

int num[3][256], score[256];

int main(void) {
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &num[0][i], &num[1][i], &num[2][i]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            t = 1;
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                if (num[i][j] == num[i][k]) {
                    t = 0;
                    break;
                }
            }
            score[j] += t * num[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", score[i]);
    }
    return 0;
}