#pragma once
#include <stdint.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

class MemoryBuf {
	std::vector<uint8_t> _buf;
//	uint8_t *_buf;
//	size_t _max_size;
//	size_t _size;
public:
	MemoryBuf() {}
	void write(const uint8_t *bytes, size_t size) {
		_buf.resize(_buf.size() + size);
		std::copy(bytes, bytes + size, _buf.end() - size);
	}
	void copy(const std::vector<uint8_t> &src) {
		std::copy(src.begin(), src.end(), _buf.end());
	}
	template <typename T>
	void put(const T &obj) {
		_buf.resize(_buf.size() + sizeof(T));
		std::copy((uint8_t*)&obj, (uint8_t*)&obj + sizeof(T), _buf.end() - sizeof(T));
	}
	size_t size() const { return _buf.size(); }
	const uint8_t *data() const { return _buf.data(); }
	void clear() { _buf.clear(); }
};
