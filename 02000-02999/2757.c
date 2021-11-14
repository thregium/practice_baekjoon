#include <stdio.h>
#include <string.h>

/*
문제 : 엑셀의 행과 열이 수(<= 5 * 10^8)로 주어질 때, 이를 엑셀에서 쓰이는 좌표로 바꿔 출력한다.

해결 방법 : 행과 열을 입력받은 후, 열을 알파벳으로 바꾸고 행과 열을 출력하면 된다.

주요 알고리즘 : 수학

출처 : GNY 2004 B번
*/

char s[1024];

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int t, r, c;
    long long x;
    while (1) {
        scanf(" R%dC%d", &r, &c);
        c--;
        if (r == 0) break;
        x = 1;
        for (int i = 0; c >= 0; i++) {
            s[i] = (c / x) % 26 + 'A';
            x *= 26;
            c -= x;
            s[i + 1] = '\0';
        }
        for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
            swap(&s[i], &s[j]);
        }
        printf("%s%d\n", s, r);
    }
    return 0;
}