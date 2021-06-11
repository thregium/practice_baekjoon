#include <stdio.h>

/*
문제 : 조건에 맞게 경보를 구현한다.(조건 생략)

해결 방법 : 조건대로 구현한다.

주요 알고리즘 : 구현

출처 : ROI Team 2020 F번
*/

int main(void) {
    int t1, v1, t2, v2;
    scanf("%d %d%d %d", &t1, &v1, &t2, &v2);
    if (t2 < 0 && v2 >= 10) printf("A storm warning for tomorrow! Be careful and stay home if possible!");
    else if (t2 < t1) printf("MCHS warns! Low temperature is expected tomorrow.");
    else if (v2 < v1) printf("MCHS warns! Strong wind is expected tomorrow.");
    else printf("No message");
    return 0;
}