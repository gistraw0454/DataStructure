#include <iostream>
using namespace std;

#include <string>
const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
public:
    ItemType() : coef(0), exp(0) {}
    ItemType(int c, int e) : coef(c), exp(e) {}
    RelationType ComparedTo(ItemType other) const {
        if (exp < other.exp) return LESS;
        else if (exp > other.exp) return GREATER;
        else return EQUAL;
    }
    int coef;
    int exp;
};

struct NodeType
{
    ItemType info;
    NodeType* next;
};


class SortedType{
public:
    SortedType();
    ~SortedType();
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType& item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
    void PrintPolynomial();
    SortedType AddPolynomials(SortedType& other);
private:
    int length;
    NodeType* listData;
    NodeType* currentPos;
};



SortedType::SortedType()
{
    length =0;
    listData = nullptr;
}

bool SortedType::IsFull() const
{
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc){
        return true;
    }
}

int SortedType::GetLength() const
{
    return length;
}

void SortedType::MakeEmpty()
{
    NodeType* tempPtr;
    while(listData != nullptr){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length=0;
}

void SortedType::PutItem(ItemType item)
{
    NodeType* newNode;
    NodeType* predLoc = nullptr;
    NodeType* location = listData;
    bool moreToSearch;
    moreToSearch = (location != nullptr);

    while(moreToSearch){
        switch(item.ComparedTo(location->info)){
            case GREATER:
                predLoc = location;
                location = location->next;
                moreToSearch = (location != nullptr);
                break;
            case LESS:
                moreToSearch = false;
                break;
        }
    }

    newNode = new NodeType;
    newNode->info = item;
    if (predLoc == nullptr){
        newNode->next = listData;
        listData = newNode;
    }
    else{
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}


ItemType SortedType::GetItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    NodeType* location;
    location = listData;
    found = false;
    moreToSearch = (location!=nullptr);
    while(moreToSearch && !found){
        switch(item.ComparedTo(location->info)){
            case GREATER:   
                location = location->next;
                moreToSearch = (location!=nullptr);
                break;
            case EQUAL:
                found = true;
                found = location -> info;
                break;
            case LESS:
                moreToSearch = false;
                break;
        }
    }   
    return item;
}


void SortedType::DeleteItem(ItemType item)
{
    NodeType* current = listData;
    NodeType* previous = nullptr;

    while(current != nullptr && item.ComparedTo(current->info)!=EQUAL){
        previous = current;
        current = current->next;
    }
    if (previous == nullptr) listData = current->next;
    else previous->next = current->next;
    delete current;
    length--;
}

void SortedType::ResetList()
{
	currentPos = nullptr;
}

ItemType SortedType::GetNextItem()
{
    ItemType item;
    if (currentPos == nullptr) currentPos = listData;
    else currentPos = currentPos->next;
    item = currentPos->info;
}

SortedType::~SortedType()
{
NodeType* tempPtr; 
    while(listData!=nullptr){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}
#endif

int main() {
    SortedType sortedList;
	
    // +
    int inputNum = 0;
    cin >> inputNum;
    // 계수 차수
    for (int i=0; i< inputNum;i++){
        int a, n;
        cin >> a >> n;  // a n
        ItemType item;
        sortedList.PutItem(item);
    }

    // *
    int inputNum = 0;

}