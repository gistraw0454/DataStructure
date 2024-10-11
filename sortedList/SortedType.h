#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H
//#include "ItemType_cc.h"
// File ItemType.h must be provided by the user of this class.
//  ItemType.h must contain the following definitions:
//  MAX_ITEMS:     the maximum number of items on the list
//  ItemType:      the definition of the objects on the list
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns
//       LESS, if self "comes before" item
//       GREATER, if self "comes after" item
//       EQUAL, if self and item are the same
struct NodeType;

class SortedType
{
public:
    SortedType();// Constructor
    ~SortedType();  // Destructor
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
    int length;
    NodeType* listData;
    NodeType* currentPos;
};

//여기부터 작성하기 !
struct NodeType
{

};

SortedType::SortedType()  // Class constructor
{

}

bool SortedType::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{

}

int SortedType::GetLength() const
// Post: Number of items in the list is returned.
{

}

void SortedType::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{

}

void SortedType::PutItem(ItemType item) //<- 변경필요
// item is in the list; length has been incremented.
{

}


ItemType SortedType::GetItem(ItemType& item, bool& found)   //<- 변경필요
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged.
{

}


void SortedType::DeleteItem(ItemType item)  //<- 변경필요
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{

}

void SortedType::ResetList()
// Post: Current position has been initialized.
{
	
}

ItemType SortedType::GetNextItem()
// Post:  A copy of the next item in the list is returned.
//        When the end of the list is reached, currentPos
//        is reset to begin again.
{

}

SortedType::~SortedType()
// Post: List is empty; all items have been deallocated.
{

}
#endif