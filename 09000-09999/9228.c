#include <stdio.h>
#include <stdlib.h>

/*
문제 : 주어진 15자리 이하 수의 체크 숫자를 구한다. 맨 뒷자리부터 2, 3, 4, ...씩 자릿수와 곱한 값을 더한 값을 11로 나눈 값을
11에서 뺀 값이며 11인 경우 0으로 바꾼다. 10인 경우에는 불량으로 처리한다. 주어진 수는 0으로 시작할 수 있다.
#이 나오기 전까지 이를 반복한다.

해결 방법 : #을 받아야 하므로 문자열로 받은 다음 long long으로 바꾸어 준다. 이것을 다시 10으로 나누어가며
곱의 합을 구하고, 체크 숫자를 확인하는 것을 반복한다.

주요 알고리즘 : 수학, 문자열

출처 : NZPC 2002 C번
*/

char buff[32];

int main(void) {
    long long n, r;
    while (1) {
        scanf("%s", buff);
        if (buff[0] == '#') break;
        n = strtoll(buff, NULL, 10);
        r = 0;
        for (long long i = 2, m = n; m; i++, m /= 10) {
            r += i * (m % 10);
        }
        r %= 11;
        printf("%lld -> ", n);
        if (r == 1) printf("Rejected\n");
        else printf("%lld\n", r ? 11 - r : 0LL);
    }
    return 0;
}