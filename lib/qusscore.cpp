#include "qusscore.h"
#include "qusscoreprivate.h"

QUssCore::QUssCore(QObject *parent)
	: QObject(parent)
	, d_ptr(new QUssCorePrivate(this)) {

}


QUssCore::~QUssCore() {
	Q_D(QUssCore);
	delete d;
}

bool QUssCore::connectToHost(QString hostname, int port) {
	Q_D(QUssCore);
	return d->connectToHost(hostname,port);
}

bool QUssCore::genericOperation(int id, int w, uint32_t addr, uint32_t *data) {
	Q_D(QUssCore);
	return d->genericOperation(id, w, addr, data);
}

bool QUssCore::disconnect() {
	Q_D(QUssCore);
	return d->disconnect();
}

