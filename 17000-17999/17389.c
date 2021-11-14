#include <stdio.h>

/*
문제 : N(N <= 10000)개의 O와 X로 이루어진 문자열이 주어질 때, 이 문자열의 점수를 구한다.
매번 O가 나올 때 마다 그 O의 위치만큼 점수를 얻고, 앞에 연속해서 O가 있다면 그 개수만큼 보너스 점수를 얻는다.

해결 방법 : 점수와 보너스 점수를 0점에서 시작해서 각 문자를 확인한다. X인 경우 보너스를 0으로 초기화한다.
O인 경우 그 O의 위치에 보너스 점수만큼을 더한 값을 점수에 더하고 보너스를 1 추가한다.
모든 문자를 확인하면 점수를 출력한다.

주요 알고리즘 : 구현

출처 : 숭고한 2019 B번
*/

char buff[10240];

int main(void) {
    int n, r = 0, b = 0;
    scanf("%d", &n);
    scanf("%s", buff);
    for (int i = 0; i < n; i++) {
        if (buff[i] == 'X') b = 0;
        else if (buff[i] == 'O') {
            r += b + i + 1;
            b++;
        }
        else return 1;
    }
    printf("%d", r);
    return 0;
}