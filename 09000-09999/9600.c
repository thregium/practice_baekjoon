#include <stdio.h>

/*
문제 : N(N <= 20)마리의 개미들이 길이 L(L <= 100)의 터널에 있다. 각 개미들은 정수 점에서 만나는 경우
서로 방향을 바꾸어 돌아가고, 그 외의 점에서는 만나더라도 가던대로 계속 간다.
각 개미들의 방향(좌, 우)과 위치(자연수)가 주어질 때, 모든 개미들이 터널을 나오는 시각과
마지막으로 나오는 개미(동시에 나온 경우 왼쪽의 개미)를 구한다.

해결 방법 : N과 L의 크기가 작기 때문에 시뮬레이션을 통해 각 개미의 위치, 방향을 확인하면서
모든 개미가 터널을 나올 때의 시각을 구하면 된다. 각 개미가 나올 때 마다 마지막 개미의 번호를
체크하고 같은 턴인 경우 왼쪽 개미의 번호를 저장하면 마지막 개미도 찾을 수 있다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Aizu 2013 B번
*/

int ant[32][2];

int main(void) {
    int n, l, p, t, c, last, lt;
    char d;
    while (1) {
        scanf("%d %d", &n, &l);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf(" %c %d", &d, &p);
            ant[i][0] = p;
            if (d == 'L') ant[i][1] = -1;
            else ant[i][1] = 1;
        }
        t = -1, c = 1, last = 0, lt = -2;
        while (c) {
            c = 0;
            for (int i = 1; i <= n; i++) {
                ant[i][0] += ant[i][1];
                if (ant[i][1]) {
                    c++;
                    if (ant[i][0] == 0 || ant[i][0] == l) {
                        ant[i][1] = 0;
                        if (t > lt) {
                            last = i;
                            lt = t;
                        }
                        else if (t == lt && ant[i][0] == 0) last = i;
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (ant[i][0] == ant[j][0]) {
                        ant[i][1] *= -1;
                        ant[j][1] *= -1;
                    }
                }
            }
            t++;
        }
        printf("%d %d\n", t, last);
    }
    return 0;
}