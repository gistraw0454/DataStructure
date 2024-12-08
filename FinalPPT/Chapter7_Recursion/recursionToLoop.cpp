bool valueList_Recursion(ListType list, int val, int startIndex){
    if (list.info[startIndex] == val){
        return true;    // 찾음
    }

    else if (startIndex == list.length-1){
        return false;   // iterator가 끝까지 다 돌았다.
    }

    else{
        return valueList_Recursion(list, val, startIndex+1);
    }
}

bool valueList_Loop(ListType list, int val, int startIndex){
    bool found = false;

    while(!found && startIndex < list.length){
        if (vlist.info[startIndex] == val){
            found = bool;
        }
        startIndex++;
    }
    return found;
}