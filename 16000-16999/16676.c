#include <stdio.h>

/*
문제 : 1부터 N(N <= 10^9)까지의 0 이상인 정수를 전부 만들려고 할 때, 필요한 0부터 9까지의 숫자 세트의 개수를 구한다.
단, 한번 사용한 숫자는 다른 수를 만들 때 다시 사용 가능하다.

해결 방법 : 1이 연속으로 놓인 수들이 나올 때 마다 필요한 개수가 1씩 증가함을 알 수 있다.
N의 크기가 크지 않으므로 일일히 조건문으로 비교해주면 된다.

주요 알고리즘 : 수학, 케이스 워크

출처 : 고려대 2018 AA/BD/IB번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if (n < 11) printf("1");
    else if (n < 111) printf("2");
    else if (n < 1111) printf("3");
    else if (n < 11111) printf("4");
    else if (n < 111111) printf("5");
    else if (n < 1111111) printf("6");
    else if (n < 11111111) printf("7");
    else if (n < 111111111) printf("8");
    else printf("9");
    return 0;
}