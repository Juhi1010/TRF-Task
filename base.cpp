#include<bits/stdc++.h>
#include<string.h>
#include<list>
using namespace std;

const int tablesize = 10;       //Initializing the table size of the Hashtable

class Hash_table  {
     private:
        int GRs[tablesize];
        char Names[tablesize];

     public:
        int Hashfunct(int GR_No);
        void insertKey(int GR_No , string name);       //The GR number is the the key and the name is the value
        void deleteKey(int GR_No);
        void modifyKey(int GR_No , string name);
        int searchKey(int GR_No);
        void print();
};

int Hash_table::Hashfunct(int GR_No) {
return (GR_No) % tablesize;
}

int main() {

}