#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)개의 문자열로 이루어진 배열이 주어진다. S(S <= 5000)개의 쿼리에 응답한다.
insert. i번째에 주어진 문자열을 삽입한다.
depart. 주어진 문자열을 배열에서 제거한다.
relocate. 주어진 문자열의 위치를 i칸 오른쪽으로 옮긴다(음수인 경우 절댓값만큼 왼쪽으로)
모든 문자열은 서로 다르며, 10자 이하의 소문자 또는 숫자로 이루어져 있다.

해결 방법 : N과 S가 적기 때문에 직접 문자열의 이동을 시뮬레이션한다. 1칸씩 직접 문자열을
밀고 당기는 작업을 하더라도 시간 제한 내에 충분히 돌아간다.

주요 알고리즘 : 구현, 문자열, 시뮬레이션

출처 : Tehran 2020 H번
*/

char bird[8192][16], op[16], bn[16];

int main(void) {
    int n, s, p, d;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%s", bird[i]);
    }
    for (int ss = 0; ss < s; ss++) {
        scanf("%s %s", op, bn);
        if (!strcmp(op, "insert")) {
            scanf("%d", &p);
            for (int i = n; i > p; i--) strcpy(bird[i], bird[i - 1]);
            strcpy(bird[p], bn);
            n++;
        }
        else if (!strcmp(op, "depart")) {
            p = -1;
            for (int i = 0; i < n; i++) {
                if (!strcmp(bn, bird[i])) {
                    p = i;
                    break;
                }
            }
            if (p < 0) return 21;
            for (int i = p; i < n - 1; i++) strcpy(bird[i], bird[i + 1]);
            n--;
        }
        else if (!strcmp(op, "relocate")) {
            scanf("%d", &d);
            p = -1;
            for (int i = 0; i < n; i++) {
                if (!strcmp(bn, bird[i])) {
                    p = i;
                    break;
                }
            }
            if (p + d < 0 || p + d >= n) return 31;
            if (d > 0) {
                for (int i = p; i < p + d; i++) strcpy(bird[i], bird[i + 1]);
                strcpy(bird[p + d], bn);
            }
            else if (d < 0) {
                for (int i = p; i > p + d; i--) strcpy(bird[i], bird[i - 1]);
                strcpy(bird[p + d], bn);
            }
        }
        else return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%s ", bird[i]);
    }
    return 0;
}