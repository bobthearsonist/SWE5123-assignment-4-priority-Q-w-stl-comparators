// Example Driver File
// Author: David Stabler

#include "PriorityString.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;	// required for string

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

	priority_queue<PriorityString> PQ3 = PQ + PQ2;
	cout << PQ3 << endl;

}