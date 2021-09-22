#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)의 2와 e로 이루어진 문자열이 주어질 때, 2와 e의 개수를 비교한다.

해결 방법 : 모든 문자들을 살펴보며 2와 e의 개수를 세면 된다.

주요 알고리즘 : 구현
*/

char s[103000];

int main(void) {
    int n, t = 0, e = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') t++;
        else e++;
    }
    if (t == e) printf("yee");
    else if (t > e) printf("2");
    else printf("e");
    return 0;
}