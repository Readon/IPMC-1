/* const ints are static by default and will be optimized away by the compiler.
 *
 * So, this is not const here.  It is in the headers.  The linker won't care.
 */
long int GIT_SHORT_INT   = D_GIT_SHORT_INT;
const char *GIT_SHORT    = D_GIT_SHORT;
const char *GIT_LONG     = D_GIT_LONG;
const char *GIT_DESCRIBE = D_GIT_DESCRIBE;
const char *GIT_BRANCH   = D_GIT_BRANCH;
const char *GIT_STATUS   = D_GIT_STATUS;