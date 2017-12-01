#include "memory_buf.hpp"
#include <cstdlib>
#include <cstring>
#include <stdexcept>

MemoryBuf::MemoryBuf(size_t max_size) : _max_size(max_size), _size(0) {
	_buf = (uint8_t*)calloc(max_size, sizeof(uint8_t));
}

MemoryBuf::~MemoryBuf() {
	free(_buf);
}

void MemoryBuf::write(const void *bytes, size_t size) {
	if (_size + size > _max_size) throw std::runtime_error("Buffer overflow");
	memcpy(_buf + _size, bytes, size);
	_size += size;
}

/*template <typename T>
void MemoryBuf::put(const T &obj) {
	if (_size + sizeof(T) > _max_size) throw std::runtime_error("Buffer overflow");
	memcpy(_buf + _size, &obj, sizeof(T));
	_size += sizeof(T);
}*/

void MemoryBuf::clear() {
	memset(_buf, 0, _max_size);
	_size = 0;
}
