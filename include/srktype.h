#ifndef _MY_TYPE_H_
#define _MY_TYPE_H_

namespace SRK
{
	typedef unsigned char UINT8;
	typedef unsigned short UINT16;
	typedef unsigned long UINT32;
	typedef unsigned long long UINT64;

	typedef  short INT16;
	typedef  long INT32;
	typedef  long long INT64;
	typedef char CHAR;

	typedef char BOOL;
	typedef char TCHAR;

#define NULL 0
#define FALSE 0
#define TRUE 1

#define DECLARE_SINGLE_OBJECT( OBJTYPE ) \
public: \
	static OBJTYPE* GetInstance() \
	{\
	static OBJTYPE o##OBJTYPE; \
	return &o##OBJTYPE; \
	}
}


#endif