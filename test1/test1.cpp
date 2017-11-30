#include "memory_buf.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

void make_message(istream &src, MemoryBuf &dst);

int main(int argc, char* argv[]) 
{
	if (argc != 2) {
		cout << "Wrong arguments\n";
		return 2;
	}
	ofstream fout(argv[1], ios::out | ios::binary);
	MemoryBuf buf(2048);
	make_message(cin, buf);
	fout.write((const char*)buf.data(), buf.size());
	fout.close();
}

void make_message(istream &src, MemoryBuf &dst) 
{
	DWORD n;
	size_t len;
	char buf[255];
	string s;
	vector<BYTE> v;
	src >> n;
	dst.put(n);
	while (n != 0) {
		if ((n & 1) == 1) {
			char t;
			src >> t; src.ignore();
			dst.put(t);
			switch(t) {
				case 'N':
					WORD d;
					src >> d;
					dst.put(d);
					break;
				case 'U':
					DWORD u;
					src >> u;
					dst.put(u);
					break;
				case 'S':
					getline(src, s);
					len = s.size();
					sprintf(buf, "%0.3d", len);
					dst.write(buf, strlen(buf));
					dst.write(s.c_str(), s.size());
					break;
				case 'H':
					getline(src, s);
					len = s.size();
					v.clear();

					for (int j = 0; j < len; j += 2) {
						BYTE x = stol(s.substr(j, 2).c_str(), nullptr, 16);
						v.push_back(x);
					}
					sprintf(buf, "%0.3d", v.size());
					dst.write(buf, strlen(buf));
					dst.write(v.data(), v.size());
					break;
				case 'D':
					char l;
					src >> l;
					src >> s;
					dst.put((char)(s.size() + '0'));
					dst.put((char)(l - '0'));
					dst.write(s.c_str(), s.size());
					break;
				default:
					throw "Wrong field format\n";
			}
		}
		n >>= 1;
	}
}
