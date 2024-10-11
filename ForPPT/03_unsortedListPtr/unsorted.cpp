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
        delete tempPtr; //�̵��� �״㲨 ����� �̵��� �״㲨 �����
    }
    length =0;
}

bool UnsortedType::IsFull() const{
    NodeType* location;
    try{
        location = new NodeType;    //heap �� �������� �Ұ���
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
    if (currentPos == NULL) currentPos = listData; //ù�κ� ã��
    else currentPos = currentPos->next;
    item = currentPos->info;    //��ĭ�̵��� info�� item�� ���
    return item;
}

UnsortedType::~UnsortedType(){
    NodeType* tempPtr;  //tempPtr�ϳ� ������ش�.   
    while(listData!=NULL){  //�� ù��°�� ���� ��(NULL)�� ���ö����� �����ش�.
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr; // temp�� ��� ��ĭ �̵� �� temp ����
    }
}
