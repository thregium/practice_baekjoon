#include <stdio.h>

/*
문제 : N(N <= 1000)대의 길이 1인 트럭이 있고, 길이 W(W <= 1000), 중량제한 L(10 <= L <= 1000)이 주어진다.
각 트럭의 무게가 주어질 때, 시간 1당 트럭이 1씩 움직일 수 있다면 모든 트럭이 다리를 건너는 데 걸리는 시간을 구한다.

해결 방법 : 각 트럭이 출발한 시각과 다리에 있는 트럭의 범위를 저장해가며 도착한 트럭이 나올 때 마다
트럭의 중량을 확인하고 트럭을 출발시킨다. 이를 시각 단위로 확인해 나가며 모든 트럭이 도착할 때 까지 반복하면 된다.
길이와 시간의 제한이 크지 않으므로 가능한 방법이다.

주요 알고리즘 : 구현, 시뮬레이션, 투 포인터

출처 : Daejeon 2016I L번
*/

int a[1024], time[1024];

int main(void) {
    int n, w, l, s = 0, e = 0, weight = 0, t = 1;
    scanf("%d %d %d", &n, &w, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    time[s] = t;
    weight = a[0];
    while (1) {
        t++;
        if (time[s] + w == t) {
            weight -= a[s];
            s++;
            if (s == n) break;
        }
        if (e < n - 1 && weight + a[e + 1] <= l) {
            e++;
            time[e] = t;
            weight += a[e];
        }
    }
    printf("%d", t);
    return 0;
}