#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 100000)명의 사람 중 조건(성별, 거리(<= 20000))에 맞는 사람의 이름을 사전순으로 출력한다.
모든 사람의 이름은 10자 이하의 알파벳으로 주어진다.

해결 방법 : 모든 사람들을 살펴보면서 조건에 맞는 지 확인한다.
그러면서 조건에 맞는 사람의 이름들을 배열에 저장해 나간다.
그 다음, 배열에 있는 이름을 정렬하고 출력하면 된다.

주요 알고리즘 : 구현, 정렬, 문자열

출처 : 한양대 5회 BB번
*/

char buff1[16], buff2[16], res[103000][16];

int main(void) {
    int n, l, rp = 0, p = 0, x;
    scanf("%s %s %d", buff1, buff2, &l);
    if (strlen(buff2) == 2) p = 3;
    else if (buff2[0] == 'M') p = 1;
    else p = 2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", buff1, buff2, &x);
        if (((buff2[0] == 'M' && ((p & 1) == 1)) || (buff2[0] == 'F' && ((p & 2) == 2))) && x <= l) {
            strcpy(res[rp++], buff1);
        }
    }
    qsort(res, rp, sizeof(char) * 16, strcmp);
    for (int i = 0; i < rp; i++) {
        printf("%s\n", res[i]);
    }
    if (rp == 0) printf("No one yet");
    return 0;
}