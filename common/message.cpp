#include "memory_buf.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

MemoryBuf make_message(istream &src) 
{
	MemoryBuf dst;
	uint32_t n;
	int len;
	char buf[255];
	string s;
	vector<uint8_t> v;
	src >> n;
	dst.put(n);
	while (n != 0) {
		if ((n & 1) == 1) {
			char t;
			src >> t; src.ignore();
			dst.put(t);
			switch(t) {
				case 'N':
					uint16_t d;
					src >> d;
					dst.put(d);
					break;
				case 'U':
					uint32_t u;
					src >> u;
					dst.put(u);
					break;
				case 'S':
					getline(src, s);
					len = s.size();
					sprintf(buf, "%.3d", len);
					dst.write((const uint8_t*)buf, strlen(buf));
					dst.write((const uint8_t*)s.c_str(), s.size());
					break;
				case 'H':
					getline(src, s);
					len = s.size();
					v.clear();

					for (int j = 0; j < len; j += 2) {
						uint8_t x = stol(s.substr(j, 2).c_str(), nullptr, 16);
						v.push_back(x);
					}
					sprintf(buf, "%.3d", (int)v.size());
					dst.write((const uint8_t*)buf, strlen(buf));
					dst.write((const uint8_t*)v.data(), v.size());
					break;
				case 'D':
					char l;
					src >> l;
					src >> s;
					dst.put((uint8_t)(s.size() + '0'));
					dst.put((uint8_t)(l - '0'));
					dst.write((const uint8_t*)s.c_str(), s.size());
					break;
				default:
					throw "Wrong field format\n";
			}
		}
		n >>= 1;
	}
	return dst;
}
