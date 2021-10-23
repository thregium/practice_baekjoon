#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 200000)개의 문제가 있고, 각 문제를 일정 기간 안에 풀면 컵라면을 고유한 개수만큼 받을 수 있다.
이때, 얻을 수 있는 컵라면의 최대 개수를 구한다. 기간과 컵라면은 2^31 이하의 자연수이고, 하루에 최대 1문제만 풀 수 있다.

해결 방법 : 마지막 날부터 역순으로 풀 수 있는 문제 가운데 가장 많은 컵라면을 받을 수 있는 것을 푼다.
이는 문제들을 날짜의 역순으로 정렬한 다음, 우선순위 큐에 해당 날 이후의 문제들을 넣고 꺼내오는 방식으로
하면 빠르게 풀 수 있다. 이때, 시간을 줄이기 위해 문제가 없는 날이라면 문제가 있는 이전의 마지막 날로 옮겨야 한다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐
*/

long long prob[204800][2];
priority_queue<long long> cr;

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long n, d = 1234567898, p = 0, r = 0;
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld %lld", &prob[i][0], &prob[i][1]);
    }
    qsort(prob, n, sizeof(long long) * 2, cmp1);
    while (d > 0) {
        if (cr.empty()) d = prob[p][0];
        while (p < n && d <= prob[p][0]) {
            cr.push(prob[p][1]);
            p++;
        }
        if (cr.size()) {
            r += cr.top();
            cr.pop();
        }
        d--;
    }
    printf("%d", r);
    return 0;
}