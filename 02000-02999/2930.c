#include <stdio.h>

/*
문제 : R(R <= 50)라운드동안 한 명이 N(N <= 50)명과 가위바위보를 한다. 한 명이 각 라운드에 낸 것과, N명이 각 라운드에
각자 낸 것들이 주어지면, 한 명의 점수를 구한다. 점수는 한 명이 나머지 N명에 대해 각자와 가위바위보를 한 결과에서
이길 때 2점, 비길 때 1점을 더한 것이다. 그리고 한 명이 최적으로 내는 경우 낼 수 있는 점수도 구한다.

해결 방법 : 먼저 각 값들을 입력받은 다음, 각 라운드에서 한 명이 가위, 바위, 보를 냈을 때 얻을 수 있는 점수를
각각 구한다. 그 다음, 그 사람이 직접 낸 것을 실제 결과에 추가하고, 세 값 가운데 가장 큰 것을 최선의 결과에 추가한다.
이를 R번 반복한 다음 실제 결과와 최선의 결과를 출력하면 된다.

주요 알고리즘 : 구현, 그리디 알고리즘

출처 : CHCI 2009RS 1번 / 2009CR 2번
*/

char sg[64], fr[64][64];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int r, n, s = 0, b = 0, sr, sp, ss; //s : 실제 결과, b : 최선의 결과
    scanf("%d", &r);
    scanf("%s", sg);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", fr[i]);
    }
    for (int i = 0; i < r; i++) {
        sr = 0, sp = 0, ss = 0; //바위, 보, 가위를 각각 냈을 때의 얻을 수 있는 점수
        for (int j = 0; j < n; j++) {
            if (fr[j][i] == 'R') {
                sp += 2;
                sr++;
            }
            else if (fr[j][i] == 'P') {
                ss += 2;
                sp++;
            }
            else if (fr[j][i] == 'S') {
                sr += 2;
                ss++;
            }
            else return 1;
        }
        if (sg[i] == 'R') s += sr; //직접 낸 것을 실제 결과에 더한다.
        else if (sg[i] == 'P') s += sp;
        else if (sg[i] == 'S') s += ss;
        else return 1;
        b += big(big(sr, sp), ss); //가장 좋은 것을 최선의 결과에 더한다.
    }
    printf("%d\n%d", s, b); //결괏값을 출력한다.
    return 0;
}