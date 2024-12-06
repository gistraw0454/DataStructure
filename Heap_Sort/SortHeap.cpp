#include <iostream>
#include <string>
/* Heap sort를 구현하고, 주어진 문자열에서 데이터를 읽어 국가명을 기준으로 정렬 후 출력해라. */
/* 국가명 : 수도명 으로 여러줄의 입력이 주어진다. 입력끝은 End로 표기*/
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

	leftChild = root*2 + 1;
	rightChild = root*2 + 2;

	if (leftChild <= bottom ){	// elements[root]가 leaf가 아니면
		maxChild = leftChild;	// 더 큰값을 가진 자식index를 maxChild에 넣는다.
	}
	else{
		if (elements[leftChild]<=elements[rightChild]){
			maxChild = rightChild;
		}
		else{
			maxChild = leftChild;
		}
	}

	// root의 값 < maxChild값면 swap 후 다시 reheapdown
	if ( elements[root] < elements[maxChild]){
		Swap (elements[root],elements[maxChild]);
		ReheapDown(maxChild,bottom);
	}
}

void HeapType<Country>::ReheapUp(int root, int bottom){
	int parent;

	if (bottom>root){ // bottom > root 일 때, (아직 탐색할게 남아있을 때)
		parent = (bottom-1)/2;	// 부모노드 index
		if (elements[parent]<elements[bottom]){	// 부모노드 값< 자식노드 값이면 swap해주기
			Swap(elements[parents],elements[bottom]);
			ReheapUp(root,parent);
		}
	}
}

void HeapSort(Country values[],int numValues){
	int index;

	for (index = numValues/2-1; index>=0; index--){
		ReheapDown(values,index,numValues-1);
	}

	for (index = numValues-1; index >=1; index--){
		Swap (values[0], values[index]);
		ReheapDown(values,0,index-1);
	}
}


using namespace std;
int main() {

	// Heap sort 객체 생성

	while(1){
		string target;
		getline(cin, target);

		if (target == "End")
			break;

		// 노드 국가명 기준으로 정렬 하면서 추가
		
	}

	// 정렬된 내용 출력
}