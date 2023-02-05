
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

	struct Vector4
	{
		float X;
		float Y;
		float Z;
		float W;
		Vector4(float x, float y, float z, float w)
			: X{ x }, Y{ y }, Z{ z }, W{ w } {}
		Vector4() : X{ 0 }, Y{ 0 }, Z{ 0 }, W{ 0 } {}
		float Magnitude()
		{
			double dX = X;
			double dY = Y;
			double dZ = Z;
			double dW = W;
			return (float)sqrt(dX * dX + dY * dY + dZ * dZ + dW * dW);
		}
	};

	class Transform
	{
	public:
		Vector3 _Position;
		Vector3 _Rotation;
		Vector3 _Scale;
		Transform() {}
		~Transform() {}
	private:
	};
}

