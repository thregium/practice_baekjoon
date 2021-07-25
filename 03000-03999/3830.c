#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 샘플이 있다. 이때, M(M <= 100000)개의 다음 쿼리에 응답한다.
1. 두 샘플의 상대적인 무게 차이가 주어진다. 이 값은 항상 일관된다.
2. 두 샘플의 무게 차이를 구할 수 있는지 확인하고 가능하다면 그 값을 출력하고 불가능하다면 UNKNOWN을 출력한다.
가능한 경우 그 값은 절댓값이 10^6 이하이다.

해결 방법 : 유니온 파인드를 통해 각 샘플이 같은 집합에 있는지와 그 무게 차이도 구할 수 있다.
각 집합과 같이 집합의 대푯값과 무게를 동시에 저장한다. 경로 압축 과정에서 무게도 같이 압축하도록 조정해야 한다.
두 집합이 서로 다른 집합이라면 유니온하며 무게 배열에 그 차이를 저장한다.
두 샘플의 무게 차이를 구할 때에는 먼저 두 샘플이 같은 집합인지 확인한 후 아니라면 UNKNOWN을 출력하고
맞다면 비교하고자 하는 샘플의 대푯값과의 차이에서 구하고자 하는 샘플의 차이를 뺀 값을 통해 구할 수 있다.

주요 알고리즘 : 자료구조, 유니온 파인드

출처 : Tokyo 2012 F번
*/

char buff[1024];
int g[103000], diff[103000], iscorrupt[103000];

long long find(long long x) {
    if (g[x] == 0) return x;
    long long r = find(g[x]);
    diff[x] += diff[g[x]];
    return g[x] = r;
}

long long getdiff(long long a, long long b) {
    long long r = 0;
    while (g[a]) {
        r -= diff[a];
        a = g[a];
    }
    while (g[b]) {
        r += diff[b];
        b = g[b];
    }
    return r;
}

void uni(long long a, long long b, long long w) {
    long long f, t, f2, t2;
    f = find(b);
    t = getdiff(f, b);
    f2 = find(a);
    t2 = getdiff(f2, a);
    if (f == f2) {

    }
    else {
        g[f] = f2;
        diff[f] = w - t + t2;
    }
}

int main(void) {
    long long n, m, a, b, w;
    char c;
    char* s;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\F.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\F_t.out", "w", stdout);
    while (1) {
        fgets(buff, 1000, stdin);
        s = strtok(buff, " ");
        n = strtoll(s, NULL, 10);
        s = strtok(NULL, " ");
        m = strtoll(s, NULL, 10);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            fgets(buff, 1000, stdin);
            s = strtok(buff, " ");
            if (buff[0] == '!') {
                s = strtok(NULL, " ");
                a = strtoll(s, NULL, 10);
                s = strtok(NULL, " ");
                b = strtoll(s, NULL, 10);
                s = strtok(NULL, " ");
                w = strtoll(s, NULL, 10);
                uni(a, b, w);
            }
            else if (buff[0] == '?') {
                s = strtok(NULL, " ");
                a = strtoll(s, NULL, 10);
                s = strtok(NULL, " ");
                b = strtoll(s, NULL, 10);
                if (find(a) != find(b)) {
                    printf("UNKNOWN\n");
                    continue;
                }
                printf("%lld\n", getdiff(a, b));
            }
        }
        for (int i = 1; i <= n; i++) {
            g[i] = 0;
            diff[i] = 0;
        }
    }
    return 0;
}