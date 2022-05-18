#include <stdio.h>
#include <string.h>
#define MOD 900528

/*
문제 : 길이 100 이하의 문자열로 이루어진 문자 집합과 그 문자 집합의 문자들로 이루어진 길이 10^6 이하
문자열이 주어질 때, 길이 -> 사전 순서대로 해당 문자열이 해당 문자 집합의 몇 번째 문자열인 지 구한다.

해결 방법 : 각 문자마다 문자 집합의 길이 ^ 뒤에 있는 문자의 수 * 문자 집합에서 해당 문자의 번째수
가 그 문자의 번째수에 추가된다. 이를 계산해 나가면 된다.

주요 알고리즘 : 수학, 조합론

출처 : author7
*/

char ch[128], s[1048576];
int ord[256], dig[1048576];

int main(void) {
    int cl, sl, r = 0;
    scanf("%s%s", ch, s);
    cl = strlen(ch);
    sl = strlen(s);
    for (int i = 0; i < cl; i++) ord[ch[i]] = i + 1;
    dig[0] = 1;
    for (int i = 1; i < sl; i++) dig[i] = (dig[i - 1] * cl) % MOD;
    for (int i = sl - 1; i >= 0; i--) {
        r = (r + dig[sl - i - 1] * ord[s[i]]) % MOD;
    }
    printf("%d", r);
    return 0;
}