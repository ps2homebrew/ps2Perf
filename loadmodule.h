/*********************************************************************
 * Sif functions for module (.irx) loading
 * Quite easy rev engineered from util demos..
 * These functions are not in any way complete or really tested!
 *                      -pukko
 */

#ifndef _LOAD_MODULE_H_
#define _LOAD_MODULE_H_

int _lf_bind(int arg0);

/*int sif_load_module(char *moduleName, int a, void *b, int c);
*/
int sif_get_iop_addr(u32 src, void *dst);

#endif
