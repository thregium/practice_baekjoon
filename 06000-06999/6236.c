#include <stdio.h>

/*
문제 : N(N <= 100000)일간 사용할 돈과 잔고가 주어질 때, M일만 출금을 하기 위해 매 출금시 출금해야 하는
최소 금액을 구한다. 단, 잔액이 부족할 때는 남은 금액을 버리고 출금한다.

해결 방법 : 매개 변수 탐색을 이용한다. X만큼 출금할 때 출금해야 하는 날의 수를 구하고
그 값이 M 이하인 가장 작은 X를 구하면 된다. 출금해야 하는 날의 수는 그리디하게 돈이 모자랄 때 마다 출금하면 구할 수 있다.

주요 알고리즘 : 파라메트릭

출처 : USACO 2007M S3번
*/

int money[103000];

int getdays(int n, int x) {
    int r = 0, m = 0;
    for (int i = 0; i < n; i++) {
        if (money[i] > m) {
            r++;
            m = x;
            if (money[i] > x) return 1012345678;
        }
        m -= money[i];
    }
    return r;
}

int main(void) {
    int n, m, l = 0, h = 1012345678;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &money[i]);
    }
    while (l < h) {
        if (getdays(n, (l + h) >> 1) <= m) h = ((l + h) >> 1);
        else l = ((l + h) >> 1) + 1;
    }
    printf("%d", l);
    return 0;
}