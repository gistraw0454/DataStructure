# Mid-term Exam 정리

> 자료구조 2024 2학기 중간고사 필기 Chapter 1~ Chapter 5
>
> 이론 40% + 실습 60%

## Chapter 5) ADTs Stack and Queue

### Stack 

- Logical (or ADT) level : 동일 유형의 item(elements)가 쌓여있는 순서있는 그룹. 추가삭제는 젤 위에서만 가능( LIFO last in first out)
- function call stack, undo functionality of 메모장, web browser back/forward 앞/뒤로가기
- MakeEmpty, IsEmpty, IsFull, Push, Pop (top 삭제), Top (마지막에 들어간 데이터가 뭐냐?)

```cpp
//StackType.h
class StackType{
    public:
    StackType();
    bool IsFull() const;
    bool IsEmpty() const;
	void Push(ItemType item);
    void Pop();
    ItemType item Top() const;
    
    private:
    int top;
    ItemType items[MAX_ITEMS];
}
```

```cpp
//StackType.cpp
#include "StackType.h"

StackType::StackType(){ top = -1; }

bool StackType::IsEmpty() const { return (top== -1); }

bool StackType::IsFull() const{ return (top >= MAX_ITEMS-1); }

void StackType::Push(ItemType newItem){
    if (IsFull()) throw FullStack();
    top++;
    items[top] = newItem;
}

void StackType::Pop(){
    if(IsEmpty()) throw EmptyStack();
    top--;
}

ItemType StackType::Top(){
    if(IsEmpty()) throw EmptyStack();
    return items[top];
}
```

- Stack의 top은 한칸 앞에서 부터 시작함. => 넣을때 증가시키고 넣기

- ```cpp
  //예외처리까지..
  try{
      stack.Push(item);
      stack.Pop();
  }
  catch(Fullstack exceptionObject){
  	//
  }
  catch(Emptystack exceptionObject){
      //
  }
  ```

  ### ADT 로 동적 배열크기 할당해보자

  ```cpp
  class StackType{
      private:
      int top;
      int maxStack;
      ItemType* items;
      
      public:
      StackType(int max);	//동적 할당
      StackType();
  };
  
  StackType::StackType(int max){
      maxStack = max;
      top = -1;
      items = new ItemType[maxStack];
  }
  
  StackType::StackType(){
      maxStack = 500; //고정
      top = -1;
      itmes = new ItemsType[maxStack];
  }
  
  bool StackType::IsFull() const{
      return (top == maxStack-1);
  }
  
  StackType::~StackType(){
  	delete[] items;
  }
  ```

  > 스택의 arr구현은 크기가 지정되어있어 공간 낭비와 부족이 일어날 수 있다. 따라서 스택을 푸쉬할때마다 동적 공간을 할당할 수 있다. // 굳이긴하다.. 
  >
  > ```cpp
  > Struct NodeType{
  >     ItemType info;
  >     NodeType* next;
  > };
  > 
  > class StackType{
  >     public://
  >     private: NodeType* topPtr;
  > 	//
  > };
  > void StackType::Push(ItemType newItem){
  >     if (IsFull()) throw FullStack();	//humm
  >     NodeType* location;
  >     location = new NodeType;
  >     location->info = newItem;
  >     location->next = topPtr;
  >     topPtr = location;
  > }
  > 
  > void StackType::Pop(){
  >     if (IsEmpty()) throw EmptyStack();
  >     else{
  >         NodeType* tempPtr;
  >         tempPtr = topPtr;
  >         topPtr = topPtr->next;
  >         delete tempPtr;
  >     }
  > }
  > 
  > ItemType StackType::Top(){
  >     if (IsEmpty()) throw EmptyStack();
  > 	else return topPtr->info;
  > }
  > 
  > bool StackType::IsFull() const{
  >     NodeType* location;
  >     try{
  >         location = new NodeType;
  >         delete location;
  >         return false;
  >     }
  >     catch(std::bad_alloc exception) return true;
  > }
  > ```

### Queue

- Logical (or ADT) level: 타입같은 순서있는애들 그룹이고, FIFO(first in first out) 이다.

