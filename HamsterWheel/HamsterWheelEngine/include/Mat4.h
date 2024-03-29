#pragma once
#include <math.h>
#include <cstring>
#include <iostream>

namespace HW
{

	class Mat4
	{
	public:
		float _Matrix[16];

		static Mat4 Identity()
		{
			float matrix[16] =
			{
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1
			};
			return Mat4(matrix);
		}
		static Mat4 OrthographicProjection(float right, float left, float top, float bottom, float far, float near)
		{
			float matrix[16] =
			{
				2.0 / right - left, 0,					  0,				   -((right + left) / (right - left)),
				0,					2.0 / (top - bottom), 0,				   -((top + bottom) / (top - bottom)),
				0,					0,					  -2.0 / (far - near), -((far + near) / (far - near)),
				0,					0,					  0,                   1
			};
			return Mat4(matrix);
		}

		Mat4()
		{
			std::memset(_Matrix, 0, sizeof(float) * 16);
		}
		Mat4(
			float x00, float x01, float x02, float x03,
			float x10, float x11, float x12, float x13,
			float x20, float x21, float x22, float x23,
			float x30, float x31, float x32, float x33)
		{
			_Matrix[0]  = x00;  _Matrix[1]  = x01; _Matrix[2]  = x02; _Matrix[3]  = x03;
			_Matrix[4]  = x10;  _Matrix[5]  = x11; _Matrix[6]  = x12; _Matrix[7]  = x13;
			_Matrix[8]  = x20;  _Matrix[9]  = x21; _Matrix[10] = x22; _Matrix[11] = x23;
			_Matrix[12] = x30;  _Matrix[13] = x31; _Matrix[14] = x32; _Matrix[15] = x33;
		}

		Mat4(float matrix[16])
		{
			std::memcpy(_Matrix, matrix, sizeof(float) * 16);
		}



		Mat4 Transpose()
		{
			Mat4 result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					// For each column, copy the corresponding row
					result[i * 4 + j] = _Matrix[j * 4 + i];
				}
			}
			return result;
		}

		float& operator[](int index)
		{
			return (float&)_Matrix[index];
		}

		const float operator[](int index) const
		{
			return (float)_Matrix[index];
		}

		Mat4 operator*(const Mat4& rhs) const
		{
			Mat4 product;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					// dot product of rows and columns for each cell
					float sum = 0;
					for (int k = 0; k < 4; k++)
					{
						sum += _Matrix[i * 4 + k] * rhs[j + k * 4];
					}
					product[4 * i + j] = sum;
				}
			}
			return product;
		}

		Mat4 operator*(float scalar) const
		{
			Mat4 product;
			for (int i = 0; i < 16; i++)
			{
				product[i] = scalar * _Matrix[i];
			}
			return product;
		}

		Mat4& operator=(const Mat4& rhs)
		{
			// Check self assignment
			if (this == &rhs)
				return *this;

			memcpy(_Matrix, rhs._Matrix, sizeof(float)*16);
			return *this;
		}

		void Print()
		{
			std::cout << "[\n";
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					std::cout << _Matrix[i * 4 + j] << " ";
				}
				std::cout << "\n";
			}
			std::cout << "]\n";
		}
	};


}