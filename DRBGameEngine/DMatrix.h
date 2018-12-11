#pragma once

#include "DCommon.h"

namespace DrbEngine
{
	struct DMatrix4x4
	{
		static DMatrix4x4 IDENTITY;

		DFloat m[4][4];

		DMatrix4x4()
		{
			memset(m, 0, sizeof(DFloat) * 16);
		}

		DMatrix4x4(const DMatrix4x4 &right)
		{
			m[0][0] = right.m[0][0], m[0][1] = right.m[0][1], m[0][2] = right.m[0][2], m[0][3] = right.m[0][3];
			m[1][0] = right.m[1][0], m[1][1] = right.m[1][1], m[1][2] = right.m[1][2], m[1][3] = right.m[1][3];
			m[2][0] = right.m[2][0], m[2][1] = right.m[2][1], m[2][2] = right.m[2][2], m[2][3] = right.m[2][3];
			m[3][0] = right.m[3][0], m[3][1] = right.m[3][1], m[3][2] = right.m[3][2], m[3][3] = right.m[3][3];
		}

		DMatrix4x4(DFloat m00,DFloat m01, DFloat m02, DFloat m03,
			DFloat m10, DFloat m11, DFloat m12, DFloat m13, 
			DFloat m20, DFloat m21, DFloat m22, DFloat m23, 
			DFloat m30, DFloat m31, DFloat m32, DFloat m33)
		{
			m[0][0] = m00, m[0][1] = m01, m[0][2] = m02, m[0][3] = m03;
			m[1][0] = m10, m[1][1] = m11, m[1][2] = m12, m[1][3] = m13;
			m[2][0] = m20, m[2][1] = m21, m[2][2] = m22, m[2][3] = m23;
			m[3][0] = m30, m[3][1] = m31, m[3][2] = m32, m[3][3] = m33;
		}

		//×ªÖÃ
		inline DMatrix4x4 transpose() const
		{
			DMatrix4x4 temp;
			for (DInt i = 0; i < 4; ++i)
			{
				for (DInt j = 0; j < 4; ++j)
				{
					temp.m[i][j] = m[j][i];
				}
			}
			return temp;
		}

		inline DFloat at(size_t i, size_t j) const
		{
			return m[i][j];
		}

		inline DFloat& at(size_t i, size_t j)
		{
			return m[i][j];
		}

		inline DMatrix4x4 operator +(const DMatrix4x4 &right) const
		{
			return DMatrix4x4(m[0][0] + right.m[0][0], m[0][1] + right.m[0][1], m[0][2] + right.m[0][2], m[0][3] + right.m[0][3],
				m[1][0] + right.m[1][0], m[1][1] + right.m[1][1], m[1][2] + right.m[1][2], m[1][3] + right.m[1][3], 
				m[2][0] + right.m[2][0], m[2][1] + right.m[2][1], m[2][2] + right.m[2][2], m[2][3] + right.m[2][3], 
				m[3][0] + right.m[3][0], m[3][1] + right.m[3][1], m[3][2] + right.m[3][2], m[3][3] + right.m[3][3]);
		}

		inline DMatrix4x4 operator -(const DMatrix4x4 &right) const
		{
			return DMatrix4x4(m[0][0] - right.m[0][0], m[0][1] - right.m[0][1], m[0][2] - right.m[0][2], m[0][3] - right.m[0][3],
				m[1][0] - right.m[1][0], m[1][1] - right.m[1][1], m[1][2] - right.m[1][2], m[1][3] - right.m[1][3],
				m[2][0] - right.m[2][0], m[2][1] - right.m[2][1], m[2][2] - right.m[2][2], m[2][3] - right.m[2][3],
				m[3][0] - right.m[3][0], m[3][1] - right.m[3][1], m[3][2] - right.m[3][2], m[3][3] - right.m[3][3]);
		}

		inline DMatrix4x4 operator *(const DFloat factor) const
		{
			return DMatrix4x4(m[0][0] * factor, m[0][1] * factor, m[0][2] * factor, m[0][3] * factor,
				m[1][0] * factor, m[1][1] * factor, m[1][2] * factor, m[1][3] * factor,
				m[2][0] * factor, m[2][1] * factor, m[2][2] * factor, m[2][3] * factor,
				m[3][0] * factor, m[3][1] * factor, m[3][2] * factor, m[3][3] * factor);
		}

		inline DMatrix4x4 operator *(const DMatrix4x4 &right) const
		{
			DMatrix4x4 ret;

			for (DInt i = 0; i < 4; ++i)
			{
				for (DInt j = 0; j < 4; ++j)
				{
					for (DInt k = 0; k < 4; ++k)
					{
						ret.m[i][j] += m[i][k] * right.m[k][j];
					}
				}
			}

			return ret;
		}

		inline DMatrix4x4 operator =(const DMatrix4x4 &right)
		{
			m[0][0] = right.m[0][0], m[0][1] = right.m[0][1], m[0][2] = right.m[0][2], m[0][3] = right.m[0][3];
			m[1][0] = right.m[1][0], m[1][1] = right.m[1][1], m[1][2] = right.m[1][2], m[1][3] = right.m[1][3];
			m[2][0] = right.m[2][0], m[2][1] = right.m[2][1], m[2][2] = right.m[2][2], m[2][3] = right.m[2][3];
			m[3][0] = right.m[3][0], m[3][1] = right.m[3][1], m[3][2] = right.m[3][2], m[3][3] = right.m[3][3];

			return *this;
		}

		inline DBool operator ==(const DMatrix4x4 &right)
		{
			return !(m[0][0] != right.m[0][0] || m[0][1] != right.m[0][1] || m[0][2] != right.m[0][2] || m[0][3] != right.m[0][3] ||
			m[1][0] != right.m[1][0] || m[1][1] != right.m[1][1] || m[1][2] != right.m[1][2] || m[1][3] != right.m[1][3] ||
			m[2][0] != right.m[2][0] || m[2][1] != right.m[2][1] || m[2][2] != right.m[2][2] || m[2][3] != right.m[2][3] ||
			m[3][0] != right.m[3][0] || m[3][1] != right.m[3][1] || m[3][2] != right.m[3][2] || m[3][3] != right.m[3][3]);
		}

		inline DBool operator !=(const DMatrix4x4 &right)
		{
			return m[0][0] != right.m[0][0] || m[0][1] != right.m[0][1] || m[0][2] != right.m[0][2] || m[0][3] != right.m[0][3] ||
				m[1][0] != right.m[1][0] || m[1][1] != right.m[1][1] || m[1][2] != right.m[1][2] || m[1][3] != right.m[1][3] ||
				m[2][0] != right.m[2][0] || m[2][1] != right.m[2][1] || m[2][2] != right.m[2][2] || m[2][3] != right.m[2][3] ||
				m[3][0] != right.m[3][0] || m[3][1] != right.m[3][1] || m[3][2] != right.m[3][2] || m[3][3] != right.m[3][3];
		}
	};
}
