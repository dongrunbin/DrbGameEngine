#pragma once

#include "DCommon.h"

namespace DrbEngine
{
	struct DVector2
	{
		static DVector2 Zero;
		static DVector2 UNIT_X;
		static DVector2 UNIT_Y;

		DFloat x;
		DFloat y;

		DVector2() : x(0), y(0) {}
		DVector2(DFloat xf, DFloat yf) : x(xf), y(yf) {}
		DVector2(const DVector2& v) :x(v.x), y(v.y) {}

		inline DFloat length() const
		{
			return sqrt(x * x + y * y);
		}

		inline DFloat normalize()
		{
			DFloat len = length();
			if (len > EPSILON_E6)
			{
				DFloat invLength = 1.0f / len;
				x *= invLength;
				y *= invLength;
			}
		}

		inline DFloat dot(const DVector2& right) const
		{
			return x * right.x + y * right.y;
		}

		inline DFloat angle(const DVector2& right) const
		{
			DFloat lenProduct = length() * right.length();
			if (lenProduct < EPSILON_E6)
			{
				lenProduct = EPSILON_E6;
			}

			DFloat f = dot(right) / lenProduct;
			return acos(f);
		}

		inline DFloat squaredLength() const
		{
			return x * x + y * y;
		}

		inline DBool isZero()
		{
			if (x == 0 && y == 0) return true;
			return length() < EPSILON_E6;
		}

		inline DVector2 operator *(DFloat right) const
		{
			return DVector2(x * right, y * right);
		}

		inline DVector2 operator *(const DVector2& right) const
		{
			return DVector2(x * right.x, y * right.y);
		}

		inline DVector2 operator +(const DVector2& right) const
		{
			return DVector2(x + right.x, y + right.y);
		}

		inline DVector2 operator -(const DVector2& right) const
		{
			return DVector2(x - right.x, y - right.y);
		}

		inline DVector2 operator -()
		{
			x = -x;
			y = -y;
			return *this;
		}

		inline DVector2 operator +()
		{
			x = +x;
			y = +y;
			return *this;
		}

		inline DBool operator ==(const DVector2& right) const
		{
			return FloatEq
		}
	};
}