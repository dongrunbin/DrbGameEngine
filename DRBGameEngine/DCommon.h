#pragma once

#include <string>

namespace DrbEngine
{
	typedef char DChar;
	typedef short DShort;
	typedef int DInt;
	typedef long DLong;
	typedef float DFloat;
	typedef bool DBool;
	typedef double DDouble;
	typedef std::string DString;
	typedef std::wstring DWString;

	typedef unsigned char DByte;
	typedef unsigned short DUShort;
	typedef unsigned int DUInt;
	typedef unsigned long DULong;

	const DInt SCREEN_WIDTH = 800;
	const DInt SCREEN_HEIGHT = 600;

#define PI 3.141592654f
#define PI2 (PI * 2f)
#define PI_DIV_2 (PI * 0.5f)
#define PI_DIV_4 (PI * 0.25f)
#define PI_INV 0.318309886f

#define EPSILON_E6 ((DFloat)(1E-6))
//角度转弧度
#define DEGREE_TO_RADIAN(deg) (deg * 0.017453f)
//弧度转角度
#define RADIAN_TO_DEGREE(rad) (rad * 57.295780f)

#define ABS(a) ((a) > 0 ? (a) : -(a))

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vo_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

#define SafeDelete(ptr) if(ptr) {delete ptr; ptr = 0;}
#define SafeDeleteArray(ptr) if(ptr){delete []ptr; ptr = 0;}

//输出
#define COUNT(a) std::count<<#a<<":"<<(a)<<std::endl;

//颜色定义
#define DCOLOR_16BIT(r,g,b) (((r) & 0xff) << 16 | ((g) & 0xff) << 8 | ((b) & 0xff))
}