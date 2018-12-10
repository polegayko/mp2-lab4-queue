#pragma once
#define MaxMemSize 10
class Queue
{
	int *pMem;
	int MemSize;
	int Hi;
	int Li;
	int DataCount;

public:
	Queue(int Size=MaxMemSize)
	{
		MemSize=Size;
		pMem = new int[MemSize];
		for (int i=0;i<MemSize;i++)
		{
			pMem[i]=0;
		}
		Hi=0;
		Li=0;
		DataCount=0;
	};
	~Queue(void)
	{
		delete[] pMem;
	};
	Queue( const Queue &tmp)
	{
		MemSize=tmp.MemSize;
		Hi=tmp.Hi;
		Li=tmp.Li;
		DataCount=tmp.DataCount;
		pMem = new int[MemSize];
		for (int i=0;i<MemSize;i++)
		{
			pMem[i]=tmp.pMem[i];
		}
	};
	Queue &operator= (Queue tmp)
	{
		if (MemSize != tmp.MemSize)
		{
			if (MemSize != 0)
			{
				delete[] pMem;
			}
			MemSize = tmp.MemSize;
			pMem = new int[MemSize];
		}
		for (int i=0;i<MemSize;i++)
		{
			pMem[i]=tmp.pMem[i];
		}
		Hi=tmp.Hi;
		Li=tmp.Li;
		DataCount=tmp.DataCount;
	};
	int IsEmpty()
	{
		if (DataCount==0)
			return 0;  //Очередь пуста
		else return 1;  // Очередь не пуста
	}
	int IsFull()
	{
		if (DataCount==MemSize)
			return 0;  //Очередь полна
		else return 1;  // Очередь не полна
	}
	void Put (int tmp)
	{
		pMem[Hi++]=tmp;
		if (Hi == MemSize)
			Hi=0;
		DataCount++;
	}
	int Get ()
	{
		int a=pMem[Li];
		DataCount --;
		if (DataCount == 0)
		{
			Hi=0;
			Li=0;
		}
		else 
		{
			Li++;
			if (Li == MemSize)
				Li=0;
		}
		return a;
	}
};
