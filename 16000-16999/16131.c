#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)명의 학생에게 기숙사가 배정되어 있다. 각 사람의 기숙사를 문제에 주어진 조건대로
매 주마다 상점과 벌점의 값에 따라 바꾼다. 이때, 1번 학생과 A번 학생의 기숙사 위치 차이가
B 이하인 주의 개수와 그러한 주의 최대 연속 값을 각각 구한다.

해결 방법 : 문제에 주어진 것들을 구현한다. 상당히 복잡하므로 주의한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 서울과고 2018_01 B번
*/

int score[128], dorm[128], stu[128]; //score: 학생의 점수, dorm: x번 방의 학생 번호, stu: 학생의 방 번호

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, a, b, m, tmp, con = 0, conr = 0, cnt = 0; //con: 현재 연속값, conr: 연속 최댓값, cnt: 횟수
    scanf("%d %d %d %d", &n, &a, &b, &m);
    for (int i = 1; i <= n; i++) {
        dorm[i] = i;
        stu[i] = i;
    }
    if (abs(stu[a] - stu[1]) <= b) {
        cnt++;
        con = 1;
        conr = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &score[j]);
        }
        for (int j = 1; j <= n; j++) {
            scanf("%d", &tmp);
            score[j] -= tmp; //점수만 보면 되므로 상점 - 벌점을 함
        }

        for (int j = 1; j < n; j++) {
            //1번부터 N번까지 방을 차례로 살펴봄
            if ((score[dorm[j]] >= 0 && score[dorm[j + 1]] >= 0 && score[dorm[j + 1]] - score[dorm[j]] >= 2)
                || (score[dorm[j]] < 0 && score[dorm[j + 1]] < 0 && score[dorm[j + 1]] - score[dorm[j]] >= 4)
                || (score[dorm[j]] < 0 && score[dorm[j + 1]] >= 0)) {
                //둘다 양수인 경우 2점차, 둘다 음수인 경우 4점차, 음/양인 경우 항상 방을 바꿈
                score[dorm[j]] += 2;
                score[dorm[j + 1]] -= 2; //두 명의 점수 변동 기록

                swap(&dorm[j], &dorm[j + 1]); //두 기숙사의 학생을 바꿈
                swap(&stu[dorm[j]], &stu[dorm[j + 1]]); //두 학생의 기숙사를 바꿈
            }
        }

        if (abs(stu[a] - stu[1]) <= b) {
            //두 명의 방 번호 차이가 B 이하인 경우
            cnt++;
            con++;
            if (con > conr) conr = con; //최대 연속치를 갱신
        }
        else con = 0; //연속치를 0으로 바꿈
    }
    printf("%d %d", cnt, conr);
    return 0;
}