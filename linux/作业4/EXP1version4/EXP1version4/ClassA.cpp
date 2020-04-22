#include "ClassA.h"
using namespace std;

ClassA::ClassA() {
	x = 0;
	y = 'w';
}
ClassA::ClassA(int i, char j) {
	x = i;
	y = j;
}
ClassA::~ClassA() {

}

bool ClassA::Serialize(int fd) const {
	if (-1 == fd) {
		return false;
	}
	if (write(fd, &x, sizeof(int)) == -1) {
		return false;
	}
	if (write(fd, &y, sizeof(char)) == -1) {
		return false;
	}
	return true;
}

bool ClassA::Deserialize(int fd) {
	if (-1 == fd) {
		return false;
	}
	int rd;
	rd = read(fd, &x, sizeof(int));
	if (-1 == rd || 0 == rd) {
		return false;
	}
	rd = read(fd, &y, sizeof(char));
	if (-1 == rd) {
		return false;
	}
	return true;
}

SerClass* ClassA::DeserializePtr(int fd) {
	ClassA * ptr = new ClassA();
	if (ptr->Deserialize(fd)) {
		return ptr;
	}
	else {
		return nullptr;
	}
}

void ClassA::PrintObject() {
	cout << "A.x = " << x << endl;
	cout << "A.y = " << y << endl;
}
