#include "..\HelperMethods.h"
#include "BoundingBox.h"

TEST(BoundingBox, Constructors)
{
	BoundingBox boundingBox;

	//BoundingBox()
	boundingBox = BoundingBox();
	EXPECT_VECTOR_EQ(boundingBox.Min, 0, 0, 0);
	EXPECT_VECTOR_EQ(boundingBox.Max, 0, 0, 0);

	//BoundingBox(Vector3, Vector3)
	boundingBox = BoundingBox(Vector3(1, 2, 3), Vector3(2, 4, 6));
	EXPECT_VECTOR_EQ(boundingBox.Min, 1, 2, 3);
	EXPECT_VECTOR_EQ(boundingBox.Max, 2, 4, 6);
}

TEST(BoundingBox, Operators)
{
	BoundingBox boundingBox, boundingBox2;

	//BoundingBox == BoundingBox
	boundingBox = BoundingBox(Vector3(1, 1, 1), Vector3(2, 4, 10));
	boundingBox2 = BoundingBox(Vector3(1, 1, 1), Vector3(2, 4, 11));
	EXPECT_FALSE(boundingBox == boundingBox2);
	boundingBox.Max.Z = 11;
	EXPECT_TRUE(boundingBox == boundingBox2);

	//BoundingBox != BoundingBox
	EXPECT_FALSE(boundingBox != boundingBox2);
	boundingBox.Min = Vector3(1, -2, -4444);
	EXPECT_TRUE(boundingBox != boundingBox2);
}

TEST(BoundingBox, Creators)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(BoundingBox, Contains)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(BoundingBox, Intersects)
{
	EXPECT_TRUE(false) << "No tests written!";
}

TEST(BoundingBox, GetCorners)
{
	EXPECT_TRUE(false) << "No tests written!";
}