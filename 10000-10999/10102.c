#include <stdio.h>

/*
문제 : 길이 V(V <= 15)의 A와 B로 이루어진 문자열에서 A와 B 중 무엇이 더 많은지 구한다.

해결 방법 : 각 문자들을 센다.

주요 알고리즘 : 문자열

출처 : CCC 2014J 2번
*/

char vote[32];

int main(void) {
    int v, a = 0, b = 0;
    scanf("%d%s", &v, vote);
    for (int i = 0; i < v; i++) {
        if (vote[i] == 'A') a++;
        else b++;
    }
    printf("%s", a > b ? "A" : a == b ? "TIE" : "B");
    return 0;
}