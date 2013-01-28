#include "connector.h"

#define TBL_SIZE 1024
#define TBL_RANGE_CHECK(X) ( ((X) >= 0 && (X) < TBL_SIZE-1) ? X : 0 )
#define TBL_FULL_ERROR -1

void *tbl[TBL_SIZE];

/* utility function to grab the next free slot in the pointer table */
int tbl_next_id() {
    int id;
    for(id=1;id<TBL_SIZE;id++) {
        if(tbl[id] == NULL) {
            return id;
        }
    }
    return TBL_FULL_ERROR;
}

void *tbl_get(int id) {
    return tbl[TBL_RANGE_CHECK(id)];
}

int tbl_store(void *ptr) {
    int id;
    id = tbl_next_id();
    if(id != TBL_FULL_ERROR) {
        tbl[id] = ptr;
    }
    return id;
}

void *tbl_clear(int id) {
    void *ref = NULL;
	if(tbl[TBL_RANGE_CHECK(id)] != NULL) {
		ref = tbl_get(id);
		tbl[TBL_RANGE_CHECK(id)] = NULL;
    }
	return(ref);
}

void tbl_init() {
    int i;
    for(i=0;i<TBL_SIZE;i++) {
        tbl[i] = NULL;
    }
}

int main(int argc, char* argv[]) {
    tbl_init();
	return MLMain(argc, argv);
}
