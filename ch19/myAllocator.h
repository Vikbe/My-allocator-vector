#pragma once

template<typename T> class myAllocator
{
public:
	T * allocate(int n);
	void deallocate(T* p, int n);

	void construct(T* p, const T& v);
	void destroy(T* p);
};

template<typename T>
T* myAllocator<T>::allocate(int n)
{
	return (T*) malloc (sizeof(T) * n);
}

template<typename T>
void myAllocator<T>::deallocate(T* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(p); 
		p++;
	}
}
template<typename T>
void myAllocator<T>::construct(T* p, const T& v)
{
	p = new (p) T(v);
}

template<typename T>
void myAllocator<T>::destroy(T* p)
{
	delete p;
}