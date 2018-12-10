#pragma once
#include <cstdlib>
class TProc
{
private:
	double ProcRate;
		int JobId;
public:
	TProc(double Rate)
	{
		ProcRate = Rate * RAND_MAX;
		JobId = 0;
	};
	int IsProcBusy(void)
	{
		double a = std::rand() % RAND_MAX;
		if (a < ProcRate)
		{
			return 0;//процессор свободен
		}
		else
		{
			return 1; //процессор занят
		}
	};
	int RunNewJob(int _JobId)
	{
		if (IsProcBusy() == 0)
		{
			JobId=_JobId;
		};
		return JobId;
	};
	~TProc() {};
};

