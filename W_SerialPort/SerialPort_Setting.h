#pragma once
class SerialPort_Setting
{
public:
	SerialPort_Setting();
	~SerialPort_Setting();

	// �򿪴���,�ɹ�����true��ʧ�ܷ���false
	// portname(������): ��Windows����"COM1""COM2"�ȣ���Linux����"/dev/ttyS1"��
	// baudrate(������): 9600��19200��38400��43000��56000��57600��115200 
	// parity(У��λ): 0Ϊ��У�飬1Ϊ��У�飬2ΪżУ�飬3Ϊ���У�飨��������windows)
	// databit(����λ): 4-8(windows),5-8(linux)��ͨ��Ϊ8λ
	// stopbit(ֹͣλ): 1Ϊ1λֹͣλ��2Ϊ2λֹͣλ,3Ϊ1.5λֹͣλ
	// synchronizeflag(ͬ�����첽,��������windows): 0Ϊ�첽��1Ϊͬ��

	bool openPort(const char* portname, int baudrate, char parity,
		char databit, char stopbit, char synchronizeflag);
	void closePort();

	int sendData(const void* buf, int len);

	int receiveData(void* buf, int maxlen);

private:
	int pHandle[16];
	char synchronizeflag;
};