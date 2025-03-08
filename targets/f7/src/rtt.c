#include <furi.h>
#include "Segger_RTT/SEGGER_RTT.h"
void segger_rtt_log_callback(const uint8_t* data, size_t size, void* context) {
    UNUSED(context);
    SEGGER_RTT_Write(0, data, size);
}
void segger_rtt_init() {
    FuriLogHandler handler = {
        .callback = segger_rtt_log_callback,
        .context = NULL,
    };
    furi_log_add_handler(handler);
}
