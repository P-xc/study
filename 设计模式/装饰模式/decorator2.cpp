//ҵ�����
class Stream {

public:
		virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

//������
class FileStream : public Stream {
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

class NetworkStream :public Stream {
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

class MemoryStream :public Stream {
public:
	virtual char Read(int number) {
		//���ڴ���
	}
	virtual void Seek(int position) {
		//��λ�ڴ���
	}
	virtual void Write(char data) {
		//д�ڴ���
	}

};

//��չ����


class CryptoStream : public Stream {

	Stream* stream;//...

public:
	CryptoStream(Stream* stm) :stream(stm) {

	}


	virtual char Read(int number) {

		//����ļ��ܲ���...
		stream->Read(number);//���ļ���
	}
	virtual void Seek(int position) {
		//����ļ��ܲ���...
		stream::Seek(position);//��λ�ļ���
		//����ļ��ܲ���...
	}
	virtual void Write(char data) {
		//����ļ��ܲ���...
		stream::Write(data);//д�ļ���
		//����ļ��ܲ���...
	}
};



class BufferedStream : public Stream {

	Stream* stream;//...

public:
	BufferedStream(Stream* stm) :stream(stm) {

	}
	//...
	virtual char Read(int number) {

		//����ļ��ܲ���...
		stream->Read(number);//���ļ���
	}
	virtual void Seek(int position) {
		//����ļ��ܲ���...
		stream::Seek(position);//��λ�ļ���
		//����ļ��ܲ���...
	}
	virtual void Write(char data) {
		//����ļ��ܲ���...
		stream::Write(data);//д�ļ���
		//����ļ��ܲ���...
	}
};





void Process() {

	//����ʱװ��
	FileStream* s1 = new FileStream();
	CryptoStream* s2 = new CryptoStream(s1);

	BufferedStream* s3 = new BufferedStream(s1);

	BufferedStream* s4 = new BufferedStream(s2);



}