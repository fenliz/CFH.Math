#pragma once

namespace CFH
{
	class Vector2;
	class Vector3;

	class Vector4
	{
	public:
		float X; float Y; float Z; float W;

		Vector4();
		Vector4(float value);
		Vector4(Vector2 vector, float z, float w);
		Vector4(Vector3 vector, float w);
		Vector4(float x, float y, float z, float w);
		~Vector4();
	};
}

