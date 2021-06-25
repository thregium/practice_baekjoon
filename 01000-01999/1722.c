#include <stdio.h>

/*
문제 : 순열의 길이 N(N <= 20)이 주어질 때, 정수 K(K <= N!)가 주어지면 K번째 순열을, 순열 A가 주어지면 A가 몇 번째 순열인지를 구한다.

해결 방법 : 맨 앞 자리부터 차례로 살펴본다. 뒤에서부터 i번째 자리가 같은 순열은 i!개 있음을 이용한다.

주요 알고리즘 : 수학, 조합론
*/

long long fact[32];
int perm[32], chk[32];

int main(void) {
    int n, o;
    long long k;
    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = fact[i - 1] * i; //팩토리얼은 미리 계산한다.
        perm[i - 1] = 1; //순열의 모든 자리를 미리 1로 맞춰둔다.
    }
    scanf("%d%d", &n, &o);
    if (o == 1) {
        scanf("%lld", &k);
        k--; //1부터 시작하므로 K에서 1을 빼준다.
        for (int i = 0; i < n; i++) {
            while (chk[perm[i]]) perm[i]++; //먼저 중복하지 않은 가장 작은 수로 맞춘다.
            while (k >= fact[n - i - 1]) {
                k -= fact[n - i - 1];
                perm[i]++;
                while (chk[perm[i]]) perm[i]++; //수가 남는 경우 K에서 i!를 빼주고 해당 자릿수를 중복하지 않는 다음 수로 올린다.
            }
            chk[perm[i]] = 1; //해당 수를 방문 표시한다.
            printf("%d ", perm[i]);
        }
    }
    else if (o == 2) {
        k = 1; //역시 K는 1부터 시작하므로 1로 맞춰준다.
        for (int i = 0; i < n; i++) {
            scanf("%d", &perm[i]);
            for (int j = 1; j < perm[i]; j++) {
                if (!chk[j]) k += fact[n - i - 1]; //1부터 해당 자릿수 이전 자리까지 확인하며 겹치지 않는 수에 대해 K에 i!를 더해준다.
            }
            chk[perm[i]] = 1; //방문 처리
        }
        printf("%lld", k);
    }
    return 0;
}