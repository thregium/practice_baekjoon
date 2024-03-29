#include <stdio.h>

/*
문제 : 시침과 분침의 각도가 주어질 때, 이 각도가 시계에서 나올 수 있는지 구한다.
각도는 자연수로 주어지고, 12시를 기준으로 시계방향이 기준이다.

해결 방법 : 시침이 1도 움직일 때, 분침은 12도씩 움직인다. 각도가 자연수이기 때문에 분침은 12의 배수여야 한다.
또한, 매 정각마다 시침은 30의 배수만큼의 각도이다. 따라서, 시침을 30으로 나눈 나머지와 분침을 12로 나눈 몫을 비교해서
같은 경우 시계에서 나올 수 있는 것이고, 다른 경우 시계에서 나올 수 없는 것임을 알 수 있다.

주요 알고리즘 : 수학

출처 : 서울대 2017 D2B번
*/

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (b % 12) printf("X");
    else if (b / 12 != a % 30) printf("X");
    else printf("O");
    return 0;
}