#include"ComputeCharacter.h"
#include<cmath>

//���캯��
ComputeCharacter::ComputeCharacter(const string str)
{
	des = str;
}
//�ַ���ת��ǩ����������
void ComputeCharacter::StrToCoor(const string &s)
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
	tag = atoi(tmp.c_str());
	tmp.clear();

	index++;
	for (;index < n;++index)
	{
		if (s[index] == ' ')break;
		tmp += s[index];
	}
	strokeCount = atoi(tmp.c_str());
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
				points.push_back(coor);
				coor.clear();
			}
			k++;
			tmp.clear();
		}
	}
}

//��������������
void ComputeCharacter::CalCount()
{
	pointsNumber = points.size();
}

//����x,y�����ֵ����Сֵ
void ComputeCharacter::GetXY()
{
	if (pointsNumber <= 0)return;
	minX = maxX = points[0][0];
	minY = maxY = points[0][1];

	for (int i = 1; i < pointsNumber;++i)
	{
		minX = min(minX, points[i][0]);
		maxX = max(maxX, points[i][0]);
		minY = min(minY, points[i][1]);
		maxY = max(maxY, points[i][1]);
	}
}

//����߽糤��
void ComputeCharacter::CalBoardLength()
{
	xLength = maxX - minX;
	yLength = maxY - minY;
}

//����߽������
void ComputeCharacter::CalBoardSquare()
{
	square = xLength * yLength;
}

//�������ڵ�֮��ľ���
void ComputeCharacter::CalDistanceOfTwoPoint()
{
	double tmp;
	for (int i = 1;i < pointsNumber;++i)
	{
		tmp = sqrt((double)(points[i][0] - points[i - 1][0])*(points[i][0] - points[i - 1][0]) + (double)(points[i][1] - points[i - 1][1])*(points[i][1] - points[i - 1][1]));
		distance.push_back(tmp);
	}
}

//����ʼ�����
void ComputeCharacter::CalHandWritingLength()
{
	for (int i = 0;i < distance.size();++i)
	{
		HandWritingLength += distance[i];
	}
}

//��������
void ComputeCharacter::CalCentroid()
{
	long long sumX = 0;
	long long sumY = 0;
	for (int i = 0;i < pointsNumber;++i)
	{
		sumX += points[i][0];
		sumY += points[i][1];
	}

	CentroidX = sumX / pointsNumber;
	CentroidY = sumY / pointsNumber;
}

//����߿����
void ComputeCharacter::CalXYRatio()
{
	XYRatio = (double)xLength / (double)yLength;
}

//������ܶ�
void ComputeCharacter::CalCompactness()
{
	Compactness = HandWritingLength * HandWritingLength / square;
}

//��������
void ComputeCharacter::CalCloseness()
{
	closeness = HandWritingLength / sqrt((points[0][0] - points[pointsNumber - 1][0])*(points[0][0] - points[pointsNumber - 1][0]) + (points[0][1] - points[pointsNumber - 1][1])*(points[0][1] - points[pointsNumber - 1][1]));
}

//��������������ļн�
void ComputeCharacter::CalAngle()
{
	int step = pointsNumber / 10;
	for (int i = 0;i < pointsNumber - 2*step;i += step)
	{
		double a = sqrt((double)(points[i][0] - points[i + step][0])*(points[i][0] - points[i + step][0]) + (double)(points[i][1] - points[i + step][1])*(points[i][1] - points[i + step][1]));
		double b = sqrt((double)(points[i + 2*step][0] - points[i + step][0])*(points[i + 2*step][0] - points[i + step][0]) + (double)(points[i + 2*step][1] - points[i + step][1])*(points[i + 2*step][1] - points[i + step][1]));;
		double c = sqrt((double)(points[i][0] - points[i + 2*step][0])*(points[i][0] - points[i + 2*step][0]) + (double)(points[i][1] - points[i + 2*step][1])*(points[i][1] - points[i + 2*step][1]));
		if (a + b > c && a + c > b && b + c > a)
		{
			angle.push_back(acos((a*a + b*b - c*c) / (2 * a*b)) * 180 / 3.1415);
		}
	}
}

