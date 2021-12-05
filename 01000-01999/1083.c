#include <stdio.h>

/*
문제 : N(N <= 50)개의 서로 다른 자연수(<= 10^6)로 이루어진 배열이 주어질 때, S(S <= 10^6)번 이하로 인접한 두 수의
순서를 바꾸어 만들 수 있는 사전순으로 가장 뒷서는 배열을 구한다.

해결 방법 : 맨 앞에서부터 남은 이동 횟수 내로 바꿀 수 있는 가장 큰 수를 찾고 그 값을 원하는 위치로 끌어오는 것을 반복한다.
이를 배열의 끝까지 반복하며 순서대로 가능한 가장 큰 수를 찾아나가면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : SRM 307 D1A / D2B
*/

int arr[64];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, s, best = -1, bp = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &s);
    for (int i = 0; i < n; i++) {
        best = arr[i], bp = i;
        for (int j = i + 1; j - i <= s && j < n; j++) {
            if (arr[j] > best) {
                best = arr[j];
                bp = j;
            }
        }
        for (int j = bp; j > i; j--) {
            swap(&arr[j], &arr[j - 1]);
        }
        s -= bp - i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}