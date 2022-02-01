#include <stdio.h>
#define INF 1012345678

/*
문제 : 전자레인지에 4개의 버튼이 있다. 하나는 10초, 하나는 1분, 하나는 10분이다. 이 버튼들은
조리 중인지 여부에 관계 없이 해당 시간만큼 조리시간이 늘어난다. 마지막 하나는 조리 시작 버튼으로,
0초일 때 또는 조리중일 때 누르면 30초가 추가되고, 조리중이 아닐 때 누르면 조리가 시작된다.
이때, 원하는 조리 시간(10초 단위, 60분 이내, 10초 이상)이 주어지면 해당 조리 시간을 맞추기 위해
눌러야 하는 버튼의 최소 횟수를 구한다.

해결 방법 : 각 시간 단위와 조리 중인지 여부를 변수로 두고 최소 버튼 횟수를 다이나믹 프로그래밍으로
구해나간다. 조리 시작 버튼에서 30초 추가되는 경우에 유의한다.

주요 알고리즘 : DP

출처 : 중앙대 2022 D번
*/

int mem[2][4096];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int m, s;
    for (int i = 0; i < 4096; i++) {
        mem[0][i] = INF;
        mem[1][i] = INF;
    }
    mem[0][0] = 0;
    mem[1][30] = 1;
    for (int i = 0; i <= 3600; i++) {
        mem[1][i] = small(mem[1][i], mem[0][i] + 1);
        mem[0][i + 10] = small(mem[0][i + 10], mem[0][i] + 1);
        mem[0][i + 60] = small(mem[0][i + 60], mem[0][i] + 1);
        if (i <= 3000) mem[0][i + 600] = small(mem[0][i + 600], mem[0][i] + 1);
    }
    for (int i = 0; i <= 3600; i++) {
        mem[1][i + 10] = small(mem[1][i + 10], mem[1][i] + 1);
        mem[1][i + 30] = small(mem[1][i + 30], mem[1][i] + 1);
        mem[1][i + 60] = small(mem[1][i + 60], mem[1][i] + 1);
        if (i <= 3000) mem[1][i + 600] = small(mem[1][i + 600], mem[1][i] + 1);
    }
    scanf("%d:%d", &m, &s);
    printf("%d", mem[1][m * 60 + s]);
    return 0;
}