#include<bits/stdc++.h>
#include<string.h>
#include<list>
using namespace std;

const int tablesize = 10;       //Initializing the table size of the Hashtable

class Hash_table  {
     private:
        int GRs[tablesize];
        string Names[tablesize];
        

     public:
        int Hashfunct(int GR_No);
        void insertKey(int GR_No , string name);       //The GR number is the the key and the name is the value
        void deleteKey(int GR_No);
        void modifyKey(int GR_No , string name);
        int searchKey(int GR_No);
        void print();
        void print_key_value(int GR_No);

        Hash_table() {
           for (int i = 0; i<tablesize; i++) {
              GRs[i] = 0;
           }
        }
};

int Hash_table::Hashfunct(int GR_No) 
{
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
int  Hash_table::searchKey(int GR_No)//Function for searching a key.
 {
     int i;
     int count=0;
     for(int i=0;i<tablesize;i++)
     {
         if(GRs[i]==GR_No)
         {
             count++;  
            return i;
            break;
         } 
          
     }
     print_key_value(GR_No);
     if(count==0)
     {
cout<<"Sorry this GR Number is not valid"<<endl;         
     }    

 }
 void Hash_table::print_key_value(int GR_No)//Function for priting particular key value .
 {
     int x;
     x=searchKey(GR_No);
     cout<<"GR Number :"<<GRs[x]<<endl;
     cout<<"Name :"<<Names[x]<<endl;

 }

int main() {
    int x;
    int y;
    Hash_table h1;
  h1.insertKey(11910360,"Prapti");
  h1.insertKey(1191022,"Juhi");
  h1.insertKey(1191044,"Harshita");
  x=h1.searchKey(1191044);
  cout<<"Index :"<<x<<endl;
  y=h1.searchKey(119103433);
 
}