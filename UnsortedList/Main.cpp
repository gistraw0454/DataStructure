//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------ITEMTYPE_H------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print() const;
    void Initialize(ItemType& item);
    friend istream& operator >>(istream& inStream, ItemType& item);
    friend ostream& operator <<(ostream& os, const ItemType& item);
private:
    string country;
    string capital;
};

ItemType::ItemType()
{
    country = "";
    capital = "";
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (country < otherItem.country)
        return LESS;
    else if (country > otherItem.country)
        return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(ItemType& item)
{
    country = item.country;
    capital = item.capital;
}

void ItemType::Print() const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
    cout << "[ " << country << " : " << capital << " ]";
}

istream& operator >>(istream& inStream, ItemType& item)
{
    string line;
    getline(inStream, line);

    size_t dashPos = line.find(':');
    item.country = line.substr(1, dashPos-2);
    item.capital = line.substr(dashPos+2);
    return inStream;
}

ostream& operator<<(ostream& os, const ItemType& item) {
    os << "Country: " << item.country << ", Capital: " << item.capital;
    return os;
}
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------UNSORTEDLIST_H--------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H
//  ItemType.h must contain the following definitions: 
//  MAX_ITEMS:     the maximum number of items on the list 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 
struct NodeType;

class UnsortedType 
{
public:
  UnsortedType();   // Constructor
  ~UnsortedType();  // Destructor
  void MakeEmpty();
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  ItemType GetItem(ItemType& item, bool& found);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned;	
  // 	 otherwise found = false and item is returned.
  //       List is unchanged.

  void PutItem(ItemType item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  ItemType GetNextItem();
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
	NodeType* listData;
	int length;
	NodeType* currentPos;
};

struct NodeType
{
	ItemType info;
	NodeType* next;
};

UnsortedType::UnsortedType()  // Class constructor 생성자
{
	length =0;
	listData = NULL;
}

bool UnsortedType::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	//return (length == MAX_ITEMS)	// length == 5 면 IsFull True
	NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch (std::bad_alloc& exception) {
        return true;
    }
}

int UnsortedType::GetLength() const
// Post: Number of items in the list is returned.
{
	return length;
}

void UnsortedType::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	NodeType* tempPtr;
    while(listData != NULL)
    {
        tempPtr = listData; //list 포인터를 저장
        listData = listData->next;  //listData가 다음 노드를 가리키게함
        delete tempPtr; // 기존의 노드를 삭제
    }
    length=0;
}

void UnsortedType::PutItem(ItemType item)
// item is in the list; length has been incremented.
{
	NodeType* location = new NodeType;
	location->info = item;
	location->next = listData;
	listData = location;    

	length++;


}

ItemType UnsortedType::GetItem(ItemType& item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
	NodeType* location = listData;
    found = false;
    while (location != NULL && !found) {
        if (item.ComparedTo(location->info) == EQUAL) {
            found = true;
            item = location->info;
        }
        location = location->next;
    }
    return item;
}

void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	NodeType* location = listData;
	NodeType* tempLocation;

	//가장 앞에 삭제하는 경우
	if (item.ComparedTo(listData->info)==EQUAL){
			tempLocation = location;
			listData = listData->next;
	}
	else{
			while(item.ComparedTo((location->next)->info)!=EQUAL){
					location = location->next;
			}
			tempLocation = location->next;  //할당해제를 위해 temp에 저장
			location->next = (location->next)->next;

	}
	delete tempLocation;
	length--;


}

void UnsortedType::ResetList()
// Post: Current position has been initialized.
{
	currentPos=NULL;

}
 
ItemType UnsortedType::GetNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{
    if (currentPos == NULL) {  // 시작부분이면
        currentPos = listData; // 첫번째 노드주소를 할당
    }
    else {  // 이미 노드를 가리키고 있다면
        currentPos = currentPos->next;  // 다음노드로 이동
    }

    if (currentPos == NULL) {  // 현재위치가 null이면 (끝이면)
        ResetList();  // 리스트를 다시 초기화
    }
    return currentPos->info; 
}

UnsortedType::~UnsortedType()
// Post: List is empty; all items have been deallocated.
{
	NodeType* tempPtr;  //tempPtr 만들기

	while(listData != NULL){
			tempPtr = listData; // listdata 저장
			listData = listData->next;  // 다음 노드 포인터로 listData 이동
			delete tempPtr;
	}

}
#endif

//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------int main()------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
using namespace std;

int main(){
	UnsortedType unsortedList; //객체 생성
	while(1){
        string command;
        cin >> command;
        if (command == "PutItem"){  //⭕
            ItemType item;
            cin >> item;
            unsortedList.PutItem(item);
            item.Print();
            cout << " was put in the list.\n";
        }
        else if (command == "DeleteItem"){  //⭕
            ItemType item;
            cin >> item;
            unsortedList.DeleteItem(item);
            item.Print();
            cout << " was deleted.\n";
        }
        else if (command == "GetItem"){ //⭕
            ItemType item;
            bool found;
            cin >> item;
            unsortedList.GetItem(item, found);
            if (found) {
                item.Print();
                cout << " was found in the list.\n";
            } else {
                item.Print();
                cout << item << " is not in the list.\n";
            }
        }
        else if (command == "GetLength"){   //⭕
            cout << "Length is " << unsortedList.GetLength()<<"\n";
        }
        else if (command == "IsFull"){  //⭕
            cout << unsortedList.IsFull();
        }
        else if (command == "MakeEmpty"){   //⭕
            unsortedList.MakeEmpty();
        }
        else if (command == "PrintList"){   //⭕
					unsortedList.ResetList();   //currentPos 초기화시켜서 젤 첨부터 순회하게 만들기
					cout << "*** Print all items ***\n";
					for (int i = 0; i < unsortedList.GetLength(); i++) {    // 길이만큼 다음노드로 이동하면서 출력
							ItemType item = unsortedList.GetNextItem(); 
							item.Print();
							cout << "\n"; 
					}
					cout << "*** The end ***\n";
				}
        else if (command == "Quit"){    //⭕
            cout << "Testing completed.\n";
            break;
        }
        else{   //⭕
            cout << command << " is not a valid command.\n";
        }
    }
    unsortedList.~UnsortedType();
    return 0;
}