//an appreciation for the std::vector<> template class

#include <iostream>
#include <cassert>

template <typename foo> 

class vector{

	private:
		foo* p; //base pointr
		int size; //num of elements

	public:
		typedef foo* iterator;
		
		//constructors
		explicit vector(int n = 100);
		vector(const vector<foo>& v); //copy vector
		vector(const foo a[], int n); //copy an array

		//destructor
		~vector(){ delete []p; }

		//methods
		iterator begin() { return p; }
		iterator end() { return p+size; }

		//overloaded operators
		foo& operator[](int i); //range-checked element
		vector<foo>& operator=(const vector<foo>& v);
};

//default constructor definition
template <typename foo> vector<foo>::vector(int n) : size(n){
	assert(n > 0);
	p = new foo[size];
	assert(p !=0);
}

//copy constructor definition
//invoked whenever vector type is copied ex: function call or 
//assigment
template <typename foo> vector<foo>::vector(const foo a[], int n){
	assert(n > 0);
	size = n;
	p = new foo[size];
	assert(p !=0);
	for(int i = 0; i < size; i++)
		p[i] = a[i];
}

//const reference constructor
template <typename foo> vector<foo>::vector(const vector<foo>& v){
	size = v.size;
	p = new foo[size];
	assert(p!=0);
	for(int i = 0; i < size; i++)
		p[i] = v.p[i];
}

//[] operator overloaded
template <typename foo> foo& vector<foo>::operator[](int i){
	assert(i >=0 && i < size);
	return p[i];
}

//= operator overloaded
template <typename foo> 
vector<foo>& vector<foo>::operator=(const vector<foo>& v){
	assert(v.size == size);
	for(int i = 0; i < size; i++)
		p[i] = v.p[i];
	
	return *this;
}

int main(void){

	vector<double> v(5);
	vector<double>::iterator p;
	int i = 0;

	for(p = v.begin(); p !=v.end(); p++)
		*p = 1.5 + i++;

	do{
		p--;
		std::cout << *p << "...";
	}while(p !=v.begin());

	std::cout << std::endl;

	return 0;
}
