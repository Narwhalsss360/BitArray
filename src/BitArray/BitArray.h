#ifndef BitArray_h
#define BitArray_h

template <size_t BitCount>
constexpr size_t getByteCountFromBitCount() { return (BitCount + 7) / 8; }

template <size_t BitCount>
class BitArray
{
public:
	constexpr size_t getBitCount() const { return BitCount; };

	constexpr size_t getByteCount() const { return getByteCountFromBitCount<BitCount>(); }

	bool get(size_t index) const { return (((bytes[index / 8]) >> (index % 8)) & 0x01); }

	void set(size_t index, bool value) { (value ? ((bytes[index / 8]) |= (1UL << (index % 8))) : ((bytes[index / 8]) &= ~(1UL << (index % 8)))); }

private:
	unsigned char bytes[getByteCountFromBitCount<BitCount>()];
};

#endif // !BitArray_h