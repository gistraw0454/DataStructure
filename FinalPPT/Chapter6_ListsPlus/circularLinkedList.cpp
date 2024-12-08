template<class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc, bool& found){
    bool moreToSearch = true;

    location = listData->next;
    predLoc = listData;
    found = false;

    while(moreToSearch && !found){  // 더 돌게 있음 && 못! 찾음
        if (item.ComparedTo(location->info) == LESS){
            moreToSearch = false;   // 이미 지남
        }
        else if (item.ComparedTo(location->info) == EQUAL){
            found = true;   // 찾음
        }
        else{
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);    // 처음으로 돌아오지않았으면 true로 계속 진행 (아직 한 바퀴 안 돌았으면) 
        }
    }
}

template<class ItemType>
void SortedType<ItemType>::PutItem(ItemType item){
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool found;

    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (listData != NULL){
        FindItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;

        // if insert in last?
        if ((listData->info.ComparedTo(item))==LESS){
            listData = newNode;
        }
    }
    else{   // if insert in empty list?
        listData = newNode;
        newNode->next = newNode;
    }
    length++;
}

template<class ItemType>
void SortType<ItemType>::DeleteItem(ItemType item){
    NodeType<ItemType>* location;
    NodeType<ItemType>* predLoc;
    bool found;

    FindItem(listData, item, location, predLoc, found);
    if (found){ // item이 list안에 있을 때
        if (predLoc == location){   // 값이 하나 뿐일 때
            listData = nullptr;
        }
        else{
            predLoc->next = location->next;
            if (location == listData){  // location이 마지막이면
                listData = predLoc;
            }
        }
        delete location;
        length--;
    }
}