#include <stdio.h>

/*
문제 : 1부터 N(N <= 314159)까지의 자연수로 이루어진 순열 가운데 반전이 M(M <= N * (N - 1) / 2)개인 순열을 구한다.

해결 방법 : 앞에서부터 역순으로 가장 큰 수부터 넣어가며 반전의 개수를 줄여나간다.
가장 큰 수를 넣을 수 없다면 그 때 들어갈 수를 넣은 다음 1부터 남은 수들을 넣으면 된다.

주요 알고리즘 : 수학, 그리디 알고리즘, 구성적

출처 : 경북대 2019 J번
*/

int main(void) {
    int n, x = 0, y = 0;
    long long k;
    scanf("%d %lld", &n, &k);
    for (int i = n; i > 0; i--) {
        if (k > i - 1) {
            k -= i - 1;
            printf("%d ", i);
        }
        else {
            printf("%d ", k + 1);
            x = k + 1;
            y = i;
            break;
        }
    }
    for (int i = 1; i <= y; i++) {
        if (i == x) continue;
        printf("%d ", i);
    }
    return 0;
}