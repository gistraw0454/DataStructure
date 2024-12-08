#include "unsorted.h"

UnsortedType::UnsortedType(){
    length =0;
    listData = NULL;
}

void UnsortedType::PutItem(ItemType item){
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = listData;

    listData = location;

    length++;
}

int UnsortedType::GetLength() const{
    return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found){
    bool moreToSearch;;
    NodeType* location;
    found = false;
    moreToSearch = (location != NULL);
    while(moreToSearch && !found){
        if (item == location->info){
            found = true;
        }
        else{
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
    return item;
}

void UnsortedType::DeleteItem(ItemType item){
    NodeType* location= listData;
    NodeType* tempLocation;

    if (item.ComparedTo(listData->info)==EQUAL){
        tempLocation = location;
        listData= listData->next;
    }
    else{
        while(item.ComparedTo((location->next)->info)!=EQUAL)
            location = location->next;
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

void UnsortedType::MakeEmpty(){
    NodeType* tempPtr;

    while(listData != NULL){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr; //이동후 그담꺼 지우고 이동후 그담꺼 지우기
    }
    length =0;
}

bool UnsortedType::IsFull() const{
    NodeType* location;
    try{
        location = new NodeType;    //heap 이 가득차면 불가능
        delete location;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
    }
}

void UnsortedType::ResetList(){
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem(){
    ItemType item;
    if (currentPos == NULL) currentPos = listData; //첫부분 찾기
    else currentPos = currentPos->next;
    item = currentPos->info;    //한칸이동후 info를 item에 담기
    return item;
}

UnsortedType::~UnsortedType(){
    NodeType* tempPtr;  //tempPtr하나 만들어준다.   
    while(listData!=NULL){  //맨 첫번째에 넣은 값(NULL)이 나올때까지 돌아준다.
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr; // temp에 담고 한칸 이동 후 temp 삭제
    }
}
