#include <string>
#include "Item.h"
using std::string;

class Hash {
    private:
        static const int table_size = 10;
        //Create HashTable Item array with the size of "table_size"
        Item *HashTable[table_size];

    public:
        Hash();
        int HashValue(string name);
        void Insert(string name);
};