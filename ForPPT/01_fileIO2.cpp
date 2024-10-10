#include <fstream>
int main(){
    using namespace std;
    int partNumber;
    float unitPrice;
    ifstream inFile;
    ofstream outFile;

    inFile.open("input.dat");   //읽기 모드로 파일 열기
    outFile.open("output.dat"); //쓰기 모드로 파일 열기

    inFile >> partNumber;   // 파일에서 읽어와 차례로 저장
    inFile >> unitPrice;
    outFile << "Part # " << partNumber << "at Unit Cost: $ "<<unitPrice << endl;
    // 파일에 내용 쓰기
    return 0;
}