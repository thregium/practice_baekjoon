#include <stdio.h>
#include <string.h>

/*
문제 : 반지름이 P인 원형 판으로 바깥 반지름이 각각 A, B이고 안쪽 반지름이 각각 a, b인 고리를 자를 수 있는지 구한다.

해결 방법 : 고리를 자르는 경우는 한 고리가 다른 고리 안쪽에 들어가거나 두 고리가 서로 독립적으로 있는 경우로 나뉜다.
먼저 첫 번째 경우는, 큰 고리의 안쪽 반지름이 작은 고리의 바깥 반지름보다 크거나 같아야 하고,
큰 고리의 바깥 반지름이 판의 반지름보다는 작아야 한다.
두 번째 경우는 두 고리의 반지름의 합이 판의 반지름의 합 이하여야 한다.

주요 알고리즘 : 기하학

출처 : NWRRC 2006 H번
*/

char dir[128] = "E:\\PS\\ICPC\\Northern Eurasia\\North&West\\2006\\tests\\halloween\\tests\\";
char buff[32];

int main(void) {
    int ao, ai, bo, bi, p;
    /*
    for (int i = 1; i <= 56; i++) {
        dir[66] = i / 10 + '0';
        dir[67] = i % 10 + '0';
        dir[68] = '\0';
        freopen(dir, "r", stdin);
        */
        scanf("%d %d %d %d %d", &ao, &ai, &bo, &bi, &p);
        if (ao <= bi && bo <= p) printf("Yes");
        else if (ai >= bo && ao <= p) printf("Yes");
        else if (ao + bo <= p) printf("Yes");
        else printf("No");
        /*
        dir[68] = '.';
        dir[69] = 'a';
        freopen(dir, "r", stdin);
        scanf("%s", buff);
        printf(" : %s\n", buff);
    }
    */
    return 0;
}