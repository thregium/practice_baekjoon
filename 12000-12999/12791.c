#include <stdio.h>

/*
���� : �������� �ٹ����� �־��� ��, S��� E�� ���� ���� �ٹ���� �߸� ������ ������� ����Ѵ�.

�ذ� ��� : �ٹ��� �̸��� �߸� ������ ������������ �ϵ��ڵ��ϰ� �� ���� �ִ� �ٹ����� Ȯ���ؼ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��ó��

��ó : CoderH 2016O B��
*/

char* album[] = { "DavidBowie", "SpaceOddity", "TheManWhoSoldTheWorld", "HunkyDory",
"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars", "AladdinSane", "PinUps", "DiamondDogs", "YoungAmericans",
"StationToStation", "Low", "Heroes", "Lodger", "ScaryMonstersAndSuperCreeps", "LetsDance", "Tonight",
"NeverLetMeDown", "BlackTieWhiteNoise", "1.Outside", "Earthling", "Hours", "Heathen", "Reality", "TheNextDay", "BlackStar" };

int albumy[] = { 1967, 1969, 1970, 1971, 1972, 1973, 1973, 1974, 1975, 1976, 1977, 1977, 1979, 1980,
1983, 1984, 1987, 1993, 1995, 1997, 1999, 2002, 2003, 2013, 2016 };

int main(void) {
    int q, s, e, r;
    scanf("%d", &q);
    for (int qq = 0; qq < q; qq++) {
        scanf("%d %d", &s, &e);
        r = 0;
        for (int j = 0; j < 25; j++) {
            if (albumy[j] <= e && albumy[j] >= s) r++;
        }
        printf("%d\n", r);
        for (int i = 0; i < 25; i++) {
            if (albumy[i] <= e && albumy[i] >= s) {
                printf("%d %s\n", albumy[i], album[i]);
            }
        }
    }
    return 0;
}