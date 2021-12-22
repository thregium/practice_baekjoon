#include <stdio.h>

/*
문제 : 오타와의 시각이 주어질 때, 나머지 캐나다의 도시의 시각을 구한다. 24시간 단위이고, 앞의 0은 출력하지 않는다.

해결 방법 : 각 지역의 시각을 계산하고 출력한다. 날짜 변경과 시간 단위 변경에 유의한다.

주요 알고리즘 : 수학, 사칙연산

출처 : CCC 2009J 3번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d in Ottawa\n", n);
    printf("%d in Victoria\n", n >= 300 ? n - 300 : n + 2100);
    printf("%d in Edmonton\n", n >= 200 ? n - 200 : n + 2200);
    printf("%d in Winnipeg\n", n >= 100 ? n - 100 : n + 2300);
    printf("%d in Toronto\n", n);
    printf("%d in Halifax\n", n < 2300 ? n + 100 : n - 2300);
    n += 100;
    if (n >= 2400) n -= 2400;
    n += 30;
    if (n % 100 >= 60) n += 40;
    if (n >= 2400) n -= 2400;
    printf("%d in St. John's", n);
    return 0;
}