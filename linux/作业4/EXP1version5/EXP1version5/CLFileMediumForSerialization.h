#ifndef _CLFILEMEDIUMFORSERIALIZATION_H_
#define _CLFILEMEDIUMFORSERIALIZATION_H_

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "ILMediumForSerialization.h"

class CLFileMediumForSerialization:
	public ILMediumForSerialization
{
public:
	CLFileMediumForSerialization(const char *pFilePath)
	{
		fd = ::open(pFilePath, O_RDWR | O_CREAT , 0666);
	}

	virtual ~CLFileMediumForSerialization()
	{
		if (fd != -1)
			::close(fd);
	}
public:
	virtual Status WriteToMedium(const char*pBuff, unsigned int iSize)
	{
		if (-1 == fd)
			return LFAILURE;
		if (::write(fd, pBuff, iSize) == -1)
			return LFAILURE;
		else
			return LSUCCESS;
	}

	virtual Status GetSizeOfObjectInMedium(unsigned int &objssize)
	{
		if (-1 == fd)
			return LFAILURE;
		struct stat buf;
		if (fstat(fd, &buf) == -1)
			return LFAILURE;
		objssize = buf.st_size;
		return LSUCCESS;
	}

	virtual Status ReadFromMedium(char * pBuff)
	{
		if (-1 == fd)
			return LFAILURE;
		unsigned int iSize;
		if (GetSizeOfObjectInMedium(iSize) < 0)
		{
			return LFAILURE;
		}
		if (::read(fd, pBuff, iSize) < 0)
		{
			return LFAILURE;
		}
		else
		{
			return LSUCCESS;
		}
	}
private:
	int fd;

};


#endif // !_CLFILEMEDIUMFORSERIALIZATION_H_



