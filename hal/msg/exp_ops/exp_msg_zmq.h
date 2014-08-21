/*
 * Copyright (C) 2014 LNLS (www.lnls.br)
 * Author: Lucas Russo <lucas.russo@lnls.br>
 *
 * Released according to the GNU LGPL, version 3 or any later version.
 */

#ifndef _EXP_MSG_ZMQ_H_
#define _EXP_MSG_ZMQ_H_

#include <czmq.h>

/* Same TAG as defined in https://github.com/zeromq/czmq/blob/master/src/zmsg.c */
#define EXP_MSG_ZMQ_TAG                             0x0003cafe

struct _exp_msg_zmq_t {
    /* This allows us to do a runtime typing and validation. Idea from
     * CZMQ 3.0.0 available at https://github.com/zeromq/czmq/blob/master/src/zmsg.c */
    uint32_t tag;
    zmsg_t **msg;
    zframe_t *reply_to;
};

typedef struct _exp_msg_zmq_t exp_msg_zmq_t;

/* ZMQ exported function arguments macros */
#define __EXP_MSG_ZMQ_ARGS_2_MSG(args)              ((exp_msg_zmq_t *) args)
#define EXP_MSG_ZMQ(args)                           (*__EXP_MSG_ZMQ_ARGS_2_MSG(args)->msg)
#define EXP_MSG_ZMQ_POP_NEXT_ARG(args)              zmsg_pop (EXP_MSG_ZMQ(args))
#define EXP_MSG_ZMQ_PEEK_NEXT_ARG(args)             zmsg_next (EXP_MSG_ZMQ(args))
#define EXP_MSG_ZMQ_PEEK_FIRST(args)                zmsg_first (EXP_MSG_ZMQ(args))
#define EXP_MSG_ZMQ_PEEK_RESTART(args)              EXP_MSG_ZMQ_PEEK_FIRST(args)
#define EXP_MSG_ZMQ_PEEK_EXIT(args)                 EXP_MSG_ZMQ_PEEK_FIRST(args)

#define EXP_MSG_ZMQ_ARG_TYPE                        zframe_t *

#define EXP_MSG_ZMQ_ARG_SIZE(frame)                 zframe_size (frame)
#define EXP_MSG_ZMQ_ARG_DATA(frame)                 zframe_data (frame)

/* For use in SMIOs exported functions */
#define EXP_MSG_ZMQ_FIRST_ARG(args)                 zframe_data (EXP_MSG_ZMQ_PEEK_FIRST(args))
#define EXP_MSG_ZMQ_NEXT_ARG(args)                  zframe_data (EXP_MSG_ZMQ_PEEK_NEXT_ARG(args))

/* Try to guess if the message is of exp_msg_zmq type */
bool exp_msg_zmq_is (void *self);

#endif
