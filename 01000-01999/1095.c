#include <stdio.h>

/*
문제 : S + F(S, F <= 10^9)개의 구슬 가운데 F개의 구슬을 고르는 경우의 수가 M(M <= 100000) 이하에서 나누어 떨어지는
가장 큰 자연수를 구한다. 없는 경우 -1을 출력한다.

해결 방법 : (S + F)_C_F mod X = 0이 되는 M 이하에서 가장 큰 X를 구하면 된다. 이는 (S + F)_C_F를
(S + F)! / (F!)(S!)으로 표현하고 M 이하의 각 X에 대해 나누어 떨어지는지 확인하는 것으로 알 수 있다.

가장 쉬운 방법은 소인수분해를 이용하는 것인데, X와 (S + F)!, F!, S!을 소수 단위로 분해하여
S + F!에 들어있는 해당 소수의 개수를 F!과 S!에 들어있는 소수의 개수만큼 뺀 것이 X에 있는 소수의 개수 이상인지를
X의 모든 소수에 대해 확인하는 것이다. 모든 소수에서 만족한다면 나누어 떨어진다고 할 수 있다.

X를 소인수분해하는 방법은 에라토스테네스의 체를 응용하여 미리 100000 이하의 모든 수를 소인수분해 해두면 되고,
S!에 들어있는 소수의 개수를 세는 방법은 S를 소수로 나누어 가며 그 개수를 모두 더하면 된다.

모든 수는 1로 나누어 떨어지기 때문에 -1을 출력하는 경우는 절대 나오지 않는다.

주요 알고리즘 : 수학, 정수론, 소인수분해, 조합론

출처 : SRM 409 D1B
*/

char sieve[103000];
int div[103000][24], prime[10240];
int pp = 0;

int getcnt(int x, int y) {
    int r = 0;
    while (x) {
        x /= y;
        r += x;
    }
    return r;
}

int main(void) {
    int s, f, m, mi, t;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i; j <= 100000; j += i) {
            div[j][div[j][0] * 2 + 1] = i;
            for (int k = j; k % i == 0; k /= i) {
                div[j][div[j][0] * 2 + 2]++;
            }
            if (j != i) sieve[j] = 1;
            div[j][div[j][0]++];
        }
    }
    scanf("%d %d %d", &s, &f, &m);
    for (int i = m; i > 0; i--) {
        mi = i;
        t = 1;
        for (int j = 1; j <= div[i][0]; j++) {
            if (getcnt(s + f, div[i][j * 2 - 1]) - getcnt(s, div[i][j * 2 - 1]) - getcnt(f, div[i][j * 2 - 1]) < div[i][j * 2]) {
                t = 0;
                break;
            }
        }
        if (t) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}