#pragma once
#include <windows.h>
#include <iostream>

class Stream {
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

//主体类
class FileStream:public Stream {
public:
	virtual char Read(int number) {
		//读文件流
	}
	virtual void Seek(int position) {
		//定位文件流
	}
	virtual void Write(char data) {
		//写文件流
	}

};

class NetworkStream:public Stream {
	Stream* stream;
public:
	virtual char Read(int number) {
		//读网络流
	}
	virtual void Seek(int position) {
		//定位网络流
	}
	virtual void Write(char data) {
		//写网络流
	}

};

//扩展操作
class CryptoFileStream:public Stream {
	Stream* stream;
public:
	virtual char Read(int number) {

		//额外的加密操作...
		FileStream::Read(number);//读文件流

	}
	virtual void Seek(int position) {
		//额外的加密操作...
		FileStream::Seek(position);//定位文件流
		//额外的加密操作...
	}
	virtual void Write(bytex data) {
		//额外的加密操作...
		FileStream::Write(data);//写文件流
		//额外的加密操作...
	}
};

class CryptoNetworkStream:public Stream {
public:
	virtual char Read(int number) {

		//额外的加密操作...
		NetworkStream::Read(number);//读网络流
	}
	virtual void Seek(int position) {
		//额外的加密操作...
		NetworkStream::Seek(position);//定位网络流
		//额外的加密操作...
	}
	virtual void Write(byte data) {
		//额外的加密操作...
		NetworkStream::Write(data);//写网络流
		//额外的加密操作...
	}
};


void Process() {

	//编译时装配
	CryptoFileStream *fs1 = new CryptoFileStream();

}