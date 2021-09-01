#include <stdio.h>

/*
문제 : 등차수열 또는 등비수열인 세 수가 주어질 때, 세 수가 등차수열인지 등비수열인지 구하고 다음 항을 구한다.
단, 등차 또는 등비는 0이 아닌 정수이고, 세 수가 모두 같은 경우는 주어지지 않는다.

해결 방법 : 인접한 두 수의 차이가 서로 같다면 이 수열은 등차수열이고, 다르다면 등비수열이다.
다음 항은 마지막 항에 수열의 종류에 따라 공차를 더하거나 공비를 곱한 값이다.

주요 알고리즘 : 수학

출처 : Arab 2010 A번
*/

int main(void) {
    int a, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        if (c - b == b - a) printf("AP %d\n", c + (b - a));
        else printf("GP %d\n", c * (b / a));
    }
    return 0;
}