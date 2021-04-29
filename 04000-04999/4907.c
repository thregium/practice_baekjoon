#include <stdio.h>

/*
문제 : 2^n 크기의 모든 원소가 1인 정사각행렬에서 재귀적으로 오른쪽 아래칸에 -1을 곱한 행렬이 있다고 한다.
이 행렬의 r번째 줄의 s번째부터 e번째까지 원소의 합을 구한다. (N <= 60)

해결 방법 : r번째 행의 s - 1번째와 e번째의 누적합을 각각 구해서 해결한다.
누적합은 r과 c의 비트 연산을 통해 구할 수 있다.

주요 알고리즘 : 수학, 누적합, 비트마스킹

출처 : Arab CPC 2008 I번
*/

long long presum(long long r, long long c) {
    long long lsb = r & -r; //lsb 구하기
    long long t = r && ((c + 1) & (lsb * 2 - 1)) > lsb ? lsb - ((c + 1) & (lsb - 1)) : ((c + 1) & (lsb * 2 - 1));
    //r을 lsb * 2로 나눈 나머지가 절댓값이 됨. 단, 그 값이 lsb보다 크다면 lsb * 2에서 빼준 값이 됨.
    for (int k = 0; k < 61; k++) {
        if ((1LL << k) <= lsb) continue;
        if ((1LL << k) & (c + 1) & r) t = -t; //lsb보다 큰 비트 가운데 r과 c + 1에서 모두 1인 비트의 수만큼 값을 반전시킴
    }
    return t;
}

int main(void) {
    long long n, r, s, e;
    while (1) {
        scanf("%lld %lld %lld %lld", &n, &r, &s, &e);
        if (n < 0) break;
        printf("%lld\n", presum(r, e) - presum(r, s - 1)); //누적합 구하기
    }
    return 0;
}