- web 대기번호, 전화순에 따라 서비스 제공.. 그런 순서있는 줄서는 것들
- MakeEmpty, IsEmpty, IsFull, Enqueue, Dequeue (아이템 리턴도함)
- front를 0으로 고정시키는 경우 : 
  - 특정위치를 지정하는게 아니라 front에 있는 값을 항상 삭제
    - 삭제시 한칸씩 당겨줘야함............ => 데이터양이 많으면 복사하기 어려움
- **front를 움직이는 경우**:
  - 삭제해도 안 옮겨도됨 
  - 앞에 공간이 남아 logical garbage가 생김 => IsFull할때 문제

- rear도 움직이자. => Circular Queue

![image-20241022171127487](E:\자료구조\assets\image-20241022171127487.png)

​	이렇게하면.. IsEmpty랑 Isfull 어케 구분할거냐

​		front > rear? ㄴㄴ 결과가 같을 수 있음

​			front 바로 앞에 하나를 RESERVED로 만들어 front가 그걸 가리키게하자. 한칸정도 낭비야.. 괜찮아

![image-20241022172131271](E:\자료구조\assets\image-20241022172131271.png)



```cpp
// 정적 배열
class QueType{
    private:
    int front;	//힝상 맨앞을 가리키므로 0임
    int rear;
    ItemType items[MAX_ITEMS];
    
    public:
    QueType(int max);	//동적 할당
    QueType();	//기본 500으로 할당
    ~QueType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(ItemType item);
    void Dequeue(ItemType& item);
    
}
```



```cpp
// 동적 배열
class QueType{
    private:
    int front;
    int rear;
    int maxQue;
    ItemType* items;
    
    public:
    QueType(int max);	//동적 할당
    QueType();	//기본 500으로 할당
    ~QueType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(ItemType item);
    void Dequeue(ItemType& item);
    
}
```

```cpp
//최종 Queue 코드
//QueType.cpp

QueType::QueType(int max){
    maxQue = max +1;
    front = maxQue -1;	// 다음데이터 -1 이어야하니까
    rear = maxQue -1;	// 원래 rear+1 해서 값을 넣으니까 
    items = new ItemType[maxQue];
}

QueType::QueType(){
    maxQue = 501;
    front = maxQue -1;
    rear = maxQue -1;
    items = new ItemType[maxQue];
}

QueType::~QueType(){
    delete[] items;
}

void QueType::MakeEmpty(){
    front = maxQue-1;	//지울필요 X
    rear = maxQue-1;
}

bool QueType::IsEmpty() const{
    return (rear == front);
}

bool QueType::IsFull() const{
    return ((rear+1)%maxQue == front);
}

void QueType::Enqueue(ItemType newItem){
    if (IsFull()) throw FullQueue();
    else{
        rear = (rear +1) % maxQue;	//마지막번째면 0으로
        items[rear] = newItem;
    }
}

void QueType::Dequeue(ItemType& item){
    if (IsEmpty()) throw EmptyQueue();
    else{
        front = (front + 1)%maxQue;
        item = items[front];
    }
}

```

enque : rear = (rear+1)%maxQue

deque : front = (front+1)%maxQue

front변수는 front에있는 자리를 사용하지않고, 항상 빈자리로 둔다.

- **def** **isEmpty**():    **return** front == rear 
- **def** **isFull**():    **return** (rear+1) % len(cQ) == front

### linked ptr 구조 : 

**공간 남고 그런걸 고민할 필요가없음.. 그냥 할당 해제 때리면되니까. 개수 고민도 필요없음 그냥 qFront, qRear만 있으면됨**

- ![image-20241022174619989](E:\자료구조\assets\image-20241022174619989.png)

![](E:\자료구조\assets\image-20241022174801075.png)

![image-20241022174831927](E:\자료구조\assets\image-20241022174831927.png)



### 정리

- list : data를 오래 저장하기 위함
- stack, Queue 는 잠시 저장하는 목적으로 사용하니 삽입삭제가 편해야함.

![image-20241022174846575](E:\자료구조\assets\image-20241022174846575.png)