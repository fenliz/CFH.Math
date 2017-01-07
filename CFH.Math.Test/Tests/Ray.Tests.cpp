#include "..\HelperMethods.h"
#include "Ray.h"

TEST(Ray, Constructors)
{
	Ray ray;

	//Ray()
	ray = Ray();
	EXPECT_VECTOR_EQ(ray.Position, 0, 0, 0);
	EXPECT_VECTOR_EQ(ray.Direction, 0, 0, 0);

	//Ray(Vector3, Vector3)
	ray = Ray(Vector3(1, 2, 3), Vector3(0, 1, 0));
	EXPECT_VECTOR_EQ(ray.Position, 1, 2, 3);
	EXPECT_VECTOR_EQ(ray.Direction, 0, 1, 0);
}

TEST(Ray, Operators)
{
	Ray a, b;

	//Ray == Ray
	a = Ray(Vector3::One, Vector3::UnitX);
	b = Ray(Vector3::One * 3, Vector3::UnitZ);
	EXPECT_FALSE(a == b);
	a.Position = Vector3(3, 3, 3);
	b.Direction = Vector3(1, 0, 0);
	EXPECT_TRUE(a == b);

	//Ray != Ray
	EXPECT_FALSE(a != b);
	b.Direction = Vector3::UnitY;
	EXPECT_TRUE(a != b);
}

TEST(Ray, Intersects)
{
	EXPECT_TRUE(false) << "No tests written!";
}