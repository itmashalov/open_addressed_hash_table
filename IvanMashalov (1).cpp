#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <stdlib.h>
#include <iomanip>
#include <limits>

using namespace std;
//PlEASE USE C++ 11 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//This is the main class that implements the Hash Table
template<class T>
class HashTable
{
	
//T *table ;
string type;
int size;

//int *arr;
//int *arr;

// here i have 2 vectors, One for the table type template and another which will have the same size but it will be integer type and will take 1 values for for the indexes where the first vector has values and 0 for no values
//PlEASE USE C++ 11 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
vector<T> *vec=new vector<T>;
vector<int> *v = new vector<int>;
int index;
public:

	//The constructor for a hashtable which take the type and the size from the user we also set that size to our vectors
    
HashTable(string type, int size)
{
  this -> type = type;
  this -> size = size;
 // table  = new T[size];
   vec->resize(size);
   v->resize(size);




}


//this is my template function which sets the index for integers,doubles and floats.
template<typename K>
void getIndex(K word,int size) 
{	
	

	index=0;
	string type_of_par=typeid(word).name();
	

	 if(type_of_par.compare("i")==0){
		index=(int)word%size;	   	
	//	cout << "it's int"<<index<< endl;
	
	 }
	 if(type_of_par.compare("d")==0){
		
	   	index=(int)word%size;	
	//	cout << "it's double"<<index<< endl;
	 }
	
	if(type_of_par.compare("f")==0){
		index=(int)word%size;	   
	//	cout << "it's float"<<index<< endl;
	   
        }

        
}
//this is my template function which sets the index for strings and show the string in ascii code% size
void getIndex2(string word,int size) 
{	
	
index=0;
	
	string type_of_par=typeid(word).name();
	
 	 if(type_of_par.compare("Ss")==0 ){
		 for (int i = 0; i < word.length(); i++) 
		 { 
			char x = word.at(i);
			index=index+static_cast<int>(x);
			index=index%size;

		 }cout << "the index is	" <<type_of_par<<index<< endl;
	 }


}
//this is my template function which sets the index for chars where the char input is converted into ascii code
void getIndex3(char word,int size) 
{
	index = (static_cast<int>(word))%size;
}


~HashTable()
{
  cout << "Object destroyed." << endl;
}
   

//int convertToASCII(T,int);
void insert(T);
void print();
void del(T);
bool look_up(T in);    
int size1();
};

//template<typename T>


/*	]
ut
    this function converts a word into ascii code and returns the ascii code ot the word

*/


//Here we have template insert function. We pass something to this function like double,float,int,string and char
template<typename T>
void HashTable<T>::insert(T in){

 	int ins_ok=0;
  if(look_up(in)!=1){
//if(vec->at(index)!=in){

        if(v->at(index)==0){
            vec->at(index)=in;
            v->at(index)=1;

		}

		
        else{
		
	        if(v->at(index)!=0 ){
				
	                for(int i=0;i<size;i++){
	                    if(index+i<size){
	
	                        if(v->at(index+i)==0){
	                           //  if(look_up(in)==0){	
									vec->at(index+i)=in;
		                            v->at(index+i)=1;
		                            ins_ok=1;
		                            break;
		                      	 // }
								  //else{
								  	//	cout<<"Sorry the element is already in the table"<< endl;
								  //}
	                        }
	
	                    }
	                    
	
	                }
            	
            	
            	
               //if(look_up(in)==0){
	                if(ins_ok==0){
	                        index=0;
	                    for(int i=0;i<size;i++){
	
	                         if(index+i<size){
	
	                            if(v->at(index+i)==0){
	                                vec->at(index+i)=in;
	                                v->at(index+i)=1;
	                                ins_ok=1;
	                                break;
	
	                            }
	
	                        }
	
	                }
	
	
	
	
	
	
	                }
	      		//}
	      		//else{
    	 		//	cout<<"Sorry the element is already in the table"<< endl;
   			//	}
            }
        }
    }
    else{
  	   cout<<"Sorry the element is already in the table"<< endl;
    }
   
  //  else{
 //   	cout<<"Sorry the element is already in the table"<< endl;
   //}
}
//Here we have template delete function. We pass something to this function like double,float,int,string and char
template<typename T>
void HashTable<T>::del(T in){
 int del_ok=0;

	
        if(v->at(index)!=0 ){
			
		 	for(int i=0;i<size;i++){
			 	if(index+i<size){
			 	
				 	if(vec->at(index+i)==in){
			 			vec->at(index+i)=vec->back();
			 			vec->pop_back();
			 			vec->resize(size);
			 			
                        v->at(size-1)=0;
		    			del_ok=1;
		    			break;
		    			
			 		}
			 			
				}
				
		 	}
		 	
		 	if(del_ok==0){
					index=0;
				for(int i=0;i<size;i++){
				 	
					 if(index+i<size){
				 	
					 	if(vec->at(index+i)==in){
				 			vec->at(index+i)=vec->back();
				    		vec->pop_back();
				 			vec->resize(size);
				 			
                            v->at(size-1)=0;
			    			del_ok=1;
			    			break;
			    			
			    			
				 		}
				 			
					}
				
		 	}					
					
				
				
					
					
					
			}

			
		}
    


}

