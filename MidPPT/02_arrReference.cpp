#include <iostream>
// []�� �׻� reference���·� ���޵Ǵµ�, const�� �̸� ��ȣ ����
float SumValues (const float values[],int numOfValues){
    float sum=0;
    for (int index =0; index< numOfValues;index++){
        sum = values[index] +sum;
    }
    return sum;
}



int main() {
    float arr1[4] = {1.2, 2.2, 3.3, 4.4};  // 4���� float ��ҷ� ������ �迭
    
    std::cout << SumValues(arr1, 4);  // �迭�� ù 4�� ����� ���� ���
}
