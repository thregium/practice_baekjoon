#include <stdio.h>

/*
문제 : N(N <= 26)개의 논증이 주어질 때, M(M <= 10)개의 논증마다 확실히 참인지 여부를 출력한다.

해결 방법 : 각 논증을 간선으로 보고, 플로이드-워셜 알고리즘을 돌린다. 만약 각 논증이 간선이 있다면
참이고, 없다면 거짓이 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : 중앙대 2018R 5번
*/

int chk[32][32];

int main(void) {
    int n;
    char c1, c2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c is %c", &c1, &c2);
        chk[c1 - 'a'][c2 - 'a'] = 1;
    }
    
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (chk[i][k] && chk[k][j]) chk[i][j] = 1;
            }
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c is %c", &c1, &c2);
        printf("%c\n", chk[c1 - 'a'][c2 - 'a'] ? 'T' : 'F');
    }
    return 0;
}