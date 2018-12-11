#include "DUtil.h"

namespace DrbEngine
{
	std::ofstream *GLogStream = NULL;

	bool InitLog(const DString &fileName)
	{
		if (GLogStream == NULL)
		{
			GLogStream = new std::ofstream();
			GLogStream->open(fileName.c_str());
			return GLogStream->good();
		}

		return true;
	}

	void Log(const DChar *string, ...)
	{
		if (GLogStream == NULL) return;

		DChar buffer[256];

		if (!string || !GLogStream) return;

		va_list arglist;
		va_start(arglist,string);
		vsprintf(buffer,string,arglist);
		va_end(arglist);

		DString info(buffer);
		*GLogStream << info << std::endl;
		GLogStream->flush();
	}

	void CloseLog()
	{
		if (GLogStream != NULL)
		{
			GLogStream->close();
			SafeDelete(GLogStream);
		}
	}

}