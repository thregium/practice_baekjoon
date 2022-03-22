#include <stdio.h>

/*
문제 : N(N <= 100) 미만의 음이 아닌 정수 Y(Y <= 200)개가 주어진다.
주어지지 않은 N 미만의 음이 아닌 정수들을 오름차순으로 모두 출력하고
서로 다른 주어진 정수들의 개수를 출력한다.

해결 방법 : 각 정수마다 주어졌는 지 여부를 저장해둔 다음, 0부터 N - 1까지 확인하면서
저장되어 있다면 답을 1씩 올려나가고, 아니라면 출력한다. 마지막으로 답을 출력하면 된다.

주요 알고리즘 : 구현

출처 : VTH 2017 C번
*/

int obst[128];

int main(void) {
    int n, y, k, r = 0;
    scanf("%d %d", &n, &y);
    for (int i = 0; i < y; i++) {
        scanf("%d", &k);
        obst[k] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (obst[i]) r++;
        else printf("%d\n", i);
    }
    printf("Mario got %d of the dangerous obstacles.", r);
    return 0;
}