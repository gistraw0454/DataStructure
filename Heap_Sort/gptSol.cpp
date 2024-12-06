#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Country {
    string name;
    string capital;
};

class Heap {
private:
    vector<Country> elements;

    void Swap(Country& a, Country& b) {
        Country temp = a;
        a = b;
        b = temp;
    }

    void ReheapDown(int root, int bottom) {
        int maxChild;
        int leftChild = root * 2 + 1;
        int rightChild = root * 2 + 2;

        if (leftChild <= bottom) { // 자식 노드가 있으면
            maxChild = leftChild; // 왼쪽 자식부터 시작
            if (rightChild <= bottom && elements[leftChild].name < elements[rightChild].name) {
                maxChild = rightChild; // 오른쪽 자식이 더 크면 오른쪽 선택
            }

            if (elements[root].name < elements[maxChild].name) { // 부모보다 자식이 크면 스왑
                Swap(elements[root], elements[maxChild]);
                ReheapDown(maxChild, bottom);
            }
        }
    }

    void ReheapUp(int root, int bottom) {
        if (bottom > root) { // 탐색할 게 있으면
            int parent = (bottom - 1) / 2;
            if (elements[parent].name < elements[bottom].name) { // 부모보다 크면 스왑
                Swap(elements[parent], elements[bottom]);
                ReheapUp(root, parent);
            }
        }
    }

public:
    void Insert(const Country& country) {
        elements.push_back(country);
        ReheapUp(0, elements.size() - 1);
    }

    void Sort() {
        for (int i = elements.size() / 2 - 1; i >= 0; --i) { // 힙 building
            ReheapDown(i, elements.size() - 1);
        }
        for (int i = elements.size() - 1; i >= 1; --i) {
            Swap(elements[0], elements[i]);
            ReheapDown(0, i - 1);
        }
    }

    void Print() {
        for (const auto& country : elements) {
            cout << country.name<<endl;
        }
    }
};

int main() {
    Heap heap;

    string input;
    while (true) {
			getline(cin, input);
			if (input == "End") break;

			size_t delimiter = input.find(" : ");

			string name = input.substr(0, delimiter);	// delimiter 인덱스 01234 : 89 입력하면 5가 나옴. substr(인덱스, 길이)로 str자르기.
			string capital = input.substr(delimiter + 3);	// 8 ~ 끝까지 str자르기

			Country inputCountry;
			inputCountry.name = name;
			inputCountry.capital = capital;
			
			heap.Insert(inputCountry);
        
    }

    heap.Sort();
    heap.Print();

    return 0;
}
