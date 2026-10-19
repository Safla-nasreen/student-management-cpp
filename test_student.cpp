#include <gtest/gtest.h>
#include "StudentManager.h"

TEST(StudentManagerTest, FindsAnuById)
{
    StudentManager manager;                 
    auto result = manager.findStudent(2);   

    ASSERT_TRUE(result.has_value());        
    EXPECT_EQ(result->name, "Anu");         
}
TEST(StudentManagerTest, StudentNotFound)
{
    StudentManager manager;                 
    auto result = manager.findStudent(99);   

    EXPECT_FALSE(result.has_value());         
}