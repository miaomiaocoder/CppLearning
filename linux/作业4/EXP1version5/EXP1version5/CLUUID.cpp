#include "CLUUID.h"
#include<memory.h>

CLUUID::CLUUID()
{
	m_u1 = m_u2 = m_u3 = m_u4 = 0;
}

CLUUID::~CLUUID() {

}

void CLUUID::SetValue(unsigned int u1, unsigned int u2, unsigned int u3, unsigned int u4) {
	m_u1 = u1;
	m_u2 = u2;
	m_u3 = u3;
	m_u4 = u4;
}

void CLUUID::GetValue(char * pBuff) const
{
	char *p = (char*)this;
	p = p + sizeof(char*); //越过虚表的指针
	memcpy(pBuff, p, 16);
}

bool CLUUID::IsEqual(const CLUUID& uuid)
{
	if ((uuid.m_u1 == m_u1) && (uuid.m_u2 == m_u2) && (uuid.m_u3 == m_u3) && (uuid.m_u4 == m_u4)) {
		return true;
	}
	else {
		return false;
	}
}
