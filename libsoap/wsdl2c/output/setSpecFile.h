/** Generated by xsd2c*/
#ifndef __setSpecFile_H__
#define __setSpecFile_H__



#ifndef _DESERIALIZER_DISABLE_
	#include <libxml/parser.h>
#endif


#define TO_SETSPECFILE(derived) (derived->__base) 


#ifdef __cplusplus
extern "C" {
#endif 


/**
 *	OBJECT: setSpecFile
 */
struct setSpecFile
{
	char* in0;
	char* in1;
};

/**
 *	LIST: setSpecFile_List
 */
struct setSpecFile_List
{
	struct setSpecFile* value;
	struct setSpecFile_List* next;
};


struct setSpecFile* setSpecFile_Create();
void setSpecFile_Free(struct setSpecFile* obj);
void setSpecFile_Sax_Serialize(struct setSpecFile* obj,
		 const char *root_element_name,
		 void (*OnStartElement)(const char* element_name, int attr_count, char **keys, char **values, void* userData),
		 void (*OnCharacters)(const char* element_name, const char* chars, void* userData),
		 void (*OnEndElement)(const char* element_name, void* userData),
		 void* userData);

#ifndef _DESERIALIZER_DISABLE_
struct setSpecFile* setSpecFile_Deserialize(xmlNodePtr xmlRoot);
#endif

void setSpecFile_Set_in0(struct setSpecFile* obj, const char* in0);
void setSpecFile_Set_in1(struct setSpecFile* obj, const char* in1);
char* setSpecFile_Get_in0(struct setSpecFile* obj);
char* setSpecFile_Get_in1(struct setSpecFile* obj);


#ifdef __cplusplus
};
#endif /*__cplusplus*/



#endif
