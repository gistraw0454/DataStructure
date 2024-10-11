#include "unsorted.h"

void UnsortedType::UnsortedType(){
    length=0;
}

int UnsortedType::GetLength() const{
    return length;
}

bool UnsortedType::IsFull() const{
    return (length == MAX_ITEMS);
}

ItemType UnsortedType::GetItem(ItemType item, bool& found){
    bool moreToSearch;
    int location=0;

    found = false;  //찾았나?
    moreToSearch = (location < length)  //다돌았나?
    while (moreToSearch && !found){ // 아직 다 안돌 && 찾지못함
        switch (item.ComparedTo(info[location])){   // 찾는값과 위치값 비교
            case LESS:
            case GREATER:
                location++;
                moreToSearch = (location < length);
                break;
            case EQUAL:
                found = true;
                item = info[location];
                break;
        }
    }
    return item;
}

void UnsortedType::PutItem(ItemType item){
    info[length] = item;    //마지막에 넣어주기
    length++;   //길이 1늘려주기
}

void UnsortedType::DeleteItem(ItemType item){
    int location =0;    //위치 0부터시작해서 쭉 돌면서, 입력값과 같은값을 찾는다.
    while(item.ComparedTo(info[location])!=EQUAL) location++;
    info[location] = info[length-1];    //발견하면 나오게됨. => 이 위치에 배열의마지막값을 넣는다.
    length--;   //길이를 1줄여준다.
}

void UnsortedType::MakeEmpty(){
    length =0;
}

void UnsortedType::ResetList(){
    currentPos = -1;   
}

ItemType UnsortedType::GetNextItem(){
    currentPos++;   //다음위치로 이동
    ItemType item = info[currentPos];    // 현재 위치에 있는 item을 return 
    return item;
}