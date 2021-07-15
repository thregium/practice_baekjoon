#include <stdio.h>
#include <string.h>

/*
���� : �־��� ��¥�� �ð�, ä�� ��ȣ, �ð��� �־��� ��, �̸� ä�� �ڵ�� �����Ѵ�. (���� ����)

�ذ� ��� : ���ؿ� �°� �����Ѵ�. �Ľ̿� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����, ��Ʈ����ŷ

��ó : MidC 1994 6��
*/

char month[16], ap[4], dump[16];
char* monthes[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main(void) {
    long long chan, year, mon, day, hour, min, time, len, cnt = 0;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1994\\problem6.in", "r", stdin);
    while (scanf("%s %lld, %s %lld %lld, %lld:%lld%s %lld%s\n", dump, &chan, month, &day, &year, &hour, &min, ap, &len, dump) != EOF) {
        if (cnt) printf("\n");
        mon = 0;
        for (int i = 1; i <= 12; i++) {
            if (!strcmp(month, monthes[i])) mon = i;
        }
        if (ap[0] == 'a') time = 0;
        else time = 24;
        time += hour * 2 + !!min;
        if (hour == 12) time -= 24;
        printf("%lld", ((year - 1994) << 25) + (chan << 19) + (mon << 15) + (day << 10) + (time << 4) + len / 30);
        cnt++;
    }
    return 0;
}