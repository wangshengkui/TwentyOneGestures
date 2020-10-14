#pragma once
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class ComputeCharacter
{
public:
	string des;
	vector<vector<int>> points;//��Ź���ÿ�����ֵ���������㼯��
	vector<double> distance;//������ڵ�֮��ľ���
	int tag;//������ֱ�ǩ
	int pointsNumber;//����������
	int minX,minY, maxX, maxY;//x,y�����Сֵ
	int xLength, yLength;//�߿�ĳ���
	int square;//�߿򹹳ɵ����
	double HandWritingLength;//�ʼ�����
	double CentroidX, CentroidY;//��������
	double XYRatio;//�߽����
	double Compactness;//������
	double closeness;//�����
	vector<double> angle;//����������ļн�
	double curvature;//����
	double beginDirection;//��ʼ����
	double endDirection;//��ֹ����
	double XstartPointMinOffset;//��ʼ�㵽�߽����Сֵƫ����x
	double YstartPointMinOffset;//��ʼ�㵽�߽����Сֵƫ����y
	double XstartPointMaxOffset;//��ʼ�㵽�߽�����ֵƫ����x
	double YstartPointMaxOffset;//��ʼ�㵽�߽�����ֵƫ����y
	double XendPointMinOffset;//��ʼ�㵽�߽����Сֵƫ����x
	double YendPointMinOffset;//��ʼ�㵽�߽����Сֵƫ����y
	double XendPointMaxOffset;//��ʼ�㵽�߽�����ֵƫ����x
	double YendPointMaxOffset;//��ʼ�㵽�߽�����ֵƫ����y

	//���캯��
	ComputeCharacter(const string str);
	//stringתint
	void StrToCoor(const string &s);
	//��������������
	void CalCount();
	//����x,y����ֵ
	void GetXY();
	//����߽糤��
	void CalBoardLength();
	//����߽�Χ�ɵ����
	void CalBoardSquare();
	//�������ڵ�֮��ľ���
	void CalDistanceOfTwoPoint();
	//����ʼ�����
	void CalHandWritingLength();
	//��������
	void CalCentroid();
	//����߽����
	void CalXYRatio();
	//���������
	void CalCompactness();
	//��������
	void CalCloseness();
	//��������������ļн�
	void CalAngle();
	//��������
	void CalCurvature();
	//�����ʼ����
	void CalBeginDirection();
	//������ֹ����
	void CalEndDirection();
	//����ƫ����
	void CalOffset();

	//���㺯��
	void Compute();

	//���Ժ���
	void debug();
};

