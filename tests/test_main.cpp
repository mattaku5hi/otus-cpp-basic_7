#include <gtest/gtest.h>


/* 
    Main function for running unit-tests
*/
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 