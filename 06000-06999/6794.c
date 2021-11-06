#include <stdio.h>

/*
문제 : N(N <= 10)이 주어질 때, 한 손 또는 두 손으로 나타내는 방법의 가짓수를 구한다.
단, 두 손으로 나타내는 경우 순서만 다른 것은 같은 경우이다.

해결 방법 : N의 범위가 작으므로 직접 1부터 10까지 나타내는 방법을 세 본다.
각각 1, 2, 2, 3, 3, 3, 2, 2, 1, 1가지이다.

주요 알고리즘 : 수학, 케이스 워크, 전처리

출처 : CCC 2010 J1번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    switch (n) {
    case 1:
    case 9:
    case 10:
        printf("1");
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        printf("2");
        break;
    case 4:
    case 5:
    case 6:
        printf("3");
        break;
    default:
        return 1;
    }
    return 0;
}