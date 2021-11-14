#include <stdio.h>

/*
문제 : 1부터 N(N <= 10^6)까지의 자연수로 이루어진 두 순열이 주어질 때, 두 번째 순열에서 1칸씩 밀기 또는
전체 뒤집기 연산을 여러 번 사용하여 첫 번째 순열을 만들 수 있는지 구한다.

해결 방법 : 첫 칸을 고정하고 두 퍼즐을 대조해본 다음 두 번째 퍼즐을 뒤집고 이를 한 번 더 해본다.
둘 중 하나에서 두 퍼즐이 같다면 만들 수 있고, 그 외에는 만들 수 없다.

주요 알고리즘 : 구현?

출처 : 소프트콘 1회 A번
*/

int a[1048576], b[1048576];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, stt = -1, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (b[i] == a[0]) {
            if (stt >= 0) return 1;
            stt = i;
        }
    }
    if (stt < 0) return -1;

    t = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[(stt + i) % n]) t = 0;
    }
    if (t) {
        printf("good puzzle");
        return 0;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--) swap(&b[i], &b[j]);

    stt = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] == a[0]) {
            if (stt >= 0) return 1;
            stt = i;
        }
    }
    if (stt < 0) return -1;
    t = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[(stt + i) % n]) t = 0;
    }
    if (t) printf("good puzzle");
    else printf("bad puzzle");
    return 0;
}