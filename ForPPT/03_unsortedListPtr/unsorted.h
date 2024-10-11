// Transformers
    //MakeEmpty, PutItem, DeleteItem
// Observers
    //IsFull, GetLength, GetItem
//Iterators
    //ResetList, GetNextItem

#include "ItemType.h"

class UnsortedType{
    public:
        //...
    private:
    NodeType* listData; //마지막으로 넣은 원소 위치가짐
    int length;
    NodeType* currentPos;   //마지막으로 읽은 원소 위치
}

