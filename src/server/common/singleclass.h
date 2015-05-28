#ifndef _SINGLE_H_
#define _SINGLE_H_

#define SINGLE_CLASS(T) \
	public:\
	static T* GetInstance(){ static T oInstance; return &oInstance; }

template<class T>
class CSingleClass
{
	static T* GetInstance()
	{
		T oInstance;
		return &oInstance;
	}
};


#endif