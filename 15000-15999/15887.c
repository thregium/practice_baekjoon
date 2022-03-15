#include <stdio.h>

/*
문제 : 길이 N(N <= 1000)의 1부터 N까지의 자연수로 이루어진 순열이 주어질 때,
이 순열에서 임의의 구간을 뒤집는 연산을 N * N회 이내로 하여 순열과 인덱스가 같은 원소 개수가
가장 많이 만들어지도록 하는 방법을 출력한다.

해결 방법 : 순열이 정렬된 상태가 되면 모든 원소가 같은 상태가 된다.
그런데, 버블 소트를 하는 경우 인접한 2개의 원소를 뒤집어 정렬이 가능하며, 교환 N * N회 이내로
충분히 정렬이 가능하기 때문에 버블 소트를 하는 과정을 출력하면 된다.

주요 알고리즘 : 구성적, 정렬

출처 : 선린 2회 C번
*/

int a[1024], op[1048576][2];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, c = 1, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    while (c) {
        c = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                swap(&a[i], &a[i - 1]);
                op[r][0] = i;
                op[r++][1] = i + 1;
                c++;
            }
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d %d\n", op[i][0], op[i][1]);
    }
    return 0;
}