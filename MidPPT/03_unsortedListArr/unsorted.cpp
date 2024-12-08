#include "unsorted.h"

void UnsortedType::UnsortedType(){
    length=0;
}

int UnsortedType::GetLength() const{
    return length;
}

bool UnsortedType::IsFull() const{
    return (length == MAX_ITEMS);
}

ItemType UnsortedType::GetItem(ItemType item, bool& found){
    bool moreToSearch;
    int location=0;

    found = false;  //ã�ҳ�?
    moreToSearch = (location < length)  //�ٵ��ҳ�?
    while (moreToSearch && !found){ // ���� �� �ȵ� && ã������
        switch (item.ComparedTo(info[location])){   // ã�°��� ��ġ�� ��
            case LESS:
            case GREATER:
                location++;
                moreToSearch = (location < length);
                break;
            case EQUAL:
                found = true;
                item = info[location];
                break;
        }
    }
    return item;
}

void UnsortedType::PutItem(ItemType item){
    info[length] = item;    //�������� �־��ֱ�
    length++;   //���� 1�÷��ֱ�
}

void UnsortedType::DeleteItem(ItemType item){
    int location =0;    //��ġ 0���ͽ����ؼ� �� ���鼭, �Է°��� �������� ã�´�.
    while(item.ComparedTo(info[location])!=EQUAL) location++;
    info[location] = info[length-1];    //�߰��ϸ� �����Ե�. => �� ��ġ�� �迭�Ǹ��������� �ִ´�.
    length--;   //���̸� 1�ٿ��ش�.
}

void UnsortedType::MakeEmpty(){
    length =0;
}

void UnsortedType::ResetList(){
    currentPos = -1;   
}

ItemType UnsortedType::GetNextItem(){
    currentPos++;   //������ġ�� �̵�
    ItemType item = info[currentPos];    // ���� ��ġ�� �ִ� item�� return 
    return item;
}