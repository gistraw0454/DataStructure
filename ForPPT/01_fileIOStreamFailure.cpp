#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream inFile;
    inFile.open("input.dat");
    if(!inFile){
        cout << "File input.dat could not be opened";
        return 1;
    }
    // codes..
    return 0;
}