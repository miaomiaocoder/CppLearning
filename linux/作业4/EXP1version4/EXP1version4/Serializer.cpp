#include "Serializer.h"


bool Serializer::Serialize(const char*pFilePath, vector<SerClass*>&v)
{
	int fd = open(pFilePath, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (-1 == fd)
		return false;
	for (int i = 0; i < v.size(); i++)
	{
		int type;
		type = v[i]->getType();
		if (-1 == write(fd, &type, 4))
		{
			close(fd);
			return false;
		}
		if (v[i]->Serialize(fd) == false) {
			cout << "error" << endl;
			return false;
		}
	}
	if (-1 == close(fd))
		return false;
	return true;
}

bool Serializer::Deserialize(const char*pFilePath, vector<SerClass*>&v) {
	int fd = open(pFilePath, O_RDWR);
	if (-1 == fd)
		return false;
	while (1) {
		int nType = 0;
		int rd = read(fd, &nType,4);
		if ((-1 == rd) || (0 == rd))
			break;
		//SerClass *ptr;
		for (auto i = 0; i < nSerClass.size(); ++i) {
			int type = nSerClass[i]->getType();
			if (type == nType) {
				SerClass *ptr;
				ptr = nSerClass[i]->DeserializePtr(fd);
				if (ptr != nullptr) {
					v.push_back(ptr);
				}
			}
		}
	}
	if (-1 == close(fd))
		return false;
	return true;
}

void Serializer::Register(SerClass* ptr) {
	nSerClass.push_back(ptr);
}