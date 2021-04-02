#include <stdio.h>
#include <string.h>
#include <malloc.h>

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
			scanf("%s", st);
			nl = calloc(1, sizeof(llst));
			nl->c = st[0];
			nl->l = cur->l;
			nl->r = cur;
			if (cur->l) cur->l->r = nl;
			else sl = nl;
			cur->l = nl;
		}
		else if (st[0] == 'L') {
			if (cur->l) cur = cur->l;
		}
		else if (st[0] == 'D') {
			if (cur->r) cur = cur->r;
		}
		else if (st[0] == 'B') {
			if (!(cur->l)) continue;
			if (cur->l->l) {
				cur->l->l->r = cur;
				cur->l = cur->l->l;
			}
			else {
				cur->l = NULL;
				sl = cur;
			}
		}
	}

	for (llst* i = sl; i->c; i = i->r) {
		printf("%c", i->c);
	}
	return 0;
}
