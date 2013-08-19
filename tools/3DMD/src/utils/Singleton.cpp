#ifndef _CSINGLETON_CPP_
#define _CSINGLETON_CPP_

#include "Singleton.h"

///////////////////////////////////////////
//constructor and destructor
///////////////////////////////////////////
template <class T>
CSingleton<T>::CSingleton()
{
}

template <class T>
CSingleton<T>::~CSingleton()
{
}

///////////////////////////////////////////
//static function
///////////////////////////////////////////
template <class T>
T* CSingleton<T>::m_sInstance = NULL;

template <class T>
T* CSingleton<T>::GetInstance()
{
	if(!m_sInstance)
	{
		m_sInstance = new T();
	}

	return m_sInstance;	
}

template <class T>
void CSingleton<T>::DestroyInstance()
{
	if(m_sInstance)
	{
		SAFE_DEL(m_sInstance);
	}

	m_sInstance = NULL;
}

#endif