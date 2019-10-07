#ifndef QUSSCOREPRIVATE_H
#define QUSSCOREPRIVATE_H

#include "qusscore.h"
#include <QtNetwork>

class QUssCorePrivate {
public:
	explicit QUssCorePrivate(QUssCore *parent);
	~QUssCorePrivate();

public:
	bool connectToHost(QString hostname, int port);
	bool genericOperation(int id, int w, uint32_t addr, uint32_t *data);
	bool disconnect();

private:
	QUssCore * const q_ptr;
	Q_DECLARE_PUBLIC(QUssCore);

private:
	QTcpSocket socket;
};

#endif // QUSSCOREPRIVATE_H