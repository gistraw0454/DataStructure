#include "datetype.h"

void DateType :: Initialize(int newMonth,int newDay, int newYear){
    year = newYear;
    month = newMonth;
    day = newDay;
}

int DateType :: MonthIs() const{
    return month;
}
int DateType :: DayIs() const{
    return day;
}
int DateType :: YearIs() const{
    return year;
}