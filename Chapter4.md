# Mid-term Exam 정리

> 자료구조 2024 2학기 중간고사 필기 Chapter 1~ Chapter 5
>
> 이론 40% + 실습 60%

## Chapter 4) ADT Sorted List

### Array Sorted List : 한번넣고 잘안바꾸는

- GetItem : 그대로 해도되긴하는데, search로 개선가능 

  - **Binary Search** => 값찾긴 좋은데 메모리낭비 가능성이있음 

    1. 전체배열의 중간부터 시작

    2. 원하는게 나오면 중단, half가 작으면 후반부, half가 크면 전반부 보기

- PutItem : 규칙에 맞게 위치를 찾아 넣어주기

  1. 적절한 위치 찾기 (못찾은 경우, 끝까지 돌필요없이 특정 위치까지만봐도됨)
  2. 중간에 넣으면 그 뒤 다른 원소를 뒤로 다 밀어줘야함
  3. new element list에 넣기
  4. len++

- DeleteItem : 마지막꺼를 냅다 붙이면 안됨!

  - 위치찾아제거하고 한칸씩 앞으로 다 밀기 len--;

#### Array Sorted List

```cpp
void SortedType::PutItem(ItemType item){
    bool moreToSearch;
    int location =0;
    
    moreToSearch = (location < length);
    
    while(moreToSearch){
        switch(item.ComparedTo(info[location])){
            case LESS:	//item이 location값보다 작으면 
                moreToSearch = false;
                break;
            case GREATER:	//item이 location보다 크면 더 탐색
                location ++;
                moreToSearch = (location < length);
                break;
        }
    }
    for (int index = length; index > location ; index--)
        info[index] = info[index-1];
    info[location] = item;
    length++;
}

void SortedType::DeleteItem(ItemType item){
    int location =0;
    
    while (item.ComparedTo(info[location])!=EQUAL){
        location ++;
    }
    for (int index = location+1;index<length;index++){
        info[index-1] = info[index];
    }
    length--;
}

ItemType SortedType::GetItem (ItemType item, bool& found){
    int midPoint;
    int first =0;
    int last = length-1;
    bool moreToSearch = (first<=last);
    found = false;
    
    while(moreToSearch && !found){
        midPoint = (first + last)/2;
        switch (item.ComparedTo(info[midPoint])){
            case LESS:
                last = midPoint -1;
                moreToSearch = (first<=last);
                break;
            case GREATER:
                first = midPoint +1;
                moreToSearch = (first<=last);
                break;
            case EQUAL:
                found = true;
                item = info[midPoint];
                break;
        }
    }
    return item;
}
```





### Allocation of Memory

#### Static allocation

- compile time에 할당됨

#### Dynamic allocation

- run time에 new로 할당됨

- new는 객체나 배열에 대한 메모리를 할당하고 할당된 주소 포인터를 반환한다. 그렇지않으면 NULL포인터 0이 반환된다.

- `char *ptr = new char[5]`

  ```cpp
  //아까 SortedType class를 동적으로 할당할 수 있다.
  class SortedType{
      public:
      SortedType(int max);	// 동적으로 정해주는 경우
      SortedType();
      private:
      int length;
      int maxList;
      ItemType* info;	//
      int currentPos;
  };
  SortedType::SortedType(int max){
      maxList = max;
      length=0;
      info = new ItemType[maxList];	//동적으로 배열만들기
      currentPos = -1;
  }
  ```

  #### destructor 필요한 이유?

  > 로컬 리스트 변수가 범위를 벗어나면 데이터 멤버 listData의 메모리 공간이 해제된다. 그러나 listData가 가리키는 노드들은 해제되지않는다. 클래스 소멸자는 데이터 멤버가 가리키는 동적 메모리를 해제하는데 사용한다.



### Data

#### Static Data

- 프로그램 실행 전반적으로 존재

#### Automatic Data

- 함수 call되면 자동으로 만들어짐

#### Dynamic Data

- new로 할당 delete로 해제



### Pointer Sorted Linked-list

```cpp
//GetItem을 binary가 아닌 sequantial하게하면 끝까지 갈 필요없이 끝남
ItemType SortedType::GetItem (ItemType item, bool& found){
    bool moreToSearch;
    NodeType* location = listData;
    found = false;
    moreToSearch = (location != NULL);
    
    while(moreToSearch && !found){
        switch(item.ComparedTo(location->info)){
            case LESS : location = location -> next;
                moreToSearch = (location!=NULL);
                break;
            case EQUAL : found = true;
                item = location -> info;
                break;
            case GREATER : moreToSearch = false;
                break;	// 커지는순간 바로 나가기
        }
    }
    return item;
}

//PutItem은 바로 직전 노드의 주소를 알아야한다! 현재노드와 이전노드의 위치를 유지하자.
void SortedType::PutItem(ItemType item){
    NodeType* newNode;
    NodeType* predLoc = NULL;
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    
    while(moreToSearch){
        switch(item.ComparedTo(location->info)){
            case LESS: predLoc = location;
                location = location->next;
                moreToSearch = (location !=NULL);
                break;
            case GREATER: moreToSearch = false;
                break;
        }
    }
    newNode = new NodeType;
    newNode-> info = item;
    if (predLoc == NULL){	//첫번째에 넣어야한다면
        newNode->next = listData;
        listData = newNode;
    }
    else{
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

SortedType::~SortedType(){
    NodeType* temp;
    while(listData!=NULL){
        temp = listData;
        listData = listData->next;
        delete temp;
    }
}
```

![image-20241022160816522](E:\자료구조\assets\image-20241022160816522.png)

### Bounded and Unbounded ADTs

#### Bounded ADT

- 구조체 안의 항목수에 논리적 한계가 <u>있는</u> ADTs

#### Unbounded ADT

- 구조체 안의 항목수에 논리적 한계가 <u>없는</u> ADTs



### OOP 디자인 순서

1. Brainstorming
   - 모든 구성원의 아이디어 
2. Filtering
   - 필수적 클래스 결정
3. Scenarios
   - 각 class의 기능생각
4. Responsibility algorithms