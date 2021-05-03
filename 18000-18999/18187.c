#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 1000) ������ �� ���ڷ� �̷���� �� ���ڿ��� �־��� ��, �� ���ڿ��� �Ʒ� ���ڿ��� �Ȱ��� ����� ���� �ʿ��� ���� ������ ������ �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : ����, �Ʒ��� ���ڿ����� Ư���� ���ڰ� ���� �� ���� ���ڿ��� �����´�.
Ư���� ������ ���ڿ��� ������ ��, ��� ���ڰ� �����ϰ� �̷���� ���ӵ� ������ �κ��̶�� �Ѵٸ� �� �κ��� ������ ���� 2 �κ��� ���� �� �ִ�.
����, �κ��� ���� ���� ����� ���ؼ��� �ּ��� (�κ��� ��) / 2���� ������ ������ �ʿ��ϴ�.

�ֿ� �˰��� : �׸��� �˰���, ���ڿ�

��ó : USACO 2020F B2��
*/

char s[1024], s2[1024];

int main(void) {
	FILE* fi = stdin;
	FILE* fo = stdout;
	if (FOUT) {
		fi = fopen("breedflip.in", "r");
		fo = fopen("breedflip.out", "w");
	}
	int n, r = 0;
	scanf("%d", &n);
	scanf("%s%s", s, s2);
	for (int i = 0; i < n; i++) {
		if (s2[i] == 'H') {
			if (s[i] == 'G') s[i] = 'H';
			else s[i] = 'G';
		}
	}
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) r++;
	}
	printf("%d", (r + 1) >> 1);
	return 0;
}