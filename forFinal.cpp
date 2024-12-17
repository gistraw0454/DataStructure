// cirlinkedlist
template<class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc, bool& found){
    bool moreToSearch = true;
    location = listData->next;
    predLoc = listData;
    found = false;

    while(moreToSearch && !found){
        if (item.ComparedTo(location->info) == LESS){
            moreToSearch = false;
        }
        else if (item.ComparedTo(location->info) == EQUAL){
            found = true;
        }
        else{
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}

template<class ItemType>
void SortedType<ItemType>::PutItem(ItemType item){
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool found;

    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (listData != NULL){
        FindItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;

        if ((listData->info.ComparedTo(item)) == LESS){
            listData = newNode;
        }
    }
    else{
        listData = newNode;
        newNode->next = newNode;
    }
    length++;
}

template<class ItemType>
void SortType<ItemType>::DeleteItem(ItemType item){
    NodeType<ItemType>* location;
    NodeType<ItemType>* predLoc;
    bool found;

    FindItem(listData, item, location, predLoc, found);
    if (found){
        if (predLoc == location){
            listData = nullptr;
        }
        else{
            predLoc->next = location->next;
            if (location == listData){
                listData = predLoc;
            }
        }
        delete location;
        length--;
    }
}


/// / heap sort
/* Heap sort를 구현하고, 주어진 문자열에서 데이터를 읽어 국가명을 기준으로 정렬 후 출력해라. */
template<class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc, bool& found){
    bool moreToSearch = true;
    location = listData->next;
    predLoc = listData;
    found = false;

    while(moreToSearch && !found){
        if (item.ComparedTo(location->info) == LESS){
            moreToSearch = false;
        }
        else if (item.ComparedTo(location->info) == EQUAL){
            found = true;
        }
        else{
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}

template<class ItemType>
void SortedType<ItemType>::PutItem(ItemType item){
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool found;

    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (listData != NULL){
        FindItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;

        if ((listData->info.ComparedTo(item)) == LESS){
            listData = newNode;
        }
    }
    else{
        listData = newNode;
        newNode->next = newNode;
    }
    length++;
}

template<class ItemType>
void SortType<ItemType>::DeleteItem(ItemType item){
    NodeType<ItemType>* location;
    NodeType<ItemType>* predLoc;
    bool found;

    FindItem(listData, item, location, predLoc, found);
    if (found){
        if (predLoc == location){
            listData = nullptr;
        }
        else{
            predLoc->next = location->next;
            if (location == listData){
                listData = predLoc;
            }
        }
        delete location;
        length--;
    }
}

struct Country {
    string name;
    string capital;
};

struct HeapType{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);

    Country* elements;
    int numElements;
};

void Swap(Country& a, Country& b) {
    Country temp = a;
    a = b;
    b = temp;
}

void HeapType<Country>::ReheapDown(int root, int bottom){
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    if (leftChild <= bottom){
        maxChild = leftChild;
    }
    else{
        if (elements[leftChild] <= elements[rightChild]){
            maxChild = rightChild;
        }
        else{
            maxChild = leftChild;
        }
    }

    if (elements[root] < elements[maxChild]){
        Swap(elements[root], elements[maxChild]);
        ReheapDown(maxChild, bottom);
    }
}

void HeapType<Country>::ReheapUp(int root, int bottom){
    int parent;

    if (bottom > root){
        parent = (bottom - 1) / 2;
        if (elements[parent] < elements[bottom]){
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}

void HeapSort(Country values[], int numValues){
    int index;

    for (index = numValues / 2 - 1; index >= 0; index--){
        ReheapDown(values, index, numValues - 1);
    }

    for (index = numValues - 1; index >= 1; index--){
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1);
    }
}



//// 이진검색트리BST

#include <iostream>
#include <string>
using namespace std;

struct ItemType {
    string country;
    string capital;

	bool operator<(const ItemType& other) const {
        return country < other.country;
    }

    bool operator>(const ItemType& other) const {
        return country > other.country;
    }

    bool operator==(const ItemType& other) const {
        return country == other.country;
    }
};

// 트리 노드 정의
struct TreeNode {
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

class TreeType {
public:
    TreeType();
    ~TreeType();
	bool IsFull() const;
    bool IsEmpty() const;
    void PutItem(ItemType item);
    int GetItem(string target);

private:
    TreeNode* root;

    void Insert(TreeNode*& tree, ItemType item);
    int Retrieve(TreeNode* tree, string target, int& cmpCnt);
    void Destroy(TreeNode*& tree);
};

TreeType::TreeType() {
    root = nullptr;
}

TreeType::~TreeType() {
    Destroy(root);
}

bool TreeType::IsFull() const{
	TreeNode* location;
	try{
		location = new TreeNode;
		delete location;
		return false;
	}
	catch(std::bad_alloc exception){
		return true;
	}
}

bool TreeType::IsEmpty() const {
    return root == nullptr;
}

void TreeType::PutItem(ItemType item) {
    Insert(root, item);
}

int TreeType::GetItem(string target) {
    int cmpCnt = 0;
    return Retrieve(root, target, cmpCnt);
}

void TreeType::Insert(TreeNode*& tree, ItemType item) {
    if (tree == nullptr) {
        tree = new TreeNode;
		tree->right = nullptr;
        tree->left = nullptr;
		tree->info = item;
    
    } else if (item.country < tree->info.country) {	//나라이름 기준으로 정렬
        Insert(tree->left, item);
    } else {
        Insert(tree->right, item);
    }
}

// 검색 함수
int TreeType::Retrieve(TreeNode* tree, string target, int& cmpCnt) {
    if (tree == nullptr) {
        return -1;	// 값이 없으면 -1 리턴
    }
    cmpCnt++;
    if (target == tree->info.country) {
        return cmpCnt;
    } else if (target < tree->info.country) {
        return Retrieve(tree->left, target, cmpCnt);
    } else {
        return Retrieve(tree->right, target, cmpCnt);
    }
}

// 트리 메모리 해제
void TreeType::Destroy(TreeNode*& tree) {
    if (tree != nullptr) {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
        tree = nullptr;
    }
}


//// 재귀 linkedlist

void RevPrint(NodeType* listPtr){
    if (listPtr != nullptr){
        RevPrint(listPtr->next);
        std::cout << listPtr->info << std::endl;
    }else{
        ;
    }
}

template<class ItemType>
void PutItem(NodeType<ItemType>*& listPtr, ItemType item){
    // listPtr이 끝이거나, item보다 큰 값을 만나는 순간 삽입on 
    if (listPtr == nullptr || item < listPtr->info){
        NodeType<ItemType>* tempPtr = listPtr;

        listPtr = new NodeType<ItemType>;
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