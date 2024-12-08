template<class ItemType>
bool BinarySearch(ItemType info [], ItemType item, int fromLoc, int toLoc){
    int mid;
    if (fromLoc > toLoc)  return false;
    else{
        mid = (fromLoc + toLoc)/2;
        if (info[mid]== item){
            return BinarySearch(info, item, fromLoc,mid-1);
        }
        else{
            return BinarySearch(info, item, mid+1, toLoc);
        }
    }
}