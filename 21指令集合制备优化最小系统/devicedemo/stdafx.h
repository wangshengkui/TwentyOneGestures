// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <iostream>
#include <string>


#ifdef _WIN64
#include "x64/inc/RobotUsbWrapper.h"#pragma comment(lib, "x64/lib/RobotUsbWrapper.lib")
#else
#include "inc/RobotUsbWrapper.h"
#pragma comment(lib, "lib/RobotUsbWrapper.lib")
#endif


// ���SDKͷ�ļ�
//#include "RobotUsbWrapper.h"

// ���SDK����
//#ifndef _AMD64_
//#pragma comment(lib, "lib/RobotUsbWrapper.lib")
//#else
//#pragma comment(lib, "x64_lib/RobotUsbWrapper.lib")
//#endif
