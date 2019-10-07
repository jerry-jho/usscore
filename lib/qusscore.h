#ifndef QUSSCORE_H
#define QUSSCORE_H

#include <QObject>
#include <stdint.h>

class QUssCorePrivate;

class QUssCore : public QObject
{
	Q_OBJECT
public:
	explicit QUssCore(QObject *parent = nullptr);
	~QUssCore();
	enum enum_rw {
		WRITE = 0,
		READ  = 1
	};
	enum enum_id {
		REG  = 0,
		INST = 1,
		DATA = 2,
		IO   = 3,
		TAP  = 7
	};

public:
	bool connectToHost(QString hostname, int port);
	bool genericOperation(int id, int w, uint32_t addr, uint32_t *data);
	bool disconnect();
	
	bool genericRead(int id, uint32_t addr, uint32_t *data) {
		return genericOperation(id, QUssCore::READ, addr, data);
	}
	bool regRead(uint32_t addr, uint32_t *data) {
		return genericRead(QUssCore::REG, addr, data);
	}
	bool instRead(uint32_t addr, uint32_t *data) {
		return genericRead(QUssCore::INST, addr, data);
	}
	bool dataRead(uint32_t addr, uint32_t *data) {
		return genericRead(QUssCore::DATA, addr, data);
	}
	bool ioRead(uint32_t addr, uint32_t *data) {
		return genericRead(QUssCore::IO, addr, data);
	}
	bool tapRead(uint32_t addr, uint32_t *data) {
		return genericRead(QUssCore::TAP, addr, data);
	}
	bool genericWrite(int id, uint32_t addr, uint32_t *data) {
		return genericOperation(id, QUssCore::WRITE, addr, data);
	}
	bool regWrite(uint32_t addr, uint32_t *data) {
		return genericWrite(QUssCore::REG, addr, data);
	}
	bool instWrite(uint32_t addr, uint32_t *data) {
		return genericWrite(QUssCore::INST, addr, data);
	}
	bool dataWrite(uint32_t addr, uint32_t *data) {
		return genericWrite(QUssCore::DATA, addr, data);
	}
	bool ioWrite(uint32_t addr, uint32_t *data) {
		return genericWrite(QUssCore::IO, addr, data);
	}
	bool tapWrite(uint32_t addr, uint32_t *data) {
		return genericWrite(QUssCore::TAP, addr, data);
	}
	bool genericWrite(int id, uint32_t addr, uint32_t data) {
		return genericOperation(id, QUssCore::WRITE, addr, &data);
	}
	bool regWrite(uint32_t addr, uint32_t data) {
		return genericWrite(QUssCore::REG, addr, data);
	}
	bool instWrite(uint32_t addr, uint32_t data) {
		return genericWrite(QUssCore::INST, addr, data);
	}
	bool dataWrite(uint32_t addr, uint32_t data) {
		return genericWrite(QUssCore::DATA, addr, data);
	}
	bool ioWrite(uint32_t addr, uint32_t data) {
		return genericWrite(QUssCore::IO, addr, data);
	}
	bool tapWrite(uint32_t addr, uint32_t data) {
		return genericWrite(QUssCore::TAP, addr, data);
	}
private:
	QUssCorePrivate * const d_ptr;
	Q_DECLARE_PRIVATE(QUssCore);
};

#endif // QUSSCORE_H