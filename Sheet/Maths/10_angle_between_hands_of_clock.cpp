#include <bits/stdc++.h>
using namespace std;

double angleClock(int hour, int minutes)
{
    if (hour == 12)
        hour = 0;
    double h = (hour + (double)minutes / 60) * 5;
    double angle_min = min(abs(h - minutes), 60 - abs(h - minutes));
    return 6 * angle_min;
}