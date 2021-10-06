#include <stdio.h>

/*
문제 : 초등학생 N(N <= 1000)명의 1학년부터 5학년까지 반이 주어진다. 이때, 가장 같은 반이었던 사람이 많은 학생을 구한다.
그러한 학생이 여럿이라면 가장 앞에 있는 학생을 출력한다.

해결 방법 : 각 학생들의 반을 입력받은 후, 각각에 대해 같은 반이었던 학생들을 기록해 둔다.
그 다음, 기록한 정보를 바탕으로 같은 반이었던 학생 수를 구한 다음, 그 값이 가장 많은 학생을 구하면 된다.

주요 알고리즘 : 구현

출처 : 정올 2006 초1번
*/

int cla[1024][5], chk[1024][1024], fri[1024];

int main(void) {
    int n, best = 0, res = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &cla[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < n; k++) {
                if (cla[i][j] == cla[k][j]) chk[i][k] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            fri[i] += chk[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (fri[i] > best) {
            res = i + 1;
            best = fri[i];
        }
    }
    if (res < 0) return 1;
    printf("%d", res);
    return 0;
}