//void ComputeCharacter::CalAngle()
//{
//	int step = pointsNumber / 10;
//	for (int i = 0;i < pointsNumber - 2;++i)
//	{
//		double a = distance[i];
//		double b = distance[i + 1];
//		double c = sqrt((double)(points[i][0] - points[i + 2][0])*(points[i][0] - points[i + 2][0]) + (double)(points[i][1] - points[i + 2][1])*(points[i][1] - points[i + 2][1]));
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			angle.push_back(acos((a*a + b*b - c*c) / (2 * a*b)) * 180 / 3.1415);
//		}
//	}
//}

//��������
void ComputeCharacter::CalCurvature()
{
	for (int i = 0;i < angle.size();++i)
	{
		curvature += angle[i];
	}

	curvature /= angle.size();
	//cout << "���Ƕ�/�ߵ���������" << curvature / angle.size() << endl << endl;
}

//�����ʼ����
void ComputeCharacter::CalBeginDirection()
{
	if (points[1][0] - points[0][0] == 0)
	{
		if (points[2][0] - points[0][0] == 0)
		{
			beginDirection = 0;
		}
		else
		{
			beginDirection = (double)(points[2][1] - points[0][1]) / (double)(points[2][0] - points[0][0]);
		}
	}
	else
	{
		beginDirection = (double)(points[1][1] - points[0][1]) / (double)(points[1][0] - points[0][0]);
	}
}

//������ֹ����
void ComputeCharacter::CalEndDirection()
{
	if (points[pointsNumber - 1][0] - points[pointsNumber - 2][0] == 0)
	{
		if (points[pointsNumber - 1][0] - points[pointsNumber - 3][0] == 0)
		{
			endDirection = 0;
		}
		else
		{
			endDirection = (double)(points[pointsNumber - 1][1] - points[pointsNumber - 3][1]) / (double)(points[pointsNumber - 1][0] - points[pointsNumber - 3][0]);
		}
	}
	else
	{
		endDirection = (double)(points[pointsNumber - 1][1] - points[pointsNumber - 2][1]) / (double)(points[pointsNumber - 1][0] - points[pointsNumber - 2][0]);
	}
}

//����ƫ����
void ComputeCharacter::CalOffset()
{
	//XstartPointMinOffset = (points[0][0] - minX) / xLength;
	//YstartPointMinOffset = (points[0][1] - minY) / xLength;//��ʼ�㵽�߽����Сֵƫ����y
	//XstartPointMaxOffset = (points[0][0] - maxX) / xLength;//��ʼ�㵽�߽�����ֵƫ����x
	//YstartPointMaxOffset = (points[0][1] - maxY) / xLength;//��ʼ�㵽�߽�����ֵƫ����y
	//XendPointMinOffset = (points[pointsNumber - 1][0] - minX) / xLength;//��ֹ�㵽�߽����Сֵƫ����x
	//YendPointMinOffset = (points[pointsNumber - 1][1] - minY) / xLength;//��ֹ�㵽�߽����Сֵƫ����y
	//XendPointMaxOffset = (points[pointsNumber - 1][0] - maxX) / xLength;//��ֹ�㵽�߽�����ֵƫ����x
	//YendPointMaxOffset = (points[pointsNumber - 1][0] - maxY) / xLength;//��ֹ�㵽�߽�����ֵƫ����y

	XstartPointMinOffset = (points[0][0] - minX);
	YstartPointMinOffset = (points[0][1] - minY);//��ʼ�㵽�߽����Сֵƫ����y
	XstartPointMaxOffset = (points[0][0] - maxX);//��ʼ�㵽�߽�����ֵƫ����x
	YstartPointMaxOffset = (points[0][1] - maxY);//��ʼ�㵽�߽�����ֵƫ����y
	XendPointMinOffset = (points[pointsNumber - 1][0] - minX);//��ֹ�㵽�߽����Сֵƫ����x
	YendPointMinOffset = (points[pointsNumber - 1][1] - minY);//��ֹ�㵽�߽����Сֵƫ����y
	XendPointMaxOffset = (points[pointsNumber - 1][0] - maxX);//��ֹ�㵽�߽�����ֵƫ����x
	YendPointMaxOffset = (points[pointsNumber - 1][0] - maxY);//��ֹ�㵽�߽�����ֵƫ����y
}

