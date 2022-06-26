#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
문제 : 일직선상의 N(N <= 10000)개의 서로 다른 위치에서의 이동 방향과 거리(<= 2 * 10^6)가 주어질 때,
시작점(|| <= 10^6)에서 이동 가능한 대로 계속 이동하여 도달하는 지점을 구한다.
주어진 모든 이동은 1번씩 쓰인다.

해결 방법 : 각 위치에서의 이동 방향을 해시맵에 넣은 다음 N회 이동하고 그 위치를 출력하면 된다.

주요 알고리즘 : 자료 구조, 해시맵, 시뮬레이션

출처 : Seoul 2021 C번
*/

unordered_map<int, int> mv;

int main(void) {
    int n, pos, diff;
    char dir;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d", &pos, &dir, &diff);
        if (dir == 'L') mv.insert({ pos, -diff });
        else if (dir == 'R') mv.insert({ pos, diff });
        else return 1;
    }
    scanf("%d", &pos);
    for (int i = 0; i < n; i++) {
        pos += mv[pos];
    }
    printf("%d", pos);
    return 0;
}