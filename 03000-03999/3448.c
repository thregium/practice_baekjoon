#include <stdio.h>
#include <string.h>

/*
문제 : 빈 줄이 나올 때 까지 입력받은 다음 '#'을 제외한 글자(개행 제외)의 비율을 % 단위로 구한다.
소수점 한 자리 단위로 출력하되, 그 값이 정수로 나누어 떨어지는 경우에는 정수로 출력한다.

해결 방법 : 각 줄을 fgets로 입력받고 첫 글자가 개행이 될 때 까지 각 글자들을 확인한다.
각 글자가 개행이 아닌 다른 문자라면 전체 글자의 수를 1 늘리고, '#'도 아니라면 인식한 글자의 수를 1 늘린다.
확인이 끝나면 출력하기 전에 sscanf()로 문자열에 단위를 소수점 한 자리로 출력한 다음
마지막 자리가 0이면 정수로 바꾸어 출력, 그 외에는 원래 하던 대로 소수점 한 자리로 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : CERC 2007 PC번
*/

char buff[128], res[32];

int main(void) {
    int t, a, o;
    scanf("%d", &t);
    getchar();
    for (int tt = 0; tt < t; tt++) {
        a = 0, o = 0;
        while (1) {
            fgets(buff, 120, stdin);
            if (buff[0] == '\n') break;
            for (int i = 0; buff[i]; i++) {
                if (buff[i] == '\n') break;
                a++;
                if (buff[i] != '#') o++;
            }
        }
        if (a == 0) return 1;
        sprintf(res, "%.1f", (double)o / a * 100);
        if (res[strlen(res) - 1] == '0') printf("Efficiency ratio is %.0f%%.\n", (double)o / a * 100);
        else printf("Efficiency ratio is %.1f%%.\n", (double)o / a * 100);
    }
    return 0;
}