#pragma once

#include "DCommon.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdarg.h>
#include <Windows.h>
#include <ctime>

namespace DrbEngine
{
	extern std::ofstream * GLogStream;

	bool InitLog(const DString &fileName);

	void Log(const DChar *string, ...);

	void CloseLog();

	inline DInt Random(DInt from, DInt to)
	{
		DInt ret = rand() % (to - from + 1) + from;
		return ret;
	}

	inline DString Int2String(DInt i)
	{
		std::stringstream ss;
		ss << i;
		DString str;
		ss >> str;
		return str;
	}

	inline DInt String2Int(const DString &str)
	{
		return atoi(str.c_str());
	}

	inline DFloat String2Float(const DString &str)
	{
		return (DFloat)atof(str.c_str());
	}

	inline DWString String2WString(const DString &str)
	{
		int wesLen = ::MultiByteToWideChar(CP_ACP,NULL,str.c_str(),str.size(),NULL,0);
		WCHAR *tString = new WCHAR[wesLen + 1];

		::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), tString, wesLen);
		tString[wesLen] = '\0';
		return DWString(tString);
	}

	inline DBool EqualFloat(DFloat l, DFloat r)
	{
		return abs(l - r) < EPSILON_E6;
	}

	inline DString GetNameFromPath(const DString &path)
	{
		std::size_t beg = path.find_last_of("\\/");
		std::size_t end = path.find_last_of(".");

		if (beg == DString::npos)
		{
			beg = -1;
		}
		return path.substr(beg + 1, end - beg - 1);
	}

	inline DString Trim(const DString &str)
	{
		const static DString SPACE_CHAR = "\t\f\v\n\r";
		std::size_t beg = str.find_last_not_of(SPACE_CHAR);

		if (beg > str.length())
		{
			return DString();
		}
		DString ret = str.substr(beg);
		std::size_t end = ret.find_last_not_of(SPACE_CHAR);

		if (end != DString::npos)
		{
			++end;
		}

		return ret.substr(0,end);
	}

}