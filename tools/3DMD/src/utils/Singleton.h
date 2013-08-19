#ifndef SINGLETON_H
#define SINGLETON_H

#include <boost/assert.hpp>

///////////////////////////////////////////////////////////////////////////////
// Singleton implementation

template <class T>
class Singleton
{
public:
	static T* GetInstance();
	static bool HasInstance();
	static void FreeInstance();

protected:
	Singleton();
	virtual ~Singleton();

private:
	static T* s_instance;
};

//////////////////////////////////////////////////////////////////////////

template <class T>
T* Singleton<T>::s_instance = 0;

//////////////////////////////////////////////////////////////////////////

template <class T>
T* Singleton<T>::GetInstance()
{
	// doesn't create the instance automatically
	BOOST_ASSERT(s_instance);
	return s_instance;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
bool Singleton<T>::HasInstance()
{
	return s_instance != 0;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
void Singleton<T>::FreeInstance()
{
	delete s_instance;
	s_instance = 0;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
Singleton<T>::Singleton()
{
	BOOST_ASSERT(s_instance == 0);
	s_instance = (T*)this;
}

//////////////////////////////////////////////////////////////////////////

template <class T>
Singleton<T>::~Singleton()
{
	s_instance = 0;
}

//
///////////////////////////////////////////////////////////////////////////////

#endif