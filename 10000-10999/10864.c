#include <stdio.h>

/*
문제 : N(N <= 1000)명의 M(M <= 1000)개의 친구 관계가 주어질 때, 각 사람의 친구의 수를 구한다.
단, 친구 관계는 양방향이고, 친구 관계가 중복해서 주어지거나 자기 자신과 친구인 경우는 없다.

해결 방법 : 친구 관계가 중복되거나 스스로 친구인 경우가 없으므로 각 친구관계마다 두 사람에게는 새로운 친구가 나오는 셈이다.
따라서, 친구 관계가 나올 때 마다 두 사람의 친구 수를 1씩 추가하면 된다.

주요 알고리즘 : 구현
*/

int friends[1024];

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        friends[a]++;
        friends[b]++;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", friends[i]);
    }
    return 0;
}