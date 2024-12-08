#include <iostream>
// []은 항상 reference형태로 전달되는데, const로 이를 보호 가능
float SumValues (const float values[],int numOfValues){
    float sum=0;
    for (int index =0; index< numOfValues;index++){
        sum = values[index] +sum;
    }
    return sum;
}



int main() {
    float arr1[4] = {1.2, 2.2, 3.3, 4.4};  // 4개의 float 요소로 구성된 배열
    
    std::cout << SumValues(arr1, 4);  // 배열의 첫 4개 요소의 합을 출력
}
