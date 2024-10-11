#include "ItemType.h"
#include "SortedType.h"

using namespace std;

int main() {
	SortedType sortedList;
	string command;
	
	while(1){
		cin >> command;
		
		if (command == "PutItem"){
            ItemType item;
            cin >> item;
            sortedList.PutItem(item);
            item.Print();
            cout << " was put in the list.\n";
        }
        else if (command == "GetItem"){

        }
        else if (command == "DeleteItem"){

        }
        else if (command == "GetLength"){

        }
        else if (command == "IsFull"){

        }
        else if (command == "MakeEmpty"){

        }
        else if (command == "PrintList"){

        }
        else if (command == "Quit"){

        }
        else{
            continue;
        }
	}
	
}