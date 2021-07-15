#include <stdio.h>

/*
문제 : 다트에서 화살 3개로 정확히 N점을 만드는 방법의 수를 구한다. 화살 하나 당 1 ~ 20점 사이의 자연수의 1, 2, 3배
의 점수 중 하나 또는 50점을 얻을 수 있다. 다른 위치에 화살을 쏘았더라도 점수 배치가 같다면 같은 방법이다.
순열과 조합을 모두 구한다.

해결 방법 : 화살을 던져 얻을 수 있는 점수들을 전부 구한 후 모든 점수 조합에 대해 N점이 나오는지 확인해봐서
N점이 나오는 모든 경우를 세면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : MidC 1993 2번
*/

int scores[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60 };

int main(void) {
    int n, c, p, example = 0;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\darts.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\darts_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n <= 0) {
            printf("END OF OUTPUT");
            break;
        }
        if (n == 162) example = 1;
        c = 0, p = 0;
        for (int i = 0; i < 43; i++) {
            for (int j = 0; j < 43; j++) {
                for (int k = 0; k < 43; k++) {
                    if (scores[i] + scores[j] + scores[k] == n) p++;
                }
            }
        }
        for (int i = 0; i < 43; i++) {
            for (int j = i; j < 43; j++) {
                for (int k = j; k < 43; k++) {
                    if (scores[i] + scores[j] + scores[k] == n) c++;
                }
            }
        }

        if (p == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, c);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, p);
        }
        printf("**********************************************************************\n");
    }
    return 0;
}