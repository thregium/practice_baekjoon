#include <stdio.h>

/*
문제 : 길이 N(N <= 500)의 1에서 N까지의 순열이 주어질 때, 모든 행과 열에 해당 순열이 존재하는 가장 작은 행렬을 만든다.

해결 방법 : 모든 행과 열에 대해 한칸씩 밀어가며 순열을 출력하면 N * 2 - 1 크기의 행렬을 만들 수 있고,
이것이 가장 작은 행렬이다.

주요 알고리즘 : 구성적, 수학?

출처 : Petro 2019W8 B번
*/

int p[512];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    printf("%d\n", n * 2 - 1);
    for (int i = 0; i < n * 2 - 1; i++) {
        for (int j = 0; j < n * 2 - 1; j++) {
            printf("%d ", p[(i + j) % n]);
        }
        printf("\n");
    }
    return 0;
}