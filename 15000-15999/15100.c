#include <stdio.h>
#include <string.h>

/*
문제 : 100000자 이하의 소문자로 이루어진 같지 않은 두 문자열 A, B가 주어진다.
이때, A의 연속한 일부분을 뒤집어 B를 만드는 방법의 가짓수를 구한다.

해결 방법 : 우선 A의 일부분을 뒤집어 B를 만들기 위해서는 A와 B의 서로 다른 부분의 범위를 뒤집어 본다.
그 범위를 뒤집어서 서로 같아진다면 B를 만드는 방법이 있는 것이고, 다르다면 만드는 방법이 없는 것이다.
방법이 있다면 양 옆으로 문자들이 대칭을 이루는 가장 긴 길이까지의 가짓수를 세 나간다.
그 모든 가짓수를 세면 답이 된다.

주요 알고리즘 : 문자열, 애드 혹?

출처 : MidC 2017 F번
*/

char a[103000], b[103000];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int l, s = 103000, e = -1, r = 1;
    scanf("%s%s", a, b);
    l = strlen(a);
    for (int i = 0; i < l; i++) {
        if (a[i] != b[i]) {
            if (i < s) s = i;
            if (i > e) e = i;
        }
    }
    for (int i = s, j = e; i < j; i++, j--) swap(&a[i], &a[j]);
    if (strcmp(a, b)) {
        printf("0");
        return 0;
    }
    for (int i = s - 1, j = e + 1; i >= 0 && j < l; i--, j++) {
        if (a[i] != a[j]) break;
        r++;
    }
    printf("%d", r);
    return 0;
}