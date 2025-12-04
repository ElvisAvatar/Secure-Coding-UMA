#include <stdio.h>

float computeFare(int dayType, int boardTime, int distance)
{
    float basicFare = 3.4;
    if (distance > 1000)
    {
        for(int i = 1000; i < distance || i < 10200; i+=400)
        {
            basicFare+=0.22;
        }
    }
    if (distance > 10200)
    {
        for(int i = 10200; i < distance; i+=350)
        {
            basicFare+=0.22;
        }
    }

    float suplement = 0;

    if (dayType == 0 || (dayType == 1 && (boardTime <= 360 || boardTime >= 569)))
    {
        if (boardTime <= 359)
        {
            suplement = 0.50*basicFare;

        }else if (boardTime <= 1439)
            {
                suplement = 0.25*basicFare;
            }
    } else
        {
            suplement = 0.25*basicFare;
        }

    return basicFare+suplement;
}

int main()
{
    int dayType, boardHour, boardMin, distance;
    printf("Are you travelling on holydays/weekends or work days? (0 or 1): ");
        scanf(" %d", &dayType);

    printf("What time are you travelling? (hour and minutes): ");
        scanf(" %d %d", &boardHour, &boardMin);

    printf("Trip distance (mts): ");
        scanf(" %d", &distance);

    int boardTime = (boardHour*60)+boardMin;

    float Fare = computeFare(dayType, boardTime, distance);
    printf("Your fare is $ %lg\n", Fare);
}
