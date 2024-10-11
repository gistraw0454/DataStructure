enum RelationType{LESS, EQUAL,GREATER};

class ItemType{
    public:
    RelationType ComparedTo(ItemType) const;
    void Print() const;
    void Initialize (int number);
    private:
        int value;
};
