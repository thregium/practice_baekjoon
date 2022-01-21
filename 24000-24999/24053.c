#include <stdio.h>

/*
문제 : N(N <= 10000)개의 자연수로 이루어진 두 배열 A, B가 주어질 때, A를 문제에 주어진 수도코드대로
삽입 정렬 하는 과정에서 A와 B가 같아지는 지점이 있는 지 구한다.

해결 방법 : A와 B의 같은 원소인지 여부를 배열에 저장하고 같은 원소의 개수를 확인하며 정렬한다.
값이 바뀔 때 마다 B와 같은 원소인지 여부를 갱신하며 같은 원소의 수를 바꿔 나간다.
같은 원소의 수가 N과 같아지는 지점이 있다면 그곳이 A와 B가 같아지는 지점인 것이고,
없다면 그러한 지점이 없는 것이다. 배열의 맨 처음 상태도 확인해야 함에 유의한다.

주요 알고리즘 : 구현, 정렬
*/

int same[10240], a[10240], b[10240];
int r = 0;

void inse(int n, int scnt) {
    int loc, ni;
    for (int i = 2; i <= n; i++) {
        loc = i - 1;
        ni = a[i];

        while (1 <= loc && ni < a[loc]) {
            if (a[loc + 1] == b[loc + 1]) {
                scnt--;
                same[loc + 1] = 0;
            }
            a[loc + 1] = a[loc];
            if (a[loc + 1] == b[loc + 1]) {
                scnt++;
                same[loc + 1] = 1;
            }
            if (scnt == n) r = 1;
            loc--;
        }

        if (loc + 1 != i) {
            if (a[loc + 1] == b[loc + 1]) {
                scnt--;
                same[loc + 1] = 0;
            }
            a[loc + 1] = ni;
            if (a[loc + 1] == b[loc + 1]) {
                scnt++;
                same[loc + 1] = 1;
            }
            if (scnt == n) r = 1;
        }
    }
}

int main(void) {
    int n, scnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (a[i] == b[i]) {
            same[i] = 1;
            scnt++;
        }
    }
    if (scnt == n) r = 1;
    inse(n, scnt);
    printf("%d", r);
    return 0;
}