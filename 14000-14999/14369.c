#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 S(S <= 20)의 대문자로 이루어진 문자열이 주어진다. 이 문자열은 오름차순으로 된 숫자들을 하나씩 문자로 쓴 것을
이어붙인 후 순서를 섞어 만들어졌다고 했을 때, 원래 숫자들로 이루어진 문자열을 출력한다.

해결 방법 : 숫자별로 각 알파벳이 등장하는 횟수를 살펴보면 0일 때의 Z, 2일 때의 W, 6일 때의 X, 8일 때의 G가 유일함을 알 수 있다.
이러한 숫자들을 제외하고 나면 3일 때의 H가 유일해지고, 비슷한 방식으로 나머지 수들도 유일한 알파벳들이 존재하게 된다.
이를 순서대로 문자열에 적은 다음, 주어지는 문자열마다 각 문자열의 개수를 센다.
그러면 적은 순서대로 유일한 문자의 개수를 통해 해당 숫자의 개수를 찾을 수 있다. 찾은 다음에는 이를 결과 문자열에 추가하고,
해당 숫자에 있는 알파벳들을 개수만큼 곱해서 지운다. 이를 각 숫자에 대해 반복한 다음 결과 문자열을 오름차순으로 정렬하면
원래 찾고자 하는 문자열을 얻을 수 있다.

주요 알고리즘 : 문자열, 애드 혹

출처 : GCJ 2016_1B A2번
*/

char* numorder = "0268345179";
char* alphorder = "ZWXGHRFOVE";
char* numalph[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
char s[2048], r[2048];
int cnt[26];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, p, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            cnt[s[i] - 'A']++;
        }
        p = 0;
        for (int i = 0; i < 10; i++) {
            c = cnt[alphorder[i] - 'A'];
            if (c < 0) return 1;
            for (int j = 0; j < c; j++) {
                r[p++] = numorder[i];
            }
            for (int j = 0; numalph[numorder[i] - '0'][j]; j++) {
                cnt[numalph[numorder[i] - '0'][j] - 'A'] -= c;
            }
        }
        r[p] = '\0';
        qsort(r, p, sizeof(char), cmp1);
        printf("Case #%d: %s\n", tt, r);
    }
    return 0;
}