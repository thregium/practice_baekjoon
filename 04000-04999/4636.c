#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 9)명의 사람들(8자 이하, 소문자)에게 직육면체 모양의 점토를 나눠주었다.
현재 각 사람들이 갖고 있는 직육면체 점토의 크기가 주어지면, 다른 사람의 점토를 가져간 사람과
뺏긴 사람의 이름을 각각 출력한다. 가져간 쌍은 한 쌍 뿐이고, 부피는 250 이하의 자연수이다.

해결 방법 : 각 점토의 부피를 계산하면 가장 부피가 큰 점토를 가진 사람이 가장 작은 부피의 점토를
가진 사람의 점토를 가져갔음을 알 수 있다.

주요 알고리즘 : 구현, 사칙연산

출처 : MidC 2003 A번
*/

char bully[16], victim[16], s[16];

int main(void) {
    int n, hi, lo, a, b, c;
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        hi = -1, lo = 256;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %s", &a, &b, &c, s);
            if (a * b * c > hi) {
                hi = a * b * c;
                strcpy(bully, s);
            }
            if (a * b * c < lo) {
                lo = a * b * c;
                strcpy(victim, s);
            }
        }
        if (hi < 0) return 1;
        printf("%s took clay from %s.\n", bully, victim);
    }
    return 0;
}