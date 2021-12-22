#include <stdio.h>
#include <string.h>

/*
문제 : 길이 1000 이하의 두 문자열 S, T가 주어질 때, S에서 T를 다음 두 연산을 이용하여 만들 수 있는지 구한다.
1. 원래 문자열의 뒤에 A를 추가한다.
2. 원래 문자열을 뒤집고 뒤에 B를 추가한다.

해결 방법 : T에서 역순으로 생각하면 모든 문자열은 빈 문자열에서 만들 수 있음을 알 수 있고,
그러한 방법은 유일함을 알 수 있다. 따라서, 역순으로 끝의 문자를 제거하며 B가 나올 때 마다 문자열을 뒤집는 과정을 반복하고,
길이가 S와 같아지면 S와 비교하면 된다.

주요 알고리즘 : 그리디 알고리즘?

출처 : SRM 663 D2B
*/

char s[1024], t[1024];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    scanf("%s%s", s, t);
    while (strlen(s) != strlen(t)) {
        if (t[strlen(t) - 1] == 'A') {
            t[strlen(t) - 1] = '\0';
        }
        else if (t[strlen(t) - 1] == 'B') {
            t[strlen(t) - 1] = '\0';
            for (int i = 0, j = strlen(t) - 1; i < j; i++, j--) swap(&t[i], &t[j]);
        }
        else return 1;
    }
    printf("%d", !strcmp(s, t));
    return 0;
}