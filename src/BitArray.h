#ifndef BitArray_h
#define BitArray_h

template <size_t BitCount>
constexpr size_t getByteCountFromBitCount() { return (BitCount + 7) / 8; }

template <size_t BitCount>
class BitArray
{
public:
	/// @brief Get bit count
	/// @return `size_t` bit count
	constexpr size_t getBitCount() const { return BitCount; };

	/// @brief Get byte count
	/// @return `size_t` byte count
	constexpr size_t getByteCount() const { return getByteCountFromBitCount<BitCount>(); }

	/// @brief Get the state of the bit from given index.
	/// @param index index of bit
	/// @return `bool` state of bit at `index`
	bool get(size_t index) const { return (((bytes[index / 8]) >> (index % 8)) & 0x01); }

	/// @brief Set the state of bit from given index
	/// @param index index of bit
	/// @param value value to set
	void set(size_t index, bool value) { (value ? ((bytes[index / 8]) |= (1UL << (index % 8))) : ((bytes[index / 8]) &= ~(1UL << (index % 8)))); }

private:
	unsigned char bytes[getByteCountFromBitCount<BitCount>()];
};

#endif // !BitArray_h