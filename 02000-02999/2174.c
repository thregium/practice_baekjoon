#include <stdio.h>

/*
문제 : A * B(A, B <= 100) 크기의 방에서 N(N <= 100)대의 로봇이 있다. 각 로봇들은 전부 겹치지 않는 위치에 있다고 할 때,
M(M <= 100)개의 명령을 충돌하지 않고 정상적으로 해낼 수 있는지 구한다. 만약 정상적으로 해낼 수 없다면 누구와 충돌했는지 구한다.
각 명령은 R칸 앞으로 이동하거나 R회 왼쪽 또는 오른쪽으로 90도 회전하는 것이다.

해결 방법 : 각 로봇들의 위치와 방향, 방에서 로봇이 있는 곳을 저장해두고 로봇을 이동시킬 때 마다 해당 값들을 업데이트시켜가며
충돌하는지 여부를 확인하면 된다. 방향 전환시에는 로봇의 방향만 돌리면 되고, 앞으로 이동시에는 해당 지점까지 로봇이 있는지,
또는 방 범위를 벗어나지는 않는지 확인한다. 만약 두 경우 중 하나라면 충돌한 상대를 찾고 출력하면 되고,
그렇지 않다면 다음 명령을 시행한다. 끝까지 명령을 수행한 경우 정상적으로 해낼 수 있는 것이다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : NCPC 2005 A번
*/

int room[128][128], robots[128][3]; //rooms : 해당 위치의 로봇 여부, robots : 0 - X좌표 / 1 - Y좌표 / 2 - 방향
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int h, w, n, m, x, y, d, rb, rp;
    char c;
    scanf("%d %d%d %d", &w, &h, &n, &m); //가로와 세로에 유의한다.
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %c", &x, &y, &c);
        robots[i][0] = x;
        robots[i][1] = y;
        room[x][y] = 1;
        if (c == 'E') robots[i][2] = 1; //북쪽 : 0, 동쪽 : 1, 남쪽 : 2, 서쪽 : 3
        else if (c == 'S') robots[i][2] = 2;
        else if (c == 'W') robots[i][2] = 3;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %c %d", &rb, &c, &rp);
        x = robots[rb][0];
        y = robots[rb][1];
        d = robots[rb][2];
        if (c == 'F') {
            for (int j = 1; j <= rp; j++) {
                if (x + dxy[d][0] * j > w || x + dxy[d][0] * j <= 0 || y + dxy[d][1] * j > h || y + dxy[d][1] * j <= 0) {
                    //해당 위치가 벽인 경우
                    printf("Robot %d crashes into the wall", rb);
                    return 0;
                }
                if (room[x + dxy[d][0] * j][y + dxy[d][1] * j]) {
                    //해당 위치에 로봇이 있는 경우
                    for (int k = 1; k <= n; k++) {
                        if (robots[k][0] == x + dxy[d][0] * j && robots[k][1] == y + dxy[d][1] * j) {
                            //해당 위치에 있는 로봇 찾기
                            printf("Robot %d crashes into robot %d", rb, k);
                            return 0;
                        }
                    }
                    return 1;
                }
            }
            room[x + dxy[d][0] * rp][y + dxy[d][1] * rp] = 1; //방과 로봇 정보 업데이트
            room[x][y] = 0;
            robots[rb][0] = x + dxy[d][0] * rp;
            robots[rb][1] = y + dxy[d][1] * rp;
        }
        else if (c == 'L') {
            for (int j = 1; j <= rp; j++) d = ((d + 3) & 3); //왼쪽 회전
            robots[rb][2] = d;
        }
        else if (c == 'R') {
            for (int j = 1; j <= rp; j++) d = ((d + 1) & 3); //오른쪽 회전
            robots[rb][2] = d;
        }
        else return 1;
    }
    printf("OK");
    return 0;
}