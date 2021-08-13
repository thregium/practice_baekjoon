#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 N(N < 25)개의 문자열을 앞뒤로 섞은 순서로 재배치한다.

해결 방법 : 문자열을 입력받으며 홀수번째엔 앞쪽에, 짝수번째엔 뒤쪽에 배치한 다음
배치한 순서대로 출력한다.

주요 알고리즘 : 구현, 문자열

출처 : MidC 2004 C번
*/

char strs[32], stre[32][32];

int main(void) {
    int n;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", strs);
            if (i & 1) strcpy(stre[n - (i >> 1) - 1], strs);
            else strcpy(stre[i >> 1], strs);
        }
        printf("SET %d\n", tt);
        for (int i = 0; i < n; i++) {
            printf("%s\n", stre[i]);
        }
    }
    return 0;
}