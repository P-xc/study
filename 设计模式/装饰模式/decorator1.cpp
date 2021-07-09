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

//������
class FileStream:public Stream {
public:
	virtual char Read(int number) {
		//���ļ���
	}
	virtual void Seek(int position) {
		//��λ�ļ���
	}
	virtual void Write(char data) {
		//д�ļ���
	}

};

class NetworkStream:public Stream {
	Stream* stream;
public:
	virtual char Read(int number) {
		//��������
	}
	virtual void Seek(int position) {
		//��λ������
	}
	virtual void Write(char data) {
		//д������
	}

};

//��չ����
class CryptoFileStream:public Stream {
	Stream* stream;
public:
	virtual char Read(int number) {

		//����ļ��ܲ���...
		FileStream::Read(number);//���ļ���

	}
	virtual void Seek(int position) {
		//����ļ��ܲ���...
		FileStream::Seek(position);//��λ�ļ���
		//����ļ��ܲ���...
	}
	virtual void Write(bytex data) {
		//����ļ��ܲ���...
		FileStream::Write(data);//д�ļ���
		//����ļ��ܲ���...
	}
};

class CryptoNetworkStream:public Stream {
public:
	virtual char Read(int number) {

		//����ļ��ܲ���...
		NetworkStream::Read(number);//��������
	}
	virtual void Seek(int position) {
		//����ļ��ܲ���...
		NetworkStream::Seek(position);//��λ������
		//����ļ��ܲ���...
	}
	virtual void Write(byte data) {
		//����ļ��ܲ���...
		NetworkStream::Write(data);//д������
		//����ļ��ܲ���...
	}
};


void Process() {

	//����ʱװ��
	CryptoFileStream *fs1 = new CryptoFileStream();

}