#include <stdio.h>

/*
문제 : A와 B가 특정한 수들(<= 6, 자연수)이 쓰인 주사위를 던진다. 서로 같은 수가 쓰여 있다면
주사위를 다시 던진다. 더 큰 수가 쓰인 사람이 이길 때, A가 이길 확률을 구한다.

해결 방법 : 두 주사위를 배열로 입력받고 두 주사위의 모든 경우에 대해 승부가 나는 횟수와 A가 이기는 횟수를
각각 센다. 그 후 A가 이기는 횟수를 전체 승부가 나는 횟수로 나누면 답이 된다.

주요 알고리즘 : 수학, 확률론, 브루트 포스

출처 : PacNW 2016 W번
*/

int a[6], b[6];

int main(void) {
    int tot = 0, hi = 0;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (a[i] != b[j]) tot++;
            if (a[i] > b[j]) hi++;
        }
    }
    if (tot == 0) return 1;
    printf("%.5f", (double)hi / tot);
    return 0;
}