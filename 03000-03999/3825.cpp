#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

/*
문제 : 은행수는 정수 (M, N)의 쌍이다. 은행수의 곱은 두 은행수 (M, N), (A, B)에 대해
(MA - NB, MB + NA)이다. 두 은행수의 곱이 (A, B) * (P, Q) = (M, N)이 되는 은행수 (A, B)가 있는 경우
(A, B)(또는 (P, Q))를 (M, N)의 약수라 말한다. A^2 + B^2 > 1인 모든 은행수 (A, B)에 대해
(0, 1), (0, -1), (1, 0), (-1, 0), (A, B), (-A, B), (A, -B), (-A, -B)는 항상 약수이다.
이때, 이 수들 외의 다른 은행수를 약수로 갖지 않는 은행수를 소수 은행수라고 한다면,
1 < A^2 + B^2 < 20000인 은행수 (A, B)에 대해 이 수가 소수 은행수인지 구한다.

해결 방법 : 은행수의 곱셈을 할 때 A^2 + B^2의 값은 그 값이 1 이상인 경우 항상 늘어남을 알 수 있다.
또한, A^2 + B^2의 값이 더 큰 수와 곱하면 반드시 더 큰 A^2 + B^2 값이 나오게 되는 것도 알 수 있다.
이를 이용해 에라토스테네스의 체를 변형할 수 있다. 주어진 조건에 맞는 (A, B)는 약 62000개이다.
이 (A, B)들을 전부 구한 다음 A^2 + B^2의 오름차순으로 정렬한다. 이렇게 되면 사실상 크기 순서대로
(A, B)들이 정렬되는 것이므로 에라토스테네스의 체를 통해 6번째부터(앞은 0, 1 역할) 차례로
소수인 수마다 은행수가 아닌 수들을 지워나가면 된다. 지워나간 값들은 셋에 추가한다.

셋에 모든 값들을 추가했으면 주어진 은행수에 대해 셋에 있는 지 여부를 확인한다. 있다면 합성수이고,
없다면 소수이다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스, 셋, 정렬

출처 : Tokyo 2012 A번
*/

int gn[65536][2];
set<pair<int, int>> sieve;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    return ai * ai + aj * aj > bi * bi + bj * bj ? 1 : ai * ai + aj * aj == bi * bi + bj * bj ? 0 : -1;
}

int main(void) {
    int cnt = 0, t, x, y;
    for (int i = -200; i <= 200; i++) {
        for (int j = -200; j <= 200; j++) {
            if (i * i + j * j < 20000) {
                gn[cnt][0] = i;
                gn[cnt++][1] = j;
            }
        }
    }
    qsort(gn, cnt, sizeof(int) * 2, cmp1);
    for (int i = 5; i < cnt; i++) {
        if (sieve.find(pair<int, int>(gn[i][0], gn[i][1])) != sieve.end()) continue;
        for (int j = 5; j < cnt; j++) {
            x = gn[i][0] * gn[j][0] - gn[i][1] * gn[j][1];
            y = gn[i][0] * gn[j][1] + gn[i][1] * gn[j][0];
            if (x * x + y * y > 20000) break;
            sieve.insert(pair<int, int>(x, y));
        }
    }
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\A.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\A_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &x, &y);
        if (sieve.find(pair<int, int>(x, y)) != sieve.end()) printf("C\n");
        else printf("P\n");
    }
    return 0;
}