#include<iostream>
#include <new>
#include <cassert>


template<class T>
class Out_Of_Memory
{
public:

	static void MemoryFailure();
	/*
	 Please see header file <new> and namespace std has code for global set_new_handler
	 which will for for global new operator.
	 We want class specific things so we are overloading this functions and operator.
	*/
	static new_handler set_new_handler(new_handler p);
	void* operator new[](size_t size);
	void  operator delete[](void *ptr);

private:
	/*
	  this function pointer will keep track of handler to call
	  when new fails to allocate memory for objects of class Out_Of_Memory
	*/
	static new_handler currentHandler ; //Declaration
};

template<class T>
new_handler Out_Of_Memory<T>::currentHandler; //Definition

/*
This function belongs to class Out_Of_Memory ans it will accept pointer to new function handler.
It will return oldHandler which might be previously set.
The global set_new_handler also works similarly.
*/

template<class T>
new_handler Out_Of_Memory<T>::set_new_handler(new_handler p)
{
	new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

template<class T>
void Out_Of_Memory<T>::MemoryFailure()
{
 std::cout << " Unable to give any memory" <<std::endl;
 assert(0);
}

template<class T>
void Out_Of_Memory<T>::operator delete[](void* ptr)
{
	::operator delete(ptr);
}

template<class T>
void* Out_Of_Memory<T>::operator new[](size_t size)
{
  /*
   Here we will make global new operator aware of our class specific handler 
  */
	new_handler globalHandler = std::set_new_handler(currentHandler);

	void* memory;

	/*
	 Here global new operator truies to allocate memory .
	 If it failes to do so it will first call 
	 Out_Of_Memory class handler as it was set as global handler.
	 If even after that it fails to allocate or get memory somehow 
	 global new operator will throw bad_alloc exception.
	 This exception we are catching here.
	 To back propogate this exception to global new we reset 
	 global handler again.
	*/
	try
	{
		
		memory = ::operator new(100000000000000 * 100000000000000); // Call to gloabal new inside overloaded new
	}
	catch(std::bad_alloc&)
	{
		std::set_new_handler(globalHandler);
		throw;
	}

	/*
	If memory was succesfully allocated restore back the original global handler
	*/
	std::set_new_handler(globalHandler);

	return memory;
}

class X : public Out_Of_Memory<X>
{

};

int main()
{
	//Out_Of_Memory::set_new_handler(Out_Of_Memory::MemoryFailure);
	X::set_new_handler(X::MemoryFailure);
	X *ptr = new X[100];
}	   
