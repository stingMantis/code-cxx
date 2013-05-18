//using maps and list

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <map>

//yes..yes..c convention
#define RND_RANGE 10000
#define TIMES 100

using namespace std;

int main(void){

	srand(time(NULL));

	//generate 10,000 numbers between 0 and 9,999
	list<int> the_list;
	list<int>::iterator iter;

	//place in list<int> container
	for(int i = 0; i < TIMES; i++){
		int j = (rand() % RND_RANGE);
		the_list.push_back(j);
	}

	//iterate over values and display them
	int x = 0;
	for(iter = the_list.begin(); iter !=the_list.end(); iter++){
		cout << "item: " << x << " = " << *iter << "..." << endl;
		if(x % 10 == 0){
			cout << "Press [ENTER] for next ten...";
			cin.get();
		}
		x++;
	}

	//create a map container to hold freq of each number
	map<int, int> freq;
	list<int>::iterator iter1, iter2;
	
	//iterate over each element in the list
	for(iter1 = the_list.begin(); iter1 !=the_list.end(); ++iter1){
		//create a key/value pair where k=num/v=freq, v=0
		freq[*iter1] = 0; 

		//iterate the list again while at current element to see if it repeates
		for(iter2 = the_list.begin(); iter2 !=the_list.end(); ++iter2){
			//if it occurs again increase the v count by 1
			if( *iter2 == *iter1){ 
				freq[*iter1]+=1;
			}
		}
	}
	
	//iterate over map to see key/value pairs
	map<int,int>::iterator map_itr;
	cout << "Number\tFrequency" << endl;
	   for(map_itr = freq.begin(); map_itr !=freq.end(); ++map_itr){
			cout << (*map_itr).first << " appears " << map_itr->second << " times" << endl;
		}

	
	return 0;
}
