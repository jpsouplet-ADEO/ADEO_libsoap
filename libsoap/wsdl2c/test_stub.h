#ifndef __TEST_SOAP_H__
#define __TEST_SOAP_H__

#include "setSourceFile.h"
#include "generateRPM.h"
#include "getError.h"
#include "setSpecFile.h"

struct setSourceFileResponse* impl_setSourceFile(const struct setSourceFile* parameters);
struct generateRPMResponse* impl_generateRPM(const struct generateRPM* parameters);
struct getErrorResponse* impl_getError(const struct getError* parameters);
struct setSpecFileResponse* impl_setSpecFile(const struct setSpecFile* parameters);


#endif
