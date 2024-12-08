typedef int ItemType;

struct TreeNode{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

class TreeType{
    public:
    TreeType();
    ~TreeType();
    TreeType(const TreeType& originalTree);
    void operator=(const TreeType& originalTree);
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int GetLenght() const;
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetTree(OrderType order);    //** **//
    ItemType GetNextItem(OrderType order, bool& finished);  //** **//
    void Print(std::ofstream& outFile) const;   
    private:
    TreeNode* root;
};

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

bool TreeType::IsEmpty() const{
    return root = nullptr;
}


int TreeType::GetLenght() const{    // CountNode func 호출해서 개수 node 개수 구하기
    return CountNodes(root);
}
int CountNodes(TreeNode* tree){ // leaf 노드의 경우 자식이 없으니 0 리턴
    if (tree == NULL){  // 자식인거임
        return 0;
    }
    else return CountNodes(tree->left) + CountNodes(tree->right) +1;
}


void TreeType::GetItem(ItemType& item, bool& found){
    Retrieve(root, item, found);
}
void Retrieve(TreeNode* tree, ItemType& item, bool& found){ // 트리돌다가 item 찾으면 found에 true를 넣어준다.
    if (tree == nullptr){   // tree가 null 이면 더 이상 찾아볼게없음 -> return false;
        found = false;
    }
    else if ( item < tree->info ){
        Retrieve(tree->left, item, found);
    }
    else if (item > tree->info){
        Retrieve(tree->right, item, found);
    }
    else{
        item = tree->info;  //굳이..?
        found = true;
    }
}


void TreeType::PutItem(ItemType item){
    Insert(root, item); // 항상 leaf node로 넣는 재귀 Insert 호출
}
void Insert(TreeNode*& tree, ItemType item){
    if (tree == nullptr){   // tree에 아무것도 없으면 새로 tree*와 tree&값을 할당해 줄거니까 매개변수로 TreeNode*& 받기
        tree = new TreeNode;
        tree->info = item;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    else if (item < tree->info){
        Insert(tree->left, item);
    }
    else{
        Insert(tree->right, item);
    }
}



// 상위노드가 필요하니까 한칸뒤에서 바라보기...!!! 
void TreeType::DeleteItem(ItemType item){
    Delete(root, item);
}
void Delete(TreeNode*& tree, ItemType item){
    if (item < tree->info){
        Delete(tree->left,item);
    }
    else if ( item > tree->info){
        Delete(tree->right,item);
    }
    else{   // 찾으면 node 지우기
        DeleteNode(tree);
    }
}
void DeleteNode(TreeNode*& tree){
    ItemType data;
    TreeNode* tempPtr;
    tempPtr = tree;

    if (tree->left == nullptr && tree->right== nullptr){
        delete tree;
    }
    else if (tree->left == nullptr){
        tree = tree->right; // tree주소자체를 tree->right 로 바꾸기
        delete tree;
    }
    else if (tree->right == nullptr){
        tree = tree->left; // tree주소자체를 tree->left 로 바꾸기
        delete tree;
    }
    else{   // 자식이 둘이면 왼쪽노드에서의 최댓값을 tree->info에 넣어주기.
        GetPredecessor(tree->left,data);    // data에는 tree->left에서의 가장 큰 값이 들어있음
        tree->info = data;
        delete(tree->left, data);   // tree->left에있는 data를 찾아 삭제
    }
}
void GetPredecessor(TreeNode* tree,ItemType& data){
    while(tree->right != nullptr){
        tree = tree->right;
    }
    data = tree->info;
}


// print시에는 상관없긴한데, inorder ㄱㄱ (left, root, right)
void TreeType::Print(std::ofstream& outFile) const{
    PrintTree(root, outFile);
}
void PrintTree(TreeNode* tree, std::ofstream& outFile){
    if (tree!=nullptr){
        PrintTree(tree->left,outFile);
        outFile << tree->info;
        PrintTree(tree->right,outFile);
    }
}


// destructor은 postorder ㄱㄱ (left , right, root)
TreeType::~TreeType(){
    Destroy(root);
}
void Destory(TreeNode*& tree){
    if (tree != nullptr){
        Destory(tree->left);
        Destory(tree->right);
        delete tree;
    }
}

// copy는 preorder ㄱㄱ (root, left, right)
TreeType::TreeType(const TreeType& originalTree){
    CopyTree(root, originalTree);
}
void CopyTree(TreeNode*& copy, const TreeNode* originalTree){
    if (originalTree == nullptr){
        copy = nullptr;
    }
    else{
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

// tree에 que를 만드는 함수
void TreeType::ResetTree(OrderType order){
    switch(order){  
        case PRE_ORDER : 
            PreOrder(root, preQue);
            break;
        case IN_ORDER:
            InOrder(root, inQue);
            break;
        case POST_ORDER;
            PostOrder(root, postQue);
            break;
    }
}
void PreOrder(TreeNode* tree, QueType& preQue){
    if (tree != nullptr){
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}
void InOrder(TreeNode* tree, QueType& inQue){
    if (tree != nullptr){
        InOrder(tree->left, preQue);
        inQue.Enqueue(tree->info);
        InOrder(tree->right, preQue);
    }
}
void PostOrder(TreeNode* tree, QueType& postQue){
    if (tree != nullptr){
        
        PostOrder(tree->left, preQue);
        PostOrder(tree->right, preQue);
        postQue.Enqueue(tree->info);
    }
}


void TreeType::GetNextItem(OrderType order,bool& finished){
    finished = false;
    switch(order){  
        case PRE_ORDER : 
            preQue.Dequeue(item);
            if(preQue.IsEmpty()) finished = true;
            break;
        case IN_ORDER:
            inQue.Dequeue(item);
            if(inQue.IsEmpty()) finished = true;
            break;
        case POST_ORDER;
            postQue.Dequeue(item);
            if(postQue.IsEmpty()) finished = true;
            break;
    }
}

// 삽입 장소 찾기 등에 사용 (nodePtr, parentPtr 이런거 다 바뀌니까..)
void FindNode(TreeNode* tree, ItemType item, TreeNode*& nodePtr, TreeNode*& parentPtr){
    nodePtr = tree; // 복사하기
    parentPtr = nullptr;
    bool found = false;
    while(nodePtr != nullptr && !found){
        if(item < nodePtr->info){
            parentPtr = nodePtr;
            nodePtr = nodePtr->left;
        }
        else if(item > nodePtr->info){
            parentPtr = nodePtr;
            nodePtr = nodePtr->right;
        }
        else{
            found = true;
        }
    }
}

void TreeType::PutItem(ItemType item){
    TreeNode* newNode;
    TreeNode* nodePtr;
    TreeNode* parentPtr;
    newNode = new TreeNode;
    newNode->info = item;
    newNode->left = nullptr;
    newNode->right = nullptr;

    FindNode(root, item, nodePtr, parentPtr);

    if (parentPtr == NULL){ //parentPtr이 null이라는건 root뿐.
        root = newNode;
    }
    else if (item < parentPtr->info){  // 일반적인 경우임.
        parentPtr->left = newNode;
    }
    else{
        parentPtr->right = newNode;
    }
}

void TreeType::DeleteItem(ItemType item){
    TreeNode* nodePtr;
    TreeNode* parentPtr;
    FindNode(root, item, nodePtr, parentPtr);
    if (nodePtr == root){
        DeleteNode(root);
    }
    else{
        if (parentPtr->left == nodePtr){
            DeleteNode(parentPtr->left);
        }
        else{
            DeleteNode(parentPtr->right);
        }
    }
}