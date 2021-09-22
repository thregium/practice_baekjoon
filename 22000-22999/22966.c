#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 4)개의 문제들의 제목과 난이도가 주어지면(난이도 <= 4), 가장 쉬운 것의 제목을 구한다.
제목의 길이는 10 이하이고, 같은 난이도의 문제는 주어지지 않는다.

해결 방법 : 가장 쉬운 것의 난이도와 이름을 저장해 놓고 더 쉬운 것이 나올 때 마다 가장 쉬운 것을 업데이트한다.
마지막의 가장 쉬운 것의 이름이 답이 된다.

주요 알고리즘 : 구현

출처 : 선린 5회 D번
*/

char s[16], bestname[16];

int main(void) {
    int n, d, b = 103000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", s, &d);
        if (d < b) {
            strcpy(bestname, s);
            b = d;
        }
    }
    printf("%s", bestname);
    return 0;
}