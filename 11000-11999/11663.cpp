#include <stdio.h>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 100000)개의 점과 M(M <= 100000)개의 선이 수직선상에 있다. 각 점의 좌표와 선의 범위가 주어질 때,
선의 범위 안에 있는 점의 개수를 구한다.

해결 방법 : upper_bound() 함수와 lower_bound() 함수를 이용하면 된다.

주요 알고리즘 : 이분 탐색, 정렬
*/

int point[103000];

int main(void) {
    int n, m, s, e;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &point[i]);
    }
    sort(point, point + n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", upper_bound(point, point + n, e) - lower_bound(point, point + n, s));
    }
    return 0;
}