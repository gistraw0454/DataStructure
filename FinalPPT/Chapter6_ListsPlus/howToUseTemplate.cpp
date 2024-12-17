#include "ItemType.h"

template<class ItemType>    // class template 사용
class StackType{
    public:
    StackType();
    bool IsEmpty();
    bool IsFull();
    void Push(ItemType item);
    void Pop(ItemType item);
    ItemType Top();

    private:
    int top;
    ItemType items[MAX_ITEMS];
};

template<class ItemType>    // class외부에서 메서드나 생성자 등을 선언하는 경우, 각각 붙여주기
StackType<ItemType>::StackType(){
    top = -1;
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem){
    if (IsFull()){
        throw FullStack();
    }
    top++;
    items[top]= newItem;
}


int main(){
    StackType<int> numStack;
}
