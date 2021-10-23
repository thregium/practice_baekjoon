#include <stdio.h>
#include <string.h>

/*
문제 : 2자리 이상 9자리 이하의 숫자로 이루어진 문자열이 주어질 때,
해당 문자열(로 만든 수)에 최소 얼마를 더해야 문자열이 팰린드롬이 되는지 구한다. 문자열 전체가 팰린드롬이 되어야 한다.

해결 방법 : 모든 자리 문자열의 가장 큰 수(999...9)는 항상 팰린드롬이므로 자릿수가 넘어갈 염려는 없다.
또한, 9자리의 수더라도 많아야 100000 단위 내로는 팰린드롬인 문자열을 만들 수 있으므로 1씩 수를 더해가며
팰린드롬 여부를 확인해나가면 된다. 각 자릿수가 9일 때는 해당 자릿수를 0으로 바꾸고 앞 자리를 올려야 한다.

주요 알고리즘 : 브루트 포스, 문자열

출처 : MidAtl 2010 A번 // SEUSA 2010 F번
*/

char s[16];

int ispal(char* s, int n) {
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

int main(void) {
    int l, r, p;
    while (1) {
        scanf("%s", s);
        l = strlen(s);
        if (l == 1) break;
        r = 0;
        while (!ispal(s, l)) {
            p = l - 1;
            while (p >= 0 && s[p] == '9') {
                s[p] = '0';
                p--;
            }
            if (p >= 0) s[p]++;
            r++;
        }
        printf("%d\n", r);
    }
    return 0;
}