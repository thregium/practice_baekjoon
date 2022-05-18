#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 100자 이하의 정수가 N(N <= 10^6)개 주어질 때, 정수들 가운데 주어지지 않은 가장 작은
음이 아닌 정수를 구한다.

해결 방법 : 비둘기집 원리에 의해 답은 N 이하가 된다. 따라서, N 이하의 음이 아닌 정수들만
확인하면 되는데, 이 과정에서 정수형으로 처리하면 오버플로가 날 수 있으므로 우선 길이가 일정(이 코드에선 8)
이하인 문자열만 정수형으로 바꾼다. 그 후 범위 안에 수가 있다면 그 수를 체크한다.

그 후 0부터 차례로 수들을 확인하면 N 이하에서는 반드시 체크되지 않은 수가 나오게 된다.
그 수를 출력한다.

주요 알고리즘 : 수학, 비둘기집 원리, 문자열

출처 : SWERC 2019 C번
*/

char s[256], chk[1048576];

int main(void) {
    int n;
    long long x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        if (strlen(s) > 7) continue;
        x = strtoll(s, NULL, 10);
        if (x < 0 || x >= 1048576) continue;
        else chk[x] = 1;
    }
    for (int i = 0;; i++) {
        if (!chk[i]) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}