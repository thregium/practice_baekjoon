#include <stdio.h>

/*
문제 : N(N <= 1000)개의 1, 2, 3으로 이루어진 수열이 주어질 때, 이 수열을 정렬하기 위해 최소로 필요한 원소 교환 횟수를 구한다.

해결 방법 : 먼저 N개의 수를 입력받는 동시에 1과 2의 개수를 센다. 그 다음, 1의 위치에 와야 할 원소들을 살펴본다.
만약 1의 위치에 다른 원소가 있다면 우선 해당하는 원소의 자리에 있는 1을 살펴보고,
없다면 다른 아무 자리에 있는 1을 골라서 바꾼다.
다른 원소는 단 2가지 뿐이므로 2가 나오면 1의 위치가 끝나는 곳에서 앞쪽부터, 3이 나오면 뒤쪽부터 살펴보면 좋다.
그 다음에는 2의 위치에 와야 할 원소들을 살펴본다. 1은 전부 제자리로 돌아갔을 것이므로 2의 위치에 올 다른 원소는 3 뿐이다.
이 3들을 3의 위치에 있는 2와 바꾸면 수열이 정렬되고, 이렇게 바꾸는 것이 최선의 방법이다. 따라서 이 과정을 하면서
원소를 교환한 횟수를 구하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 애드 혹

출처 : USACO 2007X B1번
*/

int cows[1024];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, ones = 0, twos = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cows[i]);
        if (cows[i] == 1) ones++;
        else if (cows[i] == 2) twos++;
    }

    for (int i = 0; i < ones; i++) {
        if (cows[i] == 2) {
            for (int j = ones; j < n; j++) {
                if (cows[j] == 1) {
                    swap(&cows[i], &cows[j]);
                    res++;
                    break;
                }
            }
        }
        else if (cows[i] == 3) {
            for (int j = n - 1; j >= ones; j--) {
                if (cows[j] == 1) {
                    swap(&cows[i], &cows[j]);
                    res++;
                    break;
                }
            }
        }
    }

    for (int i = ones; i < ones + twos; i++) {
        if (cows[i] == 3) {
            for (int j = n - 1; j >= ones + twos; j--) {
                if (cows[j] == 2) {
                    swap(&cows[i], &cows[j]);
                    res++;
                    break;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}