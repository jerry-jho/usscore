#ifndef CUSSCORE_H
#define CUSSCORE_H

#ifdef __MINGW32__
#define OS_WIN
#endif

#ifdef _MSC_VER
#define OS_WIN
#endif

#ifdef OS_WIN
#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#else
#define EXPORT
#endif

#include <stdint.h>

typedef void * cuss_handle;


#ifdef __cplusplus
extern "C"{
#endif
    EXPORT cuss_handle cuss_create();
    EXPORT int cuss_connect_to_host(cuss_handle t,char * host,int port);
	EXPORT int cuss_generic_operation(cuss_handle t,int id, int w, uint32_t addr, uint32_t *data);
	EXPORT int cuss_disconnect(cuss_handle t);
	EXPORT uint32_t cuss_generic_read(cuss_handle t,int id, uint32_t addr);
	EXPORT uint32_t cuss_reg_read(cuss_handle t,uint32_t addr);
	EXPORT uint32_t cuss_inst_read(cuss_handle t,uint32_t addr);
	EXPORT uint32_t cuss_data_read(cuss_handle t,uint32_t addr);
	EXPORT uint32_t cuss_io_read(cuss_handle t,uint32_t addr);
	EXPORT uint32_t cuss_tap_read(cuss_handle t,uint32_t addr);
	EXPORT int cuss_generic_write(cuss_handle t,int id, uint32_t addr, uint32_t data);
	EXPORT int cuss_reg_write(cuss_handle t,uint32_t addr, uint32_t data);
	EXPORT int cuss_inst_write(cuss_handle t,uint32_t addr, uint32_t data) ;
	EXPORT int cuss_data_write(cuss_handle t,uint32_t addr, uint32_t data);
	EXPORT int cuss_io_write(cuss_handle t,uint32_t addr, uint32_t data);
	EXPORT int cuss_tap_write(cuss_handle t,uint32_t addr, uint32_t data);
    EXPORT void cuss_destroy(cuss_handle t);
#ifdef __cplusplus
}
#endif

#endif