#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^18)이 주어질 때, N번째로 작은 단 2개의 숫자로 이루어진 수를 구한다.
수는 0으로 시작할 수 없다.

해결 방법 : 각 남은 자릿수와 결정된 숫자의 가짓수를 이용하여 각 경우에 대한 가짓수를 각각 구할 수 있다.
우선 수의 길이를 구한 다음, 각 자릿수를 앞에서부터 결정해 나가면 된다.

주요 알고리즘 : 수학, 조합론

출처 : JAG 2018D D번
*/

int main(void) {
    long long n, len = 0, types, type1 = 0, type2 = 0;
    while (1) {
        scanf("%lld", &n);
        if (n == 0) break;
        len = 2;
        for (long long i = 1;; i++) {
            if (((1LL << i) - 1) * 81 < n) {
                len = i + 2;
                n -= ((1LL << i) - 1) * 81;
            }
            else break;
        }
        types = 0;
        for (long long i = 0; i < len; i++) {
            if (i == 0) {
                for (int j = 1; j <= 9; j++) {
                    if (((1LL << (len - 1)) - 1) * 9 < n) n -= ((1LL << (len - 1)) - 1) * 9;
                    else {
                        type1 = j;
                        break;
                    }
                }
                printf("%lld", type1);
                types++;
                continue;
            }
            if (types == 1) {
                for (int j = 0; j <= 9; j++) {
                    if (j == type1) {
                        if (((1LL << (len - i - 1)) - 1) * 9 < n) n -= ((1LL << (len - i - 1)) - 1) * 9;
                        else {
                            printf("%d", j);
                            break;
                        }
                    }
                    else {
                        if (1LL << (len - i - 1) < n) n -= (1LL << (len - i - 1));
                        else {
                            printf("%d", j);
                            type2 = j;
                            types++;
                            break;
                        }
                    }
                }
            }
            else {
                for (int j = 0; j <= 9; j++) {
                    if (j != type1 && j != type2) continue;
                    if (1LL << (len - i - 1) < n) n -= (1LL << (len - i - 1));
                    else {
                        printf("%d", j);
                        break;
                    }
                }
            }
        }

        printf("\n");
    }
    return 0;
}