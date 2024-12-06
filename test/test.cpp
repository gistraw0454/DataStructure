#include <iostream>
using namespace std;

class ItemType {
public:
    int a;
    int n;
    ItemType(int c = 0, int e = 0) {
        a = c;
        n = e;
    }
};

struct NodeType {
    ItemType info;
    NodeType* next;
};

class SortedType {
public:
    SortedType();
    ~SortedType();
    void PutItem(ItemType item);
    void Print();
    SortedType Add(SortedType& poly2);
    SortedType Mul(SortedType& poly2);

private:
    NodeType* listData;
};

SortedType::SortedType() {
    listData = nullptr;
}

SortedType::~SortedType() {
    NodeType* tempPtr;
    while (listData != nullptr) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

void SortedType::PutItem(ItemType item) {
    NodeType* predLoc = listData;
    NodeType* resultNode;
    resultNode = new NodeType;
    resultNode->info = item;
    resultNode->next = nullptr;

    if (listData == nullptr || (listData->info.n) < item.n) {

        resultNode->next = listData;
        listData = resultNode;
    }
    else {
        while ((predLoc->next) != nullptr && ((predLoc->next)->info.n) >= item.n) predLoc = predLoc->next;
        
        resultNode->next = predLoc->next;
        predLoc->next = resultNode;
    }
}

// 다항식 합 구하기
SortedType SortedType::Add(SortedType& poly2) {
    SortedType result;
    NodeType* poly1Ptr = listData;
    NodeType* poly2Ptr = poly2.listData;

    // poly1 , poly2 둘다 null이 아닌 동안 돌면서 다항식 합 구하기
    while (poly1Ptr!=nullptr && poly2Ptr!=nullptr) {

        if ((poly1Ptr->info.n) > (poly2Ptr->info.n)) {
            result.PutItem(poly1Ptr->info);
            poly1Ptr = poly1Ptr->next;
        }
        else if ((poly1Ptr->info.n) < (poly2Ptr->info.n)) {
            result.PutItem(poly2Ptr->info);
            poly2Ptr = poly2Ptr->next;
        }
        else {
            
            int resultA = 0;
            resultA = poly1Ptr->info.a + poly2Ptr->info.a;
            
            if (resultA != 0) result.PutItem(ItemType(resultA, poly1Ptr->info.n));

            poly1Ptr = poly1Ptr->next;
            poly2Ptr = poly2Ptr->next;
        }
    }

    // 둘중하나라도 null이 아니면 PutItem 추가로 해주기
    while (poly1Ptr != nullptr) {
        result.PutItem(poly1Ptr->info);
        poly1Ptr = poly1Ptr->next;
    }

    while (poly2Ptr != nullptr) {
        result.PutItem(poly2Ptr->info);
        poly2Ptr = poly2Ptr->next;
    }

    return result;
}

SortedType SortedType::Mul(SortedType& poly2) {
    SortedType result;
    NodeType* poly1Ptr;
    poly1Ptr = listData;

    while (poly1Ptr != nullptr) {

        NodeType* poly2Ptr= nullptr;
        poly2Ptr = poly2.listData;

        // null이 아닌 동안 돌면서 다항식 곱 구하기
        
        while (poly2Ptr!=nullptr) {
            int resultA = poly1Ptr->info.a * poly2Ptr->info.a;
            int resultN = poly1Ptr->info.n + poly2Ptr->info.n;

            NodeType* resPtr = nullptr;
            resPtr = result.listData;

            bool found = 0;
            while (resPtr!=nullptr) {

                if (resPtr->info.n == resultN) {
                    resPtr->info.a += resultA;
                    found = true;
                    break;
                }

                
                resPtr = resPtr->next;
            }
            
            // 
            if (!found) result.PutItem(ItemType(resultA, resultN));

            poly2Ptr = poly2Ptr->next;
        }
        poly1Ptr = poly1Ptr->next;
    }

    return result;
}

void SortedType::Print() {
    NodeType* location = listData;
    while (location != nullptr) {
        cout << location->info.a << " " << location->info.n << endl;
        location = location->next;
    }
}

int main() {
    SortedType poly1, poly2;
    int nNum;

    // 다항식 덧셈 +
    cin >> nNum;
    for (int i = 0; i < nNum; ++i) {
        int a, n;
        cin >> a >> n;
        poly1.PutItem(ItemType(a, n));
    }

    // 다항식 곱셈 *
    cin >> nNum;
    for (int i = 0; i < nNum; ++i) {
        int a, n;
        cin >> a >> n;
        poly2.PutItem(ItemType(a, n));
    }

    SortedType sumResult = poly1.Add(poly2);
    sumResult.Print();

    SortedType productResult = poly1.Mul(poly2);
    productResult.Print();

    return 0;
}
