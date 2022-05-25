#include <sstream>

#include "catch.hpp"


// Helper function declarations (don't change these)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

static int grade = 0;

TEST_CASE("Graded vector tests", "[graded]")
{
	SECTION("Test input 01 -- seed A")
	{


	}
}

TEST_CASE("Graded end to end tests", "[graded]")
{
//     SECTION("Test input 01 -- seed A")
//     {
//         playPoker("input/input01.txt", "output/output01.txt", 946684800);
//         bool result = false;
// 
// #ifdef _MSC_VER
//         // Use the Windows output file
// 		result = CheckTextFilesSame("output/output01.txt", "expected/winOutput01.txt");
// #elif __APPLE__
//         // Use the Mac output file
// 		result = CheckTextFilesSame("output/output01.txt", "expected/macOutput01.txt");
// #else
// 		// Use the Travis output file
// 		result = CheckTextFilesSame("output/output01.txt", "expected/travisOutput01.txt");
// #endif
// 
// 		REQUIRE(result);
// 
// 		grade += 4;
// 	}
// 
// 	SECTION("Test input 01 -- seed B")
// 	{
// 		playPoker("input/input01.txt", "output/output02.txt", 1);
// 		bool result = false;
// 
// #ifdef _MSC_VER
// 		// Use the Windows output file
// 		result = CheckTextFilesSame("output/output02.txt", "expected/winOutput02.txt");
// #elif __APPLE__
// 		// Use the Mac output file
// 		result = CheckTextFilesSame("output/output02.txt", "expected/macOutput02.txt");
// #else
// 		// Use the Travis output file
// 		result = CheckTextFilesSame("output/output02.txt", "expected/travisOutput02.txt");
// #endif
// 
// 		REQUIRE(result);
// 
// 		grade += 4;
// 	}
// 
// 	WARN("****TEST CASES GRADE: " << grade << "/" << 80 << "****");

}


TEST_CASE("Test Cases Grade", "[graded]")
{
	WARN("****TEST CASES GRADE: " << grade << "/" << 80 << "****");
}

