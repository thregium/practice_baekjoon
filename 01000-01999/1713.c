#include <stdio.h>

/*
문제 : 1번부터 100번까지 100명의 학생회장 후보가 있고, M(M <= 1000)명의 학생들이 이들 중 하나를 뽑는다. 뽑힌 사람은 학생회장 후보로 오른다.
여기서 후보로 오를 자리는 N(N <= 20)석 뿐인데, 빈 자리가 없는 경우에는 현재 자리에 있는 사람 가운데 가장 득표수가 적은 사람을 내리고 대신 앉는다.
그러한 사람이 여럿인 경우에는 가장 먼저 들어온 사람을 내린다. 내려간 경우에는 득표수가 초기화된다.
모든 사람의 투표를 마쳤을 때 후보로 뽑히는 사람을 순서대로 구한다.

해결 방법 : 문제대로 구현한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 정올 2007 초1번
*/

int picture[32][3], cnt[128];

int main(void) {
    int n, m, x, t, lowest;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        t = 0;
        lowest = 0;
        for (int j = 0; j < n; j++) {
            if (picture[j][0] == x || picture[j][0] == 0) {
                picture[j][0] = x;
                picture[j][1]++;
                if (picture[j][0] == 0) picture[j][2] = i;
                t = 1;
                break;
            }
            if ((picture[j][1] < picture[lowest][1]) || (picture[j][1] == picture[lowest][1] && picture[j][2] < picture[lowest][2])) {
                lowest = j;
            }
        }
        if (!t) {
            picture[lowest][0] = x;
            picture[lowest][1] = 1;
            picture[lowest][2] = i;
        }
    }
    for (int i = 0; i < n; i++) cnt[picture[i][0]]++;
    for (int i = 1; i <= 100; i++) {
        if (cnt[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}