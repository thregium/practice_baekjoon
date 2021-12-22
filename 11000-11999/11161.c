#include <stdio.h>

/*
문제 : M(M <= 100)번동안 집에 사람이 P1명 들어오고 P2(P1, P2 <= 1000)명 들어오는 것을 보았다고 할 때,
처음 집에 있어야 하는 사람 수의 최솟값을 구한다. 이를 T(T <= 50)번 반복한다.

해결 방법 : 처음에 사람 수를 0명으로 잡고 P1 - P2명씩 집에 있는 사람 수를 더해나간다. 이 과정에서 나오는 음의 사람 수 가운데
가장 작은 값이 처음에 0명일 때 나올 수 있는 최솟값이고, 역으로 생각하면 그때 0명이 되기 위해서는
그 값의 부호를 바꾼 값 만큼이 처음에 있어야 한다는 뜻이므로 부호를 바꾼 값을 출력하면 된다.

주요 알고리즘 : 구현, 수학

출처 : IDI 2013 D번
*/

int main(void) {
    int t, n, p1, p2, people, best;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        people = 0, best = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p1, &p2);
            people += p1 - p2;
            if (people < best) best = people;
        }
        printf("%d\n", -best);
    }
    return 0;
}