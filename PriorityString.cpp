#include "PriorityString.h"
#include <iostream>
#include <iomanip>

using namespace std;

PriorityString::PriorityString()
{
	payload="";
	priority=0;
}

PriorityString::PriorityString( const string&s )
{
	payload=s;
	priority=0;
}

PriorityString::PriorityString( const string&s, unsigned n )
{
	payload=s;
	priority=n;
}

int PriorityString::getPriority() const
{
	return priority;
}

string PriorityString::getData() const
{
	return payload;
}

void PriorityString::setPriority( unsigned n)
{
	priority=n;
}

ostream& operator<< (ostream& stream, const PriorityString& ps)
{
	return stream << setw(5) << ps.getPriority() << " : " << ps.getData() << endl ;
}

//These functions only compares the priority. The string has no bearing on the priority of an object.
bool PriorityString::operator==(const PriorityString& comparand) const
{
	return this->priority == comparand.priority;
}
bool PriorityString::operator<(const PriorityString& comparand) const
{
	return this->getPriority() < comparand.getPriority();
}
bool PriorityString::operator>(const PriorityString& comparand) const
{
	return this->getPriority() > comparand.getPriority();
}

//implemnted with multiple returns for speed
bool PriorityString::operator()(const PriorityString& left, const PriorityString& right) const
{
	//since we are dealing with an int we are guranteed to have one of the following be true
	if(left.getPriority() < right.getPriority())
	{
		return -1;
	}
	if(left.getPriority() > right.getPriority())
	{
		return 1;
	}
	if(left.getPriority() == right.getPriority())
	{
		return 0;
	}

	//the compiler requires a return value for all paths
	return 0;
}

