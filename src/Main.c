#include <wups.h>
#include <coreinit/title.h>
#include <nsysnet/socket.h>
#include <utils/logger.h>

#define TID_JAP (0x0005001010040000)
#define TID_USA (0x0005001010040100)
#define TID_EUR (0x0005001010040200)

WUPS_PLUGIN_NAME("DarkU");
WUPS_PLUGIN_DESCRIPTION("This plugin allows you to change the background color of your WiiU");
WUPS_PLUGIN_VERSION("1.0");
WUPS_PLUGIN_AUTHOR("VCoding");
WUPS_PLUGIN_LICENSE("Apache2.0");

WUPS_ALLOW_KERNEL()

ON_APPLICATION_START(args) {

    uint64_t titleID = OSGetTitleID();
    int *address    = (int * ) 0x105DD0A8;
    int *addresstwo = (int * ) 0x105DD2A8;

    socket_lib_init();
    log_init();

    if(!args.kernel_access){
        return;
    }

    if(titleID == TID_JAP || titleID == TID_USA || titleID == TID_EUR) {
    	WUPS_KernelWrite(address, 0x3D800000);
    	WUPS_KernelWrite(addresstwo, 0x3D800000);
    }
}