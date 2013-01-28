#include "connector.h"

/* too complex for this file
 
 zmq_getsockopt
 zmq_setsockopt
 zmq_msg*
 zmq_poll
 
 
 no intermediary
 zmq_strerror
 
 */


int zmq_bind_c(int socket_id, const char *endpoint) {
    return zmq_bind(tbl_get(socket_id), endpoint);
}

int zmq_close_c(int socket_id) {
    return zmq_close(tbl_clear(socket_id));
}

int zmq_connect_c(int socket_id, const char *endpoint) {
    return zmq_connect(tbl_get(socket_id), endpoint);
}

int zmq_device_c(int device_id, int fsocket_id, int bsocket_id) {
    int device;
    
    /* so I have control of my own constants */
    switch(device_id) {
        case 0:
            device = ZMQ_QUEUE; break;
        case 1:
            device = ZMQ_FORWARDER; break;
        case 2:
            device = ZMQ_STREAMER; break;
    }
    
    return zmq_device(device, tbl_get(fsocket_id), tbl_get(bsocket_id));
}

int zmq_init_c(int io_threads) {
    return tbl_store(zmq_init(io_threads));
}

int zmq_socket_c(int context_id, int type_id) {
    int type;
    switch(type_id) {
        case 0:
            type = ZMQ_REQ; break;
        case 1:
            type = ZMQ_REP; break;
        case 2:
            type = ZMQ_DEALER; break;
        case 3:
            type = ZMQ_ROUTER; break;
        case 4:
            type = ZMQ_PUB; break;
        case 5:
            type = ZMQ_SUB; break;
        case 6:
            type = ZMQ_PUSH; break;
        case 7:
            type = ZMQ_PULL; break;
        case 8:
            type = ZMQ_PAIR; break;
    }
    return tbl_store(zmq_socket(tbl_get(context_id), type));
}

int zmq_term_c(int context_id) {
    return zmq_term(tbl_clear(context_id));
}

void zmq_version_c() {
    int version[3];
    zmq_version(&version[0], &version[1], &version[2]);
    MLPutIntegerList(stdlink, version, 3);
}
