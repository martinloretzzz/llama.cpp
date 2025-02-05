#ifndef HNSW_WRAPPER_H
#define HNSW_WRAPPER_H

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

void search_load_index(const float * query, float * dest, int k, int dimensions, int ef);

#ifdef __cplusplus
}
#endif

#endif