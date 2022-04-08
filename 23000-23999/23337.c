#include <stdio.h>

/*
문제 : N(2 <= N <= 300)명의 사람이 있고, 각 사람은 각 사람에게 할당된 자리가 있다.
첫 번째 사람이 무작위하게 자신의 자리가 아닌 다른 자리에 앉았다. 다른 사람들은 순서대로 자신의 자리가
비어있는 경우 자신의 자리에 않고 비어있지 않았다면 아무 자리에나 앉는다.
이때, 마지막 사람의 자리에 다른 사람이 앉을 확률을 구한다.

해결 방법 : 첫 번째 사람이나 중간의 다른 사람이 마지막 자리에 앉는 경우를 생각하면 된다.
첫 번째 사람이 앉을 확률은 1 / (n - 1)이고, 중간의 사람들이 앉을 확률은 1 - (1 / (n - 1))에서
절반을 한 값과 같다. 중간의 사람들이 첫 번째 자리에 앉으면 나머지 모두는 제 자리에 앉을 수 있지만,
마지막 자리에 앉으면 마지막 사람은 제 자리에 앉을 수 없고, 그 외 자리에 앉으면 그 자리의 사람까지
결정이 미뤄진다. 첫 번째 자리와 마지막 자리에 앉을 확률이 같으므로 나머지의 1 / 2가 되는 것이다.
앞의 두 경우를 더하면 답이 된다.

주요 알고리즘 : 수학, 확률론

출처 : TOPC 2021 D번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%.9f", 1.0 - ((n - 2.0) / (n - 1.0)) / 2.0);
    return 0;
}