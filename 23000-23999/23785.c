#include <stdio.h>

/*
문제 : 각 자릿수의 팩토리얼 합이 N(1 <= N <= 10^9)인 가장 작은 수를 구한다.

해결 방법 : 1에서부터 9까지의 자릿수를 단위 1! ~ 9!로 하여 수를 만든 다음 그 순서대로
숫자의 값만큼 그 자릿수를 출력해 나가면 된다. N이 1일 때는 답이 0임에 유의한다.

주요 알고리즘 : 수학, 정수론, 그리디 알고리즘

출처 : CTU 2021 O번
*/

int fact[16], res[16];

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    fact[0] = 1;
    for (int i = 1; i <= 9; i++) fact[i] = fact[i - 1] * i;
    for (int i = 9; i >= 1; i--) {
        res[i] = n / fact[i];
        n %= fact[i];
    }
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < res[i]; j++) printf("%d", i);
    }
    return 0;
}