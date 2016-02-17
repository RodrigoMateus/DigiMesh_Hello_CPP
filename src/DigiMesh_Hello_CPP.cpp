//============================================================================
// Name        : DigiMesh_Hello_CPP.cpp
// Author      : 
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"

using namespace std;

int main() {
	int i = 0,
		cport_nr = 3, /* ver tabela em http://www.teuniz.net/RS-232 */
		bdrate = 115200;

	char mode[] = { '8', 'N', '1', 0 }, str[2][512];

	if (RS232_OpenComport(cport_nr, bdrate, mode)) {
		printf("Can not open comport\n");

		return (0);
	}

	// Send MESSAGE_INIT
	// 7E 00 15 11 01 00 00 00 00 00 00 FF FF FF FF 0B 17 00 00 00 01 00 00 35 99
	//
	// Start Delimiter
	RS232_SendByte(cport_nr, 0x7E);
	// Length
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x15);
	// Frame type
	RS232_SendByte(cport_nr, 0x11);
	// FrameID
	RS232_SendByte(cport_nr, 0x01);
	// 64-bit Destination Address
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0xFF);
	RS232_SendByte(cport_nr, 0xFF);
	// 16-bit Destination Address
	RS232_SendByte(cport_nr, 0xFF);
	RS232_SendByte(cport_nr, 0xFF);
	// Source Endpoint
	RS232_SendByte(cport_nr, 0x0B);
	// Destination Endpoint
	RS232_SendByte(cport_nr, 0x17);
	// Cluster ID
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	// Profile ID
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x01);
	// Broadcast radius (num hops)
	RS232_SendByte(cport_nr, 0x00);
	// Option
	RS232_SendByte(cport_nr, 0x00);
	// Payload
	RS232_SendByte(cport_nr, 0x35);
	// Ckecksum
	RS232_SendByte(cport_nr, 0x99);

	// Send MESSAGE_DATA Hello
	// 7E 00 19 11 02 00 00 00 00 00 00 FF FF FF FF 0C 17 00 00 00 05 00 00 48 65 6C 6C 6F D4
	//
	// Start Delimiter
	RS232_SendByte(cport_nr, 0x7E);
	// Length
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x19);
	// Frame type
	RS232_SendByte(cport_nr, 0x11);
	// FrameID
	RS232_SendByte(cport_nr, 0x02);
	// 64-bit Destination Address
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0xFF);
	RS232_SendByte(cport_nr, 0xFF);
	// 16-bit Destination Address
	RS232_SendByte(cport_nr, 0xFF);
	RS232_SendByte(cport_nr, 0xFF);
	// Source Endpoint
	RS232_SendByte(cport_nr, 0x0C);
	// Destination Endpoint
	RS232_SendByte(cport_nr, 0x17);
	// Cluster ID
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	// Profile ID
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x05);
	// Broadcast radius (num hops)
	RS232_SendByte(cport_nr, 0x00);
	// Option
	RS232_SendByte(cport_nr, 0x00);
	// Payload
	RS232_SendByte(cport_nr, 0x48);
	RS232_SendByte(cport_nr, 0x65);
	RS232_SendByte(cport_nr, 0x6C);
	RS232_SendByte(cport_nr, 0x6C);
	RS232_SendByte(cport_nr, 0x6F);
	// Ckecksum
	RS232_SendByte(cport_nr, 0xD4);

	// Send MESSAGE_END
	// 7E 00 15 11 03 00 00 00 00 00 00 FF FF FF FF 0D 17 00 01 00 00 00 00 35 95
	//
	// Start Delimiter
	RS232_SendByte(cport_nr, 0x7E);
	// Length
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x15);
	// Frame type
	RS232_SendByte(cport_nr, 0x11);
	// FrameID
	RS232_SendByte(cport_nr, 0x03);
	// 64-bit Destination Address
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0xFF);
	RS232_SendByte(cport_nr, 0xFF);
	// 16-bit Destination Address
	RS232_SendByte(cport_nr, 0xFF);
	RS232_SendByte(cport_nr, 0xFF);
	// Source Endpoint
	RS232_SendByte(cport_nr, 0x0D);
	// Destination Endpoint
	RS232_SendByte(cport_nr, 0x17);
	// Cluster ID
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x01);
	// Profile ID
	RS232_SendByte(cport_nr, 0x00);
	RS232_SendByte(cport_nr, 0x00);
	// Broadcast radius (num hops)
	RS232_SendByte(cport_nr, 0x00);
	// Option
	RS232_SendByte(cport_nr, 0x00);
	// Payload
	RS232_SendByte(cport_nr, 0x35);
	// Ckecksum
	RS232_SendByte(cport_nr, 0x95);

	return (0);
}
