// xml解析.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include <windows.h>
#include <regex>
#include "tinyxml.h"
using namespace std;

void test1() {
	HANDLE hfile = CreateFileA("D:\\persons.xml", GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	DWORD dwSize;
	DWORD dwRead;
	dwSize = GetFileSize(hfile, 0);
	char* buf = new char[dwSize + 1];
	memset(buf, 0, dwSize + 1);
	ReadFile(hfile, buf, dwSize, &dwRead, 0);
	char* lpStart, *lpEnd;
	lpStart = buf;
	lpEnd = buf + dwSize;
	for (; lpStart < lpEnd; lpStart++) {
		if (memcmp(lpStart, "<name>", 6) == 0) {
			lpStart += 6;
			break;
		}
	}

	char* lpStart2 = lpStart;
	for (; lpStart2 < lpEnd; lpStart2++) {
		if (memcmp(lpStart2, "</name>", 7) == 0) {
			*lpStart2 = 0;
			break;
		}
	}
	printf("%s", lpStart);
	delete[] buf;
	return;
}

void test2() {
	HANDLE hfile = CreateFileA("D:\\persons.xml", GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	DWORD dwSize;
	DWORD dwRead;
	dwSize = GetFileSize(hfile, 0);
	char* buf = new char[dwSize + 1];
	memset(buf, 0, dwSize + 1);
	ReadFile(hfile, buf, dwSize, &dwRead, 0);

	regex_constants::syntax_option_type f1 = regex_constants::icase;
	regex pattern("<name>.*</name>", f1);
	string sBuf = buf;
	/*tr1::sregex_token_iterator ite(sBuf.begin(), sBuf.end(), pattern), end;
	for (; ite != end; ++ite) {
		cout << ite->str().c_str() << endl;
	}*/
}

void test3() {
	TiXmlDocument doc("D:\\persons.xml");
	bool loadResult = doc.LoadFile();
	if (!loadResult) {
		printf("load xml file error\n"); return;
	}
	TiXmlElement* root = doc.RootElement();
	for (TiXmlNode* item = root->FirstChild("Person"); item; item = item->NextSibling("Person")) {
		TiXmlNode* child = item->FirstChild();
		const char* name = child->ToElement()->GetText();
		printf("name - %s", name);
		
		child = child->NextSiblingElement();
		const char* age = child->ToElement()->GetText();
		printf("\t\t age: [%s]\n", age);
		printf("--------------\n\n");
	}
	return;
}

int main()
{
	test3();
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