//Here we print function with no parameter which prints our hash table
template<typename T>
void HashTable<T>:: print(){
	//int bla = table[11];
	
//cout<<"indx is "<< index<<"word is"<<setprecision(15)<<	vec->at(index)<<vec->at(index+1)<< endl;
for(int i=0;i<size;i++){
	cout.precision(numeric_limits<double>::digits10 + 1);
	cout<<"\nindex: "<<i<<" element: "<<vec->at(i)<< endl;
}
	
}
//this is bool function which return 1 if the element is in the table and return 0 if it is not it has 1 parameter which is input from the user
template<typename T>
bool HashTable<T>::look_up(T in){
	
	
    int ind=index;
    int flag=0;
   
    
			
		 	for(int i=0;i<size;i++){
                if(ind+i<size){
			 	
                    if(vec->at(ind+i)==in){
			 			
                        cout<<"The element is in the table. "<<"Index:"<<ind+i<< endl;
                        flag=1;
			 			return 1;
		    			break;
		    			
			 		}
			 			
				}
				
            }
           
		 

            if(flag==0){
            
				for(int i=0;i<size;i++){
				 	                    				 	
                        if(vec->at(i)==in){
                            cout<<"The element is in the table. "<<"Index:"<<i<< endl;
			 				flag=1;
							 return 1;
		    				break;
			    			
			    			
				 		}
				 			
					
				
		 		}					
		}
				
				
					
				

			
	
			if(flag==0){
			
			cout<<"The element is not in the table"<< endl;
			return 0;
		}
	
	
	
	
	
	
	
	
}
//this function returns the number of the elements in the table
template<typename T>
int HashTable<T>::size1(){
	int siz=0;
	for(int i=0;i<size;i++){
        if(v->at(i)==1){
			siz++;
		}
	}
	cout<<"The size is:"<<siz<< endl;
	return siz;
}
		

