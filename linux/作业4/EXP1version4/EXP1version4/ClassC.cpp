#include "ClassC.h"
using namespace std;

ClassC::ClassC() {
	x = 'a';
	y = 'b';
}
ClassC::ClassC(int i, int j) {
	x = i;
	y = j;
}
ClassC::~ClassC() {

}

bool ClassC::Serialize(int fd) const {
	if (-1 == fd) {
		return false;
	}
	if (write(fd, &x, sizeof(int)) == -1) {
		return false;
	}
	if (write(fd, &y, sizeof(int)) == -1) {
		return false;
	}
	return true;
}

bool ClassC::Deserialize(int fd) {
	if (-1 == fd) {
		return false;
	}
	int rd;
	rd = read(fd, &x, sizeof(int));
	if (-1 == rd || 0 == rd) {
		return false;
	}
	rd = read(fd, &y, sizeof(int));
	if (-1 == rd) {
		return false;
	}
	return true;
}

SerClass* ClassC::DeserializePtr(int fd) {
	ClassC * ptrC = new ClassC();
	if (ptrC->Deserialize(fd)) {
		return ptrC;
	}
	else {
		return nullptr;
	}
}

void ClassC::PrintObject() {
	cout << "C.x = " << x << endl;
	cout << "C.y = " << y << endl;
}