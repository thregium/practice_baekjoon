#include <stdio.h>
#include <malloc.h>

/*
문제 : N(N <= 100000)개의 동전 목록이 동전 - 연속한 개수의 형태로 주어진다. 앞에서부터 최초로 나오는
연속 3개의 동일한 동전을 제거하고 목록의 맨 뒤에 그 동전 1개를 추가해 나갈 때,
최종적으로 남는 동전의 개수를 구한다.

해결 방법 : 연결 리스트를 이용해 앞에서부터 동전들을 확인해 나가면서 맨 뒤에 동전들을 추가해 나가기를
반복한다. 앞뒤 동전이 합쳐지는 경우에 주의한다.

주요 알고리즘 : 자료 구조, 연결 리스트

출처 : TOPC 2017 D번
*/

typedef struct coin {
    char type;
    long long len;
    struct coin* prev, *next;
} coin;

coin* clist;

void removenode(coin* node, coin** front, coin** back) {
    if (node->prev && node->next) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if (node->prev->type == node->next->type) {
            node->prev->next = node->next->next;
            if (node->next->next) node->next->next->prev = node->prev;
            node->prev->len += node->next->len;
            free(node->next);
        }
    }
    else if (node->prev) {
        *back = node->prev;
        node->prev->next = NULL;
    }
    else if (node->next) {
        *front = node->next;
        node->next->prev = NULL;
    }
    else {
        *front = NULL;
        *back = NULL;
    }
    free(node);
}

int main(void) {
    int t, n;
    long long res;
    coin* front, *back;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Taiwan\\2017\\problems\\testdata\\final\\PD.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        front = calloc(1, sizeof(coin));
        back = front;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c %lld", &(back->type), &(back->len));
            if (i < n - 1) {
                back->next = calloc(1, sizeof(coin));
                back->next->prev = back;
                back = back->next;
            }
        }
        res = 0;
        for (coin* seeing = front; seeing;) {
            if (seeing->len >= 3) {
                res += seeing->len / 3;
                if (seeing->type == back->type) back->len += seeing->len / 3;
                else {
                    back->next = calloc(1, sizeof(coin));
                    back->next->prev = back;
                    back = back->next;
                    back->len = seeing->len / 3;
                    back->type = seeing->type;
                }
                seeing->len %= 3;
                if (seeing->len == 0) {
                    if (seeing->prev) {
                        seeing = seeing->prev;
                        removenode(seeing->next, &front, &back);
                    }
                    else if (seeing->next) {
                        seeing = seeing->next;
                        removenode(seeing->prev, &front, &back);
                    }
                    else break;
                }
                else seeing = seeing->next;
            }
            else seeing = seeing->next;
        }

        res = 0;
        for (coin* seeing = front; seeing; seeing = seeing->next) {
            res += seeing->len;
            if (seeing->prev) free(seeing->prev);
        }
        free(back);
        printf("%lld\n", res);
    }
    return 0;
}