#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 길이 1000 이하의 문자열로 두 트리가 주어진다. (왼쪽 정점)[정수](오른쪽 정점)의 형태로 주어지고,
각 정수는 모두 0 이상 1000 이하로 주어진다. 이때, 두 트리를 합친 결과물을 주어진 형태의 문자열과
같은 방식으로 출력한다. 트리를 합칠 때에는 양쪽 모두 정점이 있으면 두 정점에 쓰인 정수의 합으로
해당 정점을 만들고, 하나라도 없다면 만들지 않는다. 부모 정점이 없다면 자식 정점도 없다.

해결 방법 : 괄호 깊이가 0인 곳의 정수를 찾아서 strtoll() 함수로 정수를 확인한 다음 양 옆으로 범위를 좁혀가며
두 트리를 만들어 나간다. 그 다음 트리를 중위 순회하면서 트리를 합치고 출력해 나가면 된다.

주요 알고리즘 : 문자열, 파싱, 트리, 구현

출처 : JAG 2016DA C번
*/

typedef struct node {
    int n;
    struct node* l, *r;
} node;

char buff[1024];
node* ta, *tb;

void mktree(node* nd, int st, int ed) {
    int par = 0;
    for (int i = st; i <= ed; i++) {
        if (buff[i] == '(') par++;
        else if (buff[i] == ')') par--;
        else if (buff[i] == '[' && par == 0) {
            nd->n = strtoll(&buff[i + 1], NULL, 10);
            if (i - 2 > st) {
                nd->l = calloc(1, sizeof(node));
                mktree(nd->l, st + 1, i - 2);
            }
        }
        else if (buff[i] == ']' && par == 0) {
            if (i + 2 < ed) {
                nd->r = calloc(1, sizeof(node));
                mktree(nd->r, i + 2, ed - 1);
            }
        }
    }
}

void mergetree(node* na, node* nb) {
    if (na->l && nb->l) {
        printf("(");
        mergetree(na->l, nb->l);
        printf(")");
    }
    else printf("()");
    sprintf(buff, "[%d]", na->n + nb->n);
    printf("%s", buff);
    if (na->r && nb->r) {
        printf("(");
        mergetree(na->r, nb->r);
        printf(")");
    }
    else printf("()");
}

int main(void) {
    ta = calloc(1, sizeof(node));
    tb = calloc(1, sizeof(node));
    scanf("%s", buff);
    mktree(ta, 0, strlen(buff) - 1);
    scanf("%s", buff);
    mktree(tb, 0, strlen(buff) - 1);
    mergetree(ta, tb);
    printf("\n");
    return 0;
}