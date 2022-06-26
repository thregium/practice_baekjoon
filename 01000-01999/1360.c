#include <stdio.h>

/*
문제 : N(N <= 50)개의 문자열에 문자를 추가하거나 최근 임의 개수의 연산들을 되돌리는 연산이 주어지면,
이 연산의 결과로 나온 문자열을 출력한다.

해결 방법 : 기록을 역순으로 살펴보면서 되돌리는 연산이 나올 때 마다 되돌리기 전 마지막 연산으로 돌아간다.
문자를 추가하는 연산이 있다면 결과 배열의 끝에 추가한다.
이를 반복한 후 결과 배열을 역순으로 출력하면 된다.

주요 알고리즘 : 구현?

출처 : SRM 419D1 1번 / 419D2 2번
*/

typedef struct oper {
    int type;
    char c;
    int ct;
    int time;
} oper;

oper op[64];
char buff[8], res[64];
int rlen = 0;

int main(void) {
    int n, nxt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (buff[0] == 't') {
            op[i].type = 1;
            scanf(" %c %d", &op[i].c, &op[i].time);
        }
        else {
            op[i].type = 2;
            scanf("%d %d", &op[i].ct, &op[i].time);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (op[i].type == 1) res[rlen++] = op[i].c;
        else {
            nxt = i;
            for (int j = i - 1; j >= 0; j--) {
                if (op[j].time + op[i].ct >= op[i].time) nxt = j;
                else break;
            }
            i = nxt;
        }
    }
    for (int i = rlen - 1; i >= 0; i--) printf("%c", res[i]);
    return 0;
}