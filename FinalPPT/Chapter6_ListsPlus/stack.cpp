template<class ItemType>
class StackType{
    public:
    StackType();    // default constructor
    StackType(const StackType<ItemType>& anotherStack); // &가 없으면 계속 default constructor을 호출하게됨. (=> 무한 루프 돌 수 있음)
    ~StackType();

    void operator= (StackType<ItemType>& anotherStack);

    private:
    NodeType<ItemType>* topPtr;
};

template<class ItemType>
StackType<ItemType>::StackType(const StackType<ItemType>& anotherStack){
    NodeType<ItemType>* ptr1;   // original(anotherStack) stack's node 하나를 가리키기 위한 것
    NodeType<ItemType>* ptr2;   // new stack's node 하나를 가리키기 위한 것

    if (anotherStack.topPtr == nullptr){    // empty Stack 
        topPtr = nullptr;  
    }
    else{   // not empty Stack
        topPtr = new NodeType<ItemType>;    // 새 node를 만든다.
        topPtr->info = anotherStack.topPtr->info;   // info 복사
        ptr1 = anotherStack.topPtr->next;   //
        ptr2 = topPtr;

        while(ptr1 != nullptr){ // 마지막 노드가 아니면,
            ptr2->next = new NodeType<ItemType>;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = nullptr;
    }
}



template<class ItemType>
void Copy(StackType<ItemType> original, StackType<ItemType>& copy){ // original -> copy (deep)

    if (anotherStack.topPtr == nullptr){    // empty Stack 
        copy.topPtr = nullptr;  
    }
    else{   // not empty Stack
        NodeType<ItemType>* ptr1;   // original(anotherStack) stack's node 하나를 가리키기 위한 것
        NodeType<ItemType>* ptr2;   // new stack's node 하나를 가리키기 위한 것

        copy.topPtr = new NodeType<ItemType>;    // 새 node를 만든다.
        copy.topPtr->info = original.topPtr->info;   // info 복사
        ptr1 = original.topPtr->next;   //
        ptr2 = copy.topPtr;

        while(ptr1 != nullptr){ // 마지막 노드가 아니면,
            ptr2->next = new NodeType<ItemType>;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = nullptr;
    }
}

template<class ItemType>
void operator= (StackType<ItemType>& anotherStack){
    NodeType<ItemType>* ptr1;   // original(anotherStack) stack's node 하나를 가리키기 위한 것
    NodeType<ItemType>* ptr2;   // new stack's node 하나를 가리키기 위한 것

    if (anotherStack.topPtr == nullptr){    // empty Stack 
        topPtr = nullptr;  
    }
    else{   // not empty Stack
        topPtr = new NodeType<ItemType>;    // 새 node를 만든다.
        topPtr->info = anotherStack.topPtr->info;   // info 복사
        ptr1 = anotherStack.topPtr->next;   //
        ptr2 = topPtr;

        while(ptr1 != nullptr){ // 마지막 노드가 아니면,
            ptr2->next = new NodeType<ItemType>;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = nullptr;
    }
}