#include <stdio.h>

/*
문제 : N(N <= 100000)개의 자연수(<= 100)로 이루어진 수열에서 가장 긴 등차 부분 수열의 길이를 구한다.

해결 방법 : 우선 같은 수로 이루어진 각 수열의 길이를 확인한다. 이 길이가 100 이상인 경우
다른 모든 등차수열에 대해 가장 긴 길이가 되므로 그 값을 출력하고 종료한다.
이때, N이 10000 이상인 경우 비둘기집 원리에 따라 반드시 적어도 한 가지 수의 개수는 100 이상이 되므로,
같은 수로 이루어진 수열이 가장 긴 등차수열이 된다.
그 외 경우는 브루트 포스를 이용하면 N이 10000으로 줄어들기 때문에 시간 내에 여유롭게 돌아가는 것이 가능하다.

주요 알고리즘 : 브루트 포스, 비둘기집 원리

출처 : 선린 6회예 E번
*/

int a[103000];

int main(void) {
    int n, res = 0, tlen, nxt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 100; i++) {
        tlen = 0, nxt = i;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) tlen++;
        }
        if (tlen > res) res = tlen;
    }
    if (res >= 100) {
        printf("%d", res);
        return 0;
    }
    for (int i = -99; i <= 99; i++) {
        for (int j = 1; j <= 100; j++) {
            tlen = 0, nxt = j;
            for (int k = 0; k < n; k++) {
                if (a[k] == nxt) {
                    tlen++;
                    nxt += i;
                }
            }
            if (tlen > res) res = tlen;
        }
    }
    printf("%d", res);
    return 0;
}