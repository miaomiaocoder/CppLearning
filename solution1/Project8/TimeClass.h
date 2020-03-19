
#ifndef _MYTIME_
#define _MYTIME_

class TimeClass
{
private:
	int MillSecond;
private:
	void initMillSecond(int mls);
public:
	int Hour;
	int Minute;
	int Second;
	void initTime(int tmphour, int tmpminute, int tmpsecond);
public:
	//¹¹Ôìº¯Êý
	explicit TimeClass(int tmphour, int tmpminute, int tmpsecond = 12);

	TimeClass(int tmphour);

	TimeClass();
};


#endif // !_MYTIME_


