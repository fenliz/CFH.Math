#include "..\HelperMethods.h"
#include "Plane.h"

TEST(Plane, Constructors)
{
	Plane plane;

	//Plane()
	plane = Plane();
	EXPECT_VECTOR_EQ(plane.Normal, 0, 0, 0);
	EXPECT_EQ(plane.D, 0);

	//Plane(float, float, float, float)
	plane = Plane(1, 4, -2, 8);
	EXPECT_VECTOR_EQ(plane.Normal, 1, 4, -2);
	EXPECT_EQ(plane.D, 8);

	//Plane(Vector3, float)
	plane = Plane(Vector3(1, 0, -1), -4);
	EXPECT_VECTOR_EQ(plane.Normal, 1, 0, -1);
	EXPECT_EQ(plane.D, -4);

	//Plane(Vector3, Vector3, Vector3)
	EXPECT_TRUE(false) << "No test written for Plane constructor from points!";

	//Plane(Vector4)
	plane = Plane(Vector4(10, 9, 8, 7));
	EXPECT_VECTOR_EQ(plane.Normal, 10, 9, 8);
	EXPECT_EQ(plane.D, 7);
}

TEST(Plane, Creaters)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Plane, Dot)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Plane, Normalize)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Plane, Distance)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Plane, Project)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(Plane, Intersects)
{
	EXPECT_TRUE(false) << "No tests written!";
}