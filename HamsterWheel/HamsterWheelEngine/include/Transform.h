
#pragma once
#include <math.h>

namespace HW
{
	struct Vector3
	{
		float X;
		float Y;
		float Z;
		Vector3(float x, float y, float z)
			: X{ x }, Y{ y }, Z{ z } {}
		float Magnitude()
		{
			return (float)sqrt(X * X + Y * Y + Z * Z);
		}
	};

	class Transform
	{
	public:
		Vector3 _Position;
		Vector3 _Rotation;
		Transform();
		~Transform();
	private:
	};
}

