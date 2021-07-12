#include <stdio.h>

/*
문제 : T(T <= 200)개의 팀에 대해 현재까지 경기의 수와 각 팀의 승점이 주어질 때, 무승부의 수를 구한다.
승리시 승점 3점, 무승부시 승점 1점을 얻게 된다.

해결 방법 : 승부가 갈리는 경우 양 팀 합쳐 승점 3점을 얻게 되고, 무승부라면 양 팀 합쳐 2점만 얻게 된다.
따라서 경기 수 * 3과 모든 팀의 승점 합의 차이를 구하면 무승부의 수를 구할 수 있다.

주요 알고리즘 : 애드 혹?

출처 : Brasil 2006 F번
*/

char buff[16];

int main(void) {
    int t, n, s, x;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2006\\copa.in", "r", stdin);
    while (1) {
        scanf("%d %d", &t, &n);
        if (t == 0) break;
        s = 0;
        for (int i = 0; i < t; i++) {
            scanf("%s %d", buff, &x);
            s += x;
        }
        printf("%d\n", n * 3 - s);
    }
    return 0;
}