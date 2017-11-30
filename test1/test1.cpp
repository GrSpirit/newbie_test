#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

int main(int argc, char* argv[]) 
{
	if (argc != 2) {
		cout << "Wrong arguments\n";
		return 2;
	}
	FILE *f = fopen(argv[1], "w");
	unsigned int n;
	int len;
	string s;
	vector<BYTE> v;
	cin >> n;
	fwrite(&n, sizeof(int), 1, f);
	while (n != 0) {
		if ((n & 1) == 1) {
			char t;
			cin >> t; cin.ignore();
			fputc(t, f);
			switch(t) {
				case 'N':
					WORD d;
					cin >> d;
					fwrite(&d, sizeof(d), 1, f);
					break;
				case 'U':
					DWORD u;
					cin >> u;
					fwrite(&u, sizeof(u), 1, f);
					break;
				case 'S':
					getline(cin, s);
					len = s.size();
					fprintf(f, "%0.3d", len);
					fwrite(s.c_str(), sizeof(char), s.size(), f);
					break;
				case 'H':
					getline(cin, s);
					len = s.size();
					v.clear();

					for (int j = 0; j < len; j += 2) {
						BYTE x = stol(s.substr(j, 2).c_str(), nullptr, 16);
						v.push_back(x);
					}
					fprintf(f, "%0.3d", v.size());
					fwrite(v.data(), sizeof(BYTE), v.size(), f);
					break;
				case 'D':
					char l;
					cin >> l;
					cin >> s;
					fputc(s.size() + '0', f);
					fputc(l - '0', f);
					fwrite(s.c_str(), sizeof(char), s.size(), f);
					break;
				default:
					cerr << "Wrong field format\n";
					return -1;
			}
		}
		n >>= 1;
	}
	fclose(f);
}

