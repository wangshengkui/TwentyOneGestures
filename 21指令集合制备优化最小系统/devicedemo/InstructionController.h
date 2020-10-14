#pragma once
#include<vector>
using namespace std;
//�������յ�
void CalInclusionInflectionPoint(const std::vector<std::vector<int>>& source, vector<int>& MainInclusionMinPoint, vector<int>& MainInclusionMaxPoint, vector<int>& AuxiliaryInclusionMinPoint, vector<int>& AuxiliaryInclusionMaxPoint);
//������ʼ����յ�����ж�
bool StartPointAndEndPoint(const std::vector<std::vector<int>>& source, const std::vector<std::vector<int>>& des);
//���ݵ�֮��ľ�����ж�
bool SumOfPointDistance(const std::vector<std::vector<int>>& source, const std::vector<std::vector<int>>& des);
//���ݰ��峤���ж�
bool LengthAndWidth(const std::vector<std::vector<int>>& source, const std::vector<std::vector<int>>& des);
//�������ĵ��ж�
bool CenterPoint(const std::vector<std::vector<int>>& source, const std::vector<std::vector<int>>& des);
//strToInt
void StrToCoor(const string &s, std::vector<std::vector<int>>& source,int &id);