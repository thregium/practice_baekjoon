#include <stdio.h>

/*
문제 : N(N <= 100000)개의 수로 이루어진 수열이 있을 때, 이 수열을 순서를 바꾸지 않고 M개로 쪼개서 나오는 수열들 중
가장 합이 큰 수열의 합을 가장 작게 만든다면, 이때의 합을 구한다.

해결 방법 : 이분 탐색을 통해 수열의 최대 크기가 x인 경우 M개 이상으로 쪼개는 것이 가능한지 확인해본다.
만약 가능하다면 아래쪽, 불가능하다면 위쪽 구간을 살펴보며 하한을 찾으면 된다.

주요 알고리즘 : 그리디 알고리즘, 파라메트릭
*/

int a[103000];
int n, m;

int ispossible(int x) {
    int c = 1, s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) return 0;
        if (s + a[i] > x) {
            c++;
            s = a[i];
        }
        else s += a[i];
    }
    return c <= m;
}

int main(void) {
    int l, h;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    l = 0;
    h = n * 10000;
    while (l < h) {
        if (ispossible((l + h) >> 1)) {
            h = ((l + h) >> 1);
        }
        else {
            l = ((l + h) >> 1) + 1;
        }
    }
    printf("%d", l);
    return 0;
}