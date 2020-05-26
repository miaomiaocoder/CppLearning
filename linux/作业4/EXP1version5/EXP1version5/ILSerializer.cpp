#include "ILSerializer.h"

ILSerializer::ILSerializer(ILMediumForSerialization *pMedium) {
	m_pMedium = pMedium;
}

ILSerializer::~ILSerializer() {
	delete m_pMedium;
}
