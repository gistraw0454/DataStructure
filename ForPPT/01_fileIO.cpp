#include <fstream>  //���� ����������� stream

using namespace std;


int main(){
    //declaration
    ifstream myInfile;
    ofstream myOutfile;

    //file opens
    
    myInfile.open("myIn.dat");
    myOutfile.open("myOut.dat");

    //file close
    myInfile.close();
    myOutfile.close();
}