#include <stdio.h>

/*
문제 : L초 길이의 음악을 N회 듣는다. 각 음악 사이에는 5초간의 공백이 존재한다. 이때, D초마다 전화벨이 울리는데,
공백인 시간 또는 음악이 끝난 후에만 들을 수 있다. 가장 일찍 전화벨을 들을 수 있는 시각을 구한다.

해결 방법 : 0초부터 차례로 시간을 늘려가며 전화벨이 들리는 시각을 찾는다. 시작과 끝 처리에 유의한다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n, l, d, t = 0;
    scanf("%d %d %d", &n, &l, &d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            t++;
        }
        if (i == n - 1) break;
        for (int j = 0; j < 5; j++) {
            if (t % d == 0) {
                printf("%d", t);
                return 0;
            }
            t++;
        }
    }
    while (t % d) t++;
    printf("%d", t);
    return 0;
}