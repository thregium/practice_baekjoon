#include <stdio.h>

/*
문제 : 자연수 A, B(A, B <= 50)가 주어질 때, A + B가 아닌 자연수 C(C <= 50)를 출력한다. 이를 T(T <= 1000)회 반복한다.

해결 방법 : 50 이하의 특정한 자연수를 정하고 그 수가 A + B인 경우 다른 특정한 수를 출력한다.
그 외의 경우에는 원래의 특정한 수를 출력한다.

주요 알고리즘 : 수학, 구성적

출처 : Petro 18/19_18 H번
*/

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        if (a + b == 39) printf("41\n");
        else printf("39\n");
    }
    return 0;
}