//���㺯��
void ComputeCharacter::Compute()
{
	//stringתint
	StrToCoor(des);
	//��������������
	CalCount();
	//����x,y����ֵ
	GetXY();
	//����߽糤��
	CalBoardLength();
	//����߽�Χ�ɵ����
	CalBoardSquare();
	//�������ڵ�֮��ľ���
	CalDistanceOfTwoPoint();
	//����ʼ�����
	CalHandWritingLength();
	//��������
	CalCentroid();
	//����߽����
	CalXYRatio();
	//���������
	CalCompactness();
	//��������
	CalCloseness();
	//��������������ļн�
	CalAngle();
	//��������
	CalCurvature();
	//�����ʼ����
	CalBeginDirection();
	//������ֹ����
	CalEndDirection();
	//����ƫ����
	CalOffset();
	//��ʼ��&��ֹ�㵽x��y���ֵ���������߿�ı�ֵ
	RatioOfESPoint();
	//����յ�ĸ���
	CalInflectionPointsNumber();
}

//���Ժ���
void ComputeCharacter::debug()
{
	cout << "��ǩ��" << tag << endl;
	cout << "����Ե�������" << pointsNumber << endl;
	cout << "X�����ֵ:" << maxX << endl;
	cout << "X����Сֵ:" << minX << endl;
	cout << "Y�����ֵ:" << maxY << endl;
	cout << "Y����Сֵ:" << minY << endl;
	cout << "�߿򳤶�X��" << xLength << endl;
	cout << "�߿򳤶�Y��" << yLength << endl;
	cout << "�߿򹹳ɵ������" << square << endl;
	cout << "�ʼ����ȣ�" << HandWritingLength << endl;
	cout << "��������X��" << CentroidX << endl;
	cout << "��������Y��" << CentroidY << endl;
	cout << "�߽������" << XYRatio << endl;
	cout << "�����ԣ�" << Compactness << endl;
	cout << "����ԣ�" << closeness << endl;
	cout << "���ʣ�" << curvature << endl;
	cout << "��ʼ����" << beginDirection << endl;
	cout << "��ֹ����" << endDirection << endl;
	cout << "**************end***************" << endl;
}

//��ʼ��&��ֹ�㵽x��y���ֵ���������߿�ı�ֵ
void ComputeCharacter::RatioOfESPoint()
{
	xStartMaxLengthRatio = (double)(points[0][0] - maxX) / ((double)max(xLength, yLength) / (double)1000);
	yStartMaxLengthRatio = (double)(points[0][1] - maxY) / ((double)max(xLength, yLength) / (double)1000);
	xEndMaxLengthRatio = (double)(points[pointsNumber - 1][0] - maxX) / ((double)max(xLength, yLength) / (double)1000);
	yEndMaxLengthRatio = (double)(points[pointsNumber - 1][1] - maxY) / ((double)max(xLength, yLength) / (double)1000);
	xStartMinLengthRatio = (double)(points[0][0] - minX) / ((double)max(xLength, yLength) / (double)1000);;
	yStartMinLengthRatio = (double)(points[0][1] - minY) / ((double)max(xLength, yLength) / (double)1000);
}

//����յ�ĸ���
void ComputeCharacter::CalInflectionPointsNumber()
{
	double slope = 0;
	int step = pointsNumber / 10;
	for (int i = step;i < pointsNumber - 1;i += step)
	{
		if (points[i][0] - points[i + 1][0] != 0)
		{
			if (slope == 0)
			{
				slope = (double)(points[i][1] - points[i + 1][1]) / (double)(points[i][0] - points[i + 1][0]);
			}
			else
			{
				double tmp = (double)(points[i][1] - points[i + 1][1]) / (double)(points[i][0] - points[i + 1][0]);
				if (slope*tmp < 0)
				{
					InflectionPointsNumber++;
					slope = tmp;
				}
			}
		}
	}
}

void ComputeCharacter::InrcStroketCount()
{
	ofstream outfile;
	strokeCount++;
	if (strokeCount == 3)
	{
		outfile.open("data\\trainStroke3.txt", ios::app);
	}
	else
	{
		outfile.open("data\\trainStroke12.txt", ios::app);
	}
	outfile << tag << " ";
	outfile << strokeCount << " ";
	for (int i = 0;i < pointsNumber;++i)
	{
		outfile << points[i][0] << " " << points[i][1] << " ";
	}
	outfile << endl;
}