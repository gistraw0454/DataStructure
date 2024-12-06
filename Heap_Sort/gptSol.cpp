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

        if (leftChild <= bottom) { // �ڽ� ��尡 ������
            maxChild = leftChild; // ���� �ڽĺ��� ����
            if (rightChild <= bottom && elements[leftChild].name < elements[rightChild].name) {
                maxChild = rightChild; // ������ �ڽ��� �� ũ�� ������ ����
            }

            if (elements[root].name < elements[maxChild].name) { // �θ𺸴� �ڽ��� ũ�� ����
                Swap(elements[root], elements[maxChild]);
                ReheapDown(maxChild, bottom);
            }
        }
    }

    void ReheapUp(int root, int bottom) {
        if (bottom > root) { // Ž���� �� ������
            int parent = (bottom - 1) / 2;
            if (elements[parent].name < elements[bottom].name) { // �θ𺸴� ũ�� ����
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
        for (int i = elements.size() / 2 - 1; i >= 0; --i) { // �� building
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

			string name = input.substr(0, delimiter);	// delimiter �ε��� 01234 : 89 �Է��ϸ� 5�� ����. substr(�ε���, ����)�� str�ڸ���.
			string capital = input.substr(delimiter + 3);	// 8 ~ ������ str�ڸ���

			Country inputCountry;
			inputCountry.name = name;
			inputCountry.capital = capital;
			
			heap.Insert(inputCountry);
        
    }

    heap.Sort();
    heap.Print();

    return 0;
}
