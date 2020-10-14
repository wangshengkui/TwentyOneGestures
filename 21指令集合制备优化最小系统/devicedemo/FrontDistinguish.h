#pragma once
#include<vector>
#include "stdafx.h"

using namespace std;

int InflectionPointsNumber(const vector<PEN_INFO> &source);

//�ж��Ƿ���-1
bool JudgeOne(const int strokeCount, const vector<PEN_INFO> &source);

//�ж��Ƿ���-2
bool JudgeTwo(const int strokeCount, const vector<PEN_INFO> &source);

//�ж��Ƿ���-3
bool JudgeThree(const int strokeCount, const vector<PEN_INFO> &source);

//�ж��Ƿ���-4
bool JudgeFour(const int strokeCount, const vector<PEN_INFO> &firstStroke, const vector<PEN_INFO> &secondStroke);

//�ж��Ƿ���-5
bool JudgeFive(const int strokeCount, const vector<PEN_INFO> &firstStroke, const vector<PEN_INFO> &secondStroke);

//�ж��Ƿ���-6
bool JudgeSix(const int strokeCount, const vector<PEN_INFO> &source);

//�ж��Ƿ���-7
bool JudgeSeven(const int strokeCount, const vector<PEN_INFO> &source);

//�ж��Ƿ���-8
bool JudgeEight(const int strokeCount, const vector<PEN_INFO> &source);

//�ж��Ƿ���-9
bool JudgeNine(const int strokeCount, const vector<PEN_INFO> &source);

//�ж��Ƿ���-10
bool JudgeTen(const int strokeCount, const vector<PEN_INFO> &firstStroke, const vector<PEN_INFO> &secondStroke);

//ʶ��
int Disting(const int strokeCount, const vector<PEN_INFO> &firstStroke, const vector<PEN_INFO> &secondStroke);