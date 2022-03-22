#include <stdio.h>

/*
문제 : 주어진 80자 이하의 소문자로 이루어진 문자열을 N(N <= 26)번동안 O(O < 26)자씩 돌리면서
나오는 문자열 가운데 모음이 자음의 절반 미만인 문자열이 그렇지 않은 문자열보다 많은 지 구한다.

해결 방법 : 두 종류의 문자열 개수를 확인하면서 문자열을 돌려 나간다. 돌릴 때는 나머지 연산을 이용해
간단히 문자를 바꿀 수 있고, 자모음 개수도 간단히 셀 수 있다. 모음의 2배가 자음 이상인 경우와
아닌 경우로 나누고 최종적으로 두 경우의 개수를 비교하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 문자열

출처 : VTH 2018 K번
*/

char s[128];

int main(void) {
    int o, n, v, c, good = 0, bad = 0;
    scanf("%d", &o);
    scanf("%s%d", s, &n);
    for (int i = 0; i < n; i++) {
        v = 0, c = 0;
        for (int j = 0; s[j]; j++) {
            s[j] = (s[j] - 'a' + o) % 26 + 'a';
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||
                s[j] == 'o' || s[j] == 'u' || s[j] == 'y') v++;
            else c++;
        }
        if (v * 2 >= c) bad++;
        else good++;
    }
    printf("%s", good > bad ? "Boris" : "Colleague");
    return 0;
}
