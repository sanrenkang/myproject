#ifndef _SRK_STRING_H_
#define _SRK_STRING_H_
#include "srktype.h"
#include <string>
using namespace std;
namespace SRK
{
#ifdef WIN32
#define	SRKSprintf sprintf_s 
#endif // WIN32

	class CString : public string
	{
	public: 
		CString& Format(const char* format, ...);
	};
}
#endif