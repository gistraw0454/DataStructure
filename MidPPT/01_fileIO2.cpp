#include <fstream>
int main(){
    using namespace std;
    int partNumber;
    float unitPrice;
    ifstream inFile;
    ofstream outFile;

    inFile.open("input.dat");   //�б� ���� ���� ����
    outFile.open("output.dat"); //���� ���� ���� ����

    inFile >> partNumber;   // ���Ͽ��� �о�� ���ʷ� ����
    inFile >> unitPrice;
    outFile << "Part # " << partNumber << "at Unit Cost: $ "<<unitPrice << endl;
    // ���Ͽ� ���� ����
    return 0;
}