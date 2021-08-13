#include <stdio.h>

/*
문제 : A * A 크기의 정사각형에서 주위 정사각형을 잘라 상자를 만들 때, 상자의 부피가 가장 큰 경우 자르는 정사각형의 한 변의 길이를 구한다.

해결 방법 : 이 길이는 A에 비례하게 된다. 예제에서 이 값이 A의 1 / 6이었으므로 답은 A / 6이 된다.

주요 알고리즘 : 수학, 기하학

출처 : AUCPC 2010S B번
*/

int main(void) {
    int n;
    double a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a);
        printf("%.10f", a / 6);
    }
    return 0;
}