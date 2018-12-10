// testqueue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Queue.h"
#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "TJobStream.h"
#include "TProc.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "Enter maximal queue size" << endl;
	cin >> n;
	Queue Q(n);
	/*cout << "Control pustoty " << Q.IsEmpty() << endl;
	cout << "Control polnoty " << Q.IsFull() << endl;
	for (int i=0; i<5; i++)
	{
		Q.Put(i+2*i);

	}
	cout << "Control pustoty " << Q.IsEmpty() << endl;
	cout << "Control polnoty " << Q.IsFull() << endl;
	int i;
	while (Q.IsFull()!=0)
	{
		Q.Put(4);
	}
	cout << "Control pustoty " << Q.IsEmpty() << endl;
	cout << "Control polnoty " << Q.IsFull() << endl;
	while (Q.IsEmpty() == 1)
	{
		cout << Q.Get() << endl;
	}
	cout << "Control pustoty " << Q.IsEmpty() << endl;
	cout << "Control polnoty " << Q.IsFull() << endl;*/
	int count;
	cout << "Enter count of tact" << endl;
	cin >> count;
	for (int j = 0; j < 3; j++)
	{
		int number = 0;
		int counttask = 0;
		int countreject = 0;
		int countempty = 0;
		int oldnum = 0;
		int *listnum;
		int *listtact;
		listnum = new int[count];
		listtact = new int[count];


		cout << "Enter q1 from 0 to 1" << endl;
		double q1;
		cin >> q1;
		TJobStream TJ(q1);
		/*cout << RAND_MAX << endl;
		for (int i = 0; i < 100; i++)
		{
			cout << "Is job here?" << TJ.GetNewJob() << endl;
		}*/
		cout << "Enter q2 from 0 to 1" << endl;
		double q2;
		cin >> q2;
		TProc TP(q2);
		/*for (int i = 0; i < 100; i++)
		{
			cout << "Is job here?" << TP.RunNewJob() << endl;
		}*/

		for (int i = 0; i < count; i++)
		{
			if (TJ.GetNewJob() == 0)
			{
				if (Q.IsFull() != 0)
				{
					Q.Put(++number);
				}
				else
				{
					cout << "Queue is full" << endl;
					countreject++;
				};
			};
			if (TP.IsProcBusy() == 0)
			{

				if (Q.IsEmpty() == 1)
				{
					int job = TP.RunNewJob(Q.Get());
				}
				else
				{
					cout << "Queue is empty" << endl;
					countempty++;
				}
			}
			if (oldnum == number)
			{
				listtact[counttask-1]++;
			}
			else
			{
				oldnum = number;
				listnum[counttask] = number;
				listtact[counttask++] = 1;
			};
			cout << "Number " << number << endl;

		};
		cout << "Count of full queue " << countreject*100/count <<"%"<< endl;
		cout << "Count of empty queue " << countempty*100 / count  <<"%" <<endl;
		cout << "Count of task " << counttask << endl;
		for (int i = 0; i<counttask;i++)
		{
			cout << "Number of task   " << listnum[i] << "   Count tact   " << listtact[i] << endl;
		}

	}
	system("pause");
	return 0;
}

