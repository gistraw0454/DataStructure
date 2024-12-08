# Mid-term Exam 정리

> 자료구조 2024 2학기 중간고사 필기 Chapter 1~ Chapter 5
>
> 이론 40% + 실습 60%

## Chapter 3) ADT Unsorted List

### List Definition

- Linear relationship : 위치상 선후 관계가 있다. 
- Length : 리스트 아이템 수, 유동적
- Unsorted list : 원소들의 순서가 없음. list의 선행자 후속자 관계 뿐 <- 넣을때 유리
- Sorted list : 키값을 기준으로 정렬됨.넣을때 비교해서 넣어야함 <- 찾을때 유리

- Key : 정렬 기준



### Array Unsorted Linked-list

```cpp
// unsorted.h
class UnsortedType{
   	private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
    
    public:
    void UnsortedType();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType item,bool& found);
    void PutItem(ItemType item);
    void MakeEmpty();
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
};
```

```cpp
// unsorted.cpp
#include "unsorted.h"

void UnsortedType::UnsortedType(){
    length=0;
}

bool UnsortedType::IsFull() const{
    return (length == MAX_ITEMS);
}

int UnsortedType::GetLength() const{
    return length;
}

ItemType UnsortedType::GetItem(ItemType item,bool& found){
    bool moreToSearch;
    int location=0;
    
    found = false;
    while(moreToSearch && !found){
        switch(item.ComparedTo(info[location]){
            case LESS:
            case GREATER:
            	location ++;
            	moretToSearch = (location < length);
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
    info[length++] = item;
}

void UnsortedType::DeleteItem(ItemType item){
    int location =0;
    while(item.CompareTo(info[location])!=EQUAL){
        location ++;
    }
    info[location] = info[length-1];
    length--;
}
               
void UnsortedType::MakeEmpty(){
    length=0;
}
               
void UnsortedType::ResetList(){
    currentPos = -1;
}
               
ItemType UnsortedType::GetNextItem(){
    currentPos++;
    ItemType item = info[currentPos];
    return item;
}
```



### Pointer Variable

- 값이 메모리 주소인 변수

### Dynamically Allocated Data

`char* ptr = new char;`

- `delete ptr;`
  - 현재 포인터가 가리키는 개체나 배열의 할당을 취소하고 포인터는 할당되지않을 것으로 간주
  - `int* ptr = new int[5]` -> `delete[] ptr;`
  - 안하면,,,, Memory Leak 발생

### Null Pointer

- NULL은 메모리 주소가 아니다. 아무것도 가리키고있지 않다는 것을 의미



### Pointer Unsorted Linked-list

```cpp
// NodeType.h
struct NodeType{
    int info;
    NodeType* next;
};
```

```cpp
// unsorted.h

class UnsortedType{
    public:
    //생략
    private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
};
```

```cpp
// unsorted.cpp
#include "unsorted.h"

UnsortedType::UnsortedType(){
    length = 0;
    listData = NULL;
}

void UnsortedType::PutItem(ItemType item){
    NodeType newNode = new NodeType;
    newNode->next = listData;
    newNode->info = item;
    
    listData = newNode;
    
    length ++;
}

int UnsortedType::GetLength() const{
    return length;
}

int UnsortedType::GetItem(ItemType item, bool& found){
    bool moreToSearch;;
    NodeType* location = listData;
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
    NodeType* location = listData;
    NodeType* temp;
    
    // 맨첨에 걸리면
    if (item.ComparedTo(listData->info)==EQUAL){
        temp = location;
        listData = listData->next;
    }
    else{
        while(item.ComparedTo((location->next)->info)
            location = location->next;
              
        temp = location->next;	//발견하면?
        location->next = (loaction->next)->next;
    }
    delete temp;
    length --; 
}

void UnsortedType::MakeEmpty(){
    NodeType* temp;
    while(listData!=NULL){
        temp = listData;
        listData = listData->next;
        delete temp;
    }
    length =0;
}

bool UnsortedType::IsFull() const{
    NodeType* location;
    try{
        location = new NodeType;
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

Item UnsortedType::GetNextItem(){
    ItemType item;
    if (currentPos == NULL) currentPos = listData;
    else currentPos = listData->next;
    item = currentPos -> info;
    
    return item;
}

UnsortedType::~UnsortedType(){
    NodeType* temp;
    while(listData != NULL){
        temp = listData;
        listData = listData->next;
        delete temp;
    }
}
```

