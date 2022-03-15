#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 6000)개의 선분이 있다. 각 선분은 빨간색, 초록색, 파란색 중 하나이고,
길이는 100000 이하의 자연수이다. 이때, 세개의 선분을 골라 세 변의 색이 모두 다른
삼각형을 만드는 경우의 수를 구한다.

해결 방법 : 각 선분들을 색상별로 분류한 다음 길이별로 정렬한다.
그런 다음, 빨간색과 초록색의 모든 경우를 하나씩 확인하면서 파란색 선분의 가능한 길이 구간에 대해
만들 수 있는 삼각형의 가짓수를 모두 더해나가면 된다. 가능한 구간은 두 선분의 길이 차보다 크고
길이 합보다 작은 구간이다.

주요 알고리즘 : 기하학, 이분 탐색

출처 : IATI 2016C 3번
*/

int red[6144], green[6144], blue[6144];

int main(void) {
    int n, rn = 0, gn = 0, bn = 0, x;
    long long res = 0;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &x);
        if (c == 'r') red[rn++] = x;
        else if (c == 'g') green[gn++] = x;
        else if (c == 'b') blue[bn++] = x;
        else return 1;
    }
    sort(blue, blue + bn);
    for (int i = 0; i < rn; i++) {
        for (int j = 0; j < gn; j++) {
            if (abs(red[i] - green[j]) > red[i] + green[j]) continue;
            res += upper_bound(blue, blue + bn, red[i] + green[j] - 1) -
                lower_bound(blue, blue + bn, abs(red[i] - green[j]) + 1);
        }
    }
    printf("%lld", res);
    return 0;
}