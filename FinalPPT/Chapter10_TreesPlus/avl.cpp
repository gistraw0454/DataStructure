#include <iostream>
using namespace std;

struct TreeNode {
    int info;
    TreeNode* left;
    TreeNode* right;
};

class TreeType {
private:
    TreeNode* root;

    // 오른쪽 회전
    TreeNode* RotateRight(TreeNode* T) {
        TreeNode* S = T->left;  // S 가져오기
        TreeNode* B = S->right;
        S->right = T;
        T->left = B;
        return S;
    }

    // 왼쪽 회전
    TreeNode* RotateLeft(TreeNode* T) {
        TreeNode* S = T->right;  // S 가져오기
        TreeNode* B = S->left;
        S->left = T;
        T->right = B;
        return S;
    }

    // 오른쪽-왼쪽 회전
    TreeNode* RotateRightLeft(TreeNode* T) {
        TreeNode* S = T->right;
        T->right = RotateRight(S);  // R
        return RotateLeft(T);   // L
    }

    // 왼쪽-오른쪽 회전
    TreeNode* RotateLeftRight(TreeNode* T) {
        TreeNode* S = T->left;
        T->left = RotateLeft(S);  // R
        return RotateRight(T);   // L
    }

    // 노드의 높이 계산
    int Height(TreeNode* Tree) const {
        if (Tree == nullptr) return 0;  // 높이 0 반환
        else {
            int heightLeft = Height(Tree->left);
            int heightRight = Height(Tree->right);
            if (heightLeft > heightRight) return heightLeft + 1;
            else return heightRight + 1;
        }
    }

    // Balance Factor 계산
    int Difference(TreeNode* T) const {   // balance factor 구하기
        return Height(T->left) - Height(T->right);
    }

    // 트리 균형 유지
    TreeNode* Balance(TreeNode* T) {
        int balanceFactor = Difference(T);
        if (balanceFactor > 1) { // left로 쏠림
            if (Difference(T->left) >= 0) return RotateRight(T);   // 자식도 쏠림
            else return RotateLeftRight(T); // 완전 쏠린 건 아님
        } else if (balanceFactor < -1) {   // right로 쏠림
            if (Difference(T->right) <= 0) return RotateLeft(T);    // 자식도 쏠림
            else return RotateRightLeft(T); // 완전 쏠린 건 아님
        } else return T;  // 균형 O
    }

    // 노드 삽입
    void Insert(TreeNode*& tree, int item) {
        if (tree == nullptr) {
            tree = new TreeNode;    // 이렇게 완전 포인터를 바꿔버릴 수 있으니 &로 받아오기
            tree->right = nullptr;
            tree->left = nullptr;
            tree->info = item;
        } else if (item < tree->info) {
            Insert(tree->left, item);
            tree = Balance(tree); // 삽입 후 균형 조정
        } else {
            Insert(tree->right, item);
            tree = Balance(tree); // 삽입 후 균형 조정
        }
    }

public:
    TreeType() : root(nullptr) {}

    void PutItem(int item) {
        Insert(root, item);  // 트리 삽입
    }

    // 트리 출력 (중위 순회)
    void PrintTree(TreeNode* tree) const {
        if (tree != nullptr) {
            PrintTree(tree->left);
            cout << tree->info << " ";
            PrintTree(tree->right);
        }
    }

    void Print() const {
        PrintTree(root);  // 전체 트리 출력
        cout << endl;
    }
};

int main() {
    TreeType tree;

    // 트리 삽입
    tree.PutItem(10);
    tree.PutItem(20);
    tree.PutItem(30);
    tree.PutItem(5);
    tree.PutItem(15);
    tree.PutItem(25);

    // 트리 출력
    cout << "Inorder traversal of the AVL tree:" << endl;
    tree.Print();

    return 0;
}

//Inorder traversal of the AVL tree:
// 5 10 15 20 25 30
