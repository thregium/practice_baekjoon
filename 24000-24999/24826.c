#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)의 배열에 목표 색상(<= N)들이 있다. 각 색의 테이프를 1개 이하씩 사용하여
배열 전체를 목표 색상으로 만들 수 있는 지 확인하고 가능한 경우 그 방법을 출력한다.
테이프는 연속해서 이어지고, 테이프 위에 테이프를 붙이면 밑의 테이프는 가려진다.

해결 방법 : 테이프의 색상은 스택 형태로 저장된다. 따라서, 스택 조건을 만족시키는 지 확인하고,
만족한다면 그 스택들을 순서대로 출력하면 된다.
스택에 각 테이프의 시작점과 색상을 저장한 다음, 새 색상이 나올 때 마다 나온 적 있는 값인 지 확인한다.
나온 적 있다면 스택의 맨 위 값이 그 색이 될 때 까지 스택에서 원소들을 꺼내고 결과 배열에 저장한다.
스택에 그러한 원소가 없다면 새로 그 색을 넣어야 한다는 의미이므로 조건을 만족시키지 못한다.
새로운 색상인 경우에는 스택에 그 테이프의 정보를 추가한다.
마지막으로 스택에 남은 원소들을 꺼내고 결과 배열에 저장하면 조건을 만족하는 경우
결과 배열의 역순으로 테이프들을 붙여 나가면 답이 된다.

주요 알고리즘 : 자료 구조, 스택, 구성적

출처 : VTH 2019 I번
*/

int c[103000], stk[103000][2], chk[103000], res[103000][3], sim[103000];
int top = 0;

int main(void) {
    int n, r = 0;
    //freopen("E:\\PS\\High School\\VTH\\2019\\reconstructingtapeart\\data\\secret\\028.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        if (chk[c[i]]) {
            while (top > 0 && stk[top - 1][0] != c[i]) {
                res[r][0] = stk[top - 1][1];
                res[r][1] = i - 1;
                res[r][2] = stk[top - 1][0];
                r++, top--;
            }
            if (top == 0) {
                printf("IMPOSSIBLE");
                return 0;
            }
        }
        else {
            stk[top][0] = c[i], stk[top][1] = i;
            top++;
            chk[c[i]] = 1;
        }
    }
    while (top > 0) {
        res[r][0] = stk[top - 1][1];
        res[r][1] = n;
        res[r][2] = stk[top - 1][0];
        r++, top--;
    }
    printf("%d\n", r);
    for (int i = r - 1; i >= 0; i--) {
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
        //for (int j = res[i][0]; j <= res[i][1]; j++) sim[j] = res[i][2];
    }
    /*
    for (int i = 1; i <= n; i++) {
        if (sim[i] != c[i]) {
            printf("ERROR! at %d(%d, %d)\n", i, c[i], sim[i]);
            return 1;
        }
    }
    */
    return 0;
}