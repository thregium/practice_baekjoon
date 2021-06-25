#include <stdio.h>

/*
문제 : 100 이하의 수 5개가 주어질 때, 이 수들 가운데 3개 이상의 수의 배수 중 가장 작은 수를 구한다.

해결 방법 : 최악의 경우에도 100^3 = 10^6 이하에는 답이 있을 수 밖에 없으므로 브루트 포스를 통해 1부터 직접 값을 찾으면 된다.

주요 알고리즘 : 브루트 포스, 사칙연산
*/

int a[5];

int main(void) {
    int cnt;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1;; i++) {
        cnt = 0;
        for (int j = 0; j < 5; j++) {
            if (i % a[j] == 0) cnt++;
        }
        if (cnt >= 3) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}