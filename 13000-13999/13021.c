#include <stdio.h>

/*
문제 : N(N <= 1000)개의 공이 일렬로 있고, M(M <= 50)개의 구간에 대해 차례로 공들을 흰색 또는 검은색으로 칠했다.
이때, 나올 수 있는 공의 색 순열의 개짓수를 구한다.

해결 방법 : 만약 어떠한 구간을 이후 구간들로 모두 덮어버리게 된다면, 해당 구간은 신경 쓸 필요가 없다. 하지만, 그 외의 구간들은
해당 구간에 칠한 색에 자우되는 경우가 있다는 의미이므로 신경써야 한다.
따라서, 각 공들을 마지막으로 칠한 구간을 찾은 다음, 그러한 공이 있는 구간들에 대해서만 순열의 가짓수를 계산하면 된다.
각 구간마다 나올 수 있는 가짓수는 해당 구간을 흰색으로 칠하는 경우와 검은색으로 칠하는 경우 두 가지이므로
2^(겹치지 않은 구간 수)를 계산하면 된다.

주요 알고리즘 : 수학, 조합론
*/

int chk[1024], cnt[64];

int main(void) {
    int n, m, l, r, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &l, &r);
        for (int j = l; j <= r; j++) chk[j] = i;
    }
    for (int i = 1; i <= n; i++) {
        cnt[chk[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        if (cnt[i]) res++;
    }
    printf("%lld", 1LL << res);
    return 0;
}