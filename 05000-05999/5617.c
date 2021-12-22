#include <stdio.h>
#include <stdlib.h>

/*
문제 : 세 변의 길이가 자연수(<= 100)로 주어질 때, 삼각형이 아닌 것이 나올 때 까지 받고,
삼각형인 것, 직각 삼각형인 것, 예각 삼각형인 것, 둔각 삼각형인 것의 개수를 각각 구한다.
삼각형이 아닌 것이 반드시 주어진다.

해결 방법 : 삼각형인지 여부는 가장 긴 변의 길이를 통해 알 수 있다.
가장 긴 변의 길이가 나머지 두 변의 길이 이하인 경우 삼각형이다.
직각, 예각, 둔각 여부는 피타고라스 정리를 이용한다. 가장 긴 변의 길이 제곱이 나머지 두 변의 길이의 제곱 합보다 작으면
예각, 같으면 직각 더 크면 둔각이다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : JOI 2006모1 1번
*/

int a[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    while (1) {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        qsort(a, 3, sizeof(int), cmp1);
        if (a[2] >= a[0] + a[1]) {
            printf("%d %d %d %d", r1, r2, r3, r4);
            break;
        }
        else {
            r1++;
            if (a[2] * a[2] < a[0] * a[0] + a[1] * a[1]) r3++;
            else if (a[2] * a[2] == a[0] * a[0] + a[1] * a[1]) r2++;
            else r4++;
        }
    }
    return 0;
}