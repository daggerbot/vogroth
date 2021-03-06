/*
 * Copyright (c) 2021 Marty Mills <daggerbot@gmail.com>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_MEMORY_H
#define INCLUDED_MEMORY_H

#include "types.h"

/* Expandable memory buffer. */
struct buf {
    char *data;
    size_t alloc_size;
    size_t len;
};
#define BUF_INIT {0}
#define BUF_NULL ((struct buf)BUF_INIT)

void *mem_alloc(size_t size);
void *mem_alloc_array(size_t n, size_t size);
void *mem_realloc(void *mem, size_t size);
void *mem_realloc_array(void *mem, size_t n, size_t size);
void *mem_free(void *mem);

void buf_alloc(struct buf *buf, size_t size);
void buf_fini(struct buf *buf);
/* Ensure a terminating null byte (does not contribute to len) */
void buf_terminate(struct buf *buf);
void buf_append(struct buf *buf, size_t size, const void *data);
void buf_appends(struct buf *buf, const char *src);
void buf_appendf(struct buf *buf, const char *fmt, ...) PRINTFLIKE(2, 3);
void buf_vappendf(struct buf *buf, const char *fmt, va_list args) PRINTFLIKE(2, 0);

/*
 * Convenient string functions. The caller doesn't have to know the size of the
 * allocation, as it is reallocated with each operation. This makes these
 * functions easy to use but theoretically slow.
 */
char *str_clone(const char *src);
char *str_printf(const char *fmt, ...) PRINTFLIKE(1, 2);
char *str_vprintf(const char *fmt, va_list args) PRINTFLIKE(1, 0);
char *str_append(char *str, const char *src);
char *str_appendf(char *str, const char *fmt, ...) PRINTFLIKE(2, 3);
char *str_vappendf(char *str, const char *fmt, va_list args) PRINTFLIKE(2, 0);
char *str_assign(char *str, const char *src);
char *str_assignf(char *str, const char *fmt, ...) PRINTFLIKE(2, 3);
char *str_vassignf(char *str, const char *fmt, va_list args) PRINTFLIKE(2, 0);
void str_put(char **out_str, const char *src);
void str_putf(char **out_str, const char *fmt, ...) PRINTFLIKE(2, 3);
void str_vputf(char **out_str, const char *fmt, va_list args) PRINTFLIKE(2, 0);

#endif /* INCLUDED_MEMORY_H */
