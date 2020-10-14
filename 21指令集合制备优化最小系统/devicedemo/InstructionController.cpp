#include"InstructionController.h"
#include<bits/stdc++.h>

//������&������յ�
void CalInclusionInflectionPoint(const std::vector<std::vector<int>>& source, vector<int>& MainInclusionMinPoint, vector<int>& MainInclusionMaxPoint, vector<int>& AuxiliaryInclusionMinPoint, vector<int>& AuxiliaryInclusionMaxPoint)
{
	if (source.size() <= 0)
	{
		return;
	}

	int MainInclusionMinIndex = 0;
	
	for (int i = 1;i < source.size();++i)
	{
		if (source[i][0] < source[MainInclusionMinIndex][0])
		{
			MainInclusionMinIndex = i;
		}
	}

	int AuxiliaryInclusionMaxIndex = MainInclusionMinIndex;
	int count = 0;
	for (int i = MainInclusionMinIndex + 1;i < source.size();++i)
	{
		if (source[i][0] > source[AuxiliaryInclusionMaxIndex][0])
		{
			AuxiliaryInclusionMaxIndex = i;
			count = 0;
		}
		else
		{
			count++;
			if (count > 3)break;
		}
	}

	int AuxiliaryInclusionMinIndex = AuxiliaryInclusionMaxIndex;
	for (int i = AuxiliaryInclusionMaxIndex + 1;i < source.size();++i)
	{
		if (source[i][0] < source[AuxiliaryInclusionMinIndex][0])
		{
			AuxiliaryInclusionMinIndex = i;
		}
	}

	int MainInclusionMaxIndex = MainInclusionMinIndex;
	for (int i = MainInclusionMinIndex + 1;i < AuxiliaryInclusionMaxIndex;++i)
	{
		if (abs(source[i][0] - source[AuxiliaryInclusionMinIndex][0]) < abs(source[MainInclusionMaxIndex][0] - source[AuxiliaryInclusionMinIndex][0]))
		{
			MainInclusionMaxIndex = i;
		}
	}

	MainInclusionMinPoint[0] = source[MainInclusionMinIndex][0];
	MainInclusionMinPoint[1] = source[MainInclusionMinIndex][1];

	MainInclusionMaxPoint[0] = source[MainInclusionMaxIndex][0];
	MainInclusionMaxPoint[1] = source[MainInclusionMaxIndex][1];

	AuxiliaryInclusionMinPoint[0] = source[AuxiliaryInclusionMinIndex][0];
	AuxiliaryInclusionMinPoint[1] = source[AuxiliaryInclusionMinIndex][1];

	AuxiliaryInclusionMaxPoint[0] = source[AuxiliaryInclusionMaxIndex][0];
	AuxiliaryInclusionMaxPoint[1] = source[AuxiliaryInclusionMaxIndex][1];
}


//������ʼ����յ�����ж�
bool StartPointAndEndPoint(const std::vector<std::vector<int>>& source, const std::vector<std::vector<int>>& des)
{
	int sLength = source.size();
	int dLength = des.size();
	int startPointDistance = sqrt((source[0][0] - des[0][0])*(source[0][0] - des[0][0]) + (source[0][1] - des[0][1])*(source[0][1] - des[0][1]));
	int endPointDistance = sqrt((source[sLength - 1][0] - des[dLength - 1][0])*(source[sLength - 1][0] - des[dLength - 1][0]) + (source[sLength - 1][1] - des[dLength - 1][1])*(source[sLength - 1][1] - des[dLength - 1][1]));
	cout << "��ʼ��֮��ľ��룺" << startPointDistance << endl;
	cout << "�յ�֮��ľ��룺" << endPointDistance << endl;
	if (sLength <= 0 || dLength <= 0)
	{
		return false;
	}
	else if (startPointDistance > 300 &&  endPointDistance> 300)
	{
		return false;
	}
	else return true;
}

//���ݵ�֮��ľ�����ж�
bool SumOfPointDistance(const std::vector<std::vector<int>>& source, const std::vector<std::vector<int>>& des)
{
	int Length = min(source.size(),des.size());
	int distance = 0;
	for (int i = 0;i < Length;++i)
	{
		distance += sqrt((source[i][0] - des[i][0])*(source[i][0] - des[i][0]) + (source[i][1] - des[i][1])*(source[i][1] - des[i][1]));
	}
	cout << "���ڵ�֮��ľ���ͣ�" << distance << endl;
	cout << "�������" << Length << endl;
	return distance < 120000 ? true : false;
}

//strToInt
void StrToCoor(const string &s, std::vector<std::vector<int>>& source,int&id)
{
	int n = s.size();
	string tmp;
	vector<int>coor;
	int index = 0;
	int k = 1;

	for (;index < n;++index)
	{
		if (s[index] == ' ')break;
		tmp += s[index];
	}

	id = atoi(tmp.c_str());
	tmp.clear();

	for (int i = index + 1;i < n;++i)
	{
		if (s[i] != ' ')
		{
			tmp += s[i];
		}
		else
		{
			coor.push_back(atoi(tmp.c_str()));
			if (k % 2 == 0)
			{
				source.push_back(coor);
				coor.clear();
			}
			k++;
			tmp.clear();
		}
	}
}