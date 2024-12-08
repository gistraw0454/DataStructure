template<class ItemType>
struct NodeType{
    ItemType info;
    NodeType<ItemType>* next;
    NodeType<ItemType>* back;
}

template<class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, bool& found){
    bool moreToSearch = true;

    location = listData;
    found = false;
    while(moreToSearch&& !found){
        if (item < location->info){
            moreToSearch = false;
        }
        else if (item == location->info){
            found = true;
        }
        else{
            location = location->next;
            moreToSearch = (location != NULL);  // locaion->next 가 null인 경우 즉, 마지막 노드였을 경우 더이상 찾을 게 없다.
        }
    }
}
