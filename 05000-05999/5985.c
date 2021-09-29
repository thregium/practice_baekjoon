#include <stdio.h>

/*
문제 : 2^N(N <= 10) 크기의 1부터 2^N까지의 자연수로 이루어진 순열이 주어진다. 이때, 이 순열을 주어진대로 정렬한 결과와
정렬하며 이동한 수의 거리 합을 구한다.
순열을 반으로 쪼개는 것을 반복해 크기 1이 될 때 까지 반복한 후, 양쪽 집합을 사전순으로 비교해 두 집합의 순서를 바꾸는 것을
집합이 하나가 될 때 까지 반복한다.

해결 방법 : 문제에서 주어진 대로 재귀적으로 구현한다. 집합의 크기를 절반으로 줄여나가다 크기가 1이 되면 그때부터
양쪽 집합의 첫 원소를 비교해 순열을 정렬해 나가면 된다.(순열이기 때문에 첫 원소만 비교한다.)
이동한 수의 거리는 순서를 바꾸었을 때 집합의 크기^2 / 2와 같다.

주요 알고리즘 : 구현, 분할 정복

출처 : USACO 2011O B2번
*/

int cows[1024];

int skew(int s, int z) {
    int r = 0, t;
    if (z < 2) return 0;
    t = skew(s, z >> 1);
    if (t < 0) return -1;
    r += t;
    t = skew(s + (z >> 1), z >> 1);
    if (t < 0) return -1;
    r += t;
    if (cows[s] == cows[s + (z >> 1)]) return -1;
    else if (cows[s] > cows[s + (z >> 1)]) {
        for (int i = 0; i < (z >> 1); i++) {
            t = cows[s + i];
            cows[s + i] = cows[s + (z >> 1) + i];
            cows[s + (z >> 1) + i] = t;
        }
        r += z * (z >> 1);
    }
    return r;
}

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++) {
        scanf("%d", &cows[i]);
    }
    r = skew(0, (1 << n));
    if (r < 0) return 1;
    printf("%d\n", r);
    for (int i = 0; i < (1 << n); i++) {
        printf("%d\n", cows[i]);
    }
    return 0;
}