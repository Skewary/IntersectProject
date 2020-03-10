#include "pch.h"
#include "CppUnitTest.h"
#include "../IntersectProject/CalDots.h"
#include<time.h>
#include<stdio.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		
		TEST_METHOD(TestCalDot)
		{
			CalDots*cald = new CalDots();
			int x0 = 0;
			int y0 = 0;
			int x1 = 1;
			int y1 = 1;
			int x2 = 0;
			int y2 = 0;
			int x3 = 0;
			int y3 = 0;
			double dotx = 0;
			double doty = 0;
			Assert::AreEqual(dotx, cald->CalDot(x0, y0, x1, y1, x2, y2, x3, y3).DotX);
			Assert::AreEqual(doty, cald->CalDot(x0, y0, x1, y1, x2, y2, x3, y3).DotY);
		}
		TEST_METHOD(TestTime)
		{
			srand(time(NULL));
			long t = clock();
			CalDots* cald = new CalDots();
			int Dot[5000][4];
			int i, j;
			for (i = 0; i < 5000; i++) {
				Dot[i][0] = rand() % 1000;
				Dot[i][1] = rand() % 1000;
				Dot[i][2] = rand() % 1000;
				Dot[i][3] = rand() % 1000;
			}

			for (i = 0; i < 5000; i++) {
				for (j = i + 1; j < 4999; j++) {
					cald->CalDot(Dot[i][0], Dot[i][1], Dot[i][2], Dot[i][3], Dot[j][0], Dot[j][1], Dot[j][2], Dot[j][3]);
				}
			}
			Assert::IsTrue(clock() - t < 60000);
		}
	};
}
