#include <stdio.h>

/*
문제 : 1000 이하의 두 수가 주어질 때, 각 수를 뒤집어서 더한 후, 더한 수를 다시 뒤집어 출력한다.

해결 방법 : 문제에서 주어진대로 구현한다.

주요 알고리즘 : 구현
*/

int main(void) {
	int x, y, z;
	scanf("%d %d", &x, &y);
    if(x == 1000) x = 1;
	if(x >= 100) x = x / 100 + x / 10 % 10 * 10 + x % 10 * 100;
	else if(x >= 10) x = x / 10 + x % 10 * 10;
    if(y == 1000) y = 1;
	if(y >= 100) y = y / 100 + y / 10 % 10 * 10 + y % 10 * 100;
	else if(y >= 10) y = y / 10 + y % 10 * 10;
	z = x + y;
	if(z >= 1000) z = z / 1000 + z / 100 % 10 * 10 + z / 10 % 10 * 100 + z % 10 * 1000;
	else if(z >= 100) z = z / 100 + z / 10 % 10 * 10 + z % 10 * 100;
	else if(z >= 10) z = z / 10 + z % 10 * 10;
	printf("%d", z);
	return 0;
}