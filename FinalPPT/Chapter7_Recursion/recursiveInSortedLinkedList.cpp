struct NodeType{
    int info;
    NodeType* next;
};
class SortedType{
    public:
    private:
    NodeType* listData;
};

// unsorted/sorted 모두 가능
void RevPrint(NodeType* listPtr){
    if (listPtr != nullptr){
        RevPrint(listPtr->next);
        std::cout << listPtr->info << std::endl;
    }else{
        ;
    }
}

// 
template<class ItemType>
void PutItem(NodeType<ItemType>*& listPtr, ItemType item){
    // listPtr이 끝이거나, item보다 큰 값을 만나는 순간 삽입on 
    if (listPtr == nullptr || item < listPtr->info){
        NodeType<ItemType>* tempPtr = listPtr;

        listPtr = new NodeType<ItemType>;   //
        listPtr->info = item;
        listPtr->next = tempPtr;
    }
    else PutItem(listPtr->next, item);
}

template<class ItemType>
void DeleteItem(NodeType<ItemType>*& listPtr, ItemType item){
    if (item == listPtr->info){
        NodeType<ItemType>* tempPtr = listPtr;
        listPtr = listPtr->next;
        delete tempPtr;
    }
    else{
        DeleteItem(listPtr->next, item);
    }
}