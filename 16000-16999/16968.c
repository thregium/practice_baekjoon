#include <stdio.h>

/*
문제 : 4자리 이하의 문자판에 숫자 또는 대문자 알파벳을 넣을 수 있다. 또한, 인접한 문자는 서로 달라야 한다.
각 문자판에 적어야 하는 문자의 종류(숫자, 알파벳)가 주어질 때, 문자판으로 만들 수 있는 문자열의 개수를 구한다.

해결 방법 : 각 문자판에 넣을 수 있는 문자들을 넣어보며 만들 수 있는지 확인해 나간다.
넣을 수 없는 문자가 나오면 다음 문자를 넣어보고, 마지막 글자에서 결괏값을 올려가는 방식이다.

주요 알고리즘 : 브루트 포스
*/

char s[8];
int a[4];

int check(int a, char c) {
    //해당 글자가 들어갈 수 있는지 확인한다.
    if (a >= 0 && a < 10 && c == 'd') return 1;
    if (a >= 10 && a < 36 && c == 'c') return 1;
    return 0;
}

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i1 = 0; i1 < 36; i1++) {
        if (!check(i1, s[0])) continue;
        a[0] = i1;
        if (!s[1]) {
            r++;
            continue;
        }
        for (int i2 = 0; i2 < 36; i2++) {
            if (!check(i2, s[1]) || i2 == a[0]) continue;
            a[1] = i2;
            if (!s[2]) {
                r++;
                continue;
            }
            for (int i3 = 0; i3 < 36; i3++) {
                if (!check(i3, s[2]) || i3 == a[1]) continue;
                a[2] = i3;
                if (!s[3]) {
                    r++;
                    continue;
                }
                for (int i4 = 0; i4 < 36; i4++) {
                    if (!check(i4, s[3]) || i4 == a[2]) continue;
                    a[3] = i4;
                    if (s[4]) return 1;
                    r++;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}