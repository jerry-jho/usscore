#include <cusscore.h>

int main(int argc,char ** argv) {
    cuss_handle h = cuss_create();
    cuss_connect_to_host(h,"127.0.0.1",9000);
    cuss_data_write(h,0x00040000,0x12345678);
    cuss_disconnect(h);
    return 0;
}