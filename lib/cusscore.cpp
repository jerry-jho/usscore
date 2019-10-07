#include "cusscore.h"
#include "qusscore.h"

cuss_handle cuss_create() {
    QUssCore * core = new QUssCore;
    return static_cast<cuss_handle>(core);
}

int cuss_connect_to_host(cuss_handle t,char * host,int port) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->connectToHost(host,port);
}

int cuss_generic_operation(cuss_handle t,int id, int w, uint32_t addr, uint32_t *data) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->genericOperation(id,w,addr,data);
}

int cuss_disconnect(cuss_handle t) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->disconnect();
}

uint32_t cuss_generic_read(cuss_handle t,int id, uint32_t addr) {
    uint32_t d;
    QUssCore * core = static_cast<QUssCore *>(t);
    core->genericRead(id,addr,&d);
    return d;
}

uint32_t cuss_reg_read(cuss_handle t,uint32_t addr) {
    uint32_t d;
    QUssCore * core = static_cast<QUssCore *>(t);
    core->regRead(addr,&d);
    return d;    
}

uint32_t cuss_inst_read(cuss_handle t,uint32_t addr) {
    uint32_t d;
    QUssCore * core = static_cast<QUssCore *>(t);
    core->instRead(addr,&d);
    return d;     
}

uint32_t cuss_data_read(cuss_handle t,uint32_t addr) {
    uint32_t d;
    QUssCore * core = static_cast<QUssCore *>(t);
    core->dataRead(addr,&d);
    return d;    
}

uint32_t cuss_io_read(cuss_handle t,uint32_t addr) {
    uint32_t d;
    QUssCore * core = static_cast<QUssCore *>(t);
    core->ioRead(addr,&d);
    return d;    
}

uint32_t cuss_tap_read(cuss_handle t,uint32_t addr) {
    uint32_t d;
    QUssCore * core = static_cast<QUssCore *>(t);
    core->tapRead(addr,&d);
    return d;  
}

int cuss_generic_write(cuss_handle t,int id, uint32_t addr, uint32_t data) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->genericWrite(id,addr,data);    
}

int cuss_reg_write(cuss_handle t,uint32_t addr, uint32_t data) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->regWrite(addr,data);   
}

int cuss_inst_write(cuss_handle t,uint32_t addr, uint32_t data) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->instWrite(addr,data);    
}

int cuss_data_write(cuss_handle t,uint32_t addr, uint32_t data) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->dataWrite(addr,data);    
}

int cuss_io_write(cuss_handle t,uint32_t addr, uint32_t data) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->ioWrite(addr,data);    
}

int cuss_tap_write(cuss_handle t,uint32_t addr, uint32_t data) {
    QUssCore * core = static_cast<QUssCore *>(t);
    return core->tapWrite(addr,data);     
}

void cuss_destroy(cuss_handle t) {
    QUssCore * core = static_cast<QUssCore *>(t);
    delete core;
}
