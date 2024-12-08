#include <iostream>
void findAverages(const int stateHighs[][12],int stateAverages[]){
    int state;
    float total;
    int month;
    
    for (state =0; state <12;state++){
        total = 0.0;
        for (month=0; month<12;month++){
            total = total + stateHighs [state][month];
        }

        stateAverages[state] = (total/12.0 +0.5);
    }
}

// 배열로 타입정의도 가능
// typedef int StateHighsType [ NUM_STATES ][ NUM_MONTHS ];
// typedef float StateAveragesType [ NUM_STATES ];
// void findAverages( const StateHighsType stateHighs, StateAveragesType stateAverages )

// 다차원배열도 가능
// typedef long MonthlySalesType [NUM_DEPTS] [NUM_MONTHS] [NUM_STORES];
// MonthlySalesType monthlySales;
