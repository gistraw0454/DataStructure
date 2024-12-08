// interface

typedef int ItemType;

struct NodeType;
struct MemoryType{
    int free;
    NodeType* nodes;
};

class ListType{
    public:
    ListType();
    ListType(int);  // 동적으로 배열 크기 할당
    ~ListType();

    void InsertItem(ItemType item);
    void InitializeMemory(int maxItems, MemoryType& storage);
    void GetNode(int& nodeIndex, MemoryType& storage);
    void FreeNode(int nodeIndex, MemoryType& storage);

    private:
    int listData;
    int currentPos;
    int length;
    int maxItems;
    MemoryType storage;
};

///////////////////////////// 구현 ///////////////////////////
const int NUL = -1;

struct NodeType{
    int info;
    int next;
};

ListType::ListType(int max){
    length = 0;
    maxItems = max;
    storage.nodes = new NodeType[max];
    InitializeMemory(maxItems, storage);
    listData = NUL;
}

ListType::ListType(){
    length = 0;
    maxItems = 500;
    storage.nodes = new NodeType[500];
    InitializeMemory(500,storage);
    listData = NUL;
}

ListType::~ListType(){
    delete [] storage.nodes;
}

void InsertItem(ItemType item){
    // 맘대로 ㄱㄱ
}

// 모든 메모리를 free list로 초기화 시키기
void InitializeMemory(int maxItems, MemoryType& storage){
    for (int index = 1; index < maxItems; index++){
        storage.nodes[index-1].next = index;
    }
    storage.nodes[maxItems-1].next = NUL;
    storage.free = 0;
}

void GetNode(int& nodeIndex, MemoryType& storage){
    nodeIndex = storage.free;
    storage.free = storage.nodes[storage.free].next;
}

void FreeNode(int nodeIndex, MemoryType& storage){
    storage.nodes[nodeIndex].next = storage.free;
    storage.free = nodeIndex;
}