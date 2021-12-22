#include <stdio.h>
#include <string.h>

/*
문제 : 길이 50 이하의 두 A와 B로 이루어진 문자열 S와 T가 주어질 때, 다음 연산으로 S에서 T로 바꿀 수 있는지 구한다.
1. 문자열의 맨 뒤에 A를 추가한다.
2. 문자열의 맨 뒤에 B를 추가하고 문자열을 뒤집는다.

해결 방법 : S에서 T로의 이동을 모두 확인하기에는 S와 T의 길이가 긴 편이다.
하지만 T에서 S로의 이동을 역순으로 돌려보며 그때의 가능한 모든 경우를 따져보면 경우의 수가 줄어드므로 그렇게 하면 된다.

주요 알고리즘 : 백트래킹

출처 : SRM 663 D1A
*/

char s[1024], t[1024];
int ls, res = 0;

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void track(int st, int ed, int d) {
    if (ed - st == ls - 1) {
        int tmp = 1;
        if (d == 0) {
            for (int i = st; i <= ed; i++) {
                if (s[i - st] != t[i]) tmp = 0;
            }
        }
        else {
            for (int i = 0; i < ls; i++) {
                if (s[i] != t[ed - i]) tmp = 0;
            }
        }
        res |= tmp;
    }

    if (d) {
        if (t[st] == 'A') track(st + 1, ed, 1);
        if (t[ed] == 'B') track(st, ed - 1, 0);
    }
    else {
        if (t[ed] == 'A') track(st, ed - 1, 0);
        if (t[st] == 'B') track(st + 1, ed, 1);
    }
}

int main(void) {
    scanf("%s%s", s, t);
    ls = strlen(s);
    track(0, strlen(t) - 1, 0);
    printf("%d", res);
    return 0;
}