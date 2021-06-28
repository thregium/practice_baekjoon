#include <stdio.h>

/*
문제 : 각 문제들에 대한 테스트 케이스의 답과 출력된 답이 주어질 때, 정답으로 체크되는지 여부를 구한다.

해결 방법 : 모든 답이 정답과 같다면 정답이고, 하나라도 아닌 것이 있다면 아니다.

주요 알고리즘 : 구현

출처 : 아주대 2018D1 A번 / 2018D2 A번
*/

int main(void) {
    int s1, s2, tc, ans;
    scanf("%d %d", &s1, &s2);
    for (int i = 0; i < s1; i++) {
        scanf("%d %d", &tc, &ans);
        if (tc != ans) {
            printf("Wrong Answer");
            return 0;
        }
    }
    for (int i = 0; i < s2; i++) {
        scanf("%d %d", &tc, &ans);
        if (tc != ans) {
            printf("Why Wrong!!!");
            return 0;
        }
    }
    printf("Accepted");
    return 0;
}