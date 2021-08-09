#include <stdio.h>

/*
문제 : N(N <= 100000)개의 "전체 문장 중 X개는 참이다."라는 문장이 있다. 이 문장 가운데 참이 될 수 있는 가장 큰 X를 찾는다.
만약 없다면 -1을 출력한다. X는 100000 이하이다.

해결 방법 : 모든 X에 대해 해당하는 문장의 수를 각각 센 후, 그 값이 X와 같은 가장 큰 값을 찾으면 된다.

주요 알고리즘 : 구현?, 수학?
*/

int cnt[103000];

int main(void) {
    int n, x, r = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 0; i <= 100000; i++) {
        if (i == cnt[i]) r = i;
    }
    printf("%d", r);
    return 0;
}