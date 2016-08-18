#include <iostream>
#include <vector>

void Push(std::vector<int>& v) {
	v.push_back(1);
}

void ModifyPointer(int* &s) {
	s = new int();
	*s = 1;
}

int main() {
	std::vector<int> v;
	std::vector<int> v1;

	v = v1;
	v1.push_back(1);

	// Push(v);

	// printf("%d\n", v[0]);

	int* a = new int();
	*a = 0;
	printf("a = %d\n", *a);

	ModifyPointer(a);

	printf("a = %d\n", *a);
}