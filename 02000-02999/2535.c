#include <stdio.h>
#include <stdlib.h>

/*
문제 : 여러 국가들에서 N(3 <= N <= 100)명이 대회에 참가했다. 각 사람의 점수를 통해 상위 3명에게 메달을 수여하는데,
한 국가에서 3개의 메달 모두를 독식할 수는 없다고 한다. 이때, 메달을 받는 사람을 점수가 높은 사람부터 출력한다.
동점자는 나오지 않고 점수의 범위는 1000 이하의 음이 아닌 정수이다.

해결 방법 : N명의 국적과 번호, 점수를 입력받은 다음, 점수를 기준으로 내림차순으로 정렬한다.
그 다음, 상위 2명에게 메달을 수여한다. 만약 2명의 국적이 다르다면 그대로 3위에게 메달을 주고 끝내면 되고,
같다면 3위부터 차례로 아래로 내려가며 둘과 국적이 다른 첫 사람에게 메달을 주면 된다.

주요 알고리즘 : 구현, 정렬

출처 : 정올 2012지 고1번
*/

int stu[128][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &stu[i][1], &stu[i][2], &stu[i][0]);
    }
    qsort(stu, n, sizeof(int) * 3, cmp1);
    printf("%d %d\n%d %d\n", stu[0][1], stu[0][2], stu[1][1], stu[1][2]);
    if (stu[1][1] != stu[0][1]) {
        printf("%d %d", stu[2][1], stu[2][2]);
        return 0;
    }
    else {
        for (int i = 2; i < n; i++) {
            if (stu[i][1] != stu[0][1] && stu[i][1] != stu[1][1]) {
                printf("%d %d", stu[i][1], stu[i][2]);
                return 0;
            }
        }
    }
    return 1;
}