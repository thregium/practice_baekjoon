#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 두 음이 아닌 정수 A, B(A, B <= 10^20)가 주어질 때, R(0 <= R < 2^63)보다 큰 값이라면 "overflow"를,
그 이하라면 A * B의 결과를 출력한다.

해결 방법 : 먼저, A와 B를 문자열로 입력받는다. 만약 다른 한 쪽이 0이 아닌데 한쪽이 20자리 이상(> 2^63)이라면
곱은 당연히 2^63보다 클 것이므로 overflow를 출력하면 된다. 20자리 미만이라면 10^19 - 1이 2^64보다는 작으므로
unsigned long long을 사용하면 저장 가능하다. 두 수를 strtoull함수를 사용해 unsigned long long으로 변환한 후,
두 수가 0인지 확인한다. 하나라도 0이면 답은 0이다. 그렇지 않다면 r / bl의 몫을 al과 비교해서
그 값이 더 작다면 overflow를 출력하고, 그 외에는 r 이하의 값이므로 직접 곱해보면 된다.

주요 알고리즘 : 수학, 케이스 워크

출처 : 네블컵 1회 A번
*/

char a[32], b[32];

int main(void) {
    unsigned long long al, bl, r;
    scanf("%s %s %llu", a, b, &r);
    if ((strlen(a) > 19 || strlen(b) > 19) && !(a[0] == '0' && a[1] == '\0') && !(b[0] == '0' && b[1] == '\0')) {
        printf("overflow");
        return 0;
    }
    al = strtoull(a, NULL, 10);
    bl = strtoull(b, NULL, 10);
    if (al != 0 && bl != 0 && r / bl < al) printf("overflow");
    else printf("%lld", al * bl);
    return 0;
}