#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
문제 : 길이 N(N <= 100000)의 문자열과 M(M <= 500000)개의 커서 이동, 문자 삽입, 삭제 명령들이 주어질 때,
모든 명령 수행 후 문자열의 상태를 출력한다.

해결 방법 : 이중 연결 리스트를 통해 포인터 위치 이동, 삽입, 삭제 명령을 구현한다.

주요 알고리즘 : 자료구조, 연결 리스트

출처 : CHCI 2004 N1J 2번
*/

typedef struct llst {
	char c;
	struct llst* l;
	struct llst* r;
} llst;

char s[655360], st[2];
llst* sl;

int main(void) {
	int m, len;
	scanf("%s", s);
	len = strlen(s);
	llst* nl = calloc(1, sizeof(llst));
	nl->c = s[0];
	sl = nl;
	llst* cur = nl;
	for (int i = 1; i <= len; i++) {
		nl = calloc(1, sizeof(llst));
		nl->c = s[i];
		nl->l = cur;
		cur->r = nl;
		cur = nl;
	}
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", st);
		if (st[0] == 'P') {
			//문자 삽입
			scanf("%s", st);
			nl = calloc(1, sizeof(llst));
			nl->c = st[0];
			nl->l = cur->l;
			nl->r = cur;
			if (cur->l) cur->l->r = nl; //맨 앞이었던 경우
			else sl = nl;
			cur->l = nl;
		}
		else if (st[0] == 'L') {
			//왼쪽 이동
			if (cur->l) cur = cur->l;
		}
		else if (st[0] == 'D') {
			//오른쪽 이동
			if (cur->r) cur = cur->r;
		}
		else if (st[0] == 'B') {
			//문자 삭제
			if (!(cur->l)) continue; //맨 앞인 경우 무시
			if (cur->l->l) {
				cur->l->l->r = cur;
				cur->l = cur->l->l;
			}
			else {
				cur->l = NULL; //맨 앞이 된 경우
				sl = cur;
			}
		}
	}

	for (llst* i = sl; i->c; i = i->r) {
		printf("%c", i->c);
	}
	return 0;
}
