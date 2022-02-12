#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 500)개의 어셈블리 코드들 문제에 주어진 표를 이용하여 기계어 코드로 변환한다.

해결 방법 : opcode들과 번호를 미리 하드코딩한 다음 맞는 opcode를 확인하여 기계어로 출력한다.
각 변수(또는 상수)들은 명령어를 확인해가며 그에 맞게 출력하면 된다.

주요 알고리즘 : 구현

출처 : 충남대 2회 D번
*/

char buff[16];
char* opcode[] = { "ADD", "SUB", "MOV", "AND", "OR", "NOT", "MULT", "LSFTL",
"LSFTR", "ASFTR", "RL", "RR" };

int main(void) {
    int n, o, t, a, b, d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        o = -1;
        for (int j = 0; j < 12; j++) {
            t = 1;
            for (int k = 0; opcode[j][k]; k++) {
                if (buff[k] != opcode[j][k]) t = 0;
            }
            if (t) o = j;
        }
        if (o < 0) return 1;
        printf("%d%d%d%d", (o >> 3) & 1, (o >> 2) & 1, (o >> 1) & 1, o & 1);
        if (buff[strlen(buff) - 1] == 'C') {
            printf("10");
            scanf("%d %d %d", &d, &a, &b);
            printf("%d%d%d", (d >> 2) & 1, (d >> 1) & 1, d & 1);
            printf("%d%d%d", (a >> 2) & 1, (a >> 1) & 1, a & 1);
            printf("%d%d%d%d\n", (b >> 3) & 1, (b >> 2) & 1, (b >> 1) & 1, b & 1);
        }
        else {
            printf("00");
            scanf("%d %d %d", &d, &a, &b);
            printf("%d%d%d", (d >> 2) & 1, (d >> 1) & 1, d & 1);
            printf("%d%d%d", (a >> 2) & 1, (a >> 1) & 1, a & 1);
            printf("%d%d%d", (b >> 2) & 1, (b >> 1) & 1, b & 1);
            printf("0\n");
        }
    }
    return 0;
}