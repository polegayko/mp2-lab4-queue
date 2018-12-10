#pragma once
#include <cstdlib>
#include <ctime>
class TJobStream
{
	private:
		double JobIntens;
	public:
		TJobStream(double Intens)
		{
			std::srand(unsigned(std::time(0)));
			JobIntens = Intens * RAND_MAX;
		};
		int GetNewJob(void)
		{
			double a = std::rand()%RAND_MAX;
			if (a < JobIntens)
			{
				return 0;//поступило новое задание
			}
			else
			{
				return 1; //нового задания нет
			}

		};
		~TJobStream(){};
};

