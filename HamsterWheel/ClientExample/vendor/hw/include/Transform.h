
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
		Vector3() : X{ 0 }, Y{ 0 }, Z{ 0 } {}
		float Magnitude()
		{
			double dX = X;
			double dY = Y;
			double dZ = Z;
			return (float)sqrt(dX * dX + dY * dY + dZ * dZ);
		}
	};

	class Transform
	{
	public:
		Vector3 _Position;
		Vector3 _Rotation;
		Transform() {}
		~Transform() {}
	private:
	};
}

