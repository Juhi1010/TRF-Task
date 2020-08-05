#include<bits/stdc++.h>
#include<string.h>
#include<list>
using namespace std;

const int tablesize = 10;       //Initializing the table size of the Hashtable

class Hash_table  {
     private:
        int GRs[tablesize]; //declaring an integer array to store gr numbers
        string Names[tablesize]; //declaring string array to store names 


     public:
        int Hashfunct(int GR_No); //To find index of key to be inserted
        void insertKey(int GR_No , string name); //The GR number is the the key and the name is the value
        void deleteKey(int GR_No); //Function to delete the existing key
        void modifyKey(int GR_No , string name); //Function to change the valu(name) of n existing key
        int searchKey(int GR_No); //Function to search the index of given key
        void print_table(); //Function to print entire hash table
        void print_key_value(int GR_No); //Function to print a single key-value pair

        Hash_table() //Constructor to initialize all GR array elements to 0
        {
           for (int i = 0; i<tablesize; i++) 
           {
              GRs[i] = 0;
           }
        }
};

int Hash_table::Hashfunct(int GR_No) //Hash function
{
   return (GR_No) % tablesize;
}

void Hash_table::insertKey(int GR_No, string name) //Insert function 
{
   int index = Hashfunct(GR_No);
   while (GRs[index] != 0  &&  GRs[index] != GR_No) //Condition to avoid collisions
   {
      index = Hashfunct(index + 1);
   }
   GRs[index] = GR_No; //Insertion of key in array
   Names[index] = name; //Insertion of value in array
}
int  Hash_table::searchKey(int GR_No) //Search function.
 {
    int count=0;
    for(int i=0;i<tablesize;i++)
    {
        if(GRs[i]==GR_No)
        {
            count++;  
            return i; //Returning the index of key
            break;
        } 

    }
    if(count==0)
    {
        cout<<"Sorry this GR Number is not valid"<<endl;         
    }    

 }

 void Hash_table::print_key_value(int GR_No) //Function for priting particular key-value pair .
 {
     int x;
     x=searchKey(GR_No);
     cout<<"GR Number :"<<GRs[x]<<endl;
     cout<<"Name :"<<Names[x]<<endl;

 }
 void Hash_table::modifyKey(int GR_No , string name)//Function to modify value 
 {
int p;
 p=searchKey(GR_No);
 Names[p]=name;
 cout<<"Updated information:"<<endl;
 print_key_value(GR_No);
 }

void  Hash_table::deleteKey(int GR_No) //Delete key function
{
    int index = searchKey(GR_No);
    if (GRs[index] == 0){
        cout << "Key not found" << endl;
    }
    else{
        GRs[index] = 0;
        cout << "Key-Value pair DELETED" << endl;
    }
}

void Hash_table :: print_table() //Print function
{
    cout << "GR Number" << "\t" << "Name" << endl;
    for(int i=0;i<tablesize;i++) {
        if(GRs[i] != 0) {
            cout << GRs[i] << "\t\t" << Names[i] << endl;
        }
    }
}

int main() 
{
    int x,y;
    Hash_table h1;
    h1.insertKey(11910360,"Prapti");
     h1.insertKey(1191022,"Juhi");
     h1.insertKey(1191044,"Harshita");
     x=h1.searchKey(1191044);
    cout<<"Index :"<<x<<endl;
     h1.searchKey(119103433);
     h1.deleteKey(1191044);
     h1.searchKey(1191044);
     h1.print_table();
    h1.modifyKey(11910360,"Aarya");
} 