#pragma once
#include <xmmintrin.h>
#include <emmintrin.h>
//#include <iostream>//just for debugging
using UBYTE = unsigned __int8;
 
/**x = days, y= months, z= years, w = free space**/
UBYTE _vectorcall IsDateValid(__m128i DMY)
{
	constexpr int maxYear = 10000;
	constexpr int maxMonth = 12;
	int daysPrMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leap = 0;

	//Check if its a leap year
	const auto& year = DMY.m128i_i32[2];
	if ((year % 4) == 0 and (year % 100) || (year % 400) == 0)
		leap = 1;
	daysPrMonth[1] += leap;

	//vectorizing to compare values, these functions require CPU SSE2 support, I won't bother to add support for other CPU's  right now, all cpu's in the last 10years should support SSE2
	const auto compVals = _mm_setr_epi32(daysPrMonth[DMY.m128i_i32[1] - 1], maxMonth, maxYear, 100);//making sure that w = 100 for comparison reasons
	//Leaving this for debugging
	//std::cout << DMY.m128i_i32[0] << " " << DMY.m128i_i32[1] << " " << DMY.m128i_i32[2] << " " << DMY.m128i_i32[3] << " " << std::endl;
	//std::cout << comVals.m128i_i32[0] << " " << comVals.m128i_i32[1] << " " << comVals.m128i_i32[2] << " " << comVals.m128i_i32[3] << " " << std::endl;
	//std::cout << _mm_cmpgt_epi32(DMY, comVals).m128i_i32[0] << " " << _mm_cmpgt_epi32(DMY, comVals).m128i_i32[1] << " " << _mm_cmpgt_epi32(DMY, comVals).m128i_i32[2] << " " << _mm_cmpgt_epi32(DMY, comVals).m128i_i32[3] << " " << std::endl;
	//std::cout << ((_mm_movemask_epi8(_mm_cmpgt_epi32(DMY, comVals)) & 7) == 7) << std::endl;
	//checking if DMY > compVals with vectorization
	if (((_mm_movemask_epi8(_mm_cmpgt_epi32(DMY, compVals)) & 7) != 7))
		return false;
	return true;
}