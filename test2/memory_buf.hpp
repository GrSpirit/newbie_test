#pragma once
#include <stdint.h>
#include <cstdlib>
#include <cstring>
class MemoryBuf {
	uint8_t *_buf;
	size_t _max_size;
	size_t _size;
public:
	MemoryBuf(size_t max_size);
	virtual ~MemoryBuf();
	void write(const void *bytes, size_t size);
	template <typename T>
	void put(const T &obj) {
		if (_size + sizeof(T) > _max_size) throw "Buffer overflow";
		memcpy(_buf + _size, &obj, sizeof(T));
		_size += sizeof(T);
	}
	size_t size() const { return _size; }
	const uint8_t *data() const { return _buf; }
	void clear();
};
