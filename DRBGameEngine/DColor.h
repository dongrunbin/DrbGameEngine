#pragma once

#include "DCommon.h"

namespace DrbEngine
{
	struct DColor
	{
		DByte r, g, b, a;
		DColor(DInt color, DByte alpha = 255)
		{
			r = (DByte)((color & 0xff0000) >> 16);
			g = (DByte)((color & 0x00ff00) >> 8);
			b = (DByte)((color & 0x0000ff));
			a = alpha;
		}

		DColor(DByte r = 0, DByte g = 0, DByte b = 0, DByte a = 255) : r(r), g(g), b(b), a(a) {}
		DInt ToInt() const
		{
			return DCOLOR_16BIT(r, g, b);
		}

		DColor operator *(const DColor &c) const
		{
			DInt r = this->r * c.r >> 8;
			DInt g = this->g * c.g >> 8;
			DInt b = this->b * c.b >> 8;
			DInt a = this->a * c.a >> 8;
			return DColor(r, g, b, a);
		}
	};
}