#include <stdio.h>

/*
문제 : N(N <= 100000)가지의 옷이 각각 a_i(a_i <= 100000)벌씩 있다. 각 사람이 한벌씩 옷을 입고
원형으로 설 때, 인접한 칸에 같은 옷을 입은 사람이 없도록 하는 배치를
만들 수 있는 지 여부를 구한다.

해결 방법 : 가장 많은 종류의 옷이 전체의 절반을 넘게 되면 반드시 인접한 칸에 그 옷을 입은 사람이
와야 하기 때문에 배치가 불가능하다. 단, 1명만 있는 경우는 예외적으로 배치가 가능하다.
그 외 경우에는 항상 배치가 가능함을 증명할 수 있다.

주요 알고리즘 : 애드 혹

출처 : 서강대 2022H D번
*/

int main(void) {
    int n, x;
    long long sum = 0, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
        if (x > best) best = x;
    }
    if (best * 2 > sum && best > 1) printf("Unhappy");
    else printf("Happy");
    return 0;
}