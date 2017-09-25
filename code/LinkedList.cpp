// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>




List::List()
	: first_(NULL){
}


List::List(const List & other)
	: first_(clone(other.first_)) {
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}


const List & List::operator=(const List & other) 
{
	// check for list = list
	if (&other != this) //
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}


bool List::empty() const{
	return first_ == NULL;
}


void List::insertAsFirst(double x){
	first_ = new Node(x, first_);
}

double List::size()
{
	double count = 0;
	if (!empty())
	{
		Node * tempPtr = first_;
		while (tempPtr != NULL)
		{

			tempPtr = tempPtr->next_;
			++count;
		
		}
		return count;
	}
	
}

void List::insertAsLast(double x)
{
	int Nnum = 1;
	double size = List::size();
	if (empty())
	{
		first_ = new Node(x);
	}
	else {
		Node *ptr = first_;
		while (Nnum < size) {

			ptr=ptr->next_;
			Nnum++;
		}
			ptr->next_ = new Node(x);
	}
	
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}

double List::sum()
{
		double a = 0;
	if (!empty())
	{
		
		Node * ptr = first_;
		while (ptr != NULL)
		{
			a = ptr->entry_ + a;
			ptr = ptr->next_;
			
		}
		return a;
	}
	return 0;

}


void List::print(ostream & outfile) const //
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}


