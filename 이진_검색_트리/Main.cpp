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

// 트리 클래스 정의
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

int main() {
    TreeType tree;

    size_t start = 0;
    size_t end = countryCapitalData.find('\n');

    while (end != string::npos) {
        string line = countryCapitalData.substr(start, end - start);
        if (line == "End")
            break;

        size_t colonPos = line.find(" : ");
        if (colonPos != string::npos) {
            ItemType item;
            item.country = line.substr(0, colonPos);
            item.capital = line.substr(colonPos + 3);
            tree.PutItem(item);
        }

        start = end + 1;
        end = countryCapitalData.find('\n', start);
    }

    // 사용자 입력 루프
    while (true) {
        string target;
        getline(cin, target);

        if (target == "Quit")
            break;

        int cmpCnt = tree.GetItem(target);
        if (cmpCnt == -1)	// 입력받은 국가가 존재하지않으면
				cout << "Country "<< target <<" is not found in the list.\n";
			else	// 입력받은 국가 검색을 위해 필요한 비교횟수 출력하기
				cout << target << " : " << cmpCnt << " times compared...\n";
    }

    return 0;
}
