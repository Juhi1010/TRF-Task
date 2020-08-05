#include<bits/stdc++.h>
#include<string.h>
#include<list>
using namespace std;

const int tablesize = 10;       //Initializing the table size of the Hashtable

class Hash_table  {
     private:
        int GRs[tablesize];
        string Names[tablesize];
        int *ptr = GRs;

     public:
        int Hashfunct(int GR_No);
        void insertKey(int GR_No , string name);       //The GR number is the the key and the name is the value
        void deleteKey(int GR_No);
        void modifyKey(int GR_No , string name);
        int searchKey(int GR_No);
        void print();

        Hash_table() {
           for (int i = 0; i<tablesize; i++) {
              GRs[i] = 0;
           }
        }
};

int Hash_table::Hashfunct(int GR_No) {
   return (GR_No) % tablesize;
}

void Hash_table::insertKey(int GR_No, string name) {
   int index = Hashfunct(GR_No);
   while (GRs[index] != 0  &&  GRs[index] != GR_No) {
      index = Hashfunct(index + 1);
   }
   GRs[index] = GR_No;
   Names[index] = name;
}

int main() {
 
}