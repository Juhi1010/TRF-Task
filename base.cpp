#include<bits/stdc++.h>
#include<string.h>
#include<list>
using namespace std;

const int tablesize = 10;       //Initializing the table size of the Hashtable

class Hash_table  {
     private:
        list<pair<int, string>> hashtable[tablesize];

     public:
        int Hashfunct(int GR No);
        void insertKey(int GR No , string name);       //The GR number is the the key and the name is the value
        void deleteKey(int GR No);
        void modifyKey(int GR no , string name);
        int searchKey(int GR No);
        void print();
};

int main() {

}