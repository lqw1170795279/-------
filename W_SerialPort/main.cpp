#include <iostream>
#include "SerialPort_SDK.h"
#include "SerialPort_Setting.h"

using namespace std;

void send()
{
	SerialPort_Setting s;
	if (s.openPort("COM5", 115200, 0, 8, 1, 1)) {
		for (int i = 0; i < 10; ++i) {
			s.sendData("Hello ", 6);
		}
		cout << "send finished" << endl;
	}
	else {
		cout << "send failed" << endl;
	}
}

void receive()
{
	SerialPort_Setting s;
	if (s.openPort("COM5", 115200, 0, 8, 1, 1)) {
		char buf[1024];
		while (1) {
			memset(buf, 0, 1024);
			s.receiveData(buf, 1024);
			cout << buf;
		}
	}
}
int main(int argumentCount, const char* argumentValues[])

{
	char portName1[20] = { "COM5" };
	char portName2[20] = { "COM6" };

	Create_Port(portName1, portName2);

	send();
//	receive();
//	printf("1");
	while (1);
	return 0;
}