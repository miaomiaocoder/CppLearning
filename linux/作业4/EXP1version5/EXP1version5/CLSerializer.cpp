#include "CLSerializer.h"
#include "CLUUID.h"
#include "ILMediumForSerialization.h"
#include "ILSerClass.h"
#include<string.h>

CLSerializer::CLSerializer(ILMediumForSerialization *pMedium) : ILSerializer(pMedium)
{

}

CLSerializer::~CLSerializer()
{
	for (int i = 0; i < m_vpSerializable.size(); i++) {
		delete m_vpSerializable[i];
	}
}

Status CLSerializer::Register(ILSerClass *pSerialzable)
{
	m_vpSerializable.push_back(pSerialzable);

	return LSUCCESS;
}

Status CLSerializer::Serialize(std::vector<ILSerClass *> &vSerializable)
{
	unsigned int iSize = 0;
	for (int i = 0; i < vSerializable.size(); i++) {
		unsigned int objsize = 0;
		if (vSerializable[i]->GetObjSize(&objsize) < 0) {
			return LFAILURE;
		}

		iSize = iSize + objsize;
	}
	//16 is the sizeof uuid in bytes
	iSize = iSize + 16 * vSerializable.size();

	char *pBuff = new char[iSize];

	char *pTemp = pBuff;

	for (int i = 0; i < vSerializable.size(); i++)
	{
		CLUUID uuid;
		if (vSerializable[i]->GetType(uuid) < 0) {
			delete[] pBuff;
			return LFAILURE;
		}

		uuid.GetValue(pTemp);

		pTemp = pTemp + 16;

		if (vSerializable[i]->Serialize(pTemp) < 0) {
			delete[] pBuff;
			return LFAILURE;
		}

		unsigned int objsize = 0;
		if (vSerializable[i]->GetObjSize(&objsize) < 0) {
			delete[] pBuff;
			return LFAILURE;
		}

		pTemp = pTemp + objsize;
	}

	if (m_pMedium->WriteToMedium(pBuff, iSize) < 0) {
		delete[]pBuff;
		return LFAILURE;
	}

	delete[] pBuff;
	return LSUCCESS;
}

Status CLSerializer::Deserialize(std::vector<ILSerClass *> &vSerialized)
{
	unsigned int iSize = 0;
	if (m_pMedium->GetSizeOfObjectInMedium(iSize) < 0) {
		return LFAILURE;
	}

	char *pBuff = new char[iSize];

	if (m_pMedium->ReadFromMedium(pBuff) < 0) {
		delete[] pBuff;
		return LFAILURE;
	}
	char *pTemp = pBuff;
	for (;;)
	{
		if (pTemp >= pBuff + iSize)
			break;
		int i;
		for (i = 0; i < m_vpSerializable.size(); i++)
		{
			CLUUID uuid;
			if (m_vpSerializable[i]->GetType(uuid) < 0)
			{
				delete[]pBuff;
				return LFAILURE;
			}
			char buf[16];
			uuid.GetValue(buf);
			if (memcmp(buf, pTemp, 16) == 0)
				break;
		}
		if (m_vpSerializable.size() == i)
		{
			delete[] pBuff;
			return LFAILURE;
		}
		pTemp = pTemp + 16;

		ILSerClass *ps = NULL;
		if (m_vpSerializable[i]->Deserialize(pTemp,&ps) < 0)
		{
			delete[] pBuff;
			return LFAILURE;
		}

		unsigned int objsize = 0;
		if (ps->GetObjSize(&objsize) < 0)
		{
			delete[] pBuff;
			return LFAILURE;
		}
		pTemp = pTemp + objsize;

		vSerialized.push_back(ps);
	}

	delete[] pBuff;
	return LSUCCESS;
}