#ifndef _ZMQ_CONNECTOR_H
#define _ZMQ_CONNECTOR_H

#include "mathlink.h"
#include <zmq.h>

#include <stdlib.h>

void tbl_init();
int tbl_next_id();
void *tbl_get(int id);
int tbl_store(void *ptr);
int tbl_store(void *ptr);
void *tbl_clear(int id);

#endif
