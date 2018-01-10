#pragma once
#include "myAllocator.h" 
namespace myV
{
	template<typename T, typename A = myAllocator<T>>
	class myVector
	{
	public:
		myVector()
			: sz{ 0 }, elem{ nullptr }, space{ 0 } {}

		explicit myVector(int s)
			: sz{ s }, elem{ new T[s] }, space{ s }
		{
			for (int i = 0; i < sz; ++i)
				elem[i] = 0;
		}

		T& operator[](int n) { return elem[n]; }
		myVector<T, A>& operator=(const myVector<T, A>& mv);
		void reserve(int newalloc);
		void push_back(const T& val);

	private:
		A alloc;
		int sz;
		T* elem;
		int space;
	};

	template<typename T, typename A>
	void myVector<T, A>::reserve(int newalloc)
	{
		if (newalloc <= space) return;
		T* p = alloc.allocate(newalloc);
		for (int i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]);
		for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
		alloc.deallocate(elem, space);
		elem = p;
		space = newalloc;
	}

	template<typename T, typename A>
	void myVector<T, A>::push_back(const T& val)
	{
		if (space == 0) reserve(8);
		else if (sz == space) reserve(2 * space);
		alloc.construct(&elem[sz], val);
		++sz;
	} 

	template<typename T, typename A>
	myVector<T,A>& myVector<T, A>::operator=(const myVector<T,A>& mv)
	{
		T* p = alloc.allocate(mv.space);  
		for (int i = 0; i < mv.sz; ++i) alloc.construct(&p[i], mv.elem[i]);
		for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
		elem = p; 
		space = mv.space; 
		sz = mv.sz; 
		return *this;
	}
}
