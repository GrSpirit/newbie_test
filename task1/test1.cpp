#include "memory_buf.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include "message.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
	if (argc != 2) {
		cout << "Wrong arguments\n";
		return 2;
	}
	try {
		ofstream fout(argv[1], ios::out | ios::binary);
		MemoryBuf buf = make_message(cin);
		fout.write((const char*)buf.data(), buf.size());
		fout.close();
	}
	catch(const char *msg) {
		cerr << msg << endl;
	}
	return 0;
}

