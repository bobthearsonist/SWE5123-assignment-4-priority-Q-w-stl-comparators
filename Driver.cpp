// Example Driver File
// Author: David Stabler

#include "PriorityString.h"
#include "PriorityQueueOperators.h"
#include <iostream>
#include <string>
#include <queue>
#include <functional>

using namespace std;	// required for string

//this is just a helper function for these tests to clear out the queue, 
//it could be opushed into a clas sthat inherits from the stl::priority_queue
template <typename T>
void clear(priority_queue<T>& pq)
{
	while (!pq.empty())
	{
		pq.pop();
	}
}

//another helper, this time a class definition to make sure that my priority Q
//operators were defined properly as templates and can operate on anything implementing
//the appropriate operators
class people
{
public:
	people(string name = "") { this->name = name; }
	string name;
	int operator()(const people& left, const people& right) const 
	{
		return left.name.compare(right.name);
	}
};

void main()
{

	priority_queue<
		PriorityString,
		vector<PriorityString>,
		greater<PriorityString>
	> pq1;

	string i="hi there";
 	PriorityString ps("String with Priority 5", 5);
	pq1.push(ps);
 	PriorityString ps2("String with Priority 4", 4);
	pq1.push(ps2);
	pq1.push(PriorityString("String with Priority 3", 3) );

	//false(0) then true(1)
	cout << (ps < ps2) << endl;
	cout << (ps > ps2) << endl;

	cout << pq1.size() << endl;

	while ( ! pq1.empty() )
	{
		cout <<  pq1.top() << endl;
		pq1.pop();
	}

	
	priority_queue<
		PriorityString,
		vector<PriorityString>,
		less<PriorityString>
	> PQ;

	PQ.push( PriorityString("Test String 1", 1) );
	PQ.push( ps );
	PQ.push( PriorityString("Test String 2", 2) );

	priority_queue<
		PriorityString,
		vector<PriorityString>,
		less<PriorityString>
	> PQ2;


	PQ2.push( PriorityString("Quick", 7));
	PQ2.push( PriorityString("Fox", 6));
	PQ2.push( PriorityString("The", 2));
	PQ2.push( PriorityString("Lazy", 1));
	PQ2.push( PriorityString("Jumps", 4));
	PQ2.push( PriorityString("Dog"));
	PQ2.push( PriorityString("Brown", 7));
	PQ2.push( PriorityString("Over", 4));
	PQ2.push( PriorityString("The", 9));
	PQ2.push( PriorityString("."));

	cout << i << endl;
	cout << ps << endl;
	cout << PQ << endl;
	cout << PQ2 << endl;

	//testing commutative property of + and verify the order theory
	priority_queue<PriorityString> PQ3;
	PQ3 = PQ + PQ2;
	cout << PQ3 << endl;

	clear(PQ3);

	PQ3 = PQ2 + PQ;
	cout << PQ3 << endl;

	clear(PQ2);
	PQ2.push(PriorityString("The", 0));
	PQ2.push(PriorityString("Quick", 0));
	PQ2.push(PriorityString("Brown", 0));
	PQ2.push(PriorityString("Fox", 0));
	PQ2.push(PriorityString("Jumps", 0));
	PQ2.push(PriorityString("Over", 0));
	PQ2.push(PriorityString("The", 0));
	PQ2.push(PriorityString("Lazy", 0));
	PQ2.push(PriorityString("Dog", 0));
	PQ2.push(PriorityString(".",0));
	cout << PQ2 << endl;

	PQ2.push(PriorityString("Test", 0));
	cout << PQ2 << endl;

	PQ2.push(PriorityString("Test", 0));
	cout << PQ2 << endl;

	//test greater than comparator for max heap and operator+ 
	priority_queue<
		PriorityString,
		vector<PriorityString>,
		greater<PriorityString>
	> PQ4;
	PQ4.push(PriorityString("10", 10));
	PQ4.push(PriorityString("2", 2));
	PQ4.push(PriorityString("4", 4));
	PQ4.push(PriorityString("1", 1));

		priority_queue<
		PriorityString,
		vector<PriorityString>,
		greater<PriorityString>
	> PQ5 =	PQ4 + PQ4;
	cout << PQ5 << endl;

	//test comparator function
	priority_queue<
		PriorityString,
		vector<PriorityString>,
		cmp<PriorityString>
	> PQ6;

	PQ6.push(PriorityString("Quick", 7));
	PQ6.push(PriorityString("Fox", 6));
	PQ6.push(PriorityString("The", 2));
	PQ6.push(PriorityString("Lazy", 1));
	PQ6.push(PriorityString("Jumps", 4));
	PQ6.push(PriorityString("Dog"));
	PQ6.push(PriorityString("Brown", 7));
	PQ6.push(PriorityString("Over", 4));
	PQ6.push(PriorityString("The", 9));
	PQ6.push(PriorityString("."));
	cout << PQ6 << endl;

	//test comparator with a different type and a different way of initialization
	priority_queue<
		people,
		vector<people>,
		people
	> PQ7;
	PQ7.push(people("a"));
	PQ7.push(people("d"));
	PQ7.push(people("z"));
	PQ7.push(people("b"));
	cout << PQ6 << endl;
}