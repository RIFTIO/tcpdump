/*
 * Copyright 2016 RIFT.IO Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TCP_EXPORT_H__
#define __TCP_EXPORT_H__
#include <pthread.h>

pthread_key_t log_print_key;
#define MAX_PDU_SIZE 4096

typedef struct {
  char tcpdump_out_buf[MAX_PDU_SIZE];
  int write_count;
  int verbosity;
} rwtcpdump_state_t;

#ifdef TCPDUMP_BUF
#define printf rwtcpdump_printf_override
#define vflag (rwtcpdump_get_vflag())
#endif

extern int rwtcpdump_printf_override(const char *__restrict __format,...);
extern int rwtcpdump_get_vflag();
extern void rwtcpdump_decr_vflag(int dec_verbosity);
extern void rwtcpdump_incr_vflag(int inc_verbosity);
#endif
