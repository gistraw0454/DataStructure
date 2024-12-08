#include <iostream>

class DateType{
public:
    void Initialize(int newMonth,int newDay, int newYear);
    int YearIs() const;
    int MonthIs() const;
    int DayIs() const;
private:
    int year;
    int month;
    int day;
};