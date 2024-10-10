#include "datetype.cpp"
//dateType 멤버함수 구현이 필요하다.
using namespace std;

int main(){
    DateType startDate;
    DateType endDate;
    bool retired = false;
    startDate.Initialize(6,30,1998);
    endDate.Initialize(10,31,2002);
    cout << startDate.MonthIs() <<"/"<<startDate.DayIs()<<"/"<<startDate.YearIs()<<endl;
    while(!retired){
        //...
    }
}