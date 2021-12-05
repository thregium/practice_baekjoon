#include <stdio.h>

/*
문제 : 0부터 N - 1(N <= 10)까지의 정수로 이루어진 숫자의 가격(<= 50)이 주어진다.
자금 M(M <= 50)으로 만들 수 있는 가장 큰 수를 구한다. 단, 답이 0이 아니라면 0으로 시작해서는 안 된다.
하나 이상의 숫자를 살 수 있는 경우만 주어진다.

해결 방법 : 먼저 가장 싼 숫자 가운데 가장 큰 수를 최대한 사서 답을 그 수로 전부 채워둔다.
이때, 그 숫자가 0인 경우에는 두 번째로 싼 숫자를 찾아서 첫 숫자로 놓고 나머지를 0으로 채운다.
첫 숫자를 놓을 수 없다면 답은 0이 된다.
자릿수들을 채웠다면 앞자리부터 바꿀 수 있는 가장 큰 숫자로 바꾸어 가며 답을 구해나가면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : SRM 311 D2B
*/

int price[16];
char res[64];

int main(void) {
    int n, m, best, bnz;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    scanf("%d", &m);

    best = n - 1, bnz = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (price[i] < price[best]) best = i;
    }
    for (int i = n - 2; i > 0; i--) {
        if (price[i] < price[bnz]) bnz = i;
    }

    if (best == 0) {
        if (m < price[0]) return 1;
        if (m < price[bnz]) {
            printf("0");
            return 0;
        }
        else {
            m -= price[bnz];
            res[0] = bnz + '0';
            for (int i = 1; m >= price[0]; i++) {
                m -= price[0];
                res[i] = '0';
            }
        }
    }
    else {
        for (int i = 0; m >= price[best]; i++) {
            m -= price[best];
            res[i] = best + '0';
        }
    }

    for (int i = 0; res[i]; i++) {
        for (int j = n - 1; j > res[i] - '0'; j--) {
            if (m >= price[j] - price[res[i] - '0']) {
                m -= price[j] - price[res[i] - '0'];
                res[i] = j + '0';
                break;
            }
        }
    }
    printf("%s", res);
    return 0;
}