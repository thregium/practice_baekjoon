#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 주사위가 눈이 몇 개인 상태인지 구한다. 단, 주사위의 눈이 알맞지 않은 상태라면 unknown을 출력한다.

해결 방법 : 각 눈마다 나올 수 있는 상태를 미리 저장하고 주사위의 눈이 어느것과 같은지 구한다.
같은 것이 없다면 unknown을 출력한다.

주요 알고리즘 : 구현, 문자열

출처 : CTU 2018 D번
*/

char s[16], buff[8];
char* dice[9] = { "::::o::::", "o:::::::o", "::o:::o::", "o:::o:::o", "::o:o:o::", "o:o:::o:o", "o:o:o:o:o", "ooo:::ooo", "o:oo:oo:o" };
int dn[9] = { 1, 2, 2, 3, 3, 4, 5, 6, 6 };

int main(void) {
    for (int i = 0; i < 3; i++) {
        scanf("%s", buff);
        strcat(s, buff);
    }
    for (int i = 0; i < 9; i++) {
        if (!strcmp(s, dice[i])) {
            printf("%d", dn[i]);
            return 0;
        }
    }
    printf("unknown");
    return 0;
}