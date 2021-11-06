#include <stdio.h>

/*
문제 : W(W <= 600)개의 단어(25자 이하, 소문자)가 주어지고, 길이 L(L <= 300)의 문자열(소문자)이 주어진다.
이때, 문자열의 일부 글자를 지워 단어로 문자열을 만들 수 있도록 하기 위해서 지워야 하는 문자열의 최소 개수를 구한다.

해결 방법 : dp(x)를 x번째 문자까지만 있다 할 때 지워야 할 문자의 최소 개수로 정의하면 답은 dp(l)이 된다.
단어가 없다고 가정하면 dp(x) = x일 것이다. 이제 첫 번째 문자부터 해당 문자 이후에서 글자를 지워서
문자열에서 해당 단어를 찾을 수 있는 첫 번째 위치를 찾는다. 이는 그리디하게 가면 쉽게 찾을 수 있다.
그 위치 이후로 나오는 값은 단어의 길이를 p, 문자열에서 찾는 문자의 위치를 i, 이후의 어떤 위치를 j라고 했을 때
dp(j) = dp(j) 또는 dp(i) + (j - i) - p 중 작은 값이 된다. 이를 문자마다 모든 단어에 대해 적용하면
문자열에서 해당 단어가 들어간 부분의 문자를 지우지 않도록 하여 지우는 문자의 최소 개수(dp(l))를 구할 수 있다.

주요 알고리즘 : DP, 문자열

출처 : USACO 2007F S1번
*/

char s[384], word[768][32];
int mem[384];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int w, l, p, r;
    scanf("%d %d", &w, &l);
    scanf("%s", s);
    for (int i = 0; i < w; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 0; i <= l; i++) mem[i] = i;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            p = 0;
            for (int k = i; k < l; k++) {
                if (s[k] == word[j][p]) p++;
                if (word[j][p] == '\0') mem[k + 1] = small(mem[k + 1], mem[i] + k + 1 - i - p);
            }
        }
    }
    printf("%d", mem[l]);
    return 0;
}