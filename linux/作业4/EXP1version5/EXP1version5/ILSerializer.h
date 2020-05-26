#ifndef _ILSERIALIZER_H_
#define _ILSERIALIZER_H_

#include<vector>
#include"Status.h"

class ILSerClass;
class ILMediumForSerialization;

class ILSerializer
{
public:
	ILSerializer(ILMediumForSerialization *pMedium);

	virtual ~ILSerializer();

public:
	virtual Status Register(ILSerClass *pSerializable) = 0;

	virtual Status Serialize(std::vector<ILSerClass *> &vSerializable) = 0;

	virtual Status Deserialize(std::vector<ILSerClass *> &vSerialized) = 0;

protected:
	ILMediumForSerialization *m_pMedium;
};

#endif // !_ILSERIALIZER_H_