#include "memory_buf.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include "types.h"

using namespace std;

void make_message(istream &src, MemoryBuf &dst) 
{
	DWORD n;
	int len;
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
					sprintf(buf, "%.3d", len);
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
					sprintf(buf, "%.3d", (int)v.size());
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
