#include<bits/stdc++.h>
#include<string.h>
#include<list>
using namespace std;

const int tablesize = 10;       //Initializing the table size of the Hashtable

class Hash_table  {
     private:
        int GRs[tablesize];      //declaring an integer array to store GR numbers
        string Names[tablesize];        //declaring string array to store names 


     public:
        int Hashfunct(int GR_No);       
        void insertKey(int GR_No , string name);      
        void deleteKey(int GR_No);        
        void modifyKey(int GR_No , string name);      
        int searchKey(int GR_No);       
        void print_table();       
        void print_key_value(int GR_No);      
        void sort_key(int l, int r);         
        void merge(int l, int m, int r);
        void SortNames(int n);

        Hash_table()      //Constructor to initialize all GR array elements to 0
        {
           for (int i = 0; i<tablesize; i++) 
           {
              GRs[i] = 0;
           }
        }
};

int Hash_table::Hashfunct(int GR_No)         //Hash function(To find index of key to be inserted(or searched))
{
   return (GR_No) % tablesize;
}

void Hash_table::insertKey(int GR_No, string name)        //Insert function(The GR number is the the key and the name is the value)
{
   int index = Hashfunct(GR_No);
   while (GRs[index] != 0  &&  GRs[index] != GR_No)          //Condition to avoid collisions
   {
      index = Hashfunct(index + 1);
   }
   GRs[index] = GR_No;           //Insertion of key in array
   Names[index] = name;          //Insertion of value in array
}

int  Hash_table::searchKey(int GR_No)         //Function to search the index of given key
 {
    int count = 0;
    for(int i=0; i<tablesize; i++)
    {
        if(GRs[i] == GR_No)        
        {
            count++;  
            return i;          //Returning the index of key
            break;
        } 

    }
    if(count == 0)
    {
        cout<< "Sorry, this GR Number is not valid" <<endl;         
    }    
 }

void Hash_table::print_key_value(int GR_No)      //Function to print a particular key-value pair
 {
    int x;
    x = searchKey(GR_No);
    cout << "GR Number :" <<GRs[x] << endl;
    cout << "Name :" << Names[x] << endl;
 }

void Hash_table::modifyKey(int GR_No , string name)      //Function to change the value(name) of an existing key 
 {
    int p;
    p = searchKey(GR_No);
    Names[p] = name;
    cout << "Updated information:" << endl;
    print_key_value(GR_No);
 }

void  Hash_table::deleteKey(int GR_No)       //Function to delete the existing key
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

void Hash_table::print_table()       //Function to print entire hash table
{
    cout << "GR Number" << "\t" << "Name" << endl;
    for(int i=0; i<tablesize; i++) {
        if(GRs[i] != 0) {
            cout << GRs[i] << "\t\t" << Names[i] << endl;
        }
    }
}

void Hash_table::merge(int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // create temp arrays 
    int L[n1], R[n2];
    string LS[n1], RS[n2]; 
  
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) { 
        L[i] =GRs [l + i];
        LS[i] = Names[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = GRs[m + 1 + j];
        RS[j] = Names[m + 1 + j];
    }
     
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            GRs[k] = L[i];
            Names[k] = LS[i]; 
            i++; 
        } 
        else { 
            GRs[k] = R[j];
            Names[k] = RS[j];
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of L[], if there are any 
    while (i < n1) { 
        GRs[k] = L[i];
        Names[k] = LS[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of R[], if there are any 
    while (j < n2) { 
        GRs[k] = R[j];
        Names[k] = RS[j]; 
        j++; 
        k++; 
    } 
} 
  
// l is for left index and r is right index of the sub-array of arr to be sorted 
void Hash_table::sort_key(int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        sort_key(l, m); 
        sort_key(m + 1, r); 
  
        merge(l, m, r); 
    } 
} 

void Hash_table::SortNames(int n) 
{ 
    int index[n]; 
    int i, j, min; 

    for (i=0; i<n; i++) 
        index[i] = i;           //inserting index value at the corresponding index
      
    // selection sort     
    for (i=0; i<n-1; i++)     
    { 
        min = i; 
        for (j=i+1; j<n; j++) 
        { 
          if (GRs[i] != 0  &&  GRs[j] != 0)       //comparing only those indices which have GR Nos and Names into it
          {
            if (Names[index[min]].compare(Names[index[j]]) > 0) 
                min = j; 
          }
        }
        
            if (min != i) 
            { 
                //changing the elements of index array as per the alphabetical order of words
                int temp = index[min]; 
                index[min] = index[i]; 
                index[i] = temp; 
            } 
          
    } 
    cout << "Sorted names and corresponding GRs---" << endl;
    for (i=0; i<n; i++) {
     if (GRs[i] != 0) {
        cout << Names[index[i]] << "      " << GRs[index[i]] << endl;  //printing in sorted order
    }
    }
}  

int main()
 {

    int x,y,v;
    Hash_table h1;
    int c;
    string n;
     while (1) 
     {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Modify value of particular key"<<endl;
      cout<<"5.Print the table"<<endl;
      cout<<"6.Print a key-value pair"<<endl;
      cout<<"7.Sort the table by keys"<<endl;
      cout<<"8.Sort the table by values:"<<endl;
      cout<<"9.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) 
      {
         case 1:
            cout<<"Enter the Gr_number to be inserted: ";
            cin>>v;
            cout<<"Enter the name to be inserted: ";
            cin>>n;
            h1.insertKey(v, n);
         break;
         case 2:
            cout<<"Enter Gr_number  to be searched: ";
            cin>>v;
            x=h1.searchKey(v);
            cout<<"Index:"<<x<<endl;
         break;
         case 3:
            cout<<"Enter Gr_nummber to be deleted: ";
            cin>>v;
            h1.deleteKey(v);
         break;
         case 4:
              cout<<"Enter the GR_number and name to be modified:"<<endl;
              cin>>v;
              cin>>n;
              h1.modifyKey(v,n);
              break;
         case 5:
              h1.print_table();
              break;
         case 6:
              cout<<"Enter the GR_number to print key-vale:";
              cin>>v;
              h1.print_key_value(v);
              break;
         case 7:
              h1.sort_key(0,9);
              break;
         case 8:
              h1.SortNames(10);
              break;
         case 9:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }
    
    return 0;

}