// this is the menu function where the user have the option to create new table to choose type and size ot that table. After the table is 
//created the user have options like insert, delete, print, get size, search and create new table.
void  menu() 
{
	string type;
	int size;
	cout<<"Please enter the size of the table. "<<endl;
	cin>> size;
	cin.ignore();
	cout<< "please enter the type of the table: char, string, int, float or double. "<<endl;
	getline(std::cin, type);
	while (type.compare("float")!=0 && type.compare("double")!=0 && type.compare("int")!=0 && type.compare("char")!=0 && type.compare("string")!=0) 
	{
		//system("cls");
		cout<< "please enter the type of the table: char, string, int, float or double. "<<endl;
		getline(std::cin, type);
		
	}


	

	HashTable <int>k1(type, size );
	HashTable <string>k2(type, size );
	HashTable <float>k3(type, size );
	HashTable <double>k4(type, size );
	HashTable <char>k5(type, size );

	
	
	string choice;
	
	cout << "\n\n\nPress \"i\" to insert an element " << endl;
	cout << "Press \"d\" to Delete an element " << endl;
	cout << "Press \"s\" to Look up an element " << endl;
	cout << "Press \"n\" to see the number of elements stored in the hash table" << endl;
	cout << "Press \"p\" to prints out the current state of the hash table" << endl;
	cout << "press \"c\" to create a new table" << endl;
	cout << "Press \"exit\" to exit the program" << endl;
	
	getline(std::cin, choice);

	while(choice !="exit" ){
	
		if(choice=="i"){
			//system("cls");
			cout << "Please enter something:" << endl;
			 if(type.compare("int") == 0)
			 {
 				int input;
				cin>>input; 
				cin.ignore();
				k1.getIndex(input,size);
 				k1.insert(input);
 			 }
 			 if(type.compare("string") == 0)
			 {
 				string input;
				cin>>input; 
				//getline(std::cin, input);
				cin.ignore();
		    	k2.getIndex2(input,size);
 				k2.insert(input);
 	
 			 }
 			 if(type.compare("float") == 0)
			 {
 				float input;
				cin>>input; 
				cin.ignore();
				k3.getIndex(input,size);
 				k3.insert(input);
 	
 			 }
 			 if(type.compare("double") == 0)
			 {
 				double input;
				cin>>input; 
				cin.ignore();
				k4.getIndex(input,size);
 				k4.insert(input);
 	
 			 }
 			 if(type.compare("char") == 0)
			 {
 				char input;
				cin>>input; 
				cin.ignore();
				k5.getIndex3(input,size);
 				k5.insert(input);
 	
 			 }
			
		
			cout << "\n\n\nPress \"i\" to insert an element " << endl;
			cout << "Press \"d\" to Delete an element " << endl;
			cout << "Press \"s\" to Look up an element " << endl;
			cout << "Press \"n\" to see the number of elements stored in the hash table" << endl;
			cout << "Press \"p\" to prints out the current state of the hash table" << endl;
			cout << "press \"c\" to create a new table" << endl;
			cout << "Press \"exit\" to exit the program" << endl;
			getline(std::cin, choice);
		}
	
		if(choice=="d"){
			//system("cls");
			cout << "Please enter something:" << endl;
			 if(type.compare("int") == 0)
			 {
 				int input;
				cin>>input; 
				cin.ignore();
				k1.getIndex(input,size);
                k1.del(input);
 			 }
 			 if(type.compare("string") == 0)
			 {
 				string input;
				cin>>input; 
				//getline(std::cin, input);
				cin.ignore();
		    	k2.getIndex2(input,size);
                k2.del(input);
 	
 			 }
 			 if(type.compare("float") == 0)
			 {
 				float input;
				cin>>input; 
				cin.ignore();
				k3.getIndex(input,size);
                k3.del(input);
 	
 			 }
 			 if(type.compare("double") == 0)
			 {
 				double input;
				cin>>input; 
				cin.ignore();
				k4.getIndex(input,size);
                k4.del(input);
 	
 			 }
 			 if(type.compare("char") == 0)
			 {
 				char input;
				cin>>input; 
				cin.ignore();
				k5.getIndex3(input,size);
                k5.del(input);
 	
 			 }
			//hash1.delete_element();
			
			cout << "\n\n\nPress \"i\" to insert an element " << endl;
			cout << "Press \"d\" to Delete an element " << endl;
			cout << "Press \"s\" to Look up an element " << endl;
			cout << "Press \"n\" to see the number of elements stored in the hash table" << endl;
			cout << "Press \"p\" to prints out the current state of the hash table" << endl;
			cout << "press \"c\" to create a new table" << endl;
			cout << "Press \"exit\" to exit the program" << endl;
		
			getline(std::cin, choice);
		}
		if(choice=="s"){
			//system("cls");
			cout << "Please enter something:" << endl;
			 if(type.compare("int") == 0)
			 {
 				int input;
				cin>>input; 
				cin.ignore();
				k1.getIndex(input,size);
 				k1.look_up(input);
 			 }
 			 if(type.compare("string") == 0)
			 {
 				string input;
				cin>>input; 
				//getline(std::cin, input);
				cin.ignore();
		    	k2.getIndex2(input,size);
 				k2.look_up(input);
 	
 			 }
 			 if(type.compare("float") == 0)
			 {
 				float input;
				cin>>input; 
				cin.ignore();
				k3.getIndex(input,size);
 				k3.look_up(input);
 	
 			 }
 			 if(type.compare("double") == 0)
			 {
 				double input;
				cin>>input; 
				cin.ignore();
				k4.getIndex(input,size);
 				k4.look_up(input);
 	
 			 }
 			 if(type.compare("char") == 0)
			 {
 				char input;
				cin>>input; 
				cin.ignore();
				k5.getIndex3(input,size);
 				k5.look_up(input);
 	
 			 }

			
			cout << "\n\n\nPress \"i\" to insert an element " << endl;
			cout << "Press \"d\" to Delete an element " << endl;
			cout << "Press \"s\" to Look up an element " << endl;
			cout << "Press \"n\" to see the number of elements stored in the hash table" << endl;
			cout << "Press \"p\" to prints out the current state of the hash table" << endl;
			cout << "press \"c\" to create a new table" << endl;
			cout << "Press \"exit\" to exit the program" << endl;
		
			getline(std::cin, choice);
		}
		if(choice=="n"){
		//	system("cls");
			if(type.compare("int") == 0)
			 {
 				
 				k1.size1();
 			 }
 			 if(type.compare("string") == 0)
			 {
 				k2.size1();
 	
 			 }
 			 if(type.compare("float") == 0)
			 {
 				k3.size1();
 	
 			 }
 			 if(type.compare("double") == 0)
			 {
 				k4.size1();
 	
 			 }
 			 if(type.compare("char") == 0)
			 {
 				k5.size1();
 	
 			 }

			
			cout << "\n\n\nPress \"i\" to insert an element " << endl;
			cout << "Press \"d\" to Delete an element " << endl;
			cout << "Press \"s\" to Look up an element " << endl;
			cout << "Press \"n\" to see the number of elements stored in the hash table" << endl;
			cout << "Press \"p\" to prints out the current state of the hash table" << endl;
			cout << "press \"c\" to create a new table" << endl;
			cout << "Press \"exit\" to exit the program" << endl;
		
			getline(std::cin, choice);
		}
		if(choice=="p"){
			//system("cls\n");
			
			
		
			 if(type.compare("int") == 0)
			 {
 				k1.print();
 			 }
 			 if(type.compare("string") == 0)
			 {
 				k2.print();
 	
 			 }
 			 if(type.compare("float") == 0)
			 {
 				k3.print();
 	
 			 }
 			 if(type.compare("double") == 0)
			 {
 				k4.print();
 	
 			 }
 			 if(type.compare("char") == 0)
			 {
 				k5.print();
 	
 			 }
			
			
			cout << "\n\n\nPress \"i\" to insert an element " << endl;
			cout << "Press \"d\" to Delete an element " << endl;
			cout << "Press \"s\" to Look up an element " << endl;
			cout << "Press \"n\" to see the number of elements stored in the hash table" << endl;
			cout << "Press \"p\" to prints out the current state of the hash table" << endl;
			cout << "press \"c\" to create a new table" << endl;
			cout << "Press \"exit\" to exit the program" << endl;
		
			getline(std::cin, choice);
		}
		
		if(choice=="c"){
			//system("cls");
			menu(); 
			
			cout << "\n\n\nPress \"i\" to insert an element " << endl;
			cout << "Press \"d\" to Delete an element " << endl;
			cout << "Press \"s\" to Look up an element " << endl;
			cout << "Press \"n\" to see the number of elements stored in the hash table" << endl;
			cout << "Press \"p\" to prints out the current state of the hash table" << endl;
			cout << "press \"c\" to create a new table" << endl;
			cout << "Press \"exit\" to exit the program" << endl;
		
			getline(std::cin, choice);
		}
			if(choice!="i" && choice!="d" && choice!="s" && choice!="n" && choice!="p" && choice!="c" && choice!="exit" ){
			
			//system("cls");
			
			cout << "\n\n\nPress \"i\" to insert an element " << endl;
			cout << "Press \"d\" to Delete an element " << endl;
			cout << "Press \"s\" to Look up an element " << endl;
			cout << "Press \"n\" to see the number of elements stored in the hash table" << endl;
			cout << "Press \"p\" to prints out the current state of the hash table" << endl;
			cout << "press \"c\" to create a new table" << endl;
			cout << "Press \"exit\" to exit the program" << endl;
		
			getline(std::cin, choice);
		}	
		
		if(choice=="exit"){
		//	system("cls");
			break;
		}
		
	}
}

int main(void)
{ 

 menu();
		
	

 return 0; 



}
