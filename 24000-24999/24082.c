#include <stdio.h>

/*
문제 : 한 변의 길이가 x인 정육면체의 부피는 x * x * x이다. 자연수 X(X <= 1000)가 주어질 때
한 변의 길이가 x인 정육면체의 부피를 구한다.

해결 방법 : x를 입력받고 x * x * x를 출력한다.

주요 알고리즘 : 수학, 사칙연산

출처 : JOI 2022예1 2-1번
*/

int main(void) {
    int x;
    scanf("%d", &x);
    printf("%d", x * x * x);
    return 0;
}