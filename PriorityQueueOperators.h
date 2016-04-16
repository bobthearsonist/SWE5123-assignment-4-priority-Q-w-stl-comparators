#pragma once
#include <queue>

//Note! O(N^2). We must copy first, and then empty Queue.
template <typename T, typename Sequence, typename Compare>
std::ostream& operator<< (std::ostream& out, const std::priority_queue<T, Sequence, Compare>& pq)
{
	//make a copy so that this is not destructive
	priority_queue<T, Sequence, Compare> copy = pq;
	//TODO ensure that the comparator is preserved in the copy!

	// output the queue
	while (!copy.empty())
	{
		out << copy.top() << endl;
		copy.pop();
	}
	return out;
}

//pre-condition: pq1 and pq2 are defined with the same comparator (not explicitly enforced)
//post-condition: pq1 and pq2 are combined using the comparator from pq1
//this operation will take O(N^3). The copy takes O(N), the push and pop will take O(N), and then a copy is performed upon return
//because we must pass by value.
//This operation is not commutative due to the nature of the heap.
template <typename T, typename Sequence, typename Compare>
std::priority_queue<T, Sequence, Compare> operator+(const std::priority_queue<T, Sequence, Compare>& pq1, const std::priority_queue<T, Sequence, Compare>& pq2)
{
	priority_queue<T, Sequence, Compare> sum = pq1;
	priority_queue<T, Sequence, Compare> copy = pq2;
	while (!copy.empty())
	{
		sum.push(copy.top());
		copy.pop();
	}

	return sum;
}

//comparator class written as a generic, so it should work with any type that overloads() and returns
//a value that is convertable to a boolean
template <class T>
class cmp
{
public:
	//this will implicitley convert the int return value to a boolean!
	bool operator()(const T& left, const T& right) 
	{ 
		return left(left, right); 
	}
};