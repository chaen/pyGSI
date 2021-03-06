
/*
 * connection.h
 *
 * Copyright (C) AB Strakt 2001, All rights reserved
 *
 * Export SSL Connection data structures and functions.
 * See the file RATIONALE for a short explanation of why this module was written.
 *
 * Reviewed 2001-07-23
 *
 * @(#) $Id: connection.h,v 1.5 2008/07/08 10:54:55 acasajus Exp $
 */
#ifndef PyGSI_SSL_CONNECTION_H_
#define PyGSI_SSL_CONNECTION_H_

#include <Python.h>
#include <openssl/ssl.h>

/* shamelessly stolen from socketmodule.c */
#ifdef MS_WINDOWS
#  include <winsock.h>
typedef SOCKET SOCKET_T;

#  ifdef MS_WIN64
#    define SIZEOF_SOCKET_T 8
#  else
#    define SIZEOF_SOCKET_T 4
#  endif
#else
typedef int SOCKET_T;

#  define SIZEOF_SOCKET_T SIZEOF_INT
#endif


extern int init_ssl_connection( PyObject * );

extern PyTypeObject ssl_Connection_Type;

#define ssl_Connection_Check(v) ((v)->ob_type == &ssl_Connection_Type)

typedef struct
{
    PyObject_HEAD SSL *ssl;
    ssl_ContextObj *context;
    unsigned char remoteCertVerified;
    int handshakeErrorId;
    PyObject *socket;
    PyThreadState *tstate;
    PyObject *app_data;
} ssl_ConnectionObj;


#endif
