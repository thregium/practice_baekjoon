#include <stdio.h>

/*
문제 : 20가지 강의의 시수와 평점이 주어질 때, 평균 평점을 구한다. 평점이 P인 경우 그 강의는
계산에서 제외한다. P가 아닌 강의는 적어도 하나 이상 주어진다.

해결 방법 : 강의의 평점이 P라면 그 강의는 넘어가고 그 외 경우 모든 강의의 시간 합 * 평점의 곱을
전부 더한 것과 시간 합을 각각 저장해 나간다. 그 다음 시간 합으로 평점을 나누면 답이 된다.

주요 알고리즘 : 수학, 구현

출처 : 인하대 2022U B번
*/

char dump[64], buff[4];

int main(void) {
    int np = 0;
    double time, score, total = 0;
    for (int i = 0; i < 20; i++) {
        scanf("%s %lf %s", dump, &time, buff);
        if (buff[0] == 'P') continue;
        score = 'D' - buff[0] + 1;
        if (buff[1] == '+') score += 0.5;
        if (buff[0] == 'F') score = 0;
        np += time;
        total += time * score;
    }
    printf("%.9f", total / np);
    return 0;
}