#ifndef HELPERS_H
#define HELPERS_H
#include <xmmintrin.h>//intel intrinsics -> SSE2 functions later in code
#include <emmintrin.h>//intel intrinsics -> SSE2 functions later in code
#include <iostream>
//Helper functions
using BYTE = __int8;
using UBYTE = unsigned __int8;

/**x = days, y= months, z= years, w = free space**/ //using UBYTE here since I want just true or false for now
UBYTE inline _vectorcall IsDateValid(__m128i DMY)
{
	constexpr int maxYear = 10000;
	constexpr int maxMonth = 12;
	int daysPrMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//Check if its a leap year
	const auto& year = DMY.m128i_i32[2];
	if ((year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0)
        daysPrMonth[1] += 1;
	
	//vectorizing to compare values, these functions require CPU SSE2 support, I won't bother to add support for other CPU's  right now, all cpu's in the last 20years should support SSE2
	const auto compVals = _mm_setr_epi32(daysPrMonth[DMY.m128i_i32[1] - 1], maxMonth, maxYear, 0);
	//Leaving this for debugging
	//std::cout << DMY.m128i_i32[0] << " " << DMY.m128i_i32[1] << " " << DMY.m128i_i32[2] << " " << DMY.m128i_i32[3] << " " << std::endl;
	//std::cout << comVals.m128i_i32[0] << " " << comVals.m128i_i32[1] << " " << comVals.m128i_i32[2] << " " << comVals.m128i_i32[3] << " " << std::endl;
	//std::cout << _mm_cmpgt_epi32(DMY, comVals).m128i_i32[0] << " " << _mm_cmpgt_epi32(DMY, comVals).m128i_i32[1] << " " << _mm_cmpgt_epi32(DMY, comVals).m128i_i32[2] << " " << _mm_cmpgt_epi32(DMY, comVals).m128i_i32[3] << " " << std::endl;
	//std::cout << ((_mm_movemask_epi8(_mm_cmpgt_epi32(DMY, comVals)) & 7) == 7) << std::endl;
	//checking if DMY > compVals with vectorization, comparing only 3 values, hence the bitwise and 7/0xE and not 0xF/15
	if (((_mm_movemask_epi8(_mm_cmpgt_epi32(DMY, compVals)) & 7) != 7))
		return (UBYTE)false;
	return (UBYTE)true;
}
inline BYTE CheckYN(char r)
{
    if (r == 'y')
        return (BYTE)1;
    else if (r == 'n')
        return (BYTE)0;
    else
        return (BYTE)-1;
}
inline void cInput(const char* text, char* buffer, const size_t size)
{
    std::cout << text;
    std::cin.getline(buffer, size);
}
template<class I>
inline void iInput(const char* text, I& val)
{
    std::cout << text;
    std::cin >> val;
}
template<class I>
inline void ilInput(const char* text, I& val)
{
    std::cout << text;
    std::wcin >> val;
}
//**Cin as first parameter just to be sure that it doesn't do the check at the wrong time **//
inline bool CheckAge(std::istream& cin, unsigned short& age)
{
    iInput("Age: ", age);
    if (!cin)
    {
        std::cout << "Invalid age" << std::endl;
        return false;
    }
    return true;
}
//**Wcin as first parameter just to be sure that it doesn't do the check at the wrong time **//
inline bool CheckPhone(std::wistream& wcin, unsigned long long& phone)
{
    ilInput("Phone: ", phone);
    if (!wcin)
    {
        std::cout << "Invalid phonenumber" << std::endl;
        return false;
    }
    return true;
}

#endif // HELPERS_H