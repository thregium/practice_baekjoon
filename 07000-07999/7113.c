#include <stdio.h>

/*
문제 : N * M(N, M < 10000, 자연수) 크기의 직사각형이 주어질 때, 자를 수 있는 가장 큰 정사각형을 자르는 행동을
반복하여 얻을 수 있는 정사각형의 수를 구한다.

해결 방법 : 재귀를 통해 두 변의 길이가 같아질 때 까지 더 작은 쪽의 변을 한 변으로 하는 정사각형을 떼어나가면 된다.

주요 알고리즘 : 수학, 시뮬레이션, 재귀

출처 : LtOI 11II 1번
*/

int getres(int a, int b) {
    if (a == b) return 1;
    else return (a > b ? getres(a - b, b) : getres(a, b - a)) + 1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", getres(n, m));
    return 0;
}