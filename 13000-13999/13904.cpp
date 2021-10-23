#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 1000)개의 숙제가 있고, 각 숙제는 마감일(<= 1000)이 있다. 각 마감일 안에 숙제를 끝내면
점수(<= 1000)를 얻을 수 있다. 이때, 얻을 수 있는 최대의 점수를 구한다. 하루에 한 개의 숙제만 할 수 있다.

해결 방법 : 마지막 날부터 역순으로 숙제들을 확인하면서 그 날 끝내서 점수를 얻을 수 있는 숙제 가운데 가장 점수가 높은 것을
그 날 한다. 이는 우선순위 큐를 통해 빠르게 구할 수 있다. 그 전에 미리 숙제들을 마감일의 역순으로 정렬해둔 다음,
각 날에 그 날 이후가 마감인 숙제들을 우선순위 큐에 추가하고, 가장 큰 점수를 우선순위 큐에서 빼내는 것을 반복하면 된다.
물론 그러한 숙제가 없는 날은 숙제를 하지 않는다.
1일차가 끝나면 지금까지 숙제로 얻은 점수를 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : 서강대 12회C E번 / 12회M E번
*/

int hw[1024][2];
priority_queue<int> sco;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, d = 1234, p = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &hw[i][0], &hw[i][1]);
    }
    qsort(hw, n, sizeof(int) * 2, cmp1);
    while (d > 0) {
        while (p < n && d <= hw[p][0]) {
            sco.push(hw[p][1]);
            p++;
        }
        if (sco.size()) {
            r += sco.top();
            sco.pop();
        }
        d--;
    }
    printf("%d", r);
    return 0;
}