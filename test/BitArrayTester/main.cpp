#include <iostream>
#include <string>
#include "BitArray.h"
#include <sstream>

using std::cout;
using std::cin;

constexpr size_t bitCount = 14;

template <size_t BitCount>
std::string formatBitArray(const BitArray<BitCount>& bitArray)
{
	std::stringstream ss;
	for (size_t i = 0; i < bitArray.getBitCount(); i++)
		ss << (int)bitArray.get(i);
	return ss.str();
}

int main()
{
	if (getByteCountFromBitCount<bitCount>() != 2)
		return 1;

	BitArray<bitCount> bitArray = BitArray<bitCount>();

	if (bitArray.getBitCount() != bitCount)
		return 2;

	if (bitArray.getByteCount() != 2)
		return 3;

	cout << formatBitArray(bitArray) << '\n';
	for (size_t i = 0; i < bitArray.getBitCount(); i++)
	{
		bitArray.set(i, true);
		cout << formatBitArray(bitArray) << '\n';
		bitArray.set(i, false);
	}
	cout << formatBitArray(bitArray) << '\n';

	cout << "Press enter to exit.";
	cin.get();
}