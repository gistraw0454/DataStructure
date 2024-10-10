#include <fstream>  //파일 입출력을위한 stream

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