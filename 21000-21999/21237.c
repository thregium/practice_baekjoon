#include <stdio.h>
#include <string.h>

/*
문제 : 길이 100 이하의 'N', 'E', 'S', 'W'로 이루어진 문자열이 주어진다. 이 방향으로 움직여 원래 위치로 돌아온 경로가
주어질 때, 이 경로는 시계방향으로 움직인 것인지 반시계방향으로 움직인 것인지 구한다. 180도 회전하는 경우는 주어지지 않는다.

해결 방법 : 오른쪽 방향으로 회전한 횟수와 왼쪽 방향으로 회전한 횟수를 각각 구한다. 시작점에서 회전한 것도 포함해야 한다.
시계방향으로 움직였다면 우회전이 좌회전보다 4회 많을 것이고, 반시계방향으로 움직였다면 좌회전이 우회전보다 4회 많을 것이다.
따라서 이를 이용하면 쉽게 답을 구할 수 있다.

주요 알고리즘 : 기하학, 애드 혹

출처 : USACO 2021F B3번
*/

char s[128];

int main(void) {
    int n, c, w, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        c = 0, w = 0, l = strlen(s);
        for (int j = 0; s[j + 1]; j++) {
            if ((s[j] == 'N' && s[j + 1] == 'E') || (s[j] == 'E' && s[j + 1] == 'S') || (s[j] == 'S' && s[j + 1] == 'W') || (s[j] == 'W' && s[j + 1] == 'N')) c++;
            else if ((s[j] == 'N' && s[j + 1] == 'W') || (s[j] == 'W' && s[j + 1] == 'S') || (s[j] == 'S' && s[j + 1] == 'E') || (s[j] == 'E' && s[j + 1] == 'N')) w++;
        }
        if ((s[l - 1] == 'N' && s[0] == 'E') || (s[l - 1] == 'E' && s[0] == 'S') || (s[l - 1] == 'S' && s[0] == 'W') || (s[l - 1] == 'W' && s[0] == 'N')) c++;
        else if ((s[l - 1] == 'N' && s[0] == 'W') || (s[l - 1] == 'W' && s[0] == 'S') || (s[l - 1] == 'S' && s[0] == 'E') || (s[l - 1] == 'E' && s[0] == 'N')) w++;

        if (c - w == 4) printf("CW\n");
        else if (c - w == -4) printf("CCW\n");
        else return 1;
    }
    return 0;
}