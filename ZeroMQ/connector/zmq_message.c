#include "connector.h"

/* This file should encapsulate the msg api in some way that makes sense in mathematica */

int zmq_send_c(int socket_id, char *data, int option) {
	zmq_msg_t *msg;
	size_t length;
	char *blob;
	int flags;

	/* this is an obviously dangerous thing to do */
	length = strlen(data);
	malloc(blob, length*sizeof(char));
	memcpy(blob, data, length);

	zmq_msg_init_data(msg, blob, length, &free, NULL);

	switch(option) {
	case 1:
		flags = ZMQ_NOBLOCK; break;
	case 2:
		flags = ZMQ_SNDMORE; break;
	case 3:
		flags = ZMQ_NOBLOCK | ZMQ_SNDMORE; break;
	default:
		flags = 0;
	}

	return zmq_send(tbl_get(socket_id), msg, flags);
}

void zmq_recv_c(int socket_id, int options) {
	zmq_msg_t *msg;
	int flags = 0;
	int64_t more = 1;
	size_t *len;

	if(options == 1) flags = ZMQ_NOBLOCK;
	while(more == 1) {
		zmq_recv(tbl_bet(socket_id), msg, flags);
		MLPutByteString(stdlink, zmq_msg_data(msg), zmq_msg_size(msg));
		zmq_getsockopt(tbl_get(socket_id), ZMQ_RCVMORE, &more, len);
	}
}
