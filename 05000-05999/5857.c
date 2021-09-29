#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 좌표평면상에 N(N <= 200)개의 거울들이 있다. 각 거울들은 좌표축과 45도 기울어진 각도로(/, \ 형태) 놓여있다.
한 거울의 각도를 90도 바꾸어 (0, 0)에서 +x 방향으로 빛을 쏘았을 때 (a, b)로 빛을 보낼 수 있는 가장 작은 거울의 번호를 구한다.
바꾸지 않아도 된다면 0을 출력, 어떻게 바꾸어도 보낼 수 없다면 1을 출력한다. 좌표들의 범위는 +- 10^6 이하다.

해결 방법 : 거울을 돌리지 않고 빛을 쏘아본 다음, (a, b)에 도달하지 않는다면 하나씩 돌려보며 빛을 쏘아본다.
(0, 0)에서 +x 방향로 빛을 쏜 다음, y축 좌표가 0이면서 x축의 좌표가 0보다 크고 가장 x축의 좌표가 작은 거울에
닿게 되는 것을 알 수 있고, 그 거울의 좌표로 이동하여 거울의 방향에 맞게 방향을 돌린 다음 빛을 해당 방향으로 쏜다.
이를 반복하며 (a, b)가 있는지 찾아나가면 된다.
만약 해당하는 거울이 없다면 중간에 (a, b)가 있는지 확인하고 없다면 더이상 거울을 만날 수 없으므로 탐색을 종료한다.
또한, 중간에 (0, 0)을 지나며 +x방향으로 이동한다면 계속 반복하게 되므로
해당 지역에서 (a, b)를 발견하지 못한 상황이기에 탐색을 종료해야 한다.
거울을 만났지만 중간에 (a, b)를 만나는 경우도 따로 처리해야 함에 주의한다.

주요 알고리즘 : 브루트 포스, 구현, 케이스 워크

출처 : USACO 2013J B1번
*/

int mirror[256][3];

int check(int n, int a, int b) {
    int x, y, d, t;
    //for (int dd = 0; dd < 4; dd++) {
        x = 0, y = 0, d = 1;
        while (1) {
            if (d < 2) t = 255; //방향에 따라 임시 좌표를 정한다
            else t = 0;
            for (int i = 1; i <= n; i++) {
                //거울을 확인한다.
                if (d == 0 && mirror[i][0] == x && mirror[i][1] > y && mirror[i][1] < mirror[t][1]) t = i; 
                if (d == 1 && mirror[i][0] > x && mirror[i][1] == y && mirror[i][0] < mirror[t][0]) t = i;
                if (d == 2 && mirror[i][0] == x && mirror[i][1] < y && mirror[i][1] > mirror[t][1]) t = i;
                if (d == 3 && mirror[i][0] < x && mirror[i][1] == y && mirror[i][0] > mirror[t][0]) t = i;
            }
            if (t == 255 || t == 0) {
                if (d == 0 && x == a && y < b) return 1; //거울을 만나지 못했고 중간에 (a, b)가 있는 경우
                if (d == 1 && x < a && y == b) return 1;
                if (d == 2 && x == a && y > b) return 1;
                if (d == 3 && x > a && y == b) return 1;
                break;
            }
            if (d == 0 && x == a && y < b && mirror[t][1] > b) return 1; //거울을 만났지만 중간에 (a, b)가 있는 경우
            if (d == 1 && x < a && y == b && mirror[t][0] > a) return 1;
            if (d == 2 && x == a && y > b && mirror[t][1] < b) return 1;
            if (d == 3 && x > a && y == b && mirror[t][0] < a) return 1;
            if (d == 1 && mirror[t][0] > 0 && x < 0 && y == 0) break; //계속 반복하게 되는 경우 종료한다.
            
            x = mirror[t][0];
            y = mirror[t][1];
            if ((d & 1) ^ mirror[t][2]) d = ((d + 3) & 3); //방향을 거울의 방향에 맞게 바꾼다.
            else d = ((d + 1) & 3);
        }
        
    //}
    return 0;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("mirrors.in", "r");
        fo = fopen("mirrors.out", "w");
    }
    int n, a, b;
    char c;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %c", &mirror[i][0], &mirror[i][1], &c);
        if (c == '\\') mirror[i][2] = 1;
    }
    mirror[0][0] = -INF, mirror[0][1] = -INF, mirror[255][0] = INF, mirror[255][1] = INF; //임시 좌표들을 배열에 추가한다.

    if (check(n, a, b)) {
        //거울을 돌리지 않아도 되는 경우
        printf("%d", 0);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        mirror[i][2] = !mirror[i][2]; //거울을 하나씩 돌리고 복구해가며 (a, b)에 닿을 수 있는 경우를 찾는다.
        if (check(n, a, b)) {
            printf("%d", i);
            return 0;
        }
        mirror[i][2] = !mirror[i][2];
    }
    printf("%d", -1); //어떻게 해도 닿지 않는 경우
    return 0;
}