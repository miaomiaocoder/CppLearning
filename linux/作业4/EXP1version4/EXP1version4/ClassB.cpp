#include "ClassB.h"
using namespace std;

ClassB::ClassB() {
	x = 'a';
	y = 'b';
}
ClassB::ClassB(char i, char j) {
	x = i;
	y = j;
}
ClassB::~ClassB() {

}

bool ClassB::Serialize(int fd) const {
	if (-1 == fd) {
		return false;
	}
	if (write(fd, &x, sizeof(char)) == -1) {
		return false;
	}
	if (write(fd, &y, sizeof(char)) == -1) {
		return false;
	}
	return true;
}

bool ClassB::Deserialize(int fd) {
	if (-1 == fd) {
		return false;
	}
	int rd;
	rd = read(fd, &x, sizeof(char));
	if (-1 == rd || 0 == rd) {
		return false;
	}
	rd = read(fd, &y, sizeof(char));
	if (-1 == rd) {
		return false;
	}
	return true;
}

SerClass* ClassB::DeserializePtr(int fd) {
	ClassB * ptrB = new ClassB();
	if (ptrB->Deserialize(fd)) {
		return ptrB;
	}
	else {
		return nullptr;
	}
}

void ClassB::PrintObject() {
	cout << "B.x = " << x << endl;
	cout << "B.y = " << y << endl;
}
