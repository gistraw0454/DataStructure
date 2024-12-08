// Transformers
    //MakeEmpty, PutItem, DeleteItem
// Observers
    //IsFull, GetLength, GetItem
//Iterators
    //ResetList, GetNextItem
#include "ItemType.h"
#define MAX_ITEMS = 10

class UnsortedType{
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;

public:
    void UnsortedType();    //constructor
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void MakeEmpty();    //�����̰�..?
    void DeleteItem(ItemType item);
    void ResetList();   //currentPos �ʱ�ȭ
    ItemType GetNextItem;   //iterator
};