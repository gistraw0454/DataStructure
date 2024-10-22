//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------StackType_H-----------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
const int MAX_ITEMS = 30;
typedef char ItemType;

class FullStack
// Exception class thrown by Push when stack is full.
// do nothing
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
// do nothing
{};

class StackType
{
public:

    StackType();
    // Class constructor.
    bool IsFull() const;
    // Determines whether the stack is full.
    bool IsEmpty() const;
    // Determines whether the stack is empty.
    void Push(ItemType item);
    // Adds newItem to the top of the stack.
    void Pop();
    // Removes top item from the stack.
    ItemType Top();
    // Returns a copy of top item on the stack.

private:
    int top;
    ItemType items[MAX_ITEMS];
};
StackType::StackType()
{
	top = -1;
}

bool StackType::IsEmpty() const
{
	return (top==-1);	// 초기값을 가리키면 Empty (True)
}

bool StackType::IsFull() const
{
	return (top==MAX_ITEMS-1);	// 인덱스의 값이 가장 마지막을 가리키면 Full (True)
}

void StackType::Push(ItemType newItem)
{
	if (IsFull()){
		throw FullStack();
	}
	top++;
	items[top] = newItem;
	
	return;
}

void StackType::Pop()
{
	if (IsEmpty()){
		throw EmptyStack();
	}
	top--;
	return;
}

ItemType StackType::Top()
{
	if (IsEmpty()){
		throw EmptyStack();
	
	}
	return items[top];
}
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------int main()------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
int main() {
    char str[31] = "";
    std::cin.getline(str,31,'\n');
    
    StackType charStack;
    
    int isPal = 1;
    
    // 문자열을 스택에 저장 (대소문자 구분 없이)
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z')) {
            continue;  // 문자만 처리
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
					// std::cout << char(str[i]-('A'-'a')) << "push\n";
            charStack.Push(str[i] - ('A' - 'a'));  // 대문자는 소문자로 변환하여 푸시
        } else {
					// std::cout << str[i] << "push\n";
            charStack.Push(str[i]);  // 소문자는 그대로 푸시
        }
    }

    // 팰린드롬 확인
    int i = 0;
    while (!charStack.IsEmpty()) {
        // 알파벳 문자만 확인
        while (!(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z')) i++;
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - ('A' - 'a');  // 대문자를 소문자로 변환
        }
				
			// std::cout << str[i];
			// std::cout << charStack.Top();
			
			
        if (charStack.Top() != str[i]) {
            isPal = 0;
            break;  // 팰린드롬이 아닌 경우
        }
        charStack.Pop();  // 스택에서 문자 제거
        i++;  // 다음 문자로 이동
    }

    if (isPal == 1) {
        std::cout << "The string is a palindrome.\n";
    } else {
        std::cout << "The string is not a palindrome.\n";
    }

    return 0;
}