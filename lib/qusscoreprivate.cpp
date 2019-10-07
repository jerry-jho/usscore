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
	char buf[9];
	buf[0] = id & 0x7;
	if (w == QUssCore::WRITE) {
		buf[0] |= 0x8;
	}
	memcpy(buf + 1, &addr, 4);
	memcpy(buf + 5, data, 4);
	socket.write(buf, sizeof(buf));
	if (!socket.waitForBytesWritten()) return false;
	return true;
}

bool QUssCorePrivate::disconnect() {
	socket.disconnectFromHost();
	return true;
}