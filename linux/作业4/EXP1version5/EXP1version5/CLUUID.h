#ifndef _CLUUID_H_
#define _CLUUID_H_

class CLUUID
{
public:
	CLUUID();
	virtual ~CLUUID();

public:
	bool IsEqual(const CLUUID& uuid);

	void SetValue(unsigned int u1, unsigned int u2, unsigned int u3, unsigned int u4);

	void GetValue(char * pBuff) const;

private:
	unsigned int m_u1;
	unsigned int m_u2;
	unsigned int m_u3;
	unsigned int m_u4;
};


#endif