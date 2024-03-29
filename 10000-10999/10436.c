#include <stdio.h>

/*
문제 : 루트 노드가 1/1이고, 각 노드의 왼쪽 자식 노드는 부모 노드의 값을 p/q라고 하면 p/(p + q)이고,
오른쪽 자식 노드는 (p + q)/q인 트리가 있다. 이때, 이 노드를 레벨 순회하여 주어진 값 다음에 오는 값을 구한다.

해결 방법 : 해당 레벨에서 가장 오른쪽에 있는 노드인 경우에는 다음 레벨로 내려가 가장 왼쪽의 노드를 봐야 한다.
이러한 경우는 q가 1인 경우이고, 1, p + 1을 출력하면 된다. 그 외의 경우에는 현재 노드가 부모 노드의 오른쪽 노드인 동안
계속 위로 올라간 다음, 그 노드의 부모 노드의 오른쪽 노드로 이동한 다음 다시 왼쪽으로 원래 노드의 레벨과 같은
레벨까지 이동하면 된다.
p가 q 이상인 경우 부모 노드의 오른쪽 노드이고, 이 노드의 부모 노드는 (p - q) / q이다.
이를 반복하면, p가 p % q가 될 때 까지 반복해서 올라가야 한다. 그렇게 올라간 노드는 부모 노드의 왼쪽 노드일 것이다.
이 노드의 부모 노드는 p / (q - p)이고, 오른쪽 노드는 정의대로 (p + q) / q이다. 이제 다시 왼쪽으로 내려가서
p에다가 q를 처음의 (p / q)회만큼 더하면 된다.

주요 알고리즘 : 수학, 정수론

출처 : GNY 2014 F번
*/

int main(void) {
    int t, tn;
    long long p, q, l;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %lld/%lld", &tn, &p, &q);
        if (q == 1) {
            printf("%d %lld/%lld\n", tn, 1LL, p + 1);
            continue;
        }
        l = p / q;
        p = p % q;
        q -= p;
        p += q;
        q += l * p;
        printf("%d %lld/%lld\n", tn, p, q);
    }
    return 0;
}