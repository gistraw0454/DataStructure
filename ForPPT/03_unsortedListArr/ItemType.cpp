#include "ItemType.h"
#include <iostream>

RelationType ItemType::ComparedTo(ItemType otherItem) const{
    if (value < otherItem.value) return LESS;
    else if (value > otherItem.value) return GREATER;
    else return EQUAL;
}

void ItemType::Print() const{
    using namespace std;
    cout << value << endl;
}

void ItemType::Initialize(int number){
    value = number;
}