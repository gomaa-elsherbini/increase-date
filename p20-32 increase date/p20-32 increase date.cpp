#include <iostream>
#include <ctime>
using namespace std;



enum enInterval{OneDay, TenDays, OneWeek, TenWeeks, OneMonth, FiveMonths, OneYear, TenYears, OneDecade, TenDecades, OneCentury, OneMelinium};
struct stDate
{
    short day;
    short month;
    short year;
};

short readNumber(string msg)
{
    short num;

    cout << msg;
    cin >> num;

    return num;
}

stDate readStDate()
{
    stDate Date;

    Date.day = readNumber("Please Enter a Day ");
    Date.month = readNumber("Please Enter a Month ");
    Date.year = readNumber("Please Enter a Year ");

    return Date;
}

bool isLeapYear(short year)
{
    return (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)));
}

short numberOfDaysInMonth(short year, short month)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return  29;
        else
            return  28;
    }

    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return  31;

    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else
        return 0;
}

short numberOfDaysInYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}

bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
    //return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? ((Date1.month < Date2.month) ? true : ((Date1.month == Date2.month) ? ((Date1.day < Date2.day) ? true : false) : false)) : false);
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? (Date1.day < Date2.day) : false)) : false);
}

bool isDayIsLastDay(stDate Date)
{
    return Date.day == numberOfDaysInMonth(Date.year, Date.month);
}

bool isMonthIsLastMonth(stDate Date)
{
    return Date.month == 12;
}

stDate increaseDateByOneDay(stDate Date)
{
    if (isDayIsLastDay(Date))
    {
        if (isMonthIsLastMonth(Date))
        {
            Date.month = 1;
            Date.year++;
        }
        else
            Date.month++;

        Date.day = 1;
    }
    else
        Date.day++;

    return Date;
}

stDate increaseDateByXDays( stDate Date, short numberDays)
{
    short days = 0;
    while (days < numberDays)
    {
        Date = increaseDateByOneDay(Date);
        days++;
    }
    return Date;
}

stDate increaseDateByXWeeks( stDate Date, short numberWeeks)
{
    short weeks = 0;
    while (weeks < numberWeeks)
    {
        Date = increaseDateByXDays(Date, 7);
        weeks++;
    }
    return Date;
}

stDate increaseDateByXMonths(stDate Date, short numberMonths)
{
    short monthDays = 0;
    short months = 1;
    while (months <= numberMonths)
    {
        Date = increaseDateByXDays(Date, numberOfDaysInMonth(Date.year, Date.month));
        months++;
    }
    return Date;
}

stDate increaseDateByXYears(stDate Date, short numberYears)
{
    short years = 1;
    while (years <= numberYears)
    {
        Date = increaseDateByXDays(Date, numberOfDaysInYear(Date.year+1));
        years++;
    }
    return Date;
}

stDate increaseDateByXDecades(stDate Date, short numberDecades)
{
    short decades = 1;
    while (decades <= numberDecades)
    {
        Date = increaseDateByXYears(Date, 10);
        decades++;
    }
    return Date;
}

stDate increaseDateByOneCentury(stDate Date)
{
    return increaseDateByXDecades(Date, 10);
}

stDate increaseDateByOneMilinium(stDate Date)
{
    for(int i=1; i<=10; i++)
        Date = increaseDateByOneCentury(Date);
    return Date;
}




//int getInervalDays(enInterval interval, stDate Date)
//{
//    int days = 0;
//    switch (interval)
//    {
//    case OneDay:
//        days = 1;
//        break;
//    case TenDays:
//        days = 10;
//        break;
//    case OneWeek:
//        days = 7;
//        break;
//    case TenWeeks:
//        days = 70;
//        break;
//    case OneMonth:
//        days = numberOfDaysInMonth(Date.year, Date.month++);
//        break;
//    case FiveMonths:
//        for (short i = 1; i <= 5; i++)
//            days += numberOfDaysInMonth(Date.year, Date.month++);
//        break;
//    case OneYear:
//        days = numberOfDaysInYear(++Date.year);
//        break;
//    case TenYears:
//    case OneDecade:
//        for (short year = 1; year <= 10; year++)
//            days += numberOfDaysInYear(++Date.year);
//        break;
//    case TenDecades:
//    case OneCentury:
//        for (short year = 1; year <= 100; year++)
//            days += numberOfDaysInYear(Date.year++);
//        break;
//    case OneMelinium:
//        for (short i = 1; i <= 1000; i++)
//            days += numberOfDaysInYear(Date.year++);
//        break;
//    }
//    return days;
//}
//stDate increaseDate(stDate Date, enInterval interval)
//{
//    int days = getInervalDays(interval, Date);
//
//    int numberOfDays = 1;
//
//    while (numberOfDays <= days)
//    {
//        Date= increaseDateByOneDay(Date);
//        numberOfDays++;
//    }
//    return Date;
//}

int main()
{
    stDate Date1, Date2;

    cout << "\nPlease Enter your date1\n\n";
    Date1 = readStDate();
    cout << "\n";


    Date2 = increaseDateByXDays(Date1, 1);
    cout << "01- Adding One day is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXDays(Date2, 10);
    cout << "02- Adding 10 days is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXWeeks(Date2, 1);
    cout << "03- Adding One week is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXWeeks(Date2, 10);
    cout << "04- Adding Ten weeks is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXMonths(Date2, 1);
    cout << "05- Adding One Month is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXMonths(Date2, 5);
    cout << "06- Adding Five Months is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXYears(Date2, 1);
    cout << "07- Adding One Year is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXYears(Date2, 10);
    cout << "08- Adding Ten Years is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXDecades(Date2, 1);
    cout << "10- Adding One Decade is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByXDecades(Date2, 10);
    cout << "11- Adding Ten Decades is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;

    Date2 = increaseDateByOneCentury(Date2);
    cout << "13- Adding One Century is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;


    Date2 = increaseDateByOneMilinium(Date2);
    cout << "14- Adding One Melinium is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;


    /*Date2 = increaseDate(Date1, enInterval::OneDay);
    cout << "01- Adding One day is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenDays);
    cout << "02- Adding 10 days is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneWeek);
    cout << "03- Adding One week is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenWeeks);
    cout << "04- Adding Ten weeks is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneMonth);
    cout << "05- Adding One Month is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::FiveMonths);
    cout << "06- Adding Five Months is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneYear);
    cout << "07- Adding One Year is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenYears);
    cout << "08- Adding Ten Years is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenYears);
    cout << "09- Adding Ten Years (Faster) is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneDecade);
    cout << "10- Adding One Decade is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenDecades);
    cout << "11- Adding Ten Decades is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenDecades);
    cout << "12- Adding Ten Decades (faster) is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneCentury);
    cout << "13- Adding One Century is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneMelinium);
    cout << "14- Adding One Melinium is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;*/
    system("pause>0");
    return main();
}