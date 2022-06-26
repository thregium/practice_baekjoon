#include <stdio.h>

/*
문제 : 길이 N(N <= 10000)의 상대적인 음으로 이루어진 악보가 주어질 때,
흰색 건반만 치면서 악보를 연주하기 위한 시작음과 끝음의 가능한 모든 경우의 수를 구한다.

해결 방법 : 12칸마다 음이 반복된다는 것을 이용하여 12로 나눈 모듈로를 이용해 구현 가능하다.
각 시작점마다 흰색 건반만으로 악보를 칠 수 있는 지 확인하고 가능한 경우 시작음과 끝음을 출력하면 된다.

주요 알고리즘 : 수학, 정수론
*/

int score[10240];
const int white[7] = { 0, 2, 3, 5, 7, 8, 10 };
const int iswhite[12] = { 1, 0, 2, 3, 0, 4, 0, 5, 6, 0, 7, 0 };

int main(void) {
    int n, r, note;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
    }
    for (int i = 0; i < 7; i++) {
        note = white[i];
        r = 1;
        for (int j = 0; j < n; j++) {
            note += score[j] + 120;
            note %= 12;
            if (!iswhite[note % 12]) r = 0;
        }
        if (r) {
            printf("%c %c\n", i + 'A', iswhite[note] - 1 + 'A');
        }
    }
    return 0;
}