#include "..\HelperMethods.h"
#include "BoundingSphere.h"

TEST(BoundingSphere, Constructors)
{
	BoundingSphere boundingSphere;

	//BoundingSphere()
	boundingSphere = BoundingSphere();
	EXPECT_VECTOR_EQ(boundingSphere.Center, 0, 0, 0);
	EXPECT_EQ(boundingSphere.Radius, 0);

	//BoundingSphere(Vector3, float);
	boundingSphere = BoundingSphere(Vector3(1, 2, 3), 8.5f);
	EXPECT_VECTOR_EQ(boundingSphere.Center, 1, 2, 3);
	EXPECT_EQ(boundingSphere.Radius, 8.5f);
}

TEST(BoundingSphere, Operators)
{
	BoundingSphere boundingSphere, boundingSphere2;

	//BoundingSphere == BoundingSphere
	boundingSphere = BoundingSphere(Vector3(1, 1, 1), 1.5f);
	boundingSphere2 = BoundingSphere(Vector3(1, 2, 2), 2.5f);
	EXPECT_FALSE(boundingSphere == boundingSphere2);
	boundingSphere.Radius = 2.5f;
	boundingSphere2.Center = Vector3(1, 1, 1);
	EXPECT_TRUE(boundingSphere == boundingSphere2);

	//BoundingSphere != BoundingSphere
	EXPECT_FALSE(boundingSphere != boundingSphere2);
	boundingSphere.Center = Vector3(1, -2, -4444);
	EXPECT_TRUE(boundingSphere != boundingSphere2);
}

TEST(BoundingSphere, Creators)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(BoundingSphere, Contains)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(BoundingSphere, Intersects)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(BoundingSphere, Transforms)
{
	EXPECT_TRUE(false) << "No tests written!";
}