//using maps and list

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <map>

int main(void){

   //seed SRNG
	srand(time(NULL));

   //constants
   const int RND_RANGE(10000);
   const int TIMES(1000);

   //create and populate list
   std::list<int> the_list;
	for(int i = 0; i < TIMES; i++){
		int j = (rand() % RND_RANGE);
		the_list.push_back(j);
	}

   //outuput list contents
	int x(0);
	for(std::list<int>::iterator iter = the_list.begin(); iter !=the_list.end(); ++iter){
		std::cout << "item: " << x << " = " << *iter << "..." << std::endl;;
		if(x % 10 == 0){
			std::cout << "Press [ENTER] for next ten...";
			std::cin.get();
		}
		x++;
	}

   //log frequency of each element
	std::map<int, int> num_freq;
	//iterate over each element in the list
	for(std::list<int>::iterator iter2 = the_list.begin(); iter1 !=the_list.end(); ++iter1){
		//create a key/value pair where k=num/v=num_freq, v=0
		num_freq[*iter1] = 0; 

		//iterate again while at current element to see if it repeates
		for(std::list<int>::iterator iter2 = the_list.begin(); iter2 !=the_list.end(); ++iter2){
			//if it occurs again increase the v count by 1
			if( *iter2 == *iter1){ 
				num_freq[*iter1]+=1;
			}
		}
	}
	
	//output map contents
	std::cout << "Number\tFrequency" << std::endl;
	for(std::map<int, int>::iterator map_itr = num_freq.begin(); map_itr !=num_freq.end(); ++map_itr)
      std::cout << (*map_itr).first << " appears " << map_itr->second << " times" << std::endl;;

	return 0;
}
