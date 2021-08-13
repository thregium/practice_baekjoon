#include <stdio.h>

/*
문제 : 주어진 4자리 정수를 middle-square 법을 이용해 만들 수 있는 난수의 개수를 구한다. 주어진 수를 제곱한 다음
가운데 4자리의 값을 다음 난수로 활용하는 방식이다.

해결 방법 : 미리 지금까지 나온 난수들을 저장해 놓은 후, 난수들을 시뮬레이션 하면서 지금까지 나온 난수가 나온 경우
지금까지 나온 난수의 개수를 출력한다.

주요 알고리즘 : 수학, 시뮬레이션

출처 : ULM 2009 G번
*/

int traces[10240];

int main(void) {
    int n, x, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i < 10000; i++) traces[i] = -1;
        traces[0] = n;
        t = 0;
        for (int i = 1;; i++) {
            x = n * n / 100 % 10000;
            for (int j = 0; j < i; j++) {
                if (traces[j] == x) t = 1;
            }
            if (t) {
                printf("%d\n", i);
                break;
            }
            traces[i] = x;
            n = x;
        }
    }
    return 0;
}