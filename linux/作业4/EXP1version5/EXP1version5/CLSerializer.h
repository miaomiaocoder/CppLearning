#ifndef _CLSERIALIZER_H_
#define _CLSERIALIZER_H_

#include"ILSerializer.h"

class CLSerializer :
	public ILSerializer
{
public:
	CLSerializer(ILMediumForSerialization *pMedium);
	virtual ~CLSerializer();
public:
	virtual Status Register(ILSerClass *pSerializable);

	virtual Status Serialize(std::vector<ILSerClass *>& vSerializable);

	virtual Status Deserialize(std::vector<ILSerClass *>& vSerialized);

private:
	std::vector<ILSerClass *> m_vpSerializable;
};


#endif // !CLSerializer_H
