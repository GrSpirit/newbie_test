#include <iostream>
#include <sstream>
using namespace std;

int main() {
	stringstream ss(ios::binary);
	ss << 39 << 34;
	cout << "string stream " << ss.str() << endl;
	return 0;
}
