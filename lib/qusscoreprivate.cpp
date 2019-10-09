#include "qusscoreprivate.h"
#include <QtCore>

QUssCorePrivate::QUssCorePrivate(QUssCore *parent) : q_ptr(parent) {
	
}

QUssCorePrivate::~QUssCorePrivate() {
	
}

bool QUssCorePrivate::connectToHost(QString hostname, int port) {
	socket.connectToHost(hostname, port);
	if (!socket.waitForConnected()) return false;
	return true;
}

bool QUssCorePrivate::genericOperation(int id, int w, uint32_t addr, uint32_t *data) {
	unsigned char buf[9];
	buf[0] = id & 0x7;
	if (w == QUssCore::WRITE) {
		buf[0] |= 0x8;
	}
	buf[1] =  addr        & 0xFF;
	buf[2] = (addr >> 8)  & 0xFF;
	buf[3] = (addr >> 16) & 0xFF;
	buf[4] = (addr >> 24) & 0xFF;
	buf[5] = (*data) & 0xFF;
	buf[6] = ((*data) >> 8) & 0xFF;
	buf[7] = ((*data) >> 16) & 0xFF;
	buf[8] = ((*data) >> 24) & 0xFF;
	//for (int i = 0; i < sizeof(buf); i++) {
	//	printf("%02X ", buf[i]);
	//}
	//printf("\n");
	socket.write((char*)buf, sizeof(buf));
	if (!socket.waitForBytesWritten()) return false;
	if (!socket.waitForReadyRead(-1)) return false;
	socket.read((char *)data, 4);
	return true;
}

bool QUssCorePrivate::disconnect() {
	socket.disconnectFromHost();
	return